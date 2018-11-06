
ENTITY system_tb IS
   -- empty
END system_tb;

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

ARCHITECTURE behaviour OF system_tb IS

   CONSTANT RSTDEF: std_ulogic := '1'; -- high active
   CONSTANT FRQMAX: natural    := natural(50.0e6);
   CONSTANT tpd:    time       := 1 sec / FRQMAX;
   CONSTANT baud:   natural    := 9600;

   SUBTYPE std_byte IS std_logic_vector(7 DOWNTO 0);

   COMPONENT system
      PORT(rst:  IN  std_logic;  -- system reset, high active
           clk:  IN  std_logic;  -- system clock, 50 MHz, rising edge active
           btn0: IN  std_logic;  -- push button, low active
           rxd:  IN  std_logic;  -- receiver signal
           evn1: OUT std_logic;  -- event1, interrupt, high active
           evn2: OUT std_logic;  -- event2, RETURNI, high active
           txd:  OUT std_logic;  -- transmitter signal
           led0: OUT std_logic;  -- led, low active
           led1: OUT std_logic); -- led, low active
   END COMPONENT;

   SIGNAL rst:   std_logic := NOT RSTDEF;
   SIGNAL hlt:   std_logic := '0';
   SIGNAL clk:   std_logic := '0';
   SIGNAL btn0:  std_logic := '1';
   SIGNAL rxd:   std_logic := '1';
   SIGNAL txd:   std_logic := '1';
   SIGNAL strt:  std_logic := '0';
   SIGNAL led0:  std_logic := '1';
   SIGNAL led1:  std_logic := '1';
   SIGNAL chr1:  character := ' ';
   SIGNAL chr2:  character := ' ';
   SIGNAL strb:  std_logic := '0';
   SIGNAL evn1:  std_logic := '0';
   SIGNAL evn2:  std_logic := '0';
   SIGNAL mes:   real      := 0.0;
   SIGNAL avg:   real      := 0.0;

BEGIN

   rst <= RSTDEF AFTER 5*tpd, NOT RSTDEF AFTER 15*tpd;
   clk <= not(clk) AFTER tpd/2  WHEN hlt='0' ELSE clk;

   sys: system
   PORT MAP(rst  => rst,
            clk  => clk,
            btn0 => btn0,
            rxd  => txd,
            evn1 => evn1,
            evn2 => evn2,
            txd  => rxd,
            led0 => led0,
            led1 => led1);

   main: PROCESS IS
      CONSTANT dly: time := 1 sec / real(baud);

      FUNCTION isalnum(ch: character) RETURN boolean IS
      BEGIN
         RETURN (ch >= '0' AND ch <= '9') OR (ch >= 'a' AND ch <= 'z') OR (ch >= 'A' AND ch <= 'Z');
      END FUNCTION isalnum;

      PROCEDURE send(arg: character) IS
         VARIABLE tmp: std_byte;
      BEGIN
         WAIT FOR dly;
         chr1 <= arg;
         txd  <= '0'; -- Startbit
         strt <= '1' AFTER 7*dly/16, '0' AFTER 8*dly/16;
         WAIT FOR dly;
         tmp  := conv_std_logic_vector(character'POS(arg), tmp'LENGTH);
         FOR i IN 0 TO 7 LOOP
            txd <= tmp(i);
            WAIT FOR dly;
         END LOOP;
         txd  <= '1'; -- Stoppbit
      END PROCEDURE send;

      PROCEDURE send(arg: string) IS
      BEGIN
         FOR i IN arg'LEFT TO arg'RIGHT LOOP
            send(arg(i));
         END LOOP;
      END PROCEDURE;

      PROCEDURE recv(arg: OUT character) IS
         CONSTANT OSR: natural := 16;
         CONSTANT dly: time    := 1 sec / real(OSR*baud);
         VARIABLE tmp: std_byte;
         VARIABLE chr: character;
      BEGIN

         WAIT UNTIL rxd='0';
         WAIT FOR 8*dly;
         ASSERT rxd='0' REPORT "wrong start bit" SEVERITY error;
         strb <= '1', '0' AFTER 100 ns;
         FOR i IN 0 TO 7 LOOP
            WAIT FOR 16*dly;
            strb <= '1', '0' AFTER 100 ns;
            tmp(i) := rxd;
         END  LOOP;
         chr  := character'VAL(conv_integer(tmp));
         arg  := chr;
         chr2 <= chr;
         WAIT FOR 16*dly;
         strb <= '1', '0' AFTER 100 ns;
         ASSERT rxd='1' REPORT "wrong stop bit" SEVERITY error;

      END PROCEDURE;

      PROCEDURE recv(arg: string) IS
         VARIABLE tmp: string(1 TO arg'LENGTH) := arg;
         VARIABLE chr: character;
      BEGIN
         FOR i IN 1 TO tmp'LENGTH LOOP
            IF isalnum(tmp(i)) THEN
               recv(chr);
               ASSERT tmp(i)=chr REPORT "wrong character" SEVERITY error;
            END IF;
         END LOOP;
      END PROCEDURE;

      PROCEDURE test(nr: natural; arg: string) IS
         CONSTANT msg: string := "test " & integer'image(nr) & " ...";
      BEGIN
         REPORT msg;
         send(arg);
         recv(arg);
      END PROCEDURE;
   
   BEGIN
      hlt <= '0';
      txd <= '1';
      WAIT UNTIL rst=NOT RSTDEF;
      WAIT FOR dly;

      test(1, "0123456789012345");
      test(2, "1!2õ4$5%6&7/{(89");
      test(3, "$$$$0$$$$$$$$$$$");
      test(4, "abcdefghijklmnop");

      WAIT FOR 10*dly;
      hlt <= '1';
      REPORT "done ...";
      WAIT;
   END PROCESS;

-- ----------------------------------------------------------------------------

   PROCESS
      VARIABLE cnt1: integer := 0;
      VARIABLE cnt2: integer := 0;
   BEGIN
      WAIT UNTIL rst=NOT RSTDEF;
      mes  <= 0.0;
      WAIT UNTIL evn1='1';
      LOOP
         cnt2 := 0;
         WHILE evn2='0' LOOP
            WAIT UNTIL clk='1';
            cnt2 := cnt2 + 1;
         END LOOP;
         cnt1 := cnt2;
         WHILE evn1='0' LOOP
            WAIT UNTIL clk='1';
            cnt1 := cnt1 + 1;
         END LOOP;
         mes <= real(cnt2)/real(cnt1);
      END LOOP;
      WAIT;
   END PROCESS;

--   PROCESS IS
--      VARIABLE cnt: integer := 1;
--   BEGIN
--      LOOP
--         mes <= real(cnt);
--         cnt := cnt + 1;
--         WAIT FOR 100 ns;
--      END LOOP;
--   END PROCESS;

   PROCESS (mes) IS
      VARIABLE cnt: integer := 1;
   BEGIN
      avg <= (real(cnt-1)*avg + mes)/real(cnt);
      cnt := cnt + 1;
   END PROCESS;

END behaviour;
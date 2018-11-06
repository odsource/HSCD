
-- Hinweise:
-- Diese Testumgebung arbeitet mit einem kurzen Datenblock, nur 20 Bytes
-- Diese Datenlaenge muss in der Assembler-Applikation beruecksichtigt werden.

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

   SIGNAL rst:  std_logic := NOT RSTDEF;
   SIGNAL hlt:  std_logic := '0';
   SIGNAL hlt1: std_logic := '0';
   SIGNAL hlt2: std_logic := '0';
   SIGNAL clk:  std_logic := '0';
   SIGNAL btn0: std_logic := '1';
   SIGNAL rxd:  std_logic := '1';
   SIGNAL txd:  std_logic := '1';
   SIGNAL led0: std_logic := '1';
   SIGNAL led1: std_logic := '1';
   SIGNAL src:  integer   := 0;
   SIGNAL data: integer   := -1;
   SIGNAL strb: std_logic := '0';
   SIGNAL evn1: std_logic := '0';
   SIGNAL evn2: std_logic := '0';
   SIGNAL mes:  real      := 0.0;
   SIGNAL avg:  real      := 0.0;

   SIGNAL str:  string(1 TO 16);
   SIGNAL strt: std_logic := '0';
   SIGNAL done: std_logic := '0';
   
BEGIN

   rst <= RSTDEF, NOT RSTDEF AFTER 15*tpd;
   clk <= not(clk) AFTER tpd/2  WHEN hlt='0' ELSE clk;

   hlt <= hlt1 AND hlt2;

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

   button: PROCESS IS
   BEGIN
--      hlt1 <= '0';
--
--      btn0 <= '1';
--      WAIT FOR 5 ms;
--      btn0 <= '0';
--      WAIT FOR 10 ms;
--
--      btn0 <= '1';
--      WAIT FOR 40 ms;
--      btn0 <= '0';
--      WAIT FOR 25 ms;
--
--      btn0 <= '1';
--      WAIT FOR 100 ms;
--      btn0 <= '0';
--      WAIT FOR 75 ms;
--
--      btn0 <= '1';
      hlt1 <= '1';
      WAIT;
   END PROCESS;

   transmitter: PROCESS IS
      CONSTANT baud: natural := 9600;
      CONSTANT dly:  time    := 1 sec / real(baud);

      PROCEDURE test1 IS
         CONSTANT tpd: time := dly / 16.0;
      BEGIN
         FOR i IN 1 TO 7 LOOP
            txd  <= '0'; -- fallende Flanke am TxD-Signal erzeugen
            WAIT FOR i*tpd;
            txd  <= '1'; -- High am TxD-Signal erzeugen
            WAIT FOR dly;
         END LOOP;
         WAIT FOR dly;
      END PROCEDURE;
      
      PROCEDURE send(arg: natural) IS
         VARIABLE tmp: std_byte;
      BEGIN
         tmp  := conv_std_logic_vector(arg, tmp'LENGTH);
         src  <= arg;
         txd  <= '0'; -- Startbit
         WAIT FOR dly;
         FOR i IN 0 TO 7 LOOP
            txd <= tmp(i);
            WAIT FOR dly;
         END LOOP;
         txd  <= '1';
         WAIT FOR dly;
      END PROCEDURE send;

      PROCEDURE send(arg: string) IS
      BEGIN
         str  <= arg;
         strt <= '1', '0' AFTER 100 ns;
         FOR i IN arg'LEFT TO arg'RIGHT LOOP
            send(character'POS(arg(i)));
         END LOOP;
         WAIT ON done;
      END PROCEDURE;
   
      VARIABLE ch: character;
   BEGIN
      hlt2 <= '0';
      txd  <= '1';
      WAIT UNTIL rst=NOT RSTDEF;
      WAIT FOR dly;

      test1;
      
      send("9328120394765241");
--      send("1!2õ4$5%6&7/{(89");
--      send("$$$$0$$$$$$$$$$$");
--      send("abcdefghijklmnop");
      
      WAIT FOR 10*dly;
      hlt2 <= '1';
      WAIT;
   END PROCESS;

-- ----------------------------------------------------------------------------

   receiver: PROCESS IS
      CONSTANT baud: natural := 9600;
      CONSTANT OSR:  natural := 16;
      CONSTANT dly:  time    := 1 sec / real(OSR*baud);

      PROCEDURE receive(arg: OUT natural) IS
         VARIABLE tmp: std_byte;
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
         arg := conv_integer(tmp);
         WAIT FOR 16*dly;
         strb <= '1', '0' AFTER 100 ns;
         ASSERT rxd='1' REPORT "wrong stop bit" SEVERITY error;
      END PROCEDURE receive;

      PROCEDURE receive(str: IN string; cnt: natural) IS
         VARIABLE tmp: string(1 TO str'LENGTH);
         VARIABLE arg: natural;
      BEGIN
         FOR i IN 1 TO cnt LOOP
            receive(arg);
            tmp(i) := character'VAL(arg);
         END LOOP;
         ASSERT str(1 TO cnt)=tmp(1 TO cnt) REPORT "wrong data block" SEVERITY error;
         WAIT FOR 8*dly;
      END PROCEDURE receive;

      PROCEDURE getCharacters(arg: string; tmp: OUT string; cnt: OUT natural) IS
         FUNCTION isalnum(ch: character) RETURN boolean IS
         BEGIN
            RETURN (ch >= '0' AND ch <= '9') OR (ch >= 'a' AND ch <= 'z') OR (ch >= 'A' AND ch <= 'Z');
         END FUNCTION isalnum;
         VARIABLE k: natural;
      BEGIN
         k := 0;
         FOR i IN arg'RANGE LOOP
            IF isalnum(arg(i)) THEN
               k := k + 1;
               tmp(k) := arg(i);
            END IF;
         END LOOP;
         cnt := k;
      END PROCEDURE getCharacters;
   
      VARIABLE cnt: natural;
      VARIABLE tmp: string(1 TO 16); 
   BEGIN
      WAIT UNTIL rst=NOT RSTDEF;
      WAIT FOR dly;
--      WHILE hlt='0' LOOP
--         WAIT ON strt;
--         getCharacters(str, tmp, cnt);
--         receive(tmp, cnt);
--         done <= '1', '0' AFTER 100 ns;
--      END LOOP;
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

   PROCESS (mes) IS
      VARIABLE cnt: integer := 1;
   BEGIN
      avg <= (real(cnt-1)*avg + mes)/real(cnt);
      cnt := cnt + 1;
   END PROCESS;

END behaviour;

ENTITY insertsort_tb IS
   -- empty
END insertsort_tb;

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

ARChITECTURE verhalten OF insertsort_tb IS

   CONSTANT RSTDEF: std_ulogic := '1'; -- high active
   CONSTANT FRQMAX: natural    := natural(50.0e6);
   CONSTANT tpd:    time       := 1 sec / FRQMAX;

   TYPE string IS array(natural RANGE <>) OF character;
      
   COMPONENT insertsort
      GENERIC(RSTDEF: std_logic);
      PORT(rst:   IN  std_logic;  -- reset, RSTDEF active
           clk:   IN  std_logic;  -- clock, rising edge active
           
           -- interface to PicoBlaze
           rsel:  IN  std_logic_vector(7 DOWNTO 0); -- register select
           din:   IN  std_logic_vector(7 DOWNTO 0); -- data input
           dout:  OUT std_logic_vector(7 DOWNTO 0); -- data output
           ena:   IN  std_logic; -- enable, high active
           wre:   IN  std_logic; -- write strobe, high active
      
           -- interface to RAM block through port B
           WEB:   OUT std_logic; -- Port B Write Enable Output, high active
           ENB:   OUT std_logic; -- Port B RAM Enable, high active
           ADDRB: OUT std_logic_vector(10 DOWNTO 0); -- Port B 11-bit Address Output
           DIB:   IN  std_logic_vector(7 DOWNTO 0);  -- Port B 8-bit Data Input
           DOB:   OUT std_logic_vector(7 DOWNTO 0)); -- Port B 8-bit Data Output
   END COMPONENT;

   SIGNAL ram: string(0 TO 1023) := (OTHERS => ' ');

   SIGNAL rst:          std_logic := NOT RSTDEF;
   SIGNAL hlt:          std_logic := '0';
   SIGNAL hlt1:         std_logic := '0';
   SIGNAL hlt2:         std_logic := '0';
   SIGNAL clk:          std_logic := '0';

   SIGNAL swrst:        std_logic := '0';
   SIGNAL cnt:          integer   := 0;
   SIGNAL enable:       std_logic := '0';
   SIGNAL write_strobe: std_logic := '0';
   SIGNAL port_id:      std_logic_vector(7 DOWNTO 0) := (OTHERS => '0');
   SIGNAL out_port:     std_logic_vector(7 DOWNTO 0) := (OTHERS => '0');
   SIGNAL in_port:      std_logic_vector(7 DOWNTO 0) := (OTHERS => '0');

   SIGNAL ENB:          std_logic := '0';
   SIGNAL WEB:          std_logic := '0';
   SIGNAL DOB:          std_logic_vector( 7 DOWNTO 0) := (OTHERS => '0');
   SIGNAL DIB:          std_logic_vector( 7 DOWNTO 0) := (OTHERS => '0');
   SIGNAL ADDRB:        std_logic_vector(10 DOWNTO 0) := (OTHERS => '0');

BEGIN

   rst <= RSTDEF AFTER 5*tpd, NOT RSTDEF AFTER 15*tpd;
   clk <= not(clk) AFTER tpd/2  WHEN hlt='0' ELSE clk;

   p1: PROCESS (clk) BEGIN
      IF rising_edge(clk) THEN
         cnt <= cnt + 1;
         IF swrst='1' THEN
            cnt <= 0;
         END IF;
      END IF;
   END PROCESS;

   mem: PROCESS (rst, clk) IS
      VARIABLE adr: natural;
   BEGIN
      IF rst=RSTDEF THEN
         DOB <= (OTHERS => '0');
         ram(0 TO 279) <= "P91fQeZB4KvTMcrEfzM4" &
                          "1449BEKMMPQTZceffrvz" &
                          "zvrffecZTQPMMKEB9441" &
                          "889asdnkkj23LKJiulLK" &
                          "MghJ227UjjU777ymnbJJ" &
                          "114238123059845x9871" &
                          "andnndhheuuiqof6g6ei" &
                          "NNSGSIOAAQIEDJTCSJHK" &
                          "90019288390KKSJJAAAA" &
                          "yyaYYAppaoiiwuuwz773" &
                          "hhazz17788dnmsmkjskj" &
                          "123847hfBZG876tUZG87" &
                          "1010aplaqpoycnwwue88" &
                          "hhdztt2662628ccxykwi" ;
                         
      ELSIF rising_edge(clk) THEN
         adr := conv_integer('0' & ADDRB);
         IF ENB='1' THEN
            DOB <= conv_std_logic_vector(character'POS(ram(adr)), DOB'LENGTH);
            IF WEB='1' THEN
               ram(adr) <= character'VAL(conv_integer('0' & DIB));
            END IF;
         END IF;
      END IF;
   END PROCESS;

   cpu: PROCESS IS
      
      SUBTYPE std_byte IS std_logic_vector(7 DOWNTO 0);

      PROCEDURE clock(n: natural) IS
      BEGIN
         FOR i IN 1 TO n LOOP
            WAIT UNTIL clk='1';
         END LOOP;
      END PROCEDURE clock;

      PROCEDURE read(adr: std_byte; arg: OUT std_byte) IS
      BEGIN
         port_id      <= adr;
         enable       <= '1';
         clock(1);
         arg          := in_port;  
         enable       <= '0';
         clock(1);
      END PROCEDURE;
   
      PROCEDURE write(adr: std_byte; arg: std_byte) IS
      BEGIN
         port_id      <= adr;
         out_port     <= arg;
         enable       <= '1';
         write_strobe <= '1';
         clock(1);
         enable       <= '0';
         write_strobe <= '0';
         clock(1);
      END PROCEDURE write;
   
      PROCEDURE test(adr: natural; len: natural) IS
         VARIABLE tmp1: std_logic_vector(10 DOWNTO 0);
         VARIABLE tmp2: std_byte;
         VARIABLE res:  std_byte := X"00";
      BEGIN
         tmp1 := conv_std_logic_vector(adr, tmp1'LENGTH);
         tmp2 := conv_std_logic_vector(len, tmp2'LENGTH);
         write(X"01", tmp1( 7 DOWNTO 0));
         write(X"02", "00000" & tmp1(10 DOWNTO 8));
         write(X"03", tmp2);
         write(X"00", X"01");
         swrst <= '0';
         clock(4);
         write(X"00", X"00");
         WHILE res=X"00" LOOP
            read(X"00", res);
         END LOOP;
         swrst <= '1';
      END PROCEDURE;
   
   BEGIN
      swrst  <= '1';
      enable <= '0';
      write_strobe <= '0';
      WAIT UNTIL rst=NOT RSTDEF;
--      test(0, 3);
--      test(3, 4);
--      test(0, 20);
--      test(20, 20);
--      test(40, 20);
--      test(0, 60);
      test(0, 20);
      test(20, 240);
      test(260, 20);
      hlt <= '1';
      WAIT;
   END PROCESS;

   asic: insertsort
   GENERIC MAP(RSTDEF => RSTDEF)
   PORT MAP(rst   => rst,
            clk   => clk,

            -- interface to PicoBlaze
            rsel  => port_id,
            din   => out_port,
            dout  => in_port,
            ena   => enable,
            wre   => write_strobe,

            -- interface to RAM block through port B
            WEB   => WEB,
            ENB   => ENB,
            ADDRB => ADDRB,
            DIB   => DOB,
            DOB   => DIB);

END verhalten;
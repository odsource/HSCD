
ENTITY insertcore_tb IS
   -- empty
END insertcore_tb;

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

ARChITECTURE verhalten OF insertcore_tb IS

   CONSTANT RSTDEF: std_ulogic := '1'; -- high active
   CONSTANT FRQMAX: natural    := natural(50.0e6);
   CONSTANT tpd:    time       := 1 sec / FRQMAX;

   TYPE string IS array(natural RANGE <>) OF character;

   COMPONENT insertcore
      GENERIC(RSTDEF: std_logic);
      PORT(rst:  IN  std_logic;  -- reset, RSTDEF active
           clk:  IN  std_logic;  -- clock, rising edge active

           -- handshake signals
           strt: IN  std_logic;  -- start bit, high active
           done: OUT std_logic;  -- done bit, high active
           ptr:  IN  std_logic_vector(10 DOWNTO 0); -- pointer to vector
           len:  IN  std_logic_vector( 7 DOWNTO 0); -- length of vector

           -- interface to RAM block through port B
           WEB:  OUT std_logic; -- Port B Write Enable Output, high active
           ENB:  OUT std_logic; -- Port B RAM Enable, high active
           ADR:  OUT std_logic_vector(10 DOWNTO 0); -- Port B 11-bit Address Output
           DIB:  IN  std_logic_vector(7 DOWNTO 0);  -- Port B 8-bit Data Input
           DOB:  OUT std_logic_vector(7 DOWNTO 0)); -- Port B 8-bit Data Output
   END COMPONENT;

   SIGNAL ram: string(0 TO 1023) := (OTHERS => ' ');

   SIGNAL rst:     std_logic := NOT RSTDEF;
   SIGNAL hlt:     std_logic := '0';
   SIGNAL clk:     std_logic := '0';

   SIGNAL swrst:   std_logic := '0';
   SIGNAL cnt:     integer   := 0;

   SIGNAL strt:    std_logic := '0';
   SIGNAL done:    std_logic := '0';
   SIGNAL len:     std_logic_vector( 7 DOWNTO 0) := (OTHERS => '0');
   SIGNAL ptr:     std_logic_vector(10 DOWNTO 0) := (OTHERS => '0');

   SIGNAL ENB:     std_logic := '0';
   SIGNAL WEB:     std_logic := '0';
   SIGNAL DOB:     std_logic_vector( 7 DOWNTO 0) := (OTHERS => '0');
   SIGNAL DIB:     std_logic_vector( 7 DOWNTO 0) := (OTHERS => '0');
   SIGNAL ADR:     std_logic_vector(10 DOWNTO 0) := (OTHERS => '0');

BEGIN

   rst <= RSTDEF, NOT RSTDEF AFTER 15*tpd;
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
      VARIABLE a: natural;
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
         a := conv_integer('0' & ADR);
         IF ENB='1' THEN
            DOB <= conv_std_logic_vector(character'POS(ram(a)), DOB'LENGTH);
            IF WEB='1' THEN
               ram(a) <= character'VAL(conv_integer('0' & DIB));
            END IF;
         END IF;
      END IF;
   END PROCESS;

   cpu: PROCESS IS

      PROCEDURE clock(n: natural) IS
      BEGIN
         FOR i IN 1 TO n LOOP
            WAIT UNTIL clk='1';
         END LOOP;
      END PROCEDURE clock;

      PROCEDURE test(adr: natural; arg: natural) IS
      BEGIN
         swrst <= '0';
         ptr   <= conv_std_logic_vector(adr, ptr'LENGTH);
         len   <= conv_std_logic_vector(arg, len'LENGTH);
         strt  <= '1';
         clock(1);
         strt  <= '0';
         clock(1);
         WHILE done='0' LOOP
            clock(1);
         END LOOP;
         swrst <= '1';
      END PROCEDURE;

   BEGIN
      swrst  <= '1';
      WAIT UNTIL rst=NOT RSTDEF;
--      test(0, 3);
--      test(3, 4);
      test(0, 20);
      test(20, 20);
      test(40, 20);
--      test(0, 60);
--      test(0, 20);
--      test(20, 240);
--      test(260, 20);
      hlt <= '1';
      WAIT;
   END PROCESS;

   asic: insertcore
   GENERIC MAP(RSTDEF => RSTDEF)
   PORT MAP(rst  => rst,
            clk  => clk,

            strt => strt,
            done => done,
            ptr  => ptr,
            len  => len,

            -- interface to RAM block through port B
            WEB  => WEB,
            ENB  => ENB,
            ADR  => ADR,
            DIB  => DOB,
            DOB  => DIB);

END verhalten;
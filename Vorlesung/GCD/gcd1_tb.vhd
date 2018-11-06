
ENTITY gcd1_tb IS
   -- empty
END gcd1_tb;

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

ARCHITECTURE verhalten OF gcd1_tb IS
   CONSTANT RSTDEF: std_logic := '0';

   COMPONENT gcd
     GENERIC(RSTDEF: std_logic);
     PORT(rst:   IN  std_logic;
          clk:   IN  std_logic;
          strt:  IN  std_logic;
          done:  OUT std_logic;
          x:     IN  unsigned(15 DOWNTO 0);
          y:     IN  unsigned(15 DOWNTO 0);
          res:   OUT unsigned(15 DOWNTO 0));
   END COMPONENT;
   
   SIGNAL rst:  std_logic := RSTDEF;
   SIGNAL hlt:  std_logic := '0';
   SIGNAL clk:  std_logic := '0';
   SIGNAL strt: std_logic := '0'; 
   SIGNAL done: std_logic := '0';
   SIGNAL x:    unsigned(15 DOWNTO 0) := (OTHERS => '0');
   SIGNAL y:    unsigned(15 DOWNTO 0) := (OTHERS => '0');
   SIGNAL res:  unsigned(15 DOWNTO 0) := (OTHERS => '0');

BEGIN
   
   rst <= RSTDEF, NOT RSTDEF AFTER 20 ns;
   clk <= NOT clk AFTER 10 ns WHEN hlt='0' ELSE '0';
   
   u1: gcd
   GENERIC MAP(RSTDEF => RSTDEF)
   PORT MAP (rst  => rst,
             clk  => clk,
             strt => strt,
             done => done,
             x    => x,
             y    => y,
             res  => res);

   p1: PROCESS IS
      PROCEDURE test(arg1: integer; arg2: integer; arg3: integer) IS
      BEGIN
         WAIT UNTIL clk='1';
         x <= conv_unsigned(arg1, x'LENGTH);
         y <= conv_unsigned(arg2, y'LENGTH);
         strt <= '1';
         WAIT UNTIL clk='1';
         strt <= '0';
         WAIT UNTIL clk='1' AND done='1';
         ASSERT conv_integer(res)=arg3 REPORT "wrong result" SEVERITY error;
      END PROCEDURE;
      
   BEGIN
      WAIT UNTIL rst=NOT RSTDEF;
      test(251, 119, 1);
      test(26812, 2772, 4);
      hlt <= '1';
      WAIT;
   END PROCESS;

END verhalten;
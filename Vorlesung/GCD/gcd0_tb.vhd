
ENTITY gcd0_tb IS
   -- empty
END gcd0_tb;

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

ARCHITECTURE behaviour OF gcd0_tb IS
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
   SIGNAL clk:  std_logic := '0';
   SIGNAL strt: std_logic := '0'; 
   SIGNAL done: std_logic := '0';
   SIGNAL x:    unsigned(15 DOWNTO 0) := (OTHERS => '0');
   SIGNAL y:    unsigned(15 DOWNTO 0) := (OTHERS => '0');
   SIGNAL res:  unsigned(15 DOWNTO 0) := (OTHERS => '0');

BEGIN
   
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
         WAIT FOR 10 ns;
         x <= conv_unsigned(arg1, x'LENGTH);
         y <= conv_unsigned(arg2, y'LENGTH);
         strt <= '1';
         WAIT FOR 10 ns;
         strt <= '0';
         WAIT UNTIL done='1';
         WAIT FOR 10 ns;
         ASSERT conv_integer(res)=arg3 REPORT "wrong result" SEVERITY error;
      END PROCEDURE;
      
   BEGIN
      test(251, 119, 1);
      test(26812, 2772, 4);
      WAIT;
   END PROCESS;

END behaviour;
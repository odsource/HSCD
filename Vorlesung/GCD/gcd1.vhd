
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

ENTITY gcd IS
  GENERIC(RSTDEF: std_logic := '0');
  PORT(rst:   IN  std_logic;
       clk:   IN  std_logic;
       strt:  IN  std_logic;
       done:  OUT std_logic;
       x:     IN  unsigned(15 DOWNTO 0);
       y:     IN  unsigned(15 DOWNTO 0);
       res:   OUT unsigned(15 DOWNTO 0));
END gcd;

ARCHITECTURE behaviour OF gcd IS
  TYPE TState IS (S0, S1);
  SIGNAL state: TState; 
BEGIN
   
  PROCESS (rst, clk) IS
    VARIABLE reg_x: unsigned(x'RANGE);
    VARIABLE reg_y: unsigned(x'RANGE);  
  BEGIN
    IF rst=RSTDEF THEN
      reg_x := (OTHERS => '0');
      reg_y := (OTHERS => '0');
      res   <= (OTHERS => '0');
      done  <= '0';
      state <= S0;
    ELSIF rising_edge(clk) THEN
      CASE state IS
         WHEN S0 =>
           done <= '0';
           IF strt='1' THEN
             reg_x := x;
             reg_y := y;
             state <= S1;
            END IF;
         WHEN S1 =>
           WHILE reg_x /= reg_y LOOP
             IF reg_x<reg_y THEN
               reg_y := reg_y - reg_x;
             ELSE
               reg_x := reg_x - reg_y;
             END IF;
           END LOOP;
           state <= S0;
           done <= '1';
           res  <= reg_x;
      END CASE;
    END IF;
  END PROCESS;
  
END behaviour;

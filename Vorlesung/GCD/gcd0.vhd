
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
BEGIN
   
  PROCESS IS
    VARIABLE reg_x: unsigned(x'RANGE);
    VARIABLE reg_y: unsigned(x'RANGE);
  BEGIN
   
    WAIT UNTIL strt='1';
    done <= '0';
    reg_x := x;
    reg_y := y;
    
    WHILE reg_x /= reg_y LOOP
      IF reg_x<reg_y THEN
        reg_y := reg_y - reg_x;
      ELSE
        reg_x := reg_x - reg_y;
      END IF;
    END LOOP;
    WAIT FOR 30 ns;
    done <= '1';
    res  <= reg_x;
  END PROCESS;
  
END behaviour;

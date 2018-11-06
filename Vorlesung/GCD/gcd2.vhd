
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_unsigned.all;

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
  TYPE TState IS (S0, S1, S2, S3);
  SIGNAL state: TState;
  SIGNAL reg_x: unsigned(x'RANGE);
  SIGNAL reg_y: unsigned(x'RANGE);
BEGIN
   
  res <= reg_x;

  PROCESS(rst, clk) BEGIN
    IF rst=RSTDEF THEN
      state <= S0;
      done  <= '0';
      reg_x <= (OTHERS => '0');
      reg_y <= (OTHERS => '0');
    ELSIF rising_edge(clk) THEN
      CASE state IS
        WHEN S0 =>
          done  <= '0';
          IF strt='1' THEN
            reg_x <= x;
            reg_y <= y;
            state <= S1;
          END IF;
        WHEN S1 =>
          IF reg_x=reg_y THEN
            done  <= '1';
            state <= S0;
          ELSIF reg_x<reg_y THEN
            state <= S2;
          ELSE
            state <= S3;
          END IF;
        WHEN S2 =>
          reg_y <= reg_y - reg_x;
          state <= S1;
        WHEN S3 =>
          reg_x <= reg_x - reg_y;
          state <= S1;
      END CASE;
    END IF;
  END PROCESS;
END behaviour;

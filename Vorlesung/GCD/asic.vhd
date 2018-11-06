LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY asic IS
  PORT(rst:   IN  std_logic; -- reset, low active
       clk:   IN  std_logic; -- clock, rising edge active
       cs:    IN  std_logic; -- chip select, low active
       rw:    IN  std_logic; -- write enable, low active 
       int:   OUT std_logic; -- interrupt, low active
       abus:  IN    std_logic_vector(2 DOWNTO 0);  -- register select
       dbus:  INOUT std_logic_vector(7 DOWNTO 0)); -- data bus
END asic;

LIBRARY ieee;
USE ieee.std_logic_arith.all;
USE ieee.std_logic_unsigned.all;

ARCHITECTURE behaviour OF asic IS
   
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

  SIGNAL x:   unsigned(15 DOWNTO 0);
  SIGNAL y:   unsigned(15 DOWNTO 0);
  SIGNAL res: unsigned(15 DOWNTO 0);
  SIGNAL strt, ie, eop, done: std_logic;
  SIGNAL dout: std_logic_vector(7 DOWNTO 0);

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
             
   int <= '0' WHEN ie='1' AND eop='1' ELSE 'Z';

   PROCESS (rst, clk) BEGIN
      IF rst=RSTDEF THEN
         strt <= '0';
         ie   <= '0';
         eop  <= '0';
      ELSIF rising_edge(clk) THEN
         IF cs='0' AND rw='0' THEN
            CASE abus IS
               WHEN "000" => x(15 DOWNTO 8) <= unsigned(dbus);
               WHEN "001" => x( 7 DOWNTO 0) <= unsigned(dbus);
               WHEN "010" => y(15 DOWNTO 8) <= unsigned(dbus);
               WHEN "011" => y( 7 DOWNTO 0) <= unsigned(dbus);
               WHEN "100" => strt <= dbus(0);
                             ie   <= dbus(1);
                             eop  <= '0';
               WHEN OTHERS => NULL;
            END CASE;
         END IF;
         IF done='1' THEN
            eop  <= '1';
            strt <= '0';
         END IF;
      END IF;
   END PROCESS;

   WITH abus SELECT
   dout <= std_logic_vector(res(15 DOWNTO 8)) WHEN "000",
           std_logic_vector(res( 7 DOWNTO 0)) WHEN "001",
           "00000" & eop & ie & strt          WHEN "100",
           "00000000" WHEN OTHERS;

   dbus <= dout WHEN cs='0' AND rw='1' ELSE (OTHERS => 'Z');

END behaviour;

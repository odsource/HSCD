
ENTITY timer_tb IS
   -- empty
END timer_tb;

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

ARCHITECTURE verhalten OF timer_tb IS

   CONSTANT RSTDEF: std_ulogic := '0';
   CONSTANT FRQMAX: natural    := natural(50.0e6);
   CONSTANT tpd:    time       := 1 sec / FRQMAX;

   CONSTANT dly:    time       := 1 sec / 307.2e3;
   
   COMPONENT timer
      GENERIC(RSTDEF: std_logic);
      PORT(rst:  IN  std_logic;  -- reset, RSTDEF active
           clk:  IN  std_logic;  -- clock, rising edge active
           irq:  OUT std_logic;  -- interrupt request, high active
           iack: IN  std_logic); -- interrupt acknowledge, high active
   END COMPONENT;

   SIGNAL rst:  std_logic := RSTDEF;
   SIGNAL clk:  std_logic := '0';
   SIGNAL hlt:  std_logic := '0';
   SIGNAL irq:  std_logic := '0';
   SIGNAL iack: std_logic := '0';

BEGIN

   rst  <= RSTDEF, NOT RSTDEF AFTER 5*tpd;
   clk <= not(clk) AFTER tpd/2  WHEN hlt='0' ELSE clk;

   hlt <= '0', '1' AFTER 10*dly;
   
   iack <= irq AFTER 3*tpd;
   
-- -----------------------------------------------------------------------------------------

   u1: timer
   GENERIC MAP(RSTDEF => RSTDEF)
   PORT MAP(rst  => rst,
            clk  => clk,
            irq  => irq,
            iack => iack);

END verhalten;
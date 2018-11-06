LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY FDSx2 IS
   PORT(D : IN  std_ulogic;  -- data input
        Q : OUT std_ulogic;  -- data output
        S : IN  std_ulogic;  -- preset, high active
        C : IN  std_ulogic); -- clock, rising edge active
END FDSx2;

LIBRARY unisim;
USE unisim.vcomponents.ALL;

ARCHITECTURE structure OF FDSx2 IS
   
   SIGNAL T: std_ulogic;
   
BEGIN

   ff1: FDS
   --synthesis translate_off
   generic map (INIT => '1')
   --synthesis translate_on
   PORT MAP(D => D,
            Q => T,
            S => S,
            C => C);

   ff2: FDS
   --synthesis translate_off
   generic map (INIT => '1')
   --synthesis translate_on
   PORT MAP(D => T,
            Q => Q,
            S => S,
            C => C);
            
END structure;
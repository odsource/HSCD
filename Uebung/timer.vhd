LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

ENTITY timer IS
   GENERIC(RSTDEF: std_logic := '0');
   PORT(rst:  IN  std_logic;  -- reset, RSTDEF active
        clk:  IN  std_logic;  -- clock, rising edge active
        irq:  OUT std_logic;  -- interrupt request, high active
        iack: IN  std_logic); -- interrupt acknowledge, high active
END timer;

--
-- Der Timer erzeugt ueber seinen Ausgang irq eine Pulsfolge
-- mit einer Ausgangsfrequenz Fo von 153,6 kHz. Diese Frequenz
-- ergibt sich aus der gewaehlten Baudrate von 9,6 kbps, 
-- multipliziert mit dem 16fachen Oversampling OSR.
--
-- Das Frequenzcontrollwort FCW wird mit folgender Formel berechnet:
-- FCW := 2**K*Fo/Fs mit
-- * Fo ist die Ausgangsfrequenz von 153,6 kHz,
-- * Fs ist die Samplingfrequenz von 50 MHz und
-- * K ist die Laenge des Zaehlers (24 Bit).
--

ARCHITECTURE behaviour OF timer IS
   CONSTANT Fs:   real    := 50.0e6;
   CONSTANT OSR:  real    := 16.0;
   CONSTANT Fo:   real    := 9.6e3*OSR;
   CONSTANT K:    natural := 24;
   CONSTANT FCW:  natural := natural(real(2**K)*Fo/Fs);
   SIGNAL   acc:  std_logic_vector(K DOWNTO 0);
BEGIN

   PROCESS (rst, clk) IS
   BEGIN
      IF rst=RSTDEF THEN
         acc <= (OTHERS => '0');
         irq <= '0';
      ELSIF rising_edge(clk) THEN
         acc <= ('0' & acc(acc'LEFT-1 DOWNTO 0)) + FCW;
         IF acc(acc'LEFT)='1' THEN
            irq <= '1';
         END IF;
         IF iack='1' THEN
            irq <= '0';
         END IF;
      END IF;
   END PROCESS;

END behaviour;
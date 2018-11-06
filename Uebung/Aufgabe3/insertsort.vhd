LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY insertsort IS
   GENERIC(RSTDEF: std_logic := '1');
   PORT(rst:   IN  std_logic;  -- reset, RSTDEF active
        clk:   IN  std_logic;  -- clock, rising edge active
        
        -- interface to PicoBlaze
        rsel:  IN  std_logic_vector(7 DOWNTO 0); -- register select
        din:   IN  std_logic_vector(7 DOWNTO 0); -- data input
        dout:  OUT std_logic_vector(7 DOWNTO 0); -- data output
        ena:   IN  std_logic; -- enable, high active
        wre:   IN  std_logic; -- write strobe, high active

        -- interface to RAM block through port B
        WEB:   OUT std_logic; -- Port B Write Enable Output, high active
        ENB:   OUT std_logic; -- Port B RAM Enable, high active
        ADDRB: OUT std_logic_vector(10 DOWNTO 0); -- Port B 11-bit Address Output
        DIB:   IN  std_logic_vector(7 DOWNTO 0);  -- Port B 8-bit Data Input
        DOB:   OUT std_logic_vector(7 DOWNTO 0)); -- Port B 8-bit Data Output
END insertsort;


ARCHITECTURE behaviour OF insertsort IS

   COMPONENT insertcore
      GENERIC(RSTDEF: std_logic);
      PORT(rst:   IN  std_logic;  -- reset, RSTDEF active
           clk:   IN  std_logic;  -- clock, rising edge active
           
           -- handshake signals
           strt:  IN  std_logic;  -- start bit, high active
           done:  OUT std_logic;  -- done bit, high active
           ptr:   IN  std_logic_vector(10 DOWNTO 0); -- pointer to vector
           len:   IN  std_logic_vector( 7 DOWNTO 0); -- length of vector
           
           WEB:   OUT std_logic; -- Port B Write Enable Output, high active
           ENB:   OUT std_logic; -- Port B RAM Enable, high active
           ADR:   OUT std_logic_vector(10 DOWNTO 0);  -- Port B 11-bit Address Output
           DIB:   IN  std_logic_vector( 7 DOWNTO 0);  -- Port B 8-bit Data Input
           DOB:   OUT std_logic_vector( 7 DOWNTO 0)); -- Port B 8-bit Data Output
   END COMPONENT;

   SIGNAL strt: std_logic; -- Startbit
   SIGNAL done: std_logic;
   SIGNAL ptr:  std_logic_vector(10 DOWNTO 0);
   SIGNAL len:  std_logic_vector( 7 DOWNTO 0);

BEGIN
   
   PROCESS (rst, clk) IS
   BEGIN
      IF rst=RSTDEF THEN
         strt <= '0';
         len  <= (OTHERS => '0');
         ptr  <= (OTHERS => '0');
      ELSIF rising_edge(clk) THEN
         IF ena='1' AND wre='1' THEN
            CASE rsel(1 DOWNTO 0) IS
               WHEN "00"   => strt <= din(0);
               WHEN "01"   => ptr( 7 DOWNTO 0) <= din;
               WHEN "10"   => ptr(10 DOWNTO 8) <= din(2 DOWNTO 0);
               WHEN OTHERS => len <= din;
            END CASE;
         END IF;
      END IF;
   END PROCESS;
   
   WITH rsel(1 DOWNTO 0) SELECT
   dout <= "0000000" & done WHEN "00",
           ptr( 7 DOWNTO 0) WHEN "01",
           "00000" & ptr(10 DOWNTO 8) WHEN "10",
           len              WHEn OTHERS;
   
   u1: insertcore
   GENERIC MAP(RSTDEF => RSTDEF)
   PORT MAP(rst   => rst,
            clk   => clk,  
            strt  => strt,
            done  => done,
            ptr   => ptr,
            len   => len,
            WEB   => WEB,
            ENB   => ENB,
            ADR   => ADDRB,
            DIB   => DIB,
            DOB   => DOB);
   
END behaviour;

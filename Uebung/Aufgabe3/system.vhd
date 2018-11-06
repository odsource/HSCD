LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

ENTITY system IS
   PORT(rst:  IN  std_logic;  -- system reset, high active
        clk:  IN  std_logic;  -- system clock, 50 MHz, rising edge active
        btn0: IN  std_logic;  -- push button, low active
        rxd:  IN  std_logic;  -- receiver signal
        txd:  OUT std_logic;  -- transmitter signal
        evn1: OUT std_logic;  -- event1, interrupt, high active
        evn2: OUT std_logic;  -- event2, RETURNI, high active
        led0: OUT std_logic;  -- led, low active
        led1: OUT std_logic); -- led, low active
END system;

library unisim;
use unisim.vcomponents.all;

ARCHITECTURE structure OF system IS

   CONSTANT RSTDEF: std_ulogic := '1'; -- high active

   COMPONENT FDSx2
      PORT(D : IN  std_ulogic;  -- data input
           Q : OUT std_ulogic;  -- data output
           S : IN  std_ulogic;  -- preset, high active
           C : IN  std_ulogic); -- clock, rising edge active
   END COMPONENT;

   COMPONENT timer
      GENERIC(RSTDEF: std_logic);
      PORT(rst:  IN  std_logic;  -- reset, RSTDEF active
           clk:  IN  std_logic;  -- clock, rising edge active
           irq:  OUT std_logic;  -- interrupt request, high active
           iack: IN  std_logic); -- interrupt acknowledge, high active
   END COMPONENT;

   COMPONENT kcpsm3
       Port (      address : out std_logic_vector(9 downto 0);
               instruction : in  std_logic_vector(17 downto 0);
                   port_id : out std_logic_vector(7 downto 0);
              write_strobe : out std_logic;
                  out_port : out std_logic_vector(7 downto 0);
               read_strobe : out std_logic;
                   in_port : in  std_logic_vector(7 downto 0);
                 interrupt : in  std_logic;
             interrupt_ack : out std_logic;
                     reset : in  std_logic;
                       clk : in  std_logic);
       end COMPONENT;

   COMPONENT programm
      PORT (      address : in std_logic_vector(9 downto 0);
              instruction : out std_logic_vector(17 downto 0);
                      clk : in std_logic);
   END COMPONENT;

   COMPONENT insertsort
      GENERIC(RSTDEF: std_logic);
      PORT(rst:   IN  std_logic;  -- reset, RSTDEF active
           clk:   IN  std_logic;  -- clock, rising edge active
           
           -- interface to PicoBlaze
           rsel:  IN  std_logic_vector(7 DOWNTO 0); -- register address
           din:   IN  std_logic_vector(7 DOWNTO 0); -- data input
           dout:  OUT std_logic_vector(7 DOWNTO 0); -- data output
           ena:   IN  std_logic; -- enable, high active
           wre:   IN  std_logic; -- write enable, high active
      
           -- interface to RAM block through port B
           WEB:   OUT std_logic; -- Port B Write Enable Output, high active
           ENB:   OUT std_logic; -- Port B RAM Enable, high active
           ADDRB: OUT std_logic_vector(10 DOWNTO 0); -- Port B 11-bit Address Output
           DIB:   IN  std_logic_vector(7 DOWNTO 0);  -- Port B 8-bit Data Input
           DOB:   OUT std_logic_vector(7 DOWNTO 0)); -- Port B 8-bit Data Output
   END COMPONENT;

   SIGNAL reset         :  std_logic; -- high active
   SIGNAL sbtn0         :  std_logic;
   SIGNAL srxd          :  std_logic;

   SIGNAL enable        :  std_logic_vector(8 DOWNTO 0);
   SIGNAL led           :  std_logic_vector(1 DOWNTO 0);
   SIGNAL en0           :  std_logic;
   SIGNAL en1           :  std_logic;
   
   SIGNAL address       :  std_logic_vector( 9 downto 0);
   SIGNAL instruction   :  std_logic_vector(17 downto 0);
   SIGNAL port_id       :  std_logic_vector( 7 downto 0);
   SIGNAL write_strobe  :  std_logic; -- high active
   SIGNAL out_port      :  std_logic_vector( 7 downto 0);
   SIGNAL read_strobe   :  std_logic; -- high active
   SIGNAL in_port       :  std_logic_vector( 7 downto 0);
   SIGNAL interrupt     :  std_logic; -- high active
   SIGNAL interrupt_ack :  std_logic; -- high active

   SIGNAL addra         :   std_logic_vector(10 DOWNTO 0);
   SIGNAL dout1         :   std_logic_vector( 7 DOWNTO 0);
   SIGNAL wea           :   std_logic;
   SIGNAL dout2         :   std_logic_vector( 7 DOWNTO 0);

   SIGNAL addrb         :   std_logic_vector(10 DOWNTO 0);
   SIGNAL dib           :   std_logic_vector( 7 DOWNTO 0);
   SIGNAL dob           :   std_logic_vector( 7 DOWNTO 0);
   SIGNAL enb           :   std_logic;
   SIGNAL web           :   std_logic;

BEGIN

-- -----------------------------------------------------------------------------

   evn1 <= interrupt;
   evn2 <= '1' WHEN instruction(17 DOWNTO 14)="1110" ELSE '0';

   -- Resetgenarator und Synchronisation des Resetsignals mit dem System
   sync_rst: FDSx2
   PORT MAP(D => '0',
            Q => reset,
            S => rst,
            C => clk);

-- -----------------------------------------------------------------------------

   -- Synchronisation des Eingangssignals RXD mit dem System
   sync_rxd: FDSx2
   PORT MAP(D => rxd,
            Q => srxd,
            S => reset,
            C => clk);

-- -----------------------------------------------------------------------------

   -- Synchronisation des Eingangssignals BTN0 mit dem System
   sync_btn0: FDSx2
   PORT MAP(D => btn0,
            Q => sbtn0,
            S => reset,
            C => clk);

-- -----------------------------------------------------------------------------

   en1 <= enable(1) AND write_strobe;

   -- Flipflop fuer das serielle Datenausgangssignal TXD
   txd_ff: FDSE
   --synthesis translate_off
   generic map (INIT => '1')
   --synthesis translate_on
   PORT MAP(D   => out_port(0),
            Q   => txd,
            CE  => en1,
            S   => reset,
            C   => clk);

   en0 <= enable(0) AND write_strobe;
   
   -- Flipflop fuer das Steuerungssignals der LED0
   led0_ff: FDSE
   --synthesis translate_off
   generic map (INIT => '1')
   --synthesis translate_on
   PORT MAP(D   => out_port(0),
            Q   => led(0),
            CE  => en0,
            S   => reset,
            C   => clk);

   -- Flipflop fuer das Steuerungssignals der LED1
   led1_ff: FDSE
   --synthesis translate_off
   generic map (INIT => '1')
   --synthesis translate_on
   PORT MAP(D   => out_port(1),
            Q   => led(1),
            CE  => en0,
            S   => reset,
            C   => clk);

   led0 <= led(0);
   led1 <= led(1);

-- -----------------------------------------------------------------------------

   -- Timer
   t1: timer
   GENERIC MAP(RSTDEF => RSTDEF)
   PORT MAP(rst  => reset,
            clk  => clk,
            irq  => interrupt,
            iack => interrupt_ack);

-- -----------------------------------------------------------------------------

   -- Dekoder
   WITH port_id(3 DOWNTO 0) SELECT
   enable <= "000000001" WHEN "0000", -- LED0, LED1
             "000000010" WHEN "0001", -- transmitter bit
             "000000100" WHEN "0010", -- a7..a0 ram address
             "000001000" WHEN "0011", -- a10..a8 ram address
             "000010000" WHEN "0100", -- ram data
             "000100000" WHEN "1000", -- control register
             "000100000" WHEN "1001", -- p7..p0 pointer
             "000100000" WHEN "1010", -- p10..p8 pointer
             "000100000" WHEN "1011", -- length
             "000000000" WHEN OTHERS;

   WITH port_id(3 DOWNTO 0) SELECT
   in_port <= "00000" & sbtn0 & led        WHEN "0000", -- button & leds
              "0000000" & srxd             WHEN "0001", -- receiver bit
              addra(7 DOWNTO 0)            WHEN "0010", -- a7..a0 ram adress
              "00000" & addra(10 DOWNTO 8) WHEN "0011", -- a10..a8 ram address
              dout1                        WHEN "0100", -- ram data
              dout2                        WHEN OTHERS; -- interface to asic

-- -----------------------------------------------------------------------------

   cpu: kcpsm3
   PORT MAP(reset => reset,
              clk => clk,
          address => address,
      instruction => instruction,
          port_id => port_id,
     write_strobe => write_strobe,
         out_port => out_port,
      read_strobe => read_strobe,
          in_port => in_port,
        interrupt => interrupt,
    interrupt_ack => interrupt_ack);

-- -----------------------------------------------------------------------------

   -- programm memory
    rom: programm
    PORT MAP(clk => clk,
         address => address,
     instruction => instruction);

-- -----------------------------------------------------------------------------

   -- address register
   PROCESS(rst, clk) IS
   BEGIN
      IF rst=RSTDEF THEN
         addra <= (OTHERS => '0');
      ELSIF rising_edge(clk) THEN
         IF enable(2)='1' AND write_strobe='1' THEN
            addra(7 DOWNTO 0) <= out_port;
         END IF;
         IF enable(3)='1' AND write_strobe='1' THEN
            addra(10 DOWNTO 8) <= out_port(2 DOWNTO 0);
         END IF;
      END IF;
   END PROCESS;

   wea <= enable(4) AND write_strobe;
   
   -- data memory
   ram: RAMB16_S9_S9
   PORT MAP (
      -- interface to PicoBlaze
      DOA   => dout1,     -- Port A 8-bit Data Output
      DOPA  => open,      -- Port A 1-bit Parity Output
      ADDRA => addra,     -- Port A 11-bit Address Input
      CLKA  => clk,       -- Port A Clock
      DIA   => out_port,  -- Port A 8-bit Data Input
      DIPA  => "0",       -- Port A 1-bit parity Input
      ENA   => '1',       -- Port A RAM Enable Input
      SSRA  => reset,     -- Port A Synchronous Set/Reset Input
      WEA   => wea,       -- Port A Write Enable Input
      
      -- interface to co-processor
      DOB   => DOB,       -- Port B 8-bit Data Output
      DOPB  => open,      -- Port B 1-bit Parity Output
      ADDRB => ADDRB,     -- Port B 11-bit Address Input
      CLKB  => CLK,       -- Port B Clock
      DIB   => DIB,       -- Port B 8-bit Data Input
      DIPB  => "0",       -- Port-B 1-bit parity Input
      ENB   => ENB,       -- Port B RAM Enable Input      
      SSRB  => reset,     -- Port B Synchronous Set/Reset Input
      WEB   => WEB        -- Port B Write Enable Input
      );

-- -----------------------------------------------------------------------------

   asic: insertsort
   GENERIC MAP(RSTDEF => RSTDEF)
   PORT MAP(rst  => rst,
            clk  => clk,
            
            -- interface to PicoBlaze
            rsel  => port_id,
            din   => out_port,
            dout  => dout2,
            ena   => enable(5),
            wre   => write_strobe,
            
            -- interface to RAM block through port B
            WEB   => WEB,
            ENB   => ENB,
            ADDRB => ADDRB,
            DIB   => DOB,
            DOB   => DIB);
           
END structure;
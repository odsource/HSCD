
ENTITY asic_tb IS
   -- empty
END asic_tb;

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;

ARCHITECTURE behaviour OF asic_tb IS
   CONSTANT RSTDEF: std_logic := '0';
   CONSTANT FRQMAX: natural := 50E6;
   CONSTANT tpd: time := 1 sec / FRQMAX;

   COMPONENT asic IS
     PORT(rst:   IN    std_logic;
          clk:   IN    std_logic;
          cs:    IN    std_logic;
          rw:    IN    std_logic;
          int:   OUT   std_logic;
          abus:  IN    std_logic_vector(2 DOWNTO 0);
          dbus:  INOUT std_logic_vector(7 DOWNTO 0));
   END COMPONENT;

   SIGNAL rst:  std_logic := RSTDEF;
   SIGNAL clk:  std_logic := '0';
   SIGNAL hlt:  std_logic := '0';
   
   SIGNAL cs:   std_logic := '1';
   SIGNAL rw:   std_logic := '1';
   SIGNAL int:  std_logic := 'H';
   SIGNAL abus: std_logic_vector(2 DOWNTO 0) := (OTHERS => '0');
   SIGNAL dbus: std_logic_vector(7 DOWNTO 0) := (OTHERS => 'Z');
   
BEGIN

   rst <= RSTDEF, NOT RSTDEF AFTER 5*tpd;
   clk <= NOT clk AFTER tpd/2 WHEN hlt='0' ELSE '0';
   
   int <= 'H'; -- pull up
   
   u1: asic
   PORT MAP(rst   => rst,
            clk   => clk,
            cs    => cs,
            rw    => rw,
            int   => int,
            abus  => abus,
            dbus  => dbus);
          
   test: PROCESS
      VARIABLE x: std_logic_vector(15 DOWNTO 0) := X"6738";
      VARIABLE y: std_logic_vector(15 DOWNTO 0) := X"C434";
      VARIABLE r: std_logic_vector(15 DOWNTO 0);
      VARIABLE s: std_logic_vector( 7 DOWNTO 0);
      
      PROCEDURE write(sel: std_logic_vector(2 DOWNTO 0);
                      arg: std_logic_vector(7 DOWNTO 0)) IS
      BEGIN
         dbus <= arg;
         abus <= sel;
         cs   <= '0';
         rw   <= '0';
         WAIT UNTIL clk'EVENT AND clk='1';
         dbus <= (OTHERS => 'Z');
         cs   <= '1';
         rw   <= '1';
         WAIT UNTIL clk'EVENT AND clk='1';
      END PROCEDURE write;
   
      PROCEDURE read(sel: std_logic_vector(2 DOWNTO 0);
                     arg: OUT std_logic_vector(7 DOWNTO 0)) IS
      BEGIN
         abus <= sel;
         cs   <= '0';
         rw   <= '1';
         WAIT UNTIL clk'EVENT AND clk='1';
         arg  := dbus;
         cs   <= '1';
         rw   <= '1';
         WAIT UNTIL clk'EVENT AND clk='1';
      END PROCEDURE read;
      
   BEGIN
      WAIT UNTIL clk'EVENT AND clk='1' AND rst=NOT RSTDEF;
      write("000",  x(15 DOWNTO 8));
      write("001",  x( 7 DOWNTO 0));
      write("010",  y(15 DOWNTO 8));
      write("011",  y( 7 DOWNTO 0));
      write("100", "00000001");
      s := (OTHERS => '0');
      WHILE s(2)='0' LOOP
         read("100", s);
      END LOOP;
      read("000", r(15 DOWNTO 8));
      read("001", r( 7 DOWNTO 0));
      hlt <= '1';
      WAIT;
   END PROCESS;

END ARCHITECTURE behaviour;

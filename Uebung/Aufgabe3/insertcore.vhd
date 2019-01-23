LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

ENTITY insertcore IS
   GENERIC(RSTDEF: std_logic := '1');
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
END insertcore;

ARCHITECTURE verhalten OF insertcore IS
	-- Zustandsmaschine
		type TState is (S0, S1, S2, S3);
		SIGNAL state, state0: TState;
		
		SIGNAL d, d0:		std_logic;
		SIGNAL swp, swp0:	std_logic;
		SIGNAL flg, flg0:	std_logic;
		SIGNAL i, i0, i1:	std_logic_vector(7 DOWNTO 0);
		SIGNAL j, j0:		std_logic_vector(8 DOWNTO 0);
		SIGNAL m, m0:		std_logic_vector(7 DOWNTO 0);
		SIGNAL y, y0:		std_logic_vector(7 DOWNTO 0);
		SIGNAL tmp, tmp0:	std_logic_vector(7 DOWNTO 0);
		SIGNAL min, min0: std_logic_vector(7 DOWNTO 0);
		SIGNAL ofs:			std_logic_vector(7 DOWNTO 0);
		
		-- WHILE-Schleifenauflösung bedingte Zähler
		-- VARIABLE i: natural range 0 to n-1;
		-- VARIABLE j: natural range 1 to n;
		
		-- VARIABLE i: natural range 0 to n-1;
		-- VARIABLE key: character;
		-- VARIABLE j: integer;
BEGIN

	done 	<= d;
	ADR 	<= ptr + ofs;
	i1 	<= i + 1;
	
	reg: PROCESS(rst, clk) IS
	BEGIN
		IF rst=RSTDEF THEN
			state <= S0;
			i		<= (OTHERS => '0');
			j		<= (OTHERS => '0');
			m		<= (OTHERS => '0');
			y		<= (OTHERS => '0');
			tmo	<= (OTHERS => '0');
			min	<= (OTHERS => '0');
			d		<= '0';
		ELSIF rising_edge(clk) THEN
			state <= state0;
         i     <= i0;
         j     <= j0;
         m     <= m0;
         y     <= y0;
         tmp   <= tmp0;
         min   <= min0;
         d     <= d0;
         flg   <= flg0;
         swp   <= swp0;
      END IF;
   END PROCESS;

	fsm: PROCESS(state, strt, len, i, i1, j, d, m, y, tmp, min, flg, swp, dib) IS
	BEGIN
		state0 	<= state;
		i0 		<= i;
		j0     <= j;
      m0     <= m;
      y0     <= y;
      tmp0   <= tmp;
      min0   <= min;
      d0     <= d;
      flg0   <= flg;
      swp0   <= swp;
      
      ofs    <= i;   -- default (OTHERS => '0');
      WEB    <= '0';
      ENB    <= '0';
      DOB    <= tmp; -- default (OTHERS => '0');
		CASE state is
			-- Initialisierungszustand
			when S0 =>
				IF strt = '1' then
					d0			<= '0';
					i0			<= (OTHERS => '0');
					m0			<= len - 1;
					state0	<=	S1;
				END IF;
			
			-- Ausführungszustand
			when S1 =>
				key := a(i);
				j := i+1;
				state := S2;
				
			-- Ausführungszustand 2
			when S2 =>
				IF a(j) <= key THEN
					state := S3;
				END IF;
				a(j+1) := a(j);
				j := j + 1;
				
			-- Ausführungszustand 3
			when S3 =>
				a(j+1) := key;
				i := i + 1;
				IF i <= n-2 then
					done <= '1';
					state := S0;
				END IF;
		END CASE;
				
				
				
		-- WHILE-Schleifenrealisierung
		-- i := 0;
		-- while i <= n-2 loop
		-- 	key := a(i);
		-- 	j := i+1;
		-- 	WHILE j <= n-1 loop
		-- 		IF a(j) <= key THEN
		-- 			EXIT;
		-- 		END IF;
		-- 		a(j+1) := a(j);
		-- 		j := j + 1;
		-- 	END LOOP;
		-- 	a(j+1) := key;
		-- 	i := i + 1;
		-- END LOOP;
		-- END WHILE-Schleifenrealisierung
		
	END PROCESS;
END verhalten;

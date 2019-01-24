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
		type TState is (S0, S1, S2, S3, S5);
		SIGNAL state, state0: TState;
		
		SIGNAL d, d0:		std_logic;
		SIGNAL i, i0, i1:	std_logic_vector(10 DOWNTO 0);
		SIGNAL j, j0, j1: std_logic_vector(10 DOWNTO 0);
		SIGNAL m, m0:		std_logic_vector(7 DOWNTO 0);
		SIGNAL tmp, tmp0:	std_logic_vector(7 DOWNTO 0);
		SIGNAL ofs:			std_logic_vector(10 DOWNTO 0);

BEGIN

	done 	<= d;
	ADR 	<= ptr + ofs;
	j1    <= j + 1;
	i1		<= i + 1;
	
	reg: PROCESS(rst, clk) IS
	BEGIN
		IF rst=RSTDEF THEN
			state <= S0;
			i		<= (OTHERS => '0');
			j		<= (OTHERS => '0');
			m		<= (OTHERS => '0');
			tmp	<= (OTHERS => '0');
			d		<= '0';
		ELSIF rising_edge(clk) THEN
			state <= state0;
			i     <= i0;
			j     <= j0;
			m     <= m0;
			tmp   <= tmp0;
			d     <= d0;
		END IF;
   	END PROCESS;

	fsm: PROCESS(state, strt, len, i, i1, j, j1, d, m, tmp, dib) IS
	BEGIN
		state0 	<= state;
		i0 		<= i;
		j0     <= j;
		m0     <= m;
		tmp0   <= tmp;
		d0     <= d;

		ofs    <= i;   -- default (OTHERS => '0');
		DOB	 <= (OTHERS => '0');
		WEB    <= '0';
		ENB    <= '1';
		CASE state IS
		-- Initialisierungszustand
			WHEN S0 =>
				IF strt='1' THEN
					d0			<= '0';
					i0			<= "00000000001";
					m0			<= len - 1;
					state0	<=	S1;
					ofs      <= "00000000001";
					j0 		<= (OTHERS => '0');
				END IF;
			
			-- Ausfuehrungszustand
			WHEN S1 =>
				IF i > m THEN
					d0 <= '1';
					state0 <= S0;
				ELSE
					tmp0 <= DIB;    -- key <= a(i)
					ofs <= j;
					state0 <= S2;
				END IF;
				
			-- Ausfuehrungszustand 2
			WHEN S2 =>
				WEB <= '1';
				ofs <= j1;
				IF DIB <= tmp THEN
					DOB <= tmp;    -- a(j+1) <= key
					i0 <= i1;
					state0 <= S5;
				ELSE
					DOB <= DIB;   -- a(j+1) := a(j)
					j0 <= j - 1;
					state0 <= S3;
				END IF;

			-- Prüfe ob j out of bounds
			WHEN S3 =>
				IF j0 = "11111111111" THEN
					ofs <= j1;
					WEB <= '1';
					DOB <= tmp;    -- a(j+1) <= key
					i0 <= i1;
					state0 <= S5;
				ELSE
					ofs <= j;
					state0 <= S2;
				END IF;

			-- Ausfuehrungszustand 3
			--WHEN S4 =>
			--	ofs <= j1;
			--	WEB <= '1';
			--	DOB <= tmp;    -- a(j+1) <= key
			--	i0 <= i + 1;
			--	state0 <= S5;
				
			WHEN S5 =>
				ofs <= i;
				j0 <= i - 1;
				state0 <= S1;
				
		END CASE;
	END PROCESS;
END verhalten;
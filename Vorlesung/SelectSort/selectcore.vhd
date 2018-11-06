LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_arith.ALL;
USE ieee.std_logic_unsigned.ALL;

ENTITY selectcore IS
   GENERIC(RSTDEF: std_logic := '1');
   PORT(rst:  IN  std_logic;  -- reset, RSTDEF active
        clk:  IN  std_logic;  -- clock, rising edge active
        
        -- handshake signals
        strt: IN  std_logic;  -- start bit, high active
        done: OUT std_logic;  -- done bit, high active
        ptr:  IN  std_logic_vector(10 DOWNTO 0); -- pointer to vector
        len:  IN  std_logic_vector( 7 DOWNTO 0); -- length of vector
        
        WEB:  OUT std_logic; -- Port B Write Enable Output, high active
        ENB:  OUT std_logic; -- Port B RAM Enable, high active
        ADR:  OUT std_logic_vector(10 DOWNTO 0);  -- Port B 11-bit Address Output
        DIB:  IN  std_logic_vector( 7 DOWNTO 0);  -- Port B 8-bit Data Input
        DOB:  OUT std_logic_vector( 7 DOWNTO 0)); -- Port B 8-bit Data Output
END selectcore;

-- PROCEDURE sort9(a: INOUT string; n: positive) IS
--    TYPE TState IS (S0, S1, S2, S3, S4);
--    VARIABLE x:   character; -- Ausgangsregister des RAM-Blocks
--    VARIABLE y:   character;
--    VARIABLE tmp: character;
--    VARIABLE swp: boolean;
--    VARIABLE flg: boolean;
--    VARIABLE min: natural RANGE 0 TO n-1;
--    VARIABLE i:   natural RANGE 0 TO n-1;
--    VARIABLE j:   natural RANGE 0 TO n;
--    VARIABLE m:   natural RANGE 0 TO n-1;
--    VARIABLE state: TState := S0;
-- BEGIN
--    LOOP
--       CASE state IS
--          WHEN S0 =>
--            i     := 0;
--            m     := n - 1;
--            state := S1;
--          WHEN S1 =>
--             IF i < m THEN
--                min   := i;
--                x     := a(i);
--                flg   := false;
--                swp   := false;
--                j     := i + 1;
--                state := S2;
--             ELSE
--                RETURN;
--             END IF;
--          WHEN S2 =>
--             IF NOT flg THEN
--                flg := true;
--                y   := x;
--                tmp := x;
--             END IF;
--             IF j <= m THEN
--                x := a(j);
--                state := S3;
--             ELSE
--                IF swp THEN
--                   a(min) := y;
--                   state  := S4;
--                ELSE
--                   i     := i + 1;
--                   state := S1;
--                END IF;
--             END IF;
--          WHEN S3 =>
--             IF x < tmp THEN
--                swp := true;
--                min := j;
--                tmp := x;
--             END IF;
--             j := j + 1;
--             state := S2;
--          WHEN S4 =>
--             a(i)   := tmp;
--             i      := i + 1;
--             state  := S1;
--       END CASE;
--    END LOOP;
-- END PROCEDURE;
      
ARCHITECTURE verhalten OF selectcore IS
   TYPE TState IS (S0, S1, S2, S3, S4);
   SIGNAL state, state0: TState;
   
   SIGNAL swp, swp0: std_logic;
   SIGNAL flg, flg0: std_logic;
   SIGNAL d, d0:     std_logic;
   SIGNAL i, i0, i1: std_logic_vector(7 DOWNTO 0);
   SIGNAL j, j0:     std_logic_vector(8 DOWNTO 0);
   SIGNAL m, m0:     std_logic_vector(7 DOWNTO 0);
   SIGNAL y, y0:     std_logic_vector(7 DOWNTO 0);
   SIGNAL tmp, tmp0: std_logic_vector(7 DOWNTO 0);
   SIGNAL min, min0: std_logic_vector(7 DOWNTO 0);
   SIGNAL ofs:       std_logic_vector(7 DOWNTO 0);
   
BEGIN
   
   done <= d;
   ADR  <= ptr + ofs;
   i1   <= i + 1;
   
   reg: PROCESS (rst, clk) IS
   BEGIN
      IF rst=RSTDEF THEN
         state <= S0;
         i     <= (OTHERS => '0');
         j     <= (OTHERS => '0');
         m     <= (OTHERS => '0');
         y     <= (OTHERS => '0');
         tmp   <= (OTHERS => '0');
         min   <= (OTHERS => '0');
         d     <= '0';
         flg   <= '0';
         swp   <= '0';
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

   fsm: PROCESS (state, strt, len, i, i1, j, d, m, y, tmp, min, flg, swp, dib) IS
   BEGIN
      state0 <= state;
      i0     <= i;
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
      CASE state IS
         WHEN S0 =>
            IF strt='1' THEN
               d0     <= '0';
               i0     <= (OTHERS => '0');
               m0     <= len - 1;
               state0 <= S1;
            END IF;
         WHEN S1 =>
            IF i<m THEN
               -- ofs    <= i;
               ENB    <= '1';
               min0   <= i;
               flg0   <= '0';
               swp0   <= '0';
               j0     <= '0' & i1;
               state0 <= S2;
            ELSE
               d0     <= '1';
               state0 <= S0;
            END IF;
         WHEN S2 =>
            IF flg='0' THEN
               flg0 <= '1';
               y0   <= DIB;
               tmp0 <= DIB;
            END IF;
            IF j<=m THEN
               ofs    <= j(ofs'RANGE);
               ENB    <= '1';               
               state0 <= S3;
            ELSE
               IF swp='1' THEN
                  ofs    <= min;
                  DOB    <= y;
                  ENB    <= '1';
                  WEB    <= '1';      
                  state0 <= S4;
               ELSE
                  i0     <= i1;
                  state0 <= S1;
               END IF;
            END IF;
         WHEN S3 =>
            IF DIB<tmp THEN
               swp0   <= '1';
               min0   <= j(min0'RANGE);
               tmp0   <= DIB;              
            END IF;
            j0     <= j + 1;
            state0 <= S2;
         WHEN S4 =>
            -- ofs    <= i;
            -- DOB    <= tmp;
            ENB    <= '1';
            WEB    <= '1';
            i0     <= i1;
            state0 <= S1;
       END CASE;
   
   END PROCESS;

END verhalten;

ENTITY selectionsort IS
   -- empty
END selectionsort;

ARCHITECTURE verhalten OF selectionsort IS
  -- empty
BEGIN

   PROCESS
      CONSTANT N: natural := 20;
      TYPE string IS array(natural RANGE <>) OF character;
      CONSTANT g: string(0 TO N-1) := "1449BEKMMPQTZceffrvz";

      VARIABLE a: string(0 TO N-1) := "P91fQeZB4KvTMcrEfzM4";
      VARIABLE b: string(0 TO N-1) := "1449BEKMMPQTZceffrvz";
      VARIABLE c: string(0 TO N-1) := "zvrffecZTQPMMKEB9441";

      PROCEDURE sort1(a: INOUT string; n: positive) IS
         VARIABLE tmp: character;
         VARIABLE min: natural;
      BEGIN
         FOR i IN 0 TO n-2 LOOP
            min := i;
            FOR j IN i+1 TO n-1 LOOP
               IF a(j) < a(min) THEN
                  min := j;
               END IF;
            END LOOP;
            tmp    := a(min);
            a(min) := a(i);
            a(i)   := tmp;
         END LOOP;
      END PROCEDURE;

      -- Hinweis:
      -- min enthaelt den Index des kleinsten Elementes im zu sortierenden Bereich
      -- tmp enthaelt den Wert  des kleinsten Elementes im zu sortierenden Bereich
      
      -- Anzahl der teuren Operationen (hier Speicherzugriffe) reduzieren
      -- Speicherzugriffe sind i.d.R. nicht parallelisierbar, dauern mehrere Takte
      -- ggf. neue Hilfsvariablen/Steuervariablen hinzufuegen
      -- Schleife-invariante Ausdruecke finden
      -- 1) die Hilfsvariable swp verhindert, dass der Austausch der
      --    Elemente im Speicher auch dann stattfindet, wenn beide elemente
      --    gleich gross sind.
      -- 2) die Auswertung a(min) in der IF-Abfrage wird durch eine
      --    einfache Registerzuweisung erstezt, denn in a(j) steht
      --    der kleinere Wert, und dieser ist bereits in der Variable x
      --    gespeichert
      PROCEDURE sort2(a: INOUT string; n: positive) IS
         VARIABLE x, y: character;
         VARIABLE tmp:  character;
         VARIABLE min:  natural;
         VARIABLE swp:  boolean;
      BEGIN
         FOR i IN 0 TO n-2 LOOP
            min := i;
            y   := a(i);
            tmp := y;
            swp := false;
            FOR j IN i+1 TO n-1 LOOP
               x := a(j);
               IF x < tmp THEN
                  swp := true;
                  min := j;
                  tmp := x;
               END IF;
            END LOOP;
            IF swp THEN
               a(min) := y;
               a(i)   := tmp;
            END IF;
         END LOOP;
      END PROCEDURE;


      -- FOR-Schleifen durch WHILE-Schleifen ersetzen
      -- explizite Zaehler einfuehren, Wertebereiche beruecksichtigen
      --
      -- FOR i IN 0 TO n-2 LOOP
      --    ...
      -- END LOOP;
      --
      -- i := 0;
      -- WHILE i <= n-2 LOOP
      --   ...
      --   i := i + 1;
      -- END LOOP;
      --
      --
      PROCEDURE sort3(a: INOUT string; n: positive) IS
         VARIABLE x, y: character;
         VARIABLE tmp:  character;
         VARIABLE swp:  boolean;
         VARIABLE min:  natural RANGE 0 TO n-1;
         VARIABLE i:    natural RANGE 0 TO n-1;
         VARIABLE j:    natural RANGE 1 TO n;
      BEGIN
         i := 0;
         WHILE i <= n-2 LOOP
            min := i;
            y   := a(i);
            tmp := y;
            swp := false;
            j   := i+1;
            WHILE j <= n-1 LOOP
               x := a(j);
               IF x < tmp THEN
                  swp := true;
                  min := j;
                  tmp := x;
               END IF;
               j := j + 1;
            END LOOP;
            IF swp THEN
               a(min) := y;
               a(i)   := tmp;
            END IF;
            i := i + 1;
         END LOOP;
      END PROCEDURE;

      -- WHILE-Schleifen durch Zustandsmaschinen ersetzen
      --
      -- i := 0;
      -- WHILE i <= n-2 LOOP
      --   ...
      --   i := i + 1;
      -- END LOOP;
      --
      -- CASE state IS
      --    WHEN S0 =>
      --       i     := 0;
      --       state := S1;
      --    WHEN S1 =>
      --       IF i <= n-2 THEN
      --          ...
      --          i := i + 1;
      --          state := S1;
      --       ELSE
      --          state := S2;
      --       END IF;
      --    WHEN S2 =>
      -- END CASE;
      --
      PROCEDURE sort4(a: INOUT string; n: positive) IS
         TYPE TState IS (S0, S1, S2);
         VARIABLE x, y: character;
         VARIABLE tmp:  character;
         VARIABLE swp:  boolean;
         VARIABLE min:  natural RANGE 0 TO n-1;
         VARIABLE i:    natural RANGE 0 TO n-1;
         VARIABLE j:    natural RANGE 1 TO n;
         VARIABLE state: TState := S0;
      BEGIN
         LOOP
            CASE state IS
               WHEN S0 =>
                 i     := 0;
                 state := S1;
               WHEN S1 =>
                  IF i <= n-2 THEN
                     min   := i;
                     y     := a(i);
                     tmp   := y;
                     swp   := false;
                     j     := i+1;
                     state := S2;
                  ELSE
                     RETURN;
                  END IF;
               WHEN S2 =>
                  IF j <= n-1 THEN
                     x := a(j);
                     IF x < tmp THEN
                        swp := true;
                        min := j;
                        tmp := x;
                     END IF;
                     j := j + 1;
                     state := S2;
                  ELSE
                     IF swp THEN
                        a(min) := y;
                        a(i)   := tmp;
                     END IF;
                     i := i + 1;
                     state := S1;
                  END IF;
            END CASE;
         END LOOP;
      END PROCEDURE;

      -- Gemeinsame Ausdruecke beruecksichtigen, ggf. Hilfsvariablen einfuehren
      -- m := n - 1;
      -- aus i <= n-2 wird i < n-1 und schliesslich i < m
      --
      PROCEDURE sort5(a: INOUT string; n: positive) IS
         TYPE TState IS (S0, S1, S2);
         VARIABLE x, y: character;
         VARIABLE tmp:  character;
         VARIABLE swp:  boolean;
         VARIABLE min:  natural RANGE 0 TO n-1;
         VARIABLE i:    natural RANGE 0 TO n-1;
         VARIABLE j:    natural RANGE 1 TO n;
         VARIABLE m:    natural RANGE 0 TO n-1;
         VARIABLE state: TState := S0;
      BEGIN
         LOOP
            CASE state IS
               WHEN S0 =>
                 i     := 0;
                 m     := n - 1;
                 state := S1;
               WHEN S1 =>
                  IF i < m THEN
                     min   := i;
                     y     := a(i);
                     tmp   := y;
                     swp   := false;
                     j     := i+1;
                     state := S2;
                  ELSE
                     RETURN;
                  END IF;
               WHEN S2 =>
                  IF j <= m THEN
                     x := a(j);
                     IF x < tmp THEN
                        swp := true;
                        min := j;
                        tmp := x;
                     END IF;
                     j := j + 1;
                     state := S2;
                  ELSE
                     IF swp THEN
                        a(min) := y;
                        a(i)   := tmp;
                     END IF;
                     i := i + 1;
                     state := S1;
                  END IF;
            END CASE;
         END LOOP;
      END PROCEDURE;

      -- Lese- und Schreibzugriffe auf RAM-Block sind synchron
      -- und RAM-Block hat ein Ausgangsregister (Pipeline-Effekt),
      -- was beruecksichtigt werden muss
      -- das bedeutet, dass beispielsweise folgende Zuweisung x := a(j)
      -- in zwei Takten ablaufen muss.
      -- im 1. Takt wird der Inhalt der adressierten Speicherzelle a(j) ins
      -- Ausgangsregister des RAM-Blocks abgelegt, und erst im 2. Takt wird
      -- das Datum aus dem Ausgangsregister ins Zielregister (in die Zielvariable) x
      -- uebernommen
      --
      -- die folgende Folge von Operationen kann somit nicht in einem Zustand
      -- ausgefuehret werden
      -- x := a(j);
      -- IF x < y THEN
      -- Hier muss ein Zustand dazwischen plaziert werden.
      PROCEDURE sort6(a: INOUT string; n: positive) IS
         TYPE TState IS (S0, S1, S2, S3);
         VARIABLE x, y: character;
         VARIABLE tmp:  character;
         VARIABLE swp:  boolean;
         VARIABLE min:  natural RANGE 0 TO n-1;
         VARIABLE i:    natural RANGE 0 TO n-1;
         VARIABLE j:    natural RANGE 1 TO n;
         VARIABLE m:    natural RANGE 0 TO n-1;
         VARIABLE state: TState := S0;
      BEGIN
         LOOP
            CASE state IS
               WHEN S0 =>
                 i     := 0;
                 m     := n - 1;
                 state := S1;
               WHEN S1 =>
                  IF i < m THEN
                     min   := i;
                     y     := a(i);
                     tmp   := y;
                     swp   := false;
                     j     := i+1;
                     state := S2;
                  ELSE
                     RETURN;
                  END IF;
               WHEN S2 =>
                  IF j <= m THEN
                     x := a(j);
                     state := S3;
                  ELSE
                     IF swp THEN
                        a(min) := y;
                        a(i)   := tmp;
                     END IF;
                     i := i + 1;
                     state := S1;
                  END IF;
               WHEN S3 =>
                  IF x < tmp THEN
                     swp := true;
                     min := j;
                     tmp := x;
                  END IF;
                  j := j + 1;
                  state := S2;
            END CASE;
         END LOOP;
      END PROCEDURE;

      -- Hinweis: nach dem Zugriff auf den RAM-Block steht das Datum zuerst
      -- im Ausgangsregister des RAM-Blocks, nicht in der Zielvariable, die sich
      -- aus einer Zuweisung ergibt
      -- wenn wir nun annehmen, dass mit x das Ausgangsregister der RAM-Blocks
      -- bezeichnet wird, dann ergeben sich folgende Aenderungen in der Notation
      -- auf die (Hilfs-)Variable z kann ganz verzichtet werden, denn sie hat
      -- eine sehr eingeschraenkte, nur lokale Wirkung
      -- die Zuweisung y := a(i) muss in x := a(i) und y := x aufgeteilt werden
      PROCEDURE sort7(a: INOUT string; n: positive) IS
         TYPE TState IS (S0, S1, S2, S3);
         VARIABLE x:   character; -- Ausgangsregister des RAM-Blocks
         VARIABLE y:   character;
         VARIABLE tmp: character;
         VARIABLE swp: boolean;
         VARIABLE min: natural RANGE 0 TO n-1;
         VARIABLE i:   natural RANGE 0 TO n-1;
         VARIABLE j:   natural RANGE 1 TO n;
         VARIABLE m:   natural RANGE 0 TO n-1;
         VARIABLE state: TState := S0;
      BEGIN
         LOOP
            CASE state IS
               WHEN S0 =>
                 i     := 0;
                 m     := n - 1;
                 state := S1;
               WHEN S1 =>
                  IF i < m THEN
                     min   := i;
                     x     := a(i);
                     y     := x;
                     tmp   := x;
                     swp   := false;
                     j     := i+1;
                     state := S2;
                  ELSE
                     RETURN;
                  END IF;
               WHEN S2 =>
                  IF j <= m THEN
                     x := a(j);
                     state := S3;
                  ELSE
                     IF swp THEN
                        a(min) := y;
                        a(i)   := tmp;
                     END IF;
                     i := i + 1;
                     state := S1;
                  END IF;
               WHEN S3 =>
                  IF x < tmp THEN
                     swp := true;
                     min := j;
                     tmp := x;
                  END IF;
                  j := j + 1;
                  state := S2;
            END CASE;
         END LOOP;
      END PROCEDURE;

      -- Zwischen den Operationen  x := a(i) und y := x muss ein Takt Pause dazwischen liegen.
      -- sie duerfen nicht in demselben Zustand stattfinden. Der Folgezustand ist hier S2.
      -- Man koennte also die Operation y := x in den Zustand S2 verschieben.
      -- Das ist prinzipiell moeglich, denn im S2 wird der Wert y (noch) nicht gebraucht.
      -- Allerdings wird S2 auch vom Zustand S3 aus erreicht (eine Schleife),
      -- was dazu fueht, dass die Zuweisung y := x nicht immer stattfinden darf.
      -- Die einfachste Methode, dass zu verhindern, ist ein Sperrflag, das gesetzt wird,
      -- sobald diese Zuweisung einmalig ausgefhrt wird.
      PROCEDURE sort8(a: INOUT string; n: positive) IS
         TYPE TState IS (S0, S1, S2, S3);
         VARIABLE x:   character; -- Ausgangsregister des RAM-Blocks
         VARIABLE y:   character;
         VARIABLE tmp: character;
         VARIABLE swp: boolean;
         VARIABLE flg: boolean;
         VARIABLE min: natural RANGE 0 TO n-1;
         VARIABLE i:   natural RANGE 0 TO n-1;
         VARIABLE j:   natural RANGE 1 TO n;
         VARIABLE m:   natural RANGE 0 TO n-1;
         VARIABLE state: TState := S0;
      BEGIN
         LOOP
            CASE state IS
               WHEN S0 =>
                 i     := 0;
                 m     := n - 1;
                 state := S1;
               WHEN S1 =>
                  IF i < m THEN
                     min   := i;
                     x     := a(i);
                     flg   := false;
                     swp   := false;
                     j     := i+1;
                     state := S2;
                  ELSE
                     RETURN;
                  END IF;
               WHEN S2 =>
                  IF NOT flg THEN
                     flg := true;
                     y   := x;
                     tmp := x;
                  END IF;
                  IF j <= m THEN
                     x := a(j);
                     state := S3;
                  ELSE
                     IF swp THEN
                        a(min) := y;
                        a(i)   := tmp;
                     END IF;
                     i := i + 1;
                     state := S1;
                  END IF;
               WHEN S3 =>
                  IF x < tmp THEN
                     swp := true;
                     min := j;
                     tmp := x;
                  END IF;
                  j := j + 1;
                  state := S2;
            END CASE;
         END LOOP;
      END PROCEDURE;



      -- Fortsetzung: Pipeline-Register beim Zugriff auf RAM-Block beruecksichtigen
      -- die Befehlsfolge
      --    a(i)   := y;
      --    a(min) := x;
      -- muss durch zwei Zustaende aufgeloest werden
      -- Das besondere an dieser Folge ist, dass sie bedingt ausgefuehrt wird,
      -- und dass danach noch die Zuweisung i := i + 1 ausgefuehrt wird.

      -- Kann die erste Zuweisung z := a(i) frueher ausgefuehrt werden?
      -- wenn ja, findet sich ein Zustand, in dem das moeglich ist, also
      -- ohne Speicherzugriffe?
      -- Analyse von sort6
      -- z ist eine Hilfsvariable, die ausschliesslich in der Swap-Sequenz verwendet wird,
      -- hat also eine stark eingeschraenkte, nur lokale Wirkung
      -- wir erreichen den Zustand S2 entweder von S1 oder von S3.
      -- In S1 ist swp noch false, deshalb wird die Swap-Sequenz nie ausgefuehrt.
      -- In S3 kann swp auf true gesetzt werden, und die Swap-Sequenz kann ausgefuehrte werden.
      -- In S3 findet auch kein Speicherzugriff statt, somit waere S3 geeignet,
      -- die Operation z := a(i) aufzunehmen.
      -- Problem: Pipeline-Effekt: nach dem Lesezugriff steht das Datum nicht in
      -- der Variable z sondern im Ausgangsregister des RAM-Blocks


      PROCEDURE sort9(a: INOUT string; n: positive) IS
         TYPE TState IS (S0, S1, S2, S3, S4);
         VARIABLE x:   character; -- Ausgangsregister des RAM-Blocks
         VARIABLE y:   character;
         VARIABLE tmp: character;
         VARIABLE swp: boolean;
         VARIABLE flg: boolean;
         VARIABLE min: natural RANGE 0 TO n-1;
         VARIABLE i:   natural RANGE 0 TO n-1;
         VARIABLE j:   natural RANGE 1 TO n;
         VARIABLE m:   natural RANGE 0 TO n-1;
         VARIABLE state: TState := S0;
      BEGIN
         LOOP
            CASE state IS
               WHEN S0 =>
                 i     := 0;
                 m     := n - 1;
                 state := S1;
               WHEN S1 =>
                  IF i < m THEN
                     min   := i;
                     x     := a(i);
                     flg   := false;
                     swp   := false;
                     j     := i + 1;
                     state := S2;
                  ELSE
                     RETURN;
                  END IF;
               WHEN S2 =>
                  IF NOT flg THEN
                     flg := true;
                     y   := x;
                     tmp := x;
                  END IF;
                  IF j <= m THEN
                     x := a(j);
                     state := S3;
                  ELSE
                     IF swp THEN
                        a(min) := y;
                        state  := S4;
                     ELSE
                        i     := i + 1;
                        state := S1;
                     END IF;
                  END IF;
               WHEN S3 =>
                  IF x < tmp THEN
                     swp := true;
                     min := j;
                     tmp := x;
                  END IF;
                  j := j + 1;
                  state := S2;
               WHEN S4 =>
                  a(i)   := tmp;
                  i      := i + 1;
                  state  := S1;
            END CASE;
         END LOOP;
      END PROCEDURE;


   BEGIN
      sort9(a, n);
      ASSERT a=g SEVERITY error;
      sort9(b, n);
      ASSERT b=g SEVERITY error;
      sort9(c, n);
      ASSERT c=g SEVERITY error;
      WAIT;
   END PROCESS;

END verhalten;
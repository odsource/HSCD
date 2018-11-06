
ENTITY insertionsort IS
   -- empty
END insertionsort;

ARCHITECTURE verhalten OF insertionsort IS
   TYPE string IS array(natural RANGE <>) OF character;

BEGIN

   PROCESS
      CONSTANT N: natural := 20;
      VARIABLE a: string(0 TO N-1) := "P91fQeZB4KvTMcrEfzM4";
      VARIABLE b: string(0 TO N-1) := "1449BEKMMPQTZceffrvz";
      VARIABLE c: string(0 TO N-1) := "zvrffecZTQPMMKEB9441";

      PROCEDURE sort(a: INOUT string; n: positive) IS
         VARIABLE key: character;
         VARIABLE j: integer;
      BEGIN
         FOR i IN 1 TO n-1 LOOP
            key := a(i);
            j := i-1;
            WHILE j >= 0 LOOP
               IF a(j) <= key THEN
                  EXIT;
               END IF;
               a(j+1) := a(j);
               j := j - 1;
            END LOOP;
            a(j+1) := key;
         END LOOP;
      END PROCEDURE;

   BEGIN
      sort(a, n);
      sort(b, n);
      sort(c, n);
      WAIT;
   END PROCESS;

END verhalten;
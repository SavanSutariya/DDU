#include <stdio.h>
 void foo ()
 {
 return 1;
 }
 void main()
 {
 int x = 0;
 x = foo (); // Void 
 printf ("%d", x);
 }
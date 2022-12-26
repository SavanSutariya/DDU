#include<stdio.h>
#include<string.h>
void main ()
{ 
 char p [40]; 
 char s [40] = "Students"; 
 int length = strlen(s); 
 int i; 
 for (i = 0; i < length; i++) 
 p[i] = s [length - i]; 
 printf ("\n%s",p); //printf ("\n%s", &p[1]); 
 //Blank output
 }
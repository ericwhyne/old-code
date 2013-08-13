/*
* Eric Whyne 2000
* A simple example of an overflow exploit.
* License: Do whatever you want with this code.
*/

#include <stdlib.h>
#include <stdio.h>
main()
{
char command[80]="date";
char name[20];

printf("Please enter your name: ");
gets(name);
printf("Hello, %s, the current date and time is: ",name);
system(command);
printf("\n");
}


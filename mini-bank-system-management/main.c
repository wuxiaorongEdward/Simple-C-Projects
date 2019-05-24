#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"menu.h"
#include"bank.h"

int main()
{
     char pass[7], password[7] = "edward";
     int i;

     printf("Enter your password : ");
     scanf("%s", pass); 
     if (strcmp(pass, password) == 0) {
           printf("Login successfully\n");
	   for (i = 0; i < 6; i++) {
	         fordelay(10000000);
		 printf(".\t");
	   } 
	   printf("\n");
	   menu();
     }
     else {
         printf("Invalid password\n");
     }

     return 0;
}

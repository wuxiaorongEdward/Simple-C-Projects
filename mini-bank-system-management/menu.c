#include"menu.h"
#include"bank.h"
#include<stdio.h>

void close(void) 
{
	system("clear");
        printf("\n\n\nthe mini banking management system is developed by team c\n\n\n");
}

void menu(void)
{
     system("clear");
     int choice;

     printf("\t\t\tCUSTOMER ACCOUNT BANKING MANAGE SYSTEM\t\t\t");
     printf("\n\n\t\t\t\tWELCOME TO THE MINI MENU\n\n");
     printf("\n\t 1. create a new account");
     printf("\n\t 2. update the information of an existing account");
     printf("\n\t 3. for transcations");
     printf("\n\t 4. check the details of existing account");
     printf("\n\t 5. removing existing account");
     printf("\n\t 6. view costomer's list");
     printf("\n\t 7. Exit");

     printf("\n\n\n Enter your choice : ");
     scanf("%d", &choice);

     switch (choice) {
           case 1: new_acc();
		   break;
           case 2: edit();
		   break;
	   case 3: transact();
		   break;
           case 4: see();
		   break;
           case 5: erase();
		   break;
           case 6: view_list();
		   break;
           case 7: close();
		   break;
     }
}

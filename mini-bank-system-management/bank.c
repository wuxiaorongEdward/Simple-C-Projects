#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bank.h"
#include"menu.h"


Info add, upd, check, rem, transaction;
int main_exit;

float interest(float t, float amount, int rate)
{
      float SI;
      SI = (rate * t * amount) / 100.0;
      return SI;
}

void fordelay(int j)
{
       int i, k;
       for (i = 0; i < j; i++)
	       k = i;
}

void new_acc()
{
       int choice;
       FILE *f;

       f = fopen("record.dat", "a+");

account_no:
       system("clear");
       printf("\t\t\t ADD RECORD");
       printf("\n\n\nEnter today's date (mm/dd/yyyy):");
       scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
       printf("Enter account number :");
       scanf("%d", &check.acc_no);
       while (fscanf(f, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", \
			       &add.acc_no, add.name, &add.dob.month, &add.dob.day, \
			       &add.dob.year, &add.age, add.address, add.citizenship, \
			       &add.phone, add.acc_type, &add.amt, &add.deposit.month, \
			       &add.deposit.day, &add.deposit.year) != EOF) {
             if (check.acc_no == add.acc_no) {
	           printf("Account no. Already in use\n");
		   fordelay(100000000);
		   goto account_no;
	     }
       }
       add.acc_no = check.acc_no;
       printf("\nEnter the name:");
       scanf("%s",add.name);
       printf("\nEnter the date of birth(mm/dd/yyyy):");
       scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
       printf("\nEnter the age:");
       scanf("%d",&add.age);
       printf("\nEnter the address:");
       scanf("%s",add.address);
       printf("\nEnter the citizenship number:");
       scanf("%s",add.citizenship);
       printf("\nEnter the phone number: ");
       scanf("%lf",&add.phone);
       printf("\nEnter the amount to deposit:$");
       scanf("%f",&add.amt);
       printf("\nType of account:\n\t#saving\n\t#current\n\t#fixed1(for 1 year)\n\t#fixed2(for 2 years)\n\t#fixed3(for 3 years)\n\n\tEnter your choice:");
       scanf("%s",add.acc_type);

       fprintf(f,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",\
		       add.acc_no,add.name,add.dob.month,add.dob.day,\
		       add.dob.year,add.age,add.address,add.citizenship,\
		       add.phone,add.acc_type,add.amt,add.deposit.month,\
		       add.deposit.day,add.deposit.year); 
       fclose(f);

       printf("Create a new account successfully\n\n");
add_invalid:
       printf("Enter 1 go to the main menu and 0 to exit :");
       scanf("%d", &main_exit);
       system("clear");
       if (main_exit == 1) {
              menu();
       }
       else if (main_exit == 0) {
              close();
       }
       else {
             printf("Invalid Input\n");
	     goto add_invalid;
       }
}


void view_list(void) 
{
       FILE * view;
       view = fopen("record.dat", "r");

       int test=0;
       system("clear");
       printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

       while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",\
			       &add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,\
			       &add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,\
			       &add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }
       printf("\n");
       fclose(view);
  
      if (test==0)
        {   
	      system("clear");	
              printf("\nNO RECORDS!!\n");
	}

    view_list_invalid:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
	system("clear");
        if (main_exit == 1)
            menu();
        else if (main_exit == 0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }

}

void edit()
{
      int choice, test = 0;
      FILE *old, *new;


      old = fopen("record.dat", "r");
      new = fopen("new.dat", "w");

      printf("\nEnter the account no. of customer whose info you want to change :");
      scanf("%d", &upd.acc_no);

      while(fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",\
			      &add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,\
			      &add.age,add.address,add.citizenship,&add.phone,add.acc_type,\
			      &add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF) {
             if (upd.acc_no == add.acc_no) {
	             test = 1;
		     printf("\nWhich information do you want to change\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
		     scanf("%d", &choice);
		     if (choice == 1) {
		            printf("Enter new address : ");
			    scanf("%s", upd.address);
			    fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",\
					    add.acc_no,add.name,add.dob.month,add.dob.day,\
					    add.dob.year,add.age,upd.address,add.citizenship,\
					    add.phone,add.acc_type,add.amt,add.deposit.month,\
					    add.deposit.day,add.deposit.year);
			    printf("Changes saved.\n\n");
		     }
		     else if (choice == 2) {
		            printf("Enter new phone number : ");
			    scanf("%lf", &upd.phone);
			    fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",\
					    add.acc_no,add.name,add.dob.month,add.dob.day,\
					    add.dob.year,add.age,add.address,add.citizenship,\
					    upd.phone,add.acc_type,add.amt,add.deposit.month,\
					    add.deposit.day,add.deposit.year);
		            printf("changes saves!\n\n"); 
		     }

	     }
	     else {
			  fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",\
					    add.acc_no,add.name,add.dob.month,add.dob.day,\
					    add.dob.year,add.age,add.address,add.citizenship,\
					    add.phone,add.acc_type,add.amt,add.deposit.month,\
					    add.deposit.day,add.deposit.year);
	            
	     }
      }
      fclose(old);
      fclose(new);
      system("rm record.dat");
      system("mv new.dat record.dat");


      if (test != 1) {
              printf("Record not found!\n\n");
edit_invalid:
	      printf("Enter 1 to try again, 2 to main menu and 0 to exit : ");
	      scanf("%d", &main_exit);

	      if (main_exit == 2) {
	             menu();
	      }
	      else if (main_exit == 0) {
	             close();   
	      }
	      else if (main_exit == 1) {
	             edit();
	      }
	      else {
	             printf("\nInvalid Input\n");
		     goto edit_invalid;
	      }
      }
      else {
          printf("\nEnter 1 to the main menu and 0 to exit : ");
	  scanf("%d", &main_exit);
	  if (main_exit == 1) {
	        menu();
	  }
	  else {
	        close();
	  }
      }
}

void transact()
{
      int choice, test = 0;
      FILE *old, *new;

      old = fopen("record.dat", "r");
      new = fopen("new.dat", "w");

      printf("Enter the account no. of the customer : ");
      scanf("%d", &transaction.acc_no);
      while(fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",\
			      &add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,\
			      &add.age,add.address,add.citizenship,&add.phone,add.acc_type,\
			      &add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF) {
             if (transaction.acc_no == add.acc_no) {
	            test = 1;
		    if (strcmp(add.acc_type,"fixed1")==0||strcmp(add.acc_type,"fixed2")==0||strcmp(add.acc_type,"fixed3")==0) {
                    system("clear");
	            fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",\
					   add.acc_no,add.name,add.dob.month,add.dob.day,\
					   add.dob.year,add.age,add.address,add.citizenship,\
					   add.phone,add.acc_type,add.amt,add.deposit.month,\
					   add.deposit.day,add.deposit.year);
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!\n\n");
                    fordelay(1000000);
                    //system("clear");
                    //menu();
                     }
		    else {
	            system("clear");
		    printf("Do you want\n 1.Deposit\n 2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw) : ");
		    scanf("%d", &choice);
		    if (choice == 1) {
			   printf("Enter the amount you want to deposit : ");
			   scanf("%f", &transaction.amt);
		           add.amt += transaction.amt;
			   fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",\
					   add.acc_no,add.name,add.dob.month,add.dob.day,\
					   add.dob.year,add.age,add.address,add.citizenship,\
					   add.phone,add.acc_type,add.amt,add.deposit.month,\
					   add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!\n\n");
		    }
		    else {
			   printf("Enter the amount you want to withdraw: ");
			   scanf("%f", &transaction.amt);
		           add.amt -= transaction.amt;
			   fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",\
					   add.acc_no,add.name,add.dob.month,add.dob.day,\
					   add.dob.year,add.age,add.address,add.citizenship,\
					   add.phone,add.acc_type,add.amt,add.deposit.month,\
					   add.deposit.day,add.deposit.year);
		           printf("\n\nWithDraw successfully !\n\n");
		    }
		    }
	     }
	     else {
	            fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",\
				    add.acc_no,add.name,add.dob.month,add.dob.day,\
				    add.dob.year,add.age,add.address,add.citizenship,\
				    add.phone,add.acc_type,add.amt,add.deposit.month,\
				    add.deposit.day,add.deposit.year);

	     }
      } 
     
      fclose(old);
      fclose(new);
      system("rm record.dat");
      system("mv new.dat record.dat");

      if (test != 1) {
	    system("clear");
            printf("Account not founded!");
	    //printf("\n Enter 0 to try again, 1 to main menu and 2 to exit : ")
       transact_invalid:
	    printf("\n Enter 1 to try again, 2 to main menu and 0 to exit : ");
	    scanf("%d", &choice);
	    if (choice == 2)
		    menu();
	    else if (choice == 1)
		    transact();
	    else if (choice == 0)
		    close();
	    else {
	           printf("Invalid Input\n");
		   goto transact_invalid;
	    }
              
      }
      else {
	    //system("clear");
            printf("Enter 1 go to the main menu and 0 to exit : ");
	    scanf("%d", &main_exit);
	    system("clear");
	    if (main_exit == 1) {
	        menu();
	    }
	    else {
	         close();
	    }
      }
}

void see(void)
{
     FILE *fp;
     int choice;
     int test = 0, rate;
     float time;
     float intrst;
     
     fp = fopen("record.dat", "r");
     printf("Do you want to check by\n1. Account no.\n2.name\nEnter your choice : ");
     scanf("%d", &choice);

     if (choice == 1) {
	    printf("Enter your account number : ");
	    scanf("%d", &check.acc_no);
            
            while (fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",\
				    &add.acc_no,add.name,&add.dob.month,&add.dob.day,\
				    &add.dob.year,&add.age,add.address,add.citizenship,\
				    &add.phone,add.acc_type,&add.amt,&add.deposit.month,\
				    &add.deposit.day,&add.deposit.year) != EOF) {

	              if (check.acc_no == add.acc_no) {
		              system("clear");
			      test = 1;

			      printf("\nAccount NO. : %d\nName: %s\nDOB:%d/%d/%d\nAge: %d\nAddress: %s\nCitizenship No: %s\nPhone number:%.01f\nType Of Account: %s\nAmount deposited:$ %.2f\nDate of deposit: %d/%d/%d\n\n",\
				   add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,\
				  add.age, add.address, add.citizenship, add.phone, add.acc_type,\
				 add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

			      if (strcmp(add.acc_type,"fixed1")==0) {
                                     time=1.0;
                                     rate=9;
                                     intrst=interest(time,add.amt,rate);
                                     printf("\n\nYou will get $%.2f as interest on %d/%d/%d",\
						     intrst,add.deposit.month,add.deposit.day,\
						     add.deposit.year+1);
                                    }
                               else if (strcmp(add.acc_type,"fixed2")==0) {
                                     time=2.0;
                                     rate=11;
                                     intrst=interest(time,add.amt,rate);
                                     printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",\
						     intrst,add.deposit.month,add.deposit.day,\
						     add.deposit.year+2);

                                    }
                             else if (strcmp(add.acc_type,"fixed3")==0) {
                                    time=3.0;
                                    rate=13;
                                    intrst=interest(time,add.amt,rate);
                                    printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",\
						    intrst,add.deposit.month,add.deposit.day,\
						    add.deposit.year+3);

                                    }
                              else if (strcmp(add.acc_type,"saving")==0) {
                                       time=(1.0/12.0);
                                       rate=8;
                                       intrst=interest(time,add.amt,rate);
                                       printf("\n\nYou will get $.%.2f as interest on %d of every month",\
						       intrst,add.deposit.day);

                                          }
                              else if(strcmp(add.acc_type,"current")==0) {

                                        printf("\n\nYou will get no interest\a\a");

                                       }
 
		      }
	    }

     }
     if (choice == 2) {
	    printf("Enter your account name : ");
	    scanf("%s", check.name);
            
            while (fscanf(fp,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",\
				    &add.acc_no,add.name,&add.dob.month,&add.dob.day,\
				    &add.dob.year,&add.age,add.address,add.citizenship,\
				    &add.phone,add.acc_type,&add.amt,&add.deposit.month,\
				    &add.deposit.day,&add.deposit.year) != EOF) {

	              if (strcmp(check.name, add.name) == 0) {
		              system("clear");
			      test = 1;

			      printf("\nAccount NO. : %d\nName: %s\nDOB:%d/%d/%d\nAge: %d\nAddress: %s\nCitizenship No: %s\nPhone number:%.01f\nType Of Account: %s\nAmount deposited:$ %.2f\nDate of deposit: %d/%d/%d\n\n",\
				   add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,\
				  add.age, add.address, add.citizenship, add.phone, add.acc_type,\
				 add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
 
		      }
     
                  }
     }    
     fclose(fp);
     if (test != 1) {
            printf("Account not Founded!\n");
see_invalid:
	    printf("\nEnter 1 to try again, 2 to main menu and 0 to exit :");
	    scanf("%d", &choice);

	    if (choice == 1) {
	          system("clear");
		  see();
	    }
	    else if (choice == 2) {
	          system("clear");
		  menu();
	    }
	    else if (choice == 0) {
	         system("clear");
		 close();
	    }
	    else {
	         printf("Invalid Input!");
		 goto see_invalid;
	    }
     }
     else {
          printf("\n\nEnter 1 to the main menu 2 to exit : ");
          scanf("%d", &main_exit);

          if (main_exit == 1) {
	        system("clear");
                menu();
             }
          else {
	       system("clear");
               close();
                }
     }
}

void erase(void)
{
      FILE *old, *new;
      int choice, test = 0;

      old = fopen("record.dat", "r");
      new = fopen("new.dat", "w");

      printf("Enter the account no. of customer you want to delete : ");
      scanf("%d", &rem.acc_no);

      while(fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",\
			      &add.acc_no, add.name, &add.dob.month, \
			      &add.dob.day, &add.dob.year, &add.age, \
			      add.address, add.citizenship, &add.phone, \
			      add.acc_type, &add.amt, &add.deposit.month, \
			      &add.deposit.day, &add.deposit.year) != EOF) {
	      if (rem.acc_no != add.acc_no)  { 
	                           fprintf(new,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",\
						   add.acc_no,add.name,add.dob.month,add.dob.day,\
						   add.dob.year,add.age,add.address,add.citizenship,\
						   add.phone,add.acc_type,add.amt,add.deposit.month,\
						   add.deposit.day,add.deposit.year);

	      }
	      else {
	               test++;
		       system("clear");
		       printf("\n\nRecord deleted successfully\n\n");
	      }
      
      }
      fclose(old);
      fclose(new);
      system("rm record.dat");
      system("mv new.dat record.dat");

      if (test == 0) {
	      // system("clear");
               printf("\nRecord not found\n\a\a\a");
erease_invalid:
	       printf("Enter 1 to try again, 2 to the main menu and 0 to exit : ");
	       scanf("%d", &choice);
	       system("clear");
	       if (choice == 1) {
	               erase();
	       }
	       else if (choice == 2) {
		       menu();
	       
	       }
	       else if (choice == 0) {
	              close();
	       }
	       else {
	             printf("Invalid Input\n");
		     goto erease_invalid;
	       }
      }
      else {
	     //   system("clear");
                printf("\nEnter 1 to main menu and 0 to exit :");
		scanf("%d", &main_exit);
	        system("clear");
		if (main_exit == 1) {
		        menu();
		}
		else {
		       close();
		}

      }

}

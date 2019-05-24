#include<stdio.h>
#include"bank.h"

Info add;

int main(void) 
{
       FILE * view;
       view = fopen("record.date", "r");
       if (view == NULL) {
              printf("fail");
	      return 1;
       }
       int test=0;
       printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

       while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",\
			       &add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,\
			       &add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,\
			       &add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }
       fclose(view);
       return 0;
}


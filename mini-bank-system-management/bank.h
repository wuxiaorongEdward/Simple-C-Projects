#include<stdio.h>
#include<stdlib.h>

#ifndef BANK_H
#define BANK_H

struct date {
     int month, day, year;
};

typedef struct info {
     char name[60];
     int acc_no, age;
     char address[60];
     char citizenship[15];
     double phone;
     char acc_type[10];
     float amt;
     struct date dob;
     struct date deposit;
     struct date withdraw;
}Info;

extern int main_exit;

extern Info add, upd, check, rem, transaction;

extern float interest(float t, float amount, int rate);

extern void fordelay(int j);

extern void new_acc();

extern void view_list(void);

extern void edit(void);

extern void transact(void);

extern void see(void);

extern void erase(void);

#endif

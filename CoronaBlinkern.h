#ifndef CoronaBlinkernh
#define CoronaBlinkernh
#include<stdio.h>



struct date
{
    int day;
    int month;
    int year;
    struct date *next;
};
struct date d;
struct date *head;
struct date dat;

struct date date_registered[1000];

void option1(void);
int option2(int other);
struct date check_leapyear(struct date d);
void print_store_date(struct date d);
void print_currentDay(void);
void option4(void);

#endif

#include <stdio.h>
#include <stdlib.h>
#include "date.h"



void verify_and_print(date_t* a_date, int day, int month, int year)
{
   bool is_valid = set_date(a_date,  day, month, year);
    print_fi_std(*a_date);
    if(is_valid)
   {
    printf(" is valid date\n");
   }
   else
   {
     printf(" is not valid date\n");
   }
}
 

 void verify (bool success, char * message)
 {
   if(success)
{
  printf("Success %s\n", message);
}
else
{
  printf("Fail %s\n", message);
}

}


int main(){
    date_t date1, date2, date3;


    printf("Testning date ADT\n\n");
   
   set_date(&date1,  29, 2, 2020);

   printf("%d.%d.%d\n", date1.day, date1.month, date1.year);

   if(is_valid(date1))
   {
    printf("Date is valid\n");
   }
   else
   {
     printf("Date is not valid\n");
   }

   printf("\n");
   //test leap year
   set_date(&date1, 25, 1, 2021);

   printf("%d.%d.%d\n", date1.day, date1.month, date1.year);

   if(is_valid(date1)){
     printf("Is a leap year\n");
   }
   else
   {
     printf("Is not a leap year\n");
   }
  
  printf("\n");

   //test printing
   printf("Date i Finnish format: ");
   print_fi_std(date1);
   printf("\n Date in ISO: ");
   print_iso_std(date1);
   printf("\n");

   verify_and_print(&date1, 29, 2, 2021);
   verify_and_print(&date1, 28, 2, 2021);
   verify_and_print(&date1, 31, 11, 2021);
   verify_and_print(&date1, 0, 2, 2021);
   verify_and_print(&date1, 42, 4, 2021);
   verify_and_print(&date1, 29, 2, 2020);
   verify_and_print(&date1, 29, 2, 2000);

//Compare dates

set_date(&date1, 25, 1, 2021);
set_date(&date2, 25, 1, 2021);
verify(dates_equal(date1, date2), "Comparing equal dates");

set_date(&date2, 26, 1 ,2021);
verify(!dates_equal(date1, date2), "Comparing not equal dates");

set_date(&date2, 25, 2 ,2021);
verify(!dates_equal(date1, date2), "Comparing not equal dates");

set_date(&date2, 25, 1, 2023);
verify(!dates_equal(date1, date2), "Comparing  not equal dates");

set_date(&date1, 25, 1, 2021);
set_date(&date2, 25, 1, 2021);
verify(!is_before(date1, date2), "Checking if date is before itself");

set_date(&date1, 24, 1, 2021);
verify(is_before(date1, date2), "Checking if date is before date one day later"); 


set_date(&date1, 25, 2, 2021);
set_date(&date2, 24, 2, 2021);
date3 = get_previous_day(date1);
verify(dates_equal(date3, date2), "Checking that previous day is correct");

set_date(&date1, 1, 2, 2021);
set_date(&date2, 31, 1, 2021);
date3 = get_previous_day(date1);
verify(dates_equal(date3, date2), "Checking that previous day is correct");

set_date(&date1, 1, 1, 2021);
set_date(&date2, 31, 12, 2020);
date3 = get_previous_day(date1);
verify(dates_equal(date3, date2), "Checking that previous day is correct");

set_date(&date1, 1, 3, 2024);
set_date(&date2, 29, 2, 2024);
date3 = get_previous_day(date1);
verify(dates_equal(date3, date2), "Checking that previous day is correct");

set_date(&date1, 25, 1, 2021);
set_date(&date2, 5, 1, 2021);
date3 = get_n_days_previous(date1, 20);
verify(dates_equal(date3, date2), "Checking that  20 previous day is correct");

set_date(&date1, 5, 2, 2021);
set_date(&date2, 30, 1, 2021);
date3 = get_n_days_previous(date1, 6);
verify(dates_equal(date3, date2), "Checking that 6 previous day is correct");


set_date(&date1, 5, 2, 2021);
set_date(&date2, 30, 12, 2020);
date3 = get_n_days_previous(date1, 37);
verify(dates_equal(date3, date2), "Checking that 37 previous day is correct");

set_to_today(date1);
printf("Today is ! ");
print_fi_std(date1);
printf("\n");
   return 0;
}
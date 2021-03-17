#include "date.h"
#include <stdio.h>
#include<stdbool.h>
#include<time.h>

bool set_date(date_t *a_date, int day, int month, int year)
{
   a_date->day = day;
   a_date->month = month; 
   a_date->year = year;

   return is_valid(*a_date);
}

int days_per_month[13] = {0, 31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};

/**
 * Get the number of days for the given date
 *@param a_date The date to check
 *@returns an integer representing the maximum numbar of days ingiven month
 */


int get_days_per_month(date_t a_date)
{
 if ((a_date.month == 2) && (ceck_year(a_date)))
 { 
    return 29;

 }
    else
    {
      return days_per_month[a_date.month];
    }
    
}

bool is_valid(date_t a_date)
{

   if (a_date.month < 1 || a_date.month > 12 ||
       a_date.day < 1 || a_date.day > 31)
   {
      return false;
   }
   else if (a_date.month == 2)
   {
      if (ceck_year(a_date))
      {
         return (a_date.day <= 29);
      }
      else
      {
         return (a_date.day <= 28);
      }
   }
   else if (a_date.month == 4 || a_date.month == 6 ||
            a_date.month == 9 || a_date.month == 11)
   {
      return a_date.day <= 30;
   }
   else
   {
      return a_date.month <= 31;
   }
}

bool ceck_year(date_t a_date)
{
   // not divible by 4 not leap year.
   if (a_date.year % 4 > 0)
   {
      return false;
   }
   else if (a_date.year % 100 == 0)
   {
      if (a_date.year % 400 == 0)
      {
         // divisible by 400 --> not leap year.
         return false;
      }
      else
      {
         // divisile by 100 but not 400 --> leap year.
         return true;
      }
   }
   else
   {
      return true;
   }
}

void print_fi_std(date_t a_date)
{
   printf("%d.%d.%d", a_date.day, a_date.month, a_date.year);
}

void print_iso_std(date_t a_date)
{
   printf("%d-%d-%d", a_date.year, a_date.month, a_date.day);
}
bool dates_equal(date_t date1, date_t date2)
{
   if(date1.day == date2.day && 
     date1.month == date2.month &&
     date1.year == date2.year)
     {
        return true;
     }
     else 
     {
        return false;
     }

}

bool is_before(date_t first, date_t second)
{
 if(first.year < second.year)
 {
    return true;
 }
  else if(first.year > second.year)
 {
    return false;
 } 
 else if( first.month < second.month)  // first.year == second.year)
 {
    return true;
 } 
 else if(first.month > second.month)
 {
    return false;
 }
 else if(first.day < second.day) // first.month == second.month
 {
    return true;
 }
else //first.day > second.day or dates_equal
{
   return false;
}



}
date_t get_previous_day(date_t a_date)
{
   
   
    if (a_date.day == 1)
    {
        //beginning of month, get previous month
        a_date.month = a_date.month -1;

        if (a_date.month == 0)
        {
           //beginning of year, skip to December previous year
           a_date.year -= 1; 
           a_date.month = 12;
        }
        //uppdate the day to the last day of the previous month (now in a_date)
        a_date.day = get_days_per_month(a_date);
    }
   else
   {
      //not in the begining of the month, just decrese date
      a_date.day -= 1;
   }
   return a_date;
}

 date_t get_n_days_previous(date_t a_date, int days)
 { 
    date_t index_date =a_date;
    while(days > 0)
    {
       days--;
       index_date =get_previous_day(index_date);
    }
    return index_date;
 }
 date_t set_to_today(date_t star)
{
   time_t today_in_seconds;
   struct tm  *timeinfo;

   date_t  a_date = star;

   today_in_seconds = time(NULL);
   timeinfo = localtime(&today_in_seconds);

   a_date.day = timeinfo->tm_mday;
   a_date.month = timeinfo->tm_mon +1; //tm_mon is months since January
   a_date.year = timeinfo->tm_year + 1900; //tm_year years sinece 1900

   return a_date;
}




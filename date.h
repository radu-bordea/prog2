 #ifndef dateh
 #define dateh
 #include<stdio.h>
 #include<stdbool.h>
 


typedef struct{
    int day;
    int month;
    int year;

} date_t;

/**
 * Function for settings the date of a given date.
 * @param a_date the date to be updated.
 * @param day integer representing the day.
 * @param month integer representing the month.
 * @param year integer representing the year.
 * @param true if date valid, false othewise.
 * 
 */
 bool set_date(date_t* a_date, int day ,int month, int year);

/**
 * function for checking if a date is valid.
 * @param a_date the date to be checked.
 * @returns true if date valid, false otherwise.
*/
 bool is_valid(date_t a_date);

/**
 * Function for checking if a date is a leap year.
 * @param a_date the date to check.
 * @returns true if teh edate is on a leap year.
 * */

 bool ceck_year(date_t a_date);

 /**
  * function for printing a date in Finnish stanfard format.
  * @param a_date the date to print.
  */

 void print_fi_std (date_t a_date);

  
  /**
  * function for printing a date in ISO stanfard format.
  * @param a_date the date to print.
  */
 void print_iso_std (date_t a_date);

 /** 
  * Function for comparing if do dates are equal
  * @param date1 The first date to compare
  * @param date2 The second date to compare
  * @return true if dates are the same date, false qtherwise
  */
  bool dates_equal(date_t date1, date_t date2);

  /**
   * Function for comparing two dates to see if one is before the other.
   * @param date1 The date we want to ceck if it is first in time
   * @param second The date we want to ceck if it is after the first in time
   * @returns true if first is beafore the second, false otherwise
   */

  bool is_before(date_t first, date_t second);

  /**
   * Function for retriving the date before a given day
   * @param a_day The starting date.
   * @return The day before the given date.
   */

   date_t get_previous_day(date_t a_date);

   /**
    * function for retriving the date a given number of days befor the given date
    * @param a_date the starting date
    * @param days the number of days to go back
    * @returns the searche for date
    */
   date_t get_n_days_previous(date_t a_date, int days);

   /**
    * function for settings a date to today's date
    * @param a_date pointer to the date to be set to today's date
    */
   date_t set_to_today(date_t star);

#endif

  
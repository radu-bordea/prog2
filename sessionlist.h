#include <stdbool.h>
#include <stdio.h>
#include "date.h"

  
/**
 * Datatype for storing swsion data, i.e. date, duration in minutes and exercise type
 */ 

typedef struct session_data_struct
{
  date_t date;
  int corona_code;

}session_data; 
/**
 * Struct for storing sesion list node.
 */ 

struct sessionlist_node_struct{
   session_data data;
   struct sessionlist_node_struct * next;
};

/**
 * Datatype for node in the list node.
 */ 
typedef struct sessionlist_node_struct  sessionlist_node;

/**
 * Datatype for sessionlist.
 */ 
typedef sessionlist_node * sessionlist;

/**
 * Function for creating a session list.
 * @returns the new empty list. 
 */ 

/**
 * Function to reprot user infection
 */
void report_infection(void);


sessionlist list_create();

/**
 * function for testing if the list is empty.
 * @return true if empty false if otherwawise
 */
 bool list_is_empty(sessionlist list);

 /**
  * Function for storing session data in the list.
  * @param listptr pointer to a list.
  * @param data The data to be insertet.
  */
 void list_insert( sessionlist * listptr, session_data data);  

 /**
  * Function for printing entrie list
  * @param list A liats that will be printed
  */
 void list_print_all(sessionlist list);


/**
  * Function for writing entire list to file
  * @param fileptr Pointer to file to be written to
  * @param list A list that will be printed
  */
 void list_write_to_file(FILE * fileptr, sessionlist list);

/**
  * Function for reading a list from file
  * @param fileptr Pointer to file to be read from
  * @param list A list that will be updated. Call by value.
  * @returns the updatet sessionlist
  */
 sessionlist list_read_from_file(FILE * fileptr, sessionlist list);


 /**
  * Funciton for printimg partial list.
  * @param list the list to be partially printed.
  * @param cutoff the last date to be printed.
  */
 void list_print_partial(sessionlist list, date_t cutoff);

 /**
  * Function for printing the last 7 days.
  * @param list The list to be partially  printed.
  */

 

 void list_print_last_seven_days(sessionlist list); 

 /**
  * function for removing all sessions for a given exercise type.
  * @param lissptr poiner to the list to be updated.
  * @param exercise_type type The type of sessions to be removed.
  */

void remove_all_of_type(sessionlist *listptr, date_t old_days);



 
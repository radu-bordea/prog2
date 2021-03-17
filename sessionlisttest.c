#include "sessionlist.h"
#include<stdio.h>
#include<stdbool.h>

#define TEST_CASE(name) printf("RUNNING CASE: %s\n", name)
#define VERIFY(cond, msg) if (cond) printf("SUCCESS: %s\n", msg); else printf("FAIL: %s\n", msg);

int main()
{
    sessionlist myList;
    session_data session1;
    date_t date1, date2;

    TEST_CASE("Create list");
    myList = list_create();
    
    VERIFY (list_is_empty(myList), "list_is_empty.")
   
    TEST_CASE("Insert element");

    set_date(&date1, 24, 2, 2021);
    session1.date = date1;
    session1.corona_code =100;
    list_insert(&myList, session1);
    VERIFY(!list_is_empty(myList), "List is not empty");

    TEST_CASE("Insert second element");
    session1.corona_code = 111;
    session1.date = get_previous_day(date1);
    list_insert(&myList, session1);
    VERIFY(!list_is_empty(myList), "List is not empty");

    TEST_CASE("Print all");
    list_print_all(myList);

    TEST_CASE("Insert more elements");
    for (int i = 0; i < 10; i++)
    {
        date1 = get_previous_day(date1);
        session1.date = date1;
        session1.corona_code =i;
        list_insert(&myList, session1);

    } 
    list_print_all(myList);

    TEST_CASE("Print after 3.02.2021");
    set_date(&date2, 25, 2, 2021);
    list_print_partial(myList, date2);


    TEST_CASE("Delete tel id, witch is entire list");
    remove_all_of_type(&myList, date1);
    VERIFY (list_is_empty(myList), "list_is_empty.");

    TEST_CASE("Insert more elements with different code type.");
    for (int i = 0; i < 10; i++)
    {
        date1 = get_previous_day(date1);
        session1.date = date1;
        session1.corona_code = i;
        list_insert(&myList, session1);

    } 
    list_print_all(myList);

    TEST_CASE("Delete element with value 21");
    remove_all_of_type(&myList, date2);
    VERIFY (list_is_empty(myList), "list_is_empty.");
    list_print_all(myList);
}
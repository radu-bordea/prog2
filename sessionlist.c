#include "sessionlist.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUGON
#define DEBUG(msg) printf("DEBAG: %s\n", msg)
#else
#define DEBUG(msg)
#endif

sessionlist list_create()
{
    return NULL;
}

bool list_is_empty(sessionlist list)
{
    if (list == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void list_insert(sessionlist *headptr, session_data data)
{
    sessionlist_node *new_node;
    //aloc data for node.
    new_node = (sessionlist_node *)malloc(sizeof(sessionlist_node));

    //add data into list.
    new_node->data = data;

    //insert node into a list.
    //Case1: List is empty.
    if (*headptr == NULL)
    {
        DEBUG("list_insert, case 1 - empty list");
        *headptr = new_node;
        new_node->next = NULL;
    }

    //Case2: List is populated.
    else
    {
        DEBUG("list_insert, case 2 -  list has content");
        new_node->next = *headptr;
        *headptr = new_node;
    }
}
void print_sesion_data(session_data data, FILE *fileptr)
{
    printf("\t");
    //print_fi_std(data.date);
    fprintf(fileptr, "%d.%d.%d\t\t|\t%d\t\t\n", data.date.day, data.date.month, data.date.year, data.exercise_type);
    printf("----------------------------------------------------------------\n");
}

void list_print_all(sessionlist list)
{
    sessionlist_node *current_node;
    DEBUG("list_print_all start");
    current_node = list;

    while (current_node != NULL)
    {
        DEBUG("list_print_all inside loop");
        //Print the content of the node
        print_sesion_data(current_node->data, stdout);

        //Go to next node
        current_node = current_node->next;
    }
}

sessionlist list_read_from_file(FILE *fileptr, sessionlist list)
{
     DEBUG("List_read_from_file begining of function");
    sessionlist new_list = list;
    session_data new_data;
    int fields_read = 0;

    do
    {
        fscanf(fileptr, "%d.%d.%d type: %d\t\t|\t\n", &new_data.date.day, &new_data.date.month, &new_data.date.year,
                                                    &new_data.exercise_type);
        if (fields_read == 4)
        {
            DEBUG("List_read_from_file inserting new_session");
            list_insert(&new_list, new_data);
        }
    } while (fields_read == 4);

    return new_list;
}

void list_write_to_file(FILE *fileptr, sessionlist list)
{
    sessionlist_node *current_node;
    DEBUG("list_write_to_file start");
    current_node = list;

    while (current_node != NULL)
    {
        DEBUG("list_write_to_file inside loop");
        //Print the content of the node
        print_sesion_data(current_node->data, fileptr);

        //Go to next node
        current_node = current_node->next;
    }
}

void list_print_partial(sessionlist list, date_t cutoff)
{
    while (list != NULL)
    {
        DEBUG("list_print_partial inside loop");
        //Check if we should print this node
        if (!is_before(list->data.date, cutoff))
        {
            print_sesion_data(list->data, stdout);
        }
        else
        {
            DEBUG("list_print_partial, not printing");
        }
        // Go to next node
        list = list->next;
    }
}

void list_print_last_seven_days(sessionlist list)
{
    date_t today, seven_days_earlier;
    set_to_today(today);
    seven_days_earlier = get_n_days_previous(today, 7);
    list_print_partial(list, seven_days_earlier);
}

void remove_all_of_type(sessionlist *listptr, date_t old_days)
{

    sessionlist_node *current_node;
    sessionlist_node *previous_node;
    current_node = *listptr;
    previous_node = NULL;

    old_days= set_to_today(old_days); 
    old_days=get_n_days_previous(old_days, 21);

     while (current_node != NULL)
   { 
       
       if(is_before(current_node->data.date, old_days))
        {
           DEBUG("remove_all_of_type: found element to delete.");
           
           //This node should be deleted
           if(previous_node == NULL)
           {
              //First element deleted.
              
              DEBUG("remove_all_of_type: deleting firs element.");
              *listptr = current_node->next;
              free(current_node);
              current_node = *listptr;
           }
           else
           {
              //Other element deleted
              DEBUG("remove_all_of_type: deleting other element.");
              previous_node->next = current_node->next;
              free(current_node);
              current_node = previous_node->next;
           }   
       }
       else
       {
           //This node should no be deleted
           DEBUG("remove_all_of_type: element shod not be deleted.");
           previous_node = current_node;
           current_node = current_node->next;
       }
   }
}
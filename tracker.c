#include <stdbool.h>
#include <stdio.h>
#include "sessionlist.h"
#include "date.h"
#include <string.h>
#include <stdlib.h>

//globals
sessionlist my_sessions;
date_t old_days;

date_t today;
date_t last_day;
date_t sendit;
int myArr[1000];
date_t dateAr[1000];
int count = 0;

void print_menu()
{

    printf("\n\t        Menu           \n");
    printf("\n1. Repport infection with coronavirus\n");
    printf("2. Add a new exercise session\n");
    printf("3. Display all stored sessions\n");
    printf("4. Forget exercise type\n");
    printf("5. Quit\n\n");
}

void clear_buffer()
{
    while (getchar() != '\n')
        ;
}

void print_prompt()
{
    printf("> ");
}

int prompt_user()
{
    int selection;
    print_prompt();
    while (scanf("%d", &selection) != 1)
    {
        printf("Incorrect input, please select a number from the menu.\n");
        clear_buffer();
        print_prompt();
    }
    return selection;
}

int read_exercise_type()
{
    int corona_code;
    printf("==============================");
    printf("\nType : ");

    while (!scanf("%d", &corona_code))
    {
        printf("Incorrect input, please input an integer for duration.\n");
        clear_buffer();
        printf("Type : ");
    }
    printf("==============================");
    return corona_code;
}

date_t read_date()
{
    int day, month, year;
    date_t new_date;
    bool date_done = false;

    today = set_to_today(new_date);
    printf("\nToday: %d.%d.%d\n", today.day, today.month, today.year);
    last_day = get_n_days_previous(today, 20);
    printf("Last day: %d.%d.%d\n\n", last_day.day, last_day.month, last_day.year);

    printf("==============================\n");
    while (!date_done)
    {
        printf("Date : ");

        while ((scanf("%d.%d.%d", &day, &month, &year) < 3))
        {
            printf("Incoerent input, please input date in format dd.mm.yyyy\n");
            clear_buffer();
            printf("Date : ");
        }
        set_date(&new_date, day, month, year);
        if (!is_valid(new_date))
        {
            printf("incorect date, please input a valid date.\n");
        }
        else
        {
            date_done = true;
        }
    }
    return new_date;
}

void add_session()
{
    session_data new_session;
    new_session.date = read_date();
    new_session.corona_code = read_exercise_type();
    list_insert(&my_sessions, new_session);
}

void print_session()
{
    char *header = "----------------------------------------------------------------\n";
    printf("%s                          All sessions       \n%s", header, header);
    printf("|\tDate of exposure\t|\tRegistered codes\t|\n");
    printf("%s", header);
    list_print_all(my_sessions);
}

void report_infection(void)
{
    int code;
    printf("Enter the code you received:\n");
    scanf(" %d", &code);
    fflush(stdin);
    while (code == 0 || code < 0 || code > 10000000)
    {
        printf("Try again by inserting a maximum t digits number!");
        scanf(" %d", &code);
        fflush(stdin);
    }
    printf("You are infected with corona virus and you corona identification code is: %d\n\n", code);
}

int main(int argc, char const *argv[])
{
    bool done = false;
    int selection = 0;
    char *filename = "sessions.txt";
    FILE *fileptr;
    my_sessions = list_create();

    fileptr = fopen(filename, "r");
    if (fileptr != NULL)
    {
        my_sessions = list_read_from_file(fileptr, my_sessions);
        fclose(fileptr);
    }
    else
    {
        printf("Warning, could not open file %s for reading. Starting with empty list.\n", filename);
    }

    if (selection == strcmp("add", argv[1]))
    {
        session_data important_session;
        int the_codex;
        int daystr;
        int monthstr;
        int yearstr;
        
        sscanf(argv[2], "%d", &the_codex);
        sscanf(argv[3], "%d.%d.%d", &daystr, &monthstr, &yearstr);
        printf("added case code: %d datum: %d.%d.%d", the_codex, daystr, monthstr, yearstr);
        important_session.corona_code = the_codex;
        important_session.date.day = daystr;
        important_session.date.month = monthstr;
        important_session.date.year = yearstr;

        list_insert(&my_sessions, important_session);        
        fileptr = fopen(filename, "w");
        if (fileptr != NULL)
        {
            list_write_to_file(fileptr, my_sessions);
            fclose(fileptr);
        }
        else
        {
            printf("Warning, could not open file %s for writting. Session data lost.\n", filename);
        }
    }

    else if (selection == strcmp("history", argv[1]))
    {
        my_sessions = list_read_from_file(fileptr, my_sessions);
        print_session();
        exit(0);
    }

    else if (selection == strcmp("help", argv[1]))
    {

        printf("Commands:\nAdd (code) (day.month.year)\n"
               "History (show history of the codes)\n"
               "Interactive(Interactive mode)");
        exit(0);
    }

    else if (selection == strcmp("interactive", argv[1]))
    {
        my_sessions = list_read_from_file(fileptr, my_sessions);
        print_session();

        while (!done)
        {
            print_menu();
            selection = prompt_user();

            switch (selection)
            {
            case 1:
                report_infection();
                break;

            case 2:
                add_session();
                break;

            case 3:
                print_session();
                break;

            case 4:
                remove_all_of_type(&my_sessions, old_days);
                break;

            case 5:
                done = true;
                break;

            default:
                printf("Incorect input %d\n", selection);
                break;
            }
        }
        fileptr = fopen(filename, "w");
        if (fileptr != NULL)
        {
            list_write_to_file(fileptr, my_sessions);
            fclose(fileptr);
        }
        else
        {
            printf("Warning, could not open file %s for writting. Session data lost.\n", filename);
        }
        exit(0);
    }

    fileptr = fopen(filename, "w");
    if (fileptr != NULL)
    {
        list_write_to_file(fileptr, my_sessions);
        fclose(fileptr);
    }
    else
    {
        printf("Warning, could not open file %s for writting. Session data lost.\n", filename);
    }
}
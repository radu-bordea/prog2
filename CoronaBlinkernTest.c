#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CoronaBlinkern.h"


void option1(void)
{
    int code = 12974673;
    printf("You are infected with corona virus and you corona identification code is: %d", code);
}

int option2(int other)
{
    printf("Enter the infected registered code:\n");
    scanf(" %d", &other);
    fflush(stdin);

    while (other == 1)
    {
        printf("Try again by inserting numbers only!");
        scanf(" %d", &other);
        fflush(stdin);
    }
    while (other < 0 || other > 10000000)
    {
        printf("Try again by inserting a positiv number with maximum 7 digits!\n");
        scanf(" %d", &other);
        fflush(stdin);
    }
    return other;
}

struct date check_leapyear(struct date d){

   while (d.day > 31 || d.month > 12 || d.year < 2021 || 2040 < d.year)
            {
                printf("Date must respect the following rules:\n");
                printf("For months 1, 3, 5, 7, 8, ,10, 12 the maximum day to be inserted is 31.\n");
                printf("For months 4, 6, 9, 11 the maximum day to be inserted is 30.\n");
                printf("For month 2 the maximum day to be inserted is 28 for normal year and 29 for a bisect year.\n");
                printf("The maximum number to be inserted for month is 12.\n");
                printf("The maximum year to be inserted must be between and inclusive 2020 and 2040.\n");
                printf("Please try again!\n");

                printf("Day: ");
                scanf("%d", &d.day);
                fflush(stdin);
                printf("Month: ");
                scanf("%d", &d.month);
                fflush(stdin);
                printf("Year: ");
                scanf("%d", &d.year);
                fflush(stdin);
            }
            if (d.year % 4 == 0 && d.month == 2)
            {
                while (d.day > 29 || d.month > 12 || d.year < 2021 || 2040 < d.year)
                {
                    printf("This is an leap year!\n");
                    printf("Try again by inserting day < 30, month < 13 and year between 2021 and 2040!\n");

                    printf("Day: ");
                    scanf("%d", &d.day);
                    fflush(stdin);
                    printf("Month: ");
                    scanf("%d", &d.month);
                    fflush(stdin);
                    printf("Year: ");
                    scanf("%d", &d.year);
                    fflush(stdin);
                }
            }
            else if (d.year % 4 != 0 && d.month == 2)
            {
                while (d.day > 28 || d.month > 12 || d.year < 2021 || 2040 < d.year)
                {
                    printf("Try again by inserting Try again by inserting day < 29, month < 13 and year between 2021 and 2040!\n");

                    printf("Day: ");
                    scanf("%d", &d.day);
                    fflush(stdin);
                    printf("Month: ");
                    scanf("%d", &d.month);
                    fflush(stdin);
                    printf("Year: ");
                    scanf("%d", &d.year);
                    fflush(stdin);
                }
            }
            return d;
    }

void print_store_date(struct date date_registered)
{
               struct date *new_node = NULL;
                new_node = (struct date *)malloc(sizeof(struct date)); // Allocating the new node

                if (new_node == NULL)
                {
                    printf("Failed to insert element. Out of memory");
                }

                new_node->day = date_registered.day; 
                new_node->month = date_registered.month;
                new_node->year = date_registered.year;  /*Setting the value of the node*/
                new_node->next = head; /*Pointing the new node where head is currently pointing to*/
                head = new_node;       /*Pointing head to new element*/
                printf(" %d/%d/%d\t |", head->day, head->month, head->year);
                free(new_node);     
}

void print_currentDay(void)
{
            time_t now;
            time(&now);

            struct tm *local = localtime(&now);

            dat.day = local->tm_mday;
            dat.month = local->tm_mon + 1;
            dat.year = local->tm_year + 1900;
            // print current date
            printf("\nCurrent date is : %02d/%02d/%d\n", dat.day, dat.month, dat.year);
}

void option4(void){
    printf("You chose to close the app!\n");
    printf("The app is still on!\n");
    printf("Stay safe friend!");
}

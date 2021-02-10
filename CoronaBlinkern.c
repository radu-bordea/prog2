#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CoronaBlinkern.h"

int main(void)
{
    int other_code = 0;
    int count = 0;
    char choice;
    int registered_codes[1000];

    printf("\nWelcome to CoronaBlinkern APP");
    print_currentDay();
    printf("\n          Menu           \n");
    while (choice != '4')
    {
        printf("\nChose 1 if you get infected with Corona Virus to get a registered code!\n");
        printf("Chose 2 if you meet someone infected with Corona Virus!\n");
        printf("Chose 3 Print activ registered corona codes: \n");
        printf("Chose 4 to quit the programm!\n");
        scanf(" %c", &choice);
        if (choice == '1')
        {
            option1();
            printf("\n");
        }
        else if (choice == '2')
        {
            count++;
            int person1_code = option2(other_code);
            registered_codes[count - 1] = person1_code;
            printf("Insert tha date: ddmmyyyy: \n");
            printf("Day: ");
            scanf("%d", &d.day);
            fflush(stdin);
            printf("Month: ");
            scanf("%d", &d.month);
            fflush(stdin);
            printf("Year: ");
            scanf("%d", &d.year);
            fflush(stdin);

            check_leapyear(d);
            printf("\nThe %d persone infected was on %d/%d/%d with the code number %d.\n", count, d.day, d.month, d.year, registered_codes[count - 1]);
              date_registered[count - 1].day = d.day;
              date_registered[count - 1].month = d.month;
              date_registered[count - 1].year = d.year; 
                
        }
        else if (choice == '3')
        {
            print_currentDay();
            printf("Active codes registered les than 21 days from current date:\n");
            printf("\n--------------------------------------------------------------\n");
            printf("| Registered Code |   Date of exposure    | Days till erase  |\n");
            printf("--------------------------------------------------------------\n");
            for (int i = 0; i < count; i++)
            {
                int partial_diff = 21 - dat.day;
                if(date_registered[i].year==dat.year && date_registered[i].month==dat.month)
                {
                
                printf("| \t%d\t  |\t", registered_codes[i]);
                print_store_date(date_registered[i]);
                printf("\t  %d\t     |\n", date_registered[i].day +21 - partial_diff);
                printf("--------------------------------------------------------------\n");
                }
                else if(date_registered[i].year==dat.year && date_registered[i].month+1==dat.month)
                    {
                        if(date_registered[i].day>31-partial_diff)
                        {
                            
                            printf("| \t%d\t  |\t", registered_codes[i]);
                            print_store_date(date_registered[i]);
                            printf("\t  %d\t     |\n", partial_diff - (32 - date_registered[i].day));
                            printf("--------------------------------------------------------------\n");
                        }
                    }
            }
            

            
        }
        else if (choice == '4')
        {
            option4();
            return -1;
        }
        else
        {
            printf("No such an option. Please chose again!\n");
        }
        printf("\nFinnished session. Chose again: \n");
        printf("To leave the application press 5.\n");
    }
    return 0;
}
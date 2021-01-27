#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    int day;
    int month;
    int year;
};
struct date d;
struct date date_registered[1000];

void option1(char *the_name, int the_code)
{
    printf("You, %s, have corona virus and you must send notification to the app and then you will receive a unic code: ", the_name);
    printf("\nThe code for %s is: %d", the_name, the_code);
}
int option2(int other)
{
    printf("Enter the infected registered code:\n");
    scanf(" %d", &other);
    fflush(stdin);
    while (other == 0){
    printf("Try again by inserting numbers only!"); 
    scanf(" %d", &other);
    fflush(stdin);
    }
    return other;
}
bool option3(bool alarm_alert)
{
    alarm_alert = 1;
    printf("There is an infected persone les than 50 meters from you!\n");
    printf("Please be careful!\n");
    return alarm_alert;
}

int main(void)
{
    char app[30] = "Stay Safe Son";
    char name[30] = "Bordea Radu";
    int other_code;
    int code = 12974673;
    int count = 0;
    char choice;
    int registered_codes[1000];
    bool alarm = 0;
    bool alarm_rings;
    char stop_alarm;

    printf("Welcome to the %s - App\n\n", app);

    printf("          Menu           \n");
    while (choice != '5')
    {
        printf("\nChose 1 if you get infected with Corona Virus to get a registered code!\n");
        printf("Chose 2 if you meet someone infected with Corona Virus!\n");
        printf("Chose 3 to stop the alarm. The alarm starts when a infected persone is les than 50 meters around you!\n");
        printf("Chose 4 to show the list with registered infected persons: \n");
        printf("Chose 5 to quit the programm!\n");
        scanf(" %c", &choice);

        if (choice == '1')
        {
            option1(name, code);
            printf("\n");
        }
        else if (choice == '2')
        {
            count++;
            int person1_code = option2(other_code);
            registered_codes[count - 1] = person1_code;
            printf("Insert tha date: ddmmyyyy: \n");
            scanf(" %d%d%d", &d.day, &d.month, &d.year);
            fflush(stdin);
            while (d.day > 31 || d.month > 12 || d.year < 2020 || 2040 < d.year)
            {
                printf("Date must respect the following rules:\n");
                printf("For months 1, 3, 5, 7, 8, ,10, 12 the maximum day to be inserted is 31.\n");
                printf("For months 4, 6, 9, 11 the maximum day to be inserted is 30.\n");
                printf("For month 2 the maximum day to be inserted is 28 for normal year and 29 for a bisect year.\n");
                printf("The maximum number to be inserted for month is 12.\n");
                printf("The maximum year to be inserted must be between and inclusive 2020 and 2040.\n");
                printf("Please try again!\n");
                scanf(" %d%d%d", &d.day, &d.month, &d.year);
                fflush(stdin);   
            }

            if (d.year % 4 == 0)
                   {    
                       while ( d.day > 29){
                        printf("This is an leap year!\n");
                        printf("Try again by inserting a day smaller than 30!\n");
                        scanf(" %d%d%d", &d.day, &d.month, &d.year);
                        fflush(stdin);
                       }
                    }
            else if (d.year % 4 != 0)
                    {
                        while ( d.day > 28){
                        printf("Try again by inserting a day smaller than 29!\n");
                        scanf(" %d%d%d", &d.day, &d.month, &d.year);
                        fflush(stdin);
                        }
                    }
            printf("The %d persone infected was on %d/%d/%d with the code number %d.\n\n", count, d.day, d.month, d.year, registered_codes[count - 1]);

            date_registered[count-1].day=d.day;
            date_registered[count-1].month=d.month;
            date_registered[count-1].year=d.year;
        }
        else if (choice == '3')
        {
            alarm_rings = option3(alarm);
            printf("Tryck 0 to stop the alarm: ");
            scanf(" %c", &stop_alarm);

            while (stop_alarm != '0')
            {
                printf("Try again by pressing 0: ");
                scanf(" %c", &stop_alarm);
            }
            if (stop_alarm == '0')
            {
                printf("\nYou stoped the alarm by pressing %c", stop_alarm);
                alarm_rings = 0;
                printf("\n");
            }
        }

        else if (choice == '4')
        {
            printf("This is a list with all the codes from all the persones infected you met:\n");
             printf("\n---------------------------------------------------------\n");
            printf("|\tPersone\t|\tCode\t|\tDate\t\t|\n");
            printf("---------------------------------------------------------\n");
            for (int i = 0; i < count; i++)
            {
               printf("|\t%d\t|\t%d\t|\t", i + 1, registered_codes[i]);
               printf("%d/%d/%d\t|\n", date_registered[i].day, date_registered[i].month, date_registered[i].year); 
               printf("---------------------------------------------------------\n");
            }
        }

        else if (choice == '5')
        {
            printf("You chose to close the app!\n");
            printf("The app is still on!\n");
            printf("Stay safe friend!");
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
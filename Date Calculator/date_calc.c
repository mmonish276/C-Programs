//Program that can give you the date (month & day) of the year (leap or not) or the day in the 365-day year

#include <stdio.h>
#include <stdbool.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static int daytab_nonleap[13] = 
{
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31  //days per month in non-leap yr
};

static int daytab_leap[13] =
{
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31    //days per month in leap yr
};
 
int main()
{
    int month_num;
    int year_num;
    int year_day;
    int day;
    int choice;

    int month;
    int day_ofMONTH;

    printf("Choice (day of year (1) or month_day (2)): ");
    scanf("%i", &choice);


    if (choice == 1)
    {
        printf("# of month: ");
        scanf("%i", &month_num);

        printf("# of year: ");
        scanf("%i", &year_num);

        printf("# of day: ");
        scanf("%i", &day);

        int day_ofYR= day_of_year(year_num, month_num, day);
        printf("Day of year: %i\n", day_ofYR);
    
    }
    
    else if (choice ==2)
    {
        printf("# of year day: ");
        scanf("%i", &year_day);

        printf("# of year: ");
        scanf("%i", &year_num);

        month_day(year_num, year_day, &month, &day_ofMONTH);
        printf("Month: %i, Day: %i\n", month, day_ofMONTH);
    }
}

 /* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    bool leap;
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        leap = true;

    if (leap == true)
        for (int i = 1; i < month; i++)
            day += *(daytab_leap + i);
    else
        for (int i = 1; i < month; i++)
            day += *(daytab_nonleap + i);
    
    return day;
}

 /* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    bool leap = false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        leap = true;

    // check if yearday is within the valid range
    if (yearday < 1 || yearday > 365 + (leap ? 1 : 0)) 
    {
        *pmonth = -1; // Invalid month
        *pday = -1;   // Invalid day
        return;
    }

    if (leap = true)
    {
        int i;
        for (i = 1; yearday > *(daytab_leap + i); i++) 
        {
            yearday -= *(daytab_leap + i);   //daytab_leap/daytab_nonleap is ptr to start of array --> *(+i) deref. i-th element
        }
        *pmonth = i;
        *pday = yearday;
    }

    else
    {
        int i;
        for (i = 1; yearday > *(daytab_nonleap + i); i++) 
        {
            yearday -= *(daytab_nonleap + i);
        }
        *pmonth = i;
        *pday = yearday;
    }
}

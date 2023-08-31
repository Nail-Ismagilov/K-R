#include <stdio.h>

int const * daytab[] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int my_day_of_year(int year, int month, int day)
{
    int leap;
    int *p;
    leap = ((year%4 == 0 && year%100 !=0) || (year % 400 == 0));
    p = &daytab[leap][1];
    // Error handling
    if (month > 12 || month == 0 || day > daytab[leap][month])
        return 0;
    
    for (;month > 0; --month)
        day += *p++;
    return day;
}

void my_month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    int *p;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    
    p = &daytab[leap][1];
    //Error handling
    if (leap && yearday <= 366 || yearday <= 365){  
        int i = 0;
        while (yearday > *p)
        {
            yearday -= *p++;
            i++;
        }
        *pday = yearday;
        *pmonth = i;
    }
    printf("\n*pday: %d, *pmonth: %d\n", *pday, *pmonth);
}
#include <stdio.h>

char const daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    int *p;
    leap = ((year%4 == 0 && year%100 !=0) || (year % 400 == 0));
    p = &daytab[leap][1];
    // Error handling
    if (month > 12 || month == 0 || day > daytab[leap][month])
        return 0;
    
    for (;month > 0; --m onth)
        day += *p++;
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    int *p;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    
    p = &daytab[leap][1];
    //Error handling
    if (leap && yearday <= 366 || yearday <= 365){   
        while (yearday > *p)
        {
            yearday -= *p++;
        }
        *pday = yearday;
        *pmonth = i;
    }
    printf("\n*pday: %d, *pmonth: %d\n", *pday, *pmonth);
}
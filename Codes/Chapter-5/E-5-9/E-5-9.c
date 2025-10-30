/*

Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
indexing.

*/

#include<stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int ,int ,int );

void month_day(int , int , int *, int *);

int main()
{
    int year,month,day,month_of_year,day_of_month;

    printf("Enter a Date in DD\\MM\\YYYY format:\n");
    scanf("%d %d %d",&day,&month,&year);

    printf("\nEntered Date is %d\\%d\\%d\n",day,month,year);

    printf("\nConverting the Entered Date into Day of Year...\n");
    
    int ans=day_of_year(year,month,day);

    printf("\nThe Entered Date corresponds to %d Day of that year",ans);

    printf("\nEnter a Year:\n");
    scanf("%d",&year);

    printf("\nEnter a day of that year:\n");
    scanf("%d",&day);

    printf("\nEntered Year: %d and Day of That Year: %d\n",year,day);

    printf("\nThe Month and Day of That Year that Year and Day of Year Corresponds to are:\n");

    month_day(year,day,&month_of_year,&day_of_month);

    printf("\nMonth: %d, Day: %d\n",month_of_year,day_of_month);

    return 0;

}


int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;
    int total;

    /* compute leap flag robustly */
    leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0;

    /* validate month */
    if (month < 1 || month > 12) {
        printf("\nEntered Month: %d is Invalid\n", month);
        return -1;
    }

    /* validate day for the given month */
    if (day < 1 || day > daytab[leap][month]) {
        printf("\nEntered Day: %d Invalid for Month: %d\n", day, month);
        return -1;
    }

    /* sum days of months before 'month' using pointers */
    total = day;
    /* pointer to first month (index 1) of correct leap row */
    p = &daytab[leap][1];
    /* advance p through months 1 .. month-1 adding values */
    for (; p < &daytab[leap][month]; ++p)
        total += (int)*p;

    return total;
}


void month_day(int year, int year_day, int *pmonth, int *pday)
{
    int leap;
    char *p;
    int month = 1;
    int maxday;

    if (pmonth == NULL || pday == NULL) {
        printf("\nmonth_day: output pointers must not be NULL\n");
        return;
    }

    /* compute leap flag robustly */
    leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0;

    maxday = leap ? 366 : 365;
    if (year_day < 1 || year_day > maxday) {
        printf("\nInvalid Day of Year Entered: %d\n", year_day);
        return;
    }

    /* pointer to first month (index 1) */
    p = &daytab[leap][1];

    /* subtract month lengths until we find the month containing year_day */
    while (year_day > (int)*p && month < 12) {
        year_day -= (int)*p;
        ++p;
        ++month;
    }

    /* now month points at the correct month length and year_day is the day within that month */
    *pmonth = month;
    *pday = year_day;
}


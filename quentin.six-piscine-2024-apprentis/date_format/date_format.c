#include "date_format.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

size_t my_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return i;
}

char *date_format(const char *format)
{
    if (my_strlen(format) != 5)
        return NULL;
    char *date = malloc(50);
    int i = 0;
    size_t j = 0;
    time_t timestamp = time(NULL);
    struct tm *timeInfos = gmtime(&timestamp);
    while (format[i])
    {
        if (format[i] == 'Y')
            sprintf((date + j), "%04d", timeInfos->tm_year + 1900);
        else if (format[i] == 'D')
            sprintf((date + j), "%02d", timeInfos->tm_mday);
        else if (format[i] == 'M')
            sprintf((date + j), "%02d", timeInfos->tm_mon + 1);
        else
            sprintf((date + j), "%c", format[i]);
        i++;
        j = my_strlen(date);
    }
    return date;
}

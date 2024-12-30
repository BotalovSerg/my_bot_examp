#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef struct
{
    char fname[100];
    char old;
    char stag;
    int salary;
    double efs;
} PERSON;

void fill_data(PERSON *person, char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    char *p = strchr(format, '#');
    format = p;
    ++format;
    while (format != NULL)
    {
        // p = strchr(format, '#');
        // int max_copy = (strlen(format) - (p ? strlen(p) : 0));
        // char tmp = 0;
        // strncpy(tmp, format, 1);
        if (format[0] == 'o')
        {
            person->old = va_arg(arg, int);
        }
        else if (format[0] == 'e')
        {
            person->efs = va_arg(arg, double);
        }
        else if (format[0] == 's')
        {
            person->salary = va_arg(arg, int);
        }
        else if (format[0] == 'g')
        {
            person->stag = va_arg(arg, int);
        }
        else if (format[0] == 'f')
        {
            strcpy(person->fname, va_arg(arg, char *));
        }
        p = strchr(format, '#');

        if (p == NULL)
        {
            break;
        }

        format = p;
        ++format;
    }

    va_end(arg);
}

int main(void)
{
    PERSON p;
    char s_f[] = "  ,#o #e#s. #f";

    fill_data(&p, s_f, 38, 99.9, 150000, "Botalov");

    return 0;
}
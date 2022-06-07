# include <time.h>
# include <stdio.h>
# include <windows.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int utc(void)
{
    time_t t;
    struct tm *tmp;

    t = time(NULL);
    tmp = localtime(&t);

    return t;
}

int date(void)
{
    time_t t;
    struct tm *tmp;

    t = time(NULL);
    tmp = localtime(&t);

    printf("%d-%d-%d %d:%d:%d\n", tmp->tm_year + 1900, tmp->tm_mon + 1, tmp->tm_mday, tmp->tm_hour, tmp->tm_min, tmp->tm_sec);
}


int sleep(int milliseconds)
{
    Sleep(milliseconds);
    return 0;
}

int fps(int fps)
{
    return 1000 / fps;
}
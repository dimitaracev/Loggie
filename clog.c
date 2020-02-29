#include "clog.h"


typedef unsigned int uint;

struct logger
{
    FILE **fds;
    uint files;
    
} Logger;

void init_()
{
    Logger.fds = (FILE **)malloc(sizeof(FILE *) * 1);
    *(Logger.fds) = (FILE *)malloc(sizeof(FILE) * 1);
    Logger.files = 0;
}

static const char *levels[] = {"LOG", "WARN", "INFO", "ERROR"};

static char *timestamp_()
{
    char *buf = malloc(sizeof(char) * 32);
    time_t t = time(NULL);
    struct tm *timeinfo = localtime(&t);
    sprintf(buf, "[%02d/%02d/%04d  %02d:%02d:%02d]", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min,timeinfo->tm_sec);
    return buf;
}

void stick_(FILE *file)
{
    Logger.fds[Logger.files] = file;
    Logger.fds = realloc(Logger.fds, sizeof(FILE *) * ++Logger.files);
}

void log_(char *format, ...)
{
    va_list args;
    va_start(args, format);
    prepare_(LOG, format, args);
    va_end(args);
}

void warn_(char *format, ...)
{
    va_list args;
    va_start(args, format);
    prepare_(WARN, format, args);
    va_end(args);
}
void info_(char *format, ...)
{
    va_list args;
    va_start(args, format);
    prepare_(INFO, format, args);
    va_end(args);
}
void error_(char *format, ...)
{
    va_list args;
    va_start(args, format);
    prepare_(ERROR, format, args);
    va_end(args);
}

void prepare_(enum level _level, char *format, va_list args)
{
    fprintf(stderr, "%s %s : ", timestamp_() ,levels[_level]);
    vfprintf(stderr, format, args);
    fprintf(stderr, "\n");
    fflush(stderr);
    if(Logger.files > 0)
    {
        for(int i = 0; i < Logger.files; i++)
        {
            fprintf(Logger.fds[i], "%s %s :", levels[_level], timestamp_());
            vfprintf(Logger.fds[i], format, args);
            fprintf(Logger.fds[i], "\n");
            fflush(Logger.fds[i]);
        }
    }
}
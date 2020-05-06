#ifndef LOGC_H
#define LOGC_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum level
{
    LOG,
    WARN,
    INFO,
    ERROR
};

struct logger
{
    FILE **fds;
    int files;

} Logger;

static int initialized = 0;

#define Init()                                                \
    {                                                         \
        if (!initialized)                                     \
        {                                                     \
            Logger.fds = (FILE **)malloc(sizeof(FILE *) * 1); \
            *(Logger.fds) = (FILE *)malloc(sizeof(FILE) * 1); \
            Logger.files = 0;                                 \
            initialized = 1;                                  \
        }                                                     \
    }

#define Connect(logger)                                        \
    {                                                          \
        if (!initialized)                                      \
            Init();                                            \
        Logger.fds[Logger.files] = logger;                     \
        Logger.fds = realloc(Logger.fds,                       \
                             sizeof(FILE *) * ++Logger.files); \
    }

#define Clean()                                \
    {                                          \
        for (int i = 0; i < Logger.files; i++) \
        {                                      \
            free(Logger.fds[i]);               \
        }                                      \
        free(Logger.fds);                      \
    }

#define Log(format, ...)                   \
    {                                      \
        PRINT("LOG", format, __VA_ARGS__); \
    }

#define Warn(format, ...)                   \
    {                                       \
        PRINT("WARN", format, __VA_ARGS__); \
    }

#define Info(format, ...)                   \
    {                                       \
        PRINT("INFO", format, __VA_ARGS__); \
    }

#define Error(format, ...)                   \
    {                                        \
        PRINT("ERROR", format, __VA_ARGS__); \
    }

#define DOMAGIC(OUT, Level, format, ...)                                    \
    {                                                                       \
        time_t t = time(NULL);                                              \
        struct tm *timeinfo = localtime(&t);                                \
        fprintf(OUT, "[%02d:%02d:%02d  %02d/%02d/%04d]", timeinfo->tm_hour, \
                timeinfo->tm_min, timeinfo->tm_sec, timeinfo->tm_mday,      \
                timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);            \
        fprintf(OUT, " [FILE: %s | LINE: %d] ", __FILE__, __LINE__);        \
        fprintf(OUT, "%s  :  ", Level);                                     \
        fprintf(OUT, format, __VA_ARGS__);                                  \
        fprintf(OUT, "\n");                                                 \
    }

#define PRINT(Level, format, ...)                               \
    {                                                           \
        DOMAGIC(stderr, Level, format, __VA_ARGS__);            \
        for (int i = 0; i < Logger.files; i++)                  \
        {                                                       \
            DOMAGIC(Logger.fds[i], Level, format, __VA_ARGS__); \
        }                                                       \
    }
#endif
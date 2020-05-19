#ifndef LOGGIE_H
#define LOGGIE_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>

struct logger
{
    bool initialized = false;
    bool silent = false;
    FILE **fds;
    int files;

} Logger;

#define StderrLogging(silentBool)    \
    {                                \
        Logger.silent = !silentBool; \
    }

#define Init()                                                \
    {                                                         \
        if (!Logger.initialized)                              \
        {                                                     \
            Logger.fds = (FILE **)malloc(sizeof(FILE *) * 1); \
            Logger.files = 0;                                 \
            Logger.initialized = true;                        \
        }                                                     \
    }

#define Connect(filename)                                               \
    {                                                                   \
        assert(filename != NULL);                                       \
        FILE *fd = fopen(filename, "a");                                \
        if (!Logger.initialized)                                        \
            Init();                                                     \
        Logger.fds[Logger.files] = fd;                                  \
        Logger.fds = (FILE **)realloc(Logger.fds,                       \
                                      sizeof(FILE *) * ++Logger.files); \
    }

#define Clean()                                \
    {                                          \
        for (int i = 0; i < Logger.files; i++) \
        {                                      \
            fflush(Logger.fds[i]);             \
            free(Logger.fds[i]);               \
        }                                      \
        free(Logger.fds);                      \
    }

#define Log(format, ...)                     \
    {                                        \
        DoPrint("LOG", format, __VA_ARGS__); \
    }

#define Warn(format, ...)                     \
    {                                         \
        DoPrint("WARN", format, __VA_ARGS__); \
    }

#define Info(format, ...)                     \
    {                                         \
        DoPrint("INFO", format, __VA_ARGS__); \
    }

#define Error(format, ...)                     \
    {                                          \
        DoPrint("ERROR", format, __VA_ARGS__); \
    }

#define Print(stream, Level, format, ...)                                          \
    {                                                                              \
        time_t t = time(NULL);                                                     \
        struct tm *timeinfo = localtime(&t);                                       \
        fprintf(stream, "[%02d:%02d:%02d  %02d/%02d/%04d] [%s::%d] %-5s : ",       \
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,             \
                timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, \
                __FILE__, __LINE__, Level);                                        \
        fprintf(stream, format, __VA_ARGS__);                                      \
        fprintf(stream, "\n");                                                     \
    }

#define DoPrint(Level, format, ...)                           \
    {                                                         \
        if (!Logger.silent)                                   \
            Print(stderr, Level, format, __VA_ARGS__);        \
        for (int i = 0; i < Logger.files; i++)                \
        {                                                     \
            Print(Logger.fds[i], Level, format, __VA_ARGS__); \
        }                                                     \
    }
#endif
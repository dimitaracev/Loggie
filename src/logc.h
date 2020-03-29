#ifndef LOGC_H
#define LOGC_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Log(format, ...) log_(__FILE__, __LINE__, format __VA_OPT__(, ) __VA_ARGS__)
#define Info(format, ...) info_(__FILE__, __LINE__, format __VA_OPT__(, ) __VA_ARGS__)
#define Warn(format, ...) warn_(__FILE__, __LINE__, format __VA_OPT__(, ) __VA_ARGS__)
#define Error(format, ...) error_(__FILE__, __LINE__, format __VA_OPT__(, ) __VA_ARGS__)
#define Stick(file) stick_(file)

enum level
{
    LOG,
    WARN,
    INFO,
    ERROR
};

void init_();
static void print_(enum level _level, char *format, char *file, int line, va_list args);
static char *timestamp_();

void stick_(FILE *file);
void log_(char *file, int line, char *format, ...);
void warn_(char *file, int line, char *format, ...);
void info_(char *file, int line, char *format, ...);
void error_(char *file, int line, char *format, ...);

#endif
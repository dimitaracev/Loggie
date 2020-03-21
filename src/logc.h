#ifndef LOGC_H
#define LOGC_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum level {
    LOG, WARN, INFO, ERROR
};

void init_();
static void print_(enum level _level, char* format, va_list args);
static char* timestamp_();

void stick_(FILE *file);
void log_(char* format, ...);
void warn_(char* format, ...);
void info_(char* format, ...);
void error_(char* format, ...);


#endif
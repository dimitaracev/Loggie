#ifndef LOGC_H
#define LOGC_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Log(format, ...) log_(format, __FILE__, __LINE__, ##__VA_ARGS__)
#define Info(format, ...) info_(format, __FILE__, __LINE__, ##__VA_ARGS__)
#define Warn(format, ...) warn_(format, __FILE__, __LINE__, ##__VA_ARGS__)
#define Error(format, ...) error_(format, __FILE__, __LINE__, ##__VA_ARGS__)

enum level {
    LOG, WARN, INFO, ERROR
};

void init_();
static void print_(enum level _level, char* format,char* file, int line, va_list args);
static char* timestamp_();

void stick_(FILE *file);
void log_(char* format, char* file, int line, ...);
void warn_(char* format, char* file, int line, ...);
void info_(char* format, char* file, int line, ...);
void error_(char* format, char* file, int line, ...);


#endif
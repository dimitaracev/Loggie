# CLog
A minimal C logging library

# Usage

 ```c

 #include "clog.h"
 #include <stdio.h>

 int main(void)
 {
    // Print to stderr
    log_("Hello World");
    warn_("Warning World");
    info_("Info World");
    error_("Error World");

    // Add file to print to
    // Must call init_() first to initialize file array
    init_();
    FILE *stick = fopen("sticked", "a");
    stick_(stick);
 } 

 ```

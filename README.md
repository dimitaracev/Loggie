# CLog
A minimal C logging library

# Usage

 ```c

 #include "clog.h"
 #include <stdio.h>

 int main(void)
 {
    // Prints to stderr and/or to file descriptors
    log_("Hello World");
    warn_("Warning World");
    info_("Info World");
    error_("Error World");

    // Add file to print to
    // Optional : it can be initialized with stick_
    // Initializes the file descriptor array
    init_();
    // File descriptor
    FILE *stick = fopen("sticked", "a");
    // Adds file to log logs to
    stick_(stick);
 } 

 ```

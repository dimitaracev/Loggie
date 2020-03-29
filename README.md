# Log C
A minimal C logging library

# Usage

 ```c

 #include "src/logc.h"
 #include <stdio.h>

 int main(void)
 {
    // Prints to stderr and/or to file descriptors
    Log("Hello World");
    Warn("Warning World");
    Info("Info World");
    Error("Error World");

    // File descriptor
    FILE *stick = fopen("sticked", "a");
    // Adds file to log to
    stick_(stick);
 } 

 ```

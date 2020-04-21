# Log C
<<<<<<< HEAD

A minimal C logging library
=======
>>>>>>> 4465e004e98c2601f1a0f7fc17f3ea33e7b1ef88

# Usage

```c

#include "src/logc.h"

int main(void)
{
   // Prints to stderr and/or to connected file descriptors
   Log("Hello World");
   Warn("Warning World");
   Info("Info World");
   Error("Error World");

<<<<<<< HEAD
   // Create a file descriptor
   FILE *connector = fopen("connected", "a");
   // Connect file descriptor to logger
   Connect(connector);
}

```
=======
    // File descriptor
    FILE *stick = fopen("sticked", "a");
    // Adds file to log to
    Stick(stick);
    // free all file descriptors
    Close();
 } 
 ```
>>>>>>> 4465e004e98c2601f1a0f7fc17f3ea33e7b1ef88

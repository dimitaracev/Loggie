# Loggie

A minimal C logging library

# Usage

```c

#include "src/loggie.h"

int main(void)
{
   // Prints to stderr and/or to connected file descriptors
   Log("Hello World");
   Warn("Warning World");
   Info("Info World");
   Error("Error World");

   // Create file descriptor and connect to logger
   Connect("loggie.log");
   // Clean up memory
   Clean();
}

```

# Loggie
Loggie is a simple, header file only logging library. It can log to console as well as files.

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

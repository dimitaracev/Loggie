# Log C

A minimal C logging library

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

   // Create a file descriptor
   FILE *connector = fopen("connected", "a");
   // Connect file descriptor to logger
   Connect(connector);
}

```

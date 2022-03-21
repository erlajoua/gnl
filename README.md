## Get_next_line

### Description ✨
Get_next_line is a 42 project written in C.
This function at each call will retrieve a new line from a certain fd.
The fd can be a file to read or the standard input.
A line is finished when it meets a ``\n``.

The parameters of the function are:
- ``int fd`` is the file descriptor of the file or the stdin where the functions read.
- ``char **line`` is a pointer to the line that will be allocated with the newline.

### Main purpose :page_facing_up:
One of the goals of this project is to code this function in only **2 files**.
A bonus goal was to use only one static variable.
The static variable is used to store the characters read by read, but being after the `\n`, and so these characters will be used the next time get_next_line is called.


### How to use :rocket:
A BUFFER_SIZE must be defined. Thats the number of bytes read at each `read`'s call.
you can define it in the ``get_next_line.h`` file as:
```h
# define BUFFER_SIZE 64
```
_(or define it as a flag -D during the compilation.)_
In this example the `read` function is going to be called, reading **64** by **64** bytes each call.

Then you can add these 3 files to your project, include the ``get_next_line.h` on your own files:
```c
#include "get_next_line.h"
```
and use the function `get_next_line` to read line by line your files!

#### _Example of use:_
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int main()
{
    char *line = NULL;
    while (get_next_line(0, &line) > 0)
    {
        printf("->%s\n", line);
        free(line);
    }
    printf("->%s\n", line);
    free(line);
    return (0);
}
```
Write on the **Standard Input**, and press `Ctrl+D` to stop

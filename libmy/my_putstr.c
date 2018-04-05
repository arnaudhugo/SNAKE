#include "../include/snake.h"

void    my_putstr(char * str) 
{
    int end;

    end = 0;
    while (*(str + end) != '\0') {
        char str_end;

        str_end = *(str + end);
        write(1, &str_end, 1);
        end = end + 1;
    }
}
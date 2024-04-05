/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** print a string
*/

#include <unistd.h>
#include "../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

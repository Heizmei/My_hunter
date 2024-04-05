/*
** EPITECH PROJECT, 2023
** main
** File description:
** main for my_hunter
*/
#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        background();
    }
    if (ac > 1 && (av[1][0] == '-' && av[1][1] == 'h')) {
        my_putstr("that a duck hunt with a space ship \n");
        my_putstr("left click for kill the space ship \n");
    } else {
        return 0;
    }
}

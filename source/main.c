/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** main
*/

#include "my_hunter.h"

int main(int argc, char const *argv[])
{
    if (argc > 1 && (argv[1][0] == '-' && argv[1][1] == 'h')) {
        my_putstr("a duck hunt but the duck is a asteroid\n");
        my_putstr("left click for explosed the asteroid\n");
        return 0;
    }
    if (argc == 1) {
        init_value();
        return 0;
    }
    return 84;
}

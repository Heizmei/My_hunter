/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** free_funct
*/

#include "my_hunter.h"

int free_funct(hunt_t *hunt)
{
    free(hunt->planet);
    free(hunt);
    return 0;
}

/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** while_clock
*/

#include "my_hunter.h"

void while_clock(hunt_t *hunt)
{
    while (sfTime_asMilliseconds(
        sfClock_getElapsedTime(hunt->clock_move)) > 1) {
        while_asteroid(hunt);
        sfClock_restart(hunt->clock_move);
    }
    while_anim_planet(hunt);
}

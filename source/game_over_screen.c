/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** game_over_screen
*/

#include "my_hunter.h"

void game_over(hunt_t *hunt)
{
    if (hunt->defeat == 4) {
        sfRenderWindow_drawSprite(hunt->window, hunt->game_over->game_over,
            NULL);
    }
}

/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** disp_sprite
*/

#include "my_hunter.h"

void display_ship(hunt_t *hunt)
{
    sfRenderWindow_drawSprite(hunt->window, hunt->background, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->planet->galaxy, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->planet->planet, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->planet->black_ho, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->ship->ship_1, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->asteroid->asteroid,
        NULL);
}

int disp_sprite(hunt_t *hunt)
{
    if (hunt->defeat >= 4) {
        sfRenderWindow_drawSprite(hunt->window, hunt->game_over->game_over,
            NULL);
        if (sfKeyboard_isKeyPressed(sfKeyR) == true) {
            hunt->defeat = 0;
        }
    } else {
        display_ship(hunt);
    }
    return 0;
}

/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** event_while
*/

#include "my_hunter.h"

void hit_ship(hunt_t *hunt)
{
    sfVector2f pos = sfSprite_getPosition(hunt->asteroid->asteroid);
    sfFloatRect scale_ship = sfSprite_getGlobalBounds(hunt->ship->ship_1);

    if (pos.y <= 956 && pos.y >= 444)
        if (pos.x >= scale_ship.left)
            hunt->defeat = 4;
}

int event_while(hunt_t *hunt)
{
    while (sfRenderWindow_pollEvent(hunt->window, hunt->event)) {
        event_start(hunt);
        click_event(hunt);
        if (hunt->event->type == sfEvtClosed)
            sfRenderWindow_close(hunt->window);
    }
    return 0;
}

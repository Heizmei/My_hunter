/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** click_event
*/

#include "my_hunter.h"

void event_start(hunt_t *hunt)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(hunt->window);
    sfFloatRect hitbox = sfSprite_getGlobalBounds(hunt->menu->menu_sprite);

    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        hunt->scene = 2;
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (mouse.x >= hitbox.left && mouse.x <= hitbox.left + hitbox.width
            && mouse.y >= hitbox.top && mouse.y <= hitbox.top +
                                                   hitbox.height) {
            hunt->scene = 2;
        }
    }
}

void click_event(hunt_t *hunt)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(hunt->window);
    sfFloatRect hitbox = sfSprite_getGlobalBounds(hunt->asteroid->asteroid);
    int random = (rand() % 1020);

    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (mouse.x >= hitbox.left && mouse.x <= hitbox.left + hitbox.width
            && mouse.y >= hitbox.top && mouse.y <= hitbox.top +
            hitbox.height) {
            hunt->score++;
            hunt->asteroid->scale.y = random;
            hunt->asteroid->scale.x = 0;
            sfSprite_setPosition(hunt->asteroid->asteroid,
                hunt->asteroid->scale);
        }
    }
}

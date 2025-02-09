/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** menu
*/

#include "my_hunter.h"

void disp_menu(hunt_t *hunt)
{
    sfRenderWindow_drawSprite(hunt->window, hunt->back_menu, NULL);
    sfRenderWindow_drawSprite(hunt->window, hunt->menu->menu_sprite, NULL);
}

void set_menu(hunt_t *hunt)
{
    sfIntRect rect_pla = {320, 140, 145, 80};
    sfVector2f position = {800, 540};
    sfVector2f scale = {2, 2};

    hunt->menu = malloc(sizeof(menu_t));
    if (hunt->menu == NULL)
        return;
    hunt->menu->text_menu_sprite = sfTexture_createFromFile(MENU_BUTTON, NULL);
    hunt->menu->menu_sprite = sfSprite_create();
    sfSprite_setPosition(hunt->menu->menu_sprite, position);
    sfSprite_setTexture(hunt->menu->menu_sprite, hunt->menu->text_menu_sprite,
                        sfTrue);
    sfSprite_setTextureRect(hunt->menu->menu_sprite, rect_pla);
    sfSprite_setScale(hunt->menu->menu_sprite, scale);
}

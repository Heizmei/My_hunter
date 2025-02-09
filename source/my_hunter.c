/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** my_hunter
*/

#include "my_hunter.h"

int init_background(hunt_t *hunt)
{
    if (hunt == NULL)
        return 84;
    hunt->tex_back_menu = sfTexture_createFromFile(BACKGROUND_MENU,
        NULL);
    hunt->back_menu = sfSprite_create();
    hunt->back = sfTexture_createFromFile(BACKGROUND, NULL);
    hunt->background = sfSprite_create();
    sfSprite_setTexture(hunt->back_menu, hunt->tex_back_menu, sfTrue);
    sfSprite_setTexture(hunt->background, hunt->back, sfTrue);
    return 0;
}

int init_value(void)
{
    struct hunt_s *hunt = malloc(sizeof(hunt_t));
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "SFML window",
        sfClose, NULL);
    sfEvent event;

    init_background(hunt);
    hunt->event = &event;
    hunt->defeat = 0;
    hunt->window = window;
    hunt->clock_anim = sfClock_create();
    hunt->clock_move = sfClock_create();
    hunt->clock_menu = sfClock_create();
    main_loop(hunt);
    free_funct(hunt);
    return 0;
}

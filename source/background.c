/*
** EPITECH PROJECT, 2023
** Background
** File description:
** Bacground for my_hunter
*/

#include "../include/my.h"

int background(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->clock = sfClock_create();
    create_window(game);
    create_sprite(game);
    error_case(game);
    while (sfRenderWindow_isOpen(game->game_window)) {
        event_manager(game);
        sprite_draw(game);
        movement(game);
        anim_clock(game);
        click_event(game);
        sfRenderWindow_clear(game->game_window, sfBlack);
    }
    sfSprite_destroy(game->sprite_back);
    sfSprite_destroy(game->sprite_proj);
    sfTexture_destroy(game->texture);
    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->game_window);
    return 0;
}

int error_case(game_t *game)
{
        if (!game->game_window)
            return 84;
        if (!game->texture)
            return 84;
        return 0;
}

void create_window(game_t *game)
{
    sfVideoMode mode = {1200, 700, 32};

    game->game_window = sfRenderWindow_create(mode, "window", sfClose, NULL);
}

/*
** EPITECH PROJECT, 2023
** Sprite
** File description:
** display the sprite
*/


#include "../include/my.h"

void create_sprite(game_t *game)
{
    game->sprite_ship.pos = (sfVector2f) {0, 680};
    game->sprite_back = sfSprite_create();
    game->sprite_proj = sfSprite_create();
    game->texture = sfTexture_createFromFile(texture_back, NULL);
    game->projectile = sfTexture_createFromFile(texture_proj, NULL);
    sfSprite_setTexture(game->sprite_back, game->texture, sfTrue);
    sfSprite_setTexture(game->sprite_proj, game->projectile, sfTrue);
    sfSprite_setPosition(game->sprite_proj, game->sprite_ship.pos);
    sfSprite_setTextureRect(game->sprite_proj, rect1);
}

void sprite_draw(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_window, game->sprite_back, NULL);
    sfRenderWindow_drawSprite(game->game_window, game->sprite_proj, NULL);
}

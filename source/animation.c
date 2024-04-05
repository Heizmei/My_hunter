/*
** EPITECH PROJECT, 2023
** animation
** File description:
** initialisation of the animation
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void anim_clock(game_t *game)
{
    sfIntRect rec = sfSprite_getTextureRect(game->sprite_proj);

    if (sfTime_asSeconds(sfClock_getElapsedTime(game->clock)) > 1) {
        if (rec.left == 0) {
            rec.left = 80;
        } else {
            rec.left = 0;
            }
        sfClock_restart(game->clock);
    }
    sfSprite_setTextureRect(game->sprite_proj, rec);
    sfRenderWindow_drawSprite(game->game_window, game->sprite_proj, NULL);
    sfRenderWindow_display(game->game_window);
}

void movement(game_t *game)
{
    int random = (rand() % 1120);
    float speed = 0.1;

    game->sprite_ship.pos.y -= speed;
    sfSprite_setPosition(game->sprite_proj, game->sprite_ship.pos);
    sfSprite_getPosition(game->sprite_proj);
    if (game->sprite_ship.pos.y <= 0) {
        game->sprite_ship.pos.y = 680;
        game->sprite_ship.pos.x = random;
        sfSprite_setPosition(game->sprite_proj, game->sprite_ship.pos);
    }
}

/*
** EPITECH PROJECT, 2023
** event_Manager
** File description:
** manage every project
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window.h>
#include <SFML/Window/Mouse.h>
#include "../include/my.h"

void event_manager(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->game_window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->game_window);
    }
}

void click_event(game_t *game)
{
    sfFloatRect hitbox;
    sfVector2i mous = sfMouse_getPositionRenderWindow(game->game_window);
    int random = (rand() % 1120);

    hitbox = sfSprite_getGlobalBounds(game->sprite_proj);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (mous.x >= hitbox.left && mous.x <= hitbox.left + hitbox.width
        && mous.y >= hitbox.top && mous.y <= hitbox.top + hitbox.height) {
        game->sprite_ship.pos.y = 680;
        game->sprite_ship.pos.x = random;
        sfSprite_setPosition(game->sprite_proj, game->sprite_ship.pos);
        }
    }
}

/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** set_texture
*/

#include "my_hunter.h"

void while_asteroid(hunt_t *hunt)
{
    float nb = 1;
    sfVector2f origin = {50, 50};
    int random = (rand() % 1020);

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(hunt->clock_move)) > 1) {
        if (hunt->asteroid->scale.x >= 1920) {
            hunt->defeat++;
            hunt->score = 0;
            hunt->asteroid->scale.x = 0;
            hunt->asteroid->scale.y = random;
        }
        hunt->asteroid->scale.x += 1;
        sfSprite_setOrigin(hunt->asteroid->asteroid, origin);
        sfSprite_rotate(hunt->asteroid->asteroid, nb);
        sfClock_restart(hunt->clock_move);
    }
    sfSprite_setPosition(hunt->asteroid->asteroid, hunt->asteroid->scale);
}

void while_anim_black_hole(hunt_t *hunt)
{
    sfIntRect rec_black_hole = sfSprite_getTextureRect(hunt->planet->black_ho);

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(hunt->clock_anim)) > 50) {
        if (rec_black_hole.left >= 13000) {
            rec_black_hole.left = 210;
        }
        rec_black_hole.left += 210;
    }
    sfSprite_setTextureRect(hunt->planet->black_ho, rec_black_hole);
}

void while_anim_planet(hunt_t *hunt)
{
    sfIntRect rec = sfSprite_getTextureRect(hunt->planet->planet);

    while (sfTime_asSeconds(sfClock_getElapsedTime(hunt->clock_anim)) > 0.1) {
        while_anim_black_hole(hunt);
        if (rec.left >= 7540) {
            rec.left = 110;
        } else {
            rec.left += 110;
        }
        sfClock_restart(hunt->clock_anim);
    }
    sfSprite_setTextureRect(hunt->planet->planet, rec);
}

static int set_black_hole(hunt_t *hunt)
{
    sfIntRect rect_pla = {0, 0, 190, 190};
    sfVector2f scale = {3, 3};

    hunt->planet->black_hole = sfTexture_createFromFile(BLACK_HOLE, NULL);
    hunt->planet->black_ho = sfSprite_create();
    hunt->planet->scale = (sfVector2f) {200, 100};
    sfSprite_setPosition(hunt->planet->black_ho, hunt->planet->scale);
    sfSprite_setTexture(hunt->planet->black_ho, hunt->planet->black_hole,
                        sfTrue);
    sfSprite_setTextureRect(hunt->planet->black_ho, rect_pla);
    sfSprite_setScale(hunt->planet->black_ho, scale);
    return 0;
}

static int set_game_over_screen(hunt_t *hunt)
{
    sfVector2f place = {600, 300};

    hunt->game_over = malloc(sizeof(game_over_screen_t));
    hunt->game_over->game_over = sfSprite_create();
    hunt->game_over->game_ovr = sfTexture_createFromFile(GAME_OVER, NULL);
    sfSprite_setTexture(hunt->game_over->game_over, hunt->game_over->game_ovr,
        sfTrue);
    sfSprite_setPosition(hunt->game_over->game_over, place);
    return 0;
}

static int init_asteroid(hunt_t *hunt)
{
    sfIntRect rect_ast = {0, 0, 100, 100};
    int nb = 0;

    hunt->score = nb;
    hunt->asteroid = malloc(sizeof(asteroid_t));
    hunt->asteroid->aster = sfTexture_createFromFile(ASTEROID, NULL);
    hunt->asteroid->asteroid = sfSprite_create();
    hunt->asteroid->scale = (sfVector2f) {0, 500};
    sfSprite_setTexture(hunt->asteroid->asteroid, hunt->asteroid->aster,
                        sfTrue);
    sfSprite_setTextureRect(hunt->asteroid->asteroid, rect_ast);
    return 0;
}

static void set_ship(hunt_t *hunt)
{
    sfVector2f position = {1700, 500};

    hunt->ship = malloc(sizeof(ship_t));
    if (hunt->ship == NULL)
        return;
    hunt->ship->text_laser = sfTexture_createFromFile(LASERS, NULL);
    hunt->ship->text_ship_1 = sfTexture_createFromFile(SHIP_1, NULL);
    hunt->ship->text_ship_2 = sfTexture_createFromFile(SHIP_2, NULL);
    hunt->ship->laser = sfSprite_create();
    hunt->ship->ship_1 = sfSprite_create();
    hunt->ship->ship_2 = sfSprite_create();
    sfSprite_setTexture(hunt->ship->laser, hunt->ship->text_laser, sfTrue);
    sfSprite_setTexture(hunt->ship->ship_1, hunt->ship->text_ship_1, sfTrue);
    sfSprite_setTexture(hunt->ship->ship_2, hunt->ship->text_ship_2, sfTrue);
    sfSprite_setPosition(hunt->ship->ship_1, position);
    sfSprite_setPosition(hunt->ship->laser, position);
}

static void set_galaxy(hunt_t *hunt)
{
    hunt->planet->text_galaxy = sfTexture_createFromFile(GALAXY, NULL);
    hunt->planet->galaxy = sfSprite_create();
    sfSprite_setTexture(hunt->planet->galaxy, hunt->planet->text_galaxy,
        sfTrue);
}

int set_texture(hunt_t *hunt)
{
    sfIntRect rect_pla = {0, 0, 110, 110};

    hunt->planet = malloc(sizeof(planet_t));
    if (hunt->planet == NULL)
        return 1;
    hunt->planet->text_planet = sfTexture_createFromFile(PLANET, NULL);
    hunt->planet->planet = sfSprite_create();
    hunt->planet->scale = (sfVector2f) {1000, 750};
    sfSprite_setPosition(hunt->planet->planet, hunt->planet->scale);
    sfSprite_setTexture(hunt->planet->planet, hunt->planet->text_planet,
        sfTrue);
    sfSprite_setTextureRect(hunt->planet->planet, rect_pla);
    set_galaxy(hunt);
    set_black_hole(hunt);
    init_asteroid(hunt);
    set_game_over_screen(hunt);
    set_ship(hunt);
    return 0;
}

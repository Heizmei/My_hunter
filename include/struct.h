/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** struct
*/

#ifndef STRUCT
    #define STRUCT
    #include "my_hunter.h"

typedef enum scene_s {
    MENU = 1,
    GAME = 2,
} scene_t;

typedef struct game_over_screen_s {
    sfSprite *game_over;
    sfTexture *game_ovr;
} game_over_screen_t;

typedef struct asteroid_s {
    sfSprite *asteroid;
    sfTexture *aster;
    sfVector2f scale;
} asteroid_t;

typedef struct ship_s {
    sfVector2f pos_laser;
    sfSprite *laser;
    sfTexture *text_laser;
    sfTexture *text_ship_1;
    sfSprite *ship_1;
    sfTexture *text_ship_2;
    sfSprite *ship_2;
} ship_t;

typedef struct planet_s {
    sfSprite *galaxy;
    sfTexture *text_galaxy;
    sfSprite *planet;
    sfSprite *black_ho;
    sfTexture *text_planet;
    sfTexture *black_hole;
    sfVector2f scale;
    sfIntRect rect_pla;
} planet_t;

typedef struct menu_s {
    sfSprite *back_menu;
    sfTexture *tex_back_menu;
    sfSprite *menu_sprite;
    sfTexture *text_menu_sprite;
    sfVector2f scale;
} menu_t;

typedef struct hunt_s {
    int score;
    int defeat;
    sfEvent *event;
    sfRenderWindow *window;
    sfTexture *tex_back_menu;
    sfSprite *back_menu;
    sfSprite *background;
    sfTexture *back;
    sfClock *clock_anim;
    sfClock *clock_move;
    sfClock *clock_menu;
    planet_t *planet;
    asteroid_t *asteroid;
    game_over_screen_t *game_over;
    menu_t *menu;
    scene_t scene;
    ship_t *ship;
} hunt_t;

#endif

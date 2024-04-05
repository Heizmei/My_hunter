/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h of my_hunter
*/

#ifndef LIST
    #define LIST
    #include <SFML/Config.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/Window.h>
    #include <stdlib.h>

static const char *texture_back = "./assets/fdc_my_hunter.jpg";
static const char *texture_proj = "./assets/space_ship.png";
static const sfIntRect rect1 = {80, 85, 80, 80};
static const sfIntRect rect = {0, 85, 80, 80};

typedef struct sprite_s {
    sfWindow *mouse;
    sfVector2f pos;
} sprite_t;

typedef struct game_s {
    sfRenderWindow *game_window;
    sfTexture *texture;
    sfTexture *projectile;
    sfSprite *sprite_back;
    sfSprite *sprite_proj;
    sfEvent event;
    sfClock* clock;
    sfVector2f *offset;
    sprite_t sprite_ship;
} game_t;

int background(void);
void sprite_draw(game_t *game);
void create_window(game_t *game);
int error_case(game_t *game);
void event_manager(game_t *game);
void create_sprite(game_t *game);
void anim_clock(game_t *game);
void anim_sprite(game_t *game);
void movement(game_t *game);
void click_event(game_t *game);
int my_putstr(char const *str);
void my_putchar(char c);
void mouse(void);


#endif /* !list */

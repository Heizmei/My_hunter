/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** my
*/

#ifndef LIST
    #define LIST
    #include "headers.h"
    #include "struct.h"
int main_loop(hunt_t *hunt);
int event_while(hunt_t *hunt);
int set_texture(hunt_t *hunt);
int disp_sprite(hunt_t *hunt);
int free_funct(hunt_t *hunt);
int init_value(void);
void while_anim_planet(hunt_t *hunt);
int my_putstr(char const *str);
void while_asteroid(hunt_t *hunt);
void click_event(hunt_t *hunt);
void while_clock(hunt_t *hunt);
void while_anim_black_hole(hunt_t *hunt);
void game_over(hunt_t *hunt);
void menu(hunt_t *hunt);
void set_menu(hunt_t *hunt);
void disp_menu(hunt_t *hunt);
void event_start(hunt_t *hunt);
void hit_ship(hunt_t *hunt);
#endif

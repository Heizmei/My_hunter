/*
** EPITECH PROJECT, 2024
** my_hunter_tek_1_re
** File description:
** main_loop
*/

#include "my_hunter.h"

void select_disp(hunt_t *hunt)
{
    if (hunt->scene == 1) {
        disp_menu(hunt);
    }
    if (hunt->scene == 2) {
        disp_sprite(hunt);
    }
}

void active_or_not(hunt_t *hunt)
{
    if (hunt->scene == 2) {
        while_clock(hunt);
    }
}

void select_text(hunt_t *hunt)
{
    if (hunt->scene == 1) {
        set_menu(hunt);
    }
    if (hunt->scene == 2) {
        set_texture(hunt);
    }
}

int main_loop(hunt_t *hunt)
{
    set_menu(hunt);
    set_texture(hunt);
    hunt->scene = 1;
    while (sfRenderWindow_isOpen(hunt->window)) {
        event_while(hunt);
        active_or_not(hunt);
        hit_ship(hunt);
        select_disp(hunt);
        sfRenderWindow_display(hunt->window);
        sfRenderWindow_clear(hunt->window, sfBlack);
    }
    return 0;
}

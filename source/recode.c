#include <SFML/Window/Event.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

sfRenderWindow *create_window(char *titre, int height, int width)
{
    sfVideoMode mode =
    sfWindow *window = sfRenderWindow_create(, titre, sfClose, sfTrue);
    return window;
}


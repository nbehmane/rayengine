/* Includes */
#include "game.h"

#define WIDTH  800
#define HEIGHT 450
#define FPS    30
#define TITLE  "Game"

int main()
{
    // All window parameters should be set before initalization.
    window_set_dimensions(WIDTH, HEIGHT);
    window_set_fps(FPS);
    window_set_title(TITLE);
    window_set_routines(game_init, game_update, game_draw);

    // Initialize the window.
    window_init();

    // Start the window.
    window_start();

    return 0;
}

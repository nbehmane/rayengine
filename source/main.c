/* Includes */
#include "headers/monitor.h"
#include "headers/window.h"
#include "headers/game.h"

Window game_window;

int main()
{
    game_window.display_index  = MONITOR_PRIMARY;
    game_window.title          = "Spacegame";

    game_window.height         = 450; 
    game_window.width          = 800; 

    game_window.init_routine   = game_init; 
    game_window.update_routine = game_update;
    game_window.draw_routine   = game_draw;

    game_window.init_arg       = NULL; 
    game_window.update_arg     = NULL; 
    game_window.draw_arg       = NULL; 

    game_window.fail_status    = 1;

    game_window.fps            = 30;

    window_init(&game_window);
    window_start(&game_window);

    return 0;
}

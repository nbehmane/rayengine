#ifndef _WINDOW_H
#define _WINDOW_H
#include <stdint.h>
#include "../../raylib/include/raylib.h"

#include "monitor.h"

#define WINDOW_DEFAULT_WIDTH  800
#define WINDOW_DEFAULT_HEIGHT 450

#define WINDOW_DEFAULT_FPS 30

typedef enum _window_status
{
    WINDOW_SUCCESS,
    WINDOW_FAILURE
} windowstat;

// Window routine function typedef.
typedef int (*Window_Routine)(int width, int height);

windowstat window_init();

windowstat window_start();

windowstat window_set_dimensions(int width, int height);

windowstat window_set_fps(int fps);

windowstat window_set_title(const char *title);

windowstat window_set_routines( Window_Routine init_routine,
                                Window_Routine update_routine,
                                Window_Routine draw_routine );

#endif // _WINDOW_H
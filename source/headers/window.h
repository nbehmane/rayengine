#ifndef _WINDOW_H
#define _WINDOW_H
#include <stdint.h>
#include "../../raylib/include/raylib.h"

typedef enum _window_status
{
    WINDOW_SUCCESS,
    WINDOW_FAILURE
} windowstat;

/*
 * @brief Window Structure
 */
typedef struct _window
{
    int width;
    int height;
    int display_index;
    const char* title;
    bool is_initialized;

    int (*init_routine)(void* arg, int width, int height);
    void* init_arg;

    int (*update_routine)(void* arg, int width, int height);
    void* update_arg;

    int (*draw_routine)(void* arg, int width, int height);
    void* draw_arg;

    int fail_status;

    int fps;

} Window; 

windowstat window_init(Window* window);
windowstat window_start(Window* window);

#endif // _WINDOW_H
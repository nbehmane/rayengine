/* Includes */
#include "headers/window.h"

/*
 * @brief Initializes Window.
 */
windowstat window_init(Window* window)
{
    if (window == NULL)
        return WINDOW_FAILURE;

    InitWindow(window->width, window->height, window->title);

    if (!IsWindowReady())
        return WINDOW_FAILURE;

    SetWindowMonitor(window->display_index);

    window->is_initialized = true;
    return WINDOW_SUCCESS;
}

/*
 * @brief Starts Window Loop.
 */
windowstat window_start(Window* window)
{
    bool has_init = false;
    int routine_status = 0;

    if (window->is_initialized != true)
        return WINDOW_FAILURE;

    /* Run the initialize routine. */
    if (!has_init)
    {
        if (window->fps == 0)
            window->fps == 30;
        SetTargetFPS(window->fps);

        if (window->init_routine != NULL) 
        {
            routine_status = window->init_routine(window->init_arg, window->width, window->height);
            if (routine_status == window->fail_status)
                goto close;
        }
        has_init = true;
    }

    while (!WindowShouldClose()) 
    {
        // Update 
        if (window->update_routine != NULL)
        {
            routine_status = window->update_routine(window->update_arg, window->width, window->height);
            if (routine_status == window->fail_status)
                goto close;
        }

        // Draw
        if (window->draw_routine != NULL)
        {
            routine_status = window->draw_routine(window->draw_arg, window->width, window->height);
            if (routine_status == window->fail_status)
                goto close;
        }
    }

close:   
    window->is_initialized = false;
    CloseWindow();    
    return WINDOW_SUCCESS;
}
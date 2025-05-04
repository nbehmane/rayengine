/***** Includes *****/
#include "headers/window.h"

/***** Typedefs *****/
typedef struct _window Window;

/***** Structures *****/
/*
 * @brief Window Structure
 */
struct _window
{   
    // Width of the window to be created.
    int width;
    // Height of the window to be created.
    int height;
    // FPS for the game.
    int fps;
    // Which display the window should be created.
    int display_index;
    // Title of the window to be created.
    const char* title;
    // Whether or not the window is initialized.
    bool is_initialized;
    // Initialization function BEFORE the window is created. 
    Window_Routine init_routine;
    // Game logic before the frame is drawn.
    Window_Routine update_routine;
    // The actual draw routine. Ran after the update_routine.
    Window_Routine draw_routine;
    // Custom fail status.
    int fail_status;


}; 

/***** Static Variables *****/
/*
 * @brief Main Window structure.
 *      Because raylib only allows for a single window context,
 *      we can make the window structure static, and only accessible
 *      to the library. Default values are set here.
 */
static Window window = {
    .display_index = MONITOR_PRIMARY,

    .width = WINDOW_DEFAULT_WIDTH,
    .height = WINDOW_DEFAULT_HEIGHT,
    .fps = WINDOW_DEFAULT_FPS,
    .title = "Default Window",

    .init_routine = NULL,
    .update_routine = NULL,
    .draw_routine = NULL,

    .is_initialized = false,
    .fail_status = -1
};

/***** Functions *****/
/*
 * ==== window_init ====
 */
windowstat window_init()
{
    InitWindow(window.width, window.height, window.title);

    if (!IsWindowReady())
        return WINDOW_FAILURE;

    SetWindowMonitor(window.display_index);

    window.is_initialized = true;
    return WINDOW_SUCCESS;
}

/*
 * ==== window_set_routines ====
 */
windowstat window_set_routines( Window_Routine init_routine,
                                Window_Routine update_routine,
                                Window_Routine draw_routine)
{
    windowstat wstatus = WINDOW_FAILURE;

    window.init_routine = init_routine;

    // If the update and draw routines are NULL, then what's the point. 
    if (update_routine != NULL &&
        draw_routine   != NULL)
    {
        window.update_routine = update_routine;
        window.draw_routine   = draw_routine;
        wstatus = WINDOW_SUCCESS;        
    }

    return wstatus;
}

/*
 * ==== window_set_title ====
 */
windowstat window_set_title(const char *title)
{
    windowstat wstatus = WINDOW_FAILURE;

    if (title != NULL)
    {
        window.title = title;

        wstatus = WINDOW_SUCCESS;
    }

    return wstatus;
}

/*
 * ==== window_set_fps ====
 */
windowstat window_set_fps(int fps)
{
    windowstat wstatus = WINDOW_FAILURE;

    // FPS can't be zero.
    if (fps != 0)
    {
        window.fps = fps;

        wstatus = WINDOW_SUCCESS;
    }

    return wstatus;
}

/*
 * ==== window_set_dimensions ====
 */
windowstat window_set_dimensions(int width, int height)
{
    windowstat wstatus = WINDOW_FAILURE;

    // Neither of the values can be zero.
    if (width != 0 && height != 0)
    {
        window.width = width;
        window.height = height;

        wstatus = WINDOW_SUCCESS;
    }

    return wstatus;
}

/*
 * ==== window_start ====
 */
windowstat window_start()
{
    bool has_init = false;
    int routine_status = 0;

    if (window.is_initialized != true)
        return WINDOW_FAILURE;

    if (!has_init)
    {
        // TODO: Change this to use a time delta instead of an FPS.
        if (window.fps == 0)
            window.fps == 30;

        SetTargetFPS(window.fps);

        // An initialization function is not required. 
        if (window.init_routine != NULL) 
        {
            routine_status = window.init_routine(window.width, window.height);
            if (routine_status == window.fail_status)
                goto close;
        }
        has_init = true;
    }

    while (!WindowShouldClose()) 
    {
        // Update the game logic (state).
        if (window.update_routine != NULL)
        {
            routine_status = window.update_routine(window.width, window.height);
            if (routine_status == window.fail_status)
                goto close;
        }

        // Draw to the screen.
        if (window.draw_routine != NULL)
        {
            routine_status = window.draw_routine(window.width, window.height);
            if (routine_status == window.fail_status)
                goto close;
        }
    }

close:   
    window.is_initialized = false;
    CloseWindow();    
    return WINDOW_SUCCESS;
}
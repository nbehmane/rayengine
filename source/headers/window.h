#ifndef _WINDOW_H
#define _WINDOW_H
/***** Includes *****/
#include <stdint.h>
#include "../../raylib/include/raylib.h"

#include "monitor.h"

/***** Defines *****/
#define WINDOW_DEFAULT_WIDTH  800
#define WINDOW_DEFAULT_HEIGHT 450

#define WINDOW_DEFAULT_FPS 30

/***** Typedefs *****/
typedef enum _window_status windowstat;

/***** Enumerations *****/
enum _window_status
{
    WINDOW_SUCCESS,
    WINDOW_FAILURE
};

/***** Functions *****/
// Window routine function typedef.
typedef int (*Window_Routine)(int width, int height);

/*
 * @brief Initializes Window.
 * 
 *      Should be ran right before starting the window and
 *      after setting window parameters.
 */
windowstat window_init();

/*
 * @brief Starts Window Loop.
 */
windowstat window_start();

/*
 * @brief Sets the dimensions of the window. 
 *  
 * @param width     Width of the window in  pixels.
 * @param height    Height of the window in pixels.
 */
windowstat window_set_dimensions(int width, int height);

/*
 * @brief Sets the FPS of the window. 
 *  
 * @param fps   FPS of the window.     
 */
windowstat window_set_fps(int fps);

/*
 * @brief Sets the title of the window. 
 *  
 * @param title   Title of the window.     
 */
windowstat window_set_title(const char *title);

/*
 * @brief Sets the routines of the window. 
 *  
 * @param init_routine     Ran once before update and draw routines.     
 * @param update_routine   Game logic code function.     
 * @param draw_routine     Routine to draw things to the string.     
 */
windowstat window_set_routines( Window_Routine init_routine,
                                Window_Routine update_routine,
                                Window_Routine draw_routine );

#endif // _WINDOW_H
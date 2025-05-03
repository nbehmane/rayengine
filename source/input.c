/* Headers */
#include "headers/input.h"

void input_init(Input* in)
{
    in->is_up    = false; 
    in->is_down  = false;
    in->is_left  = false;
    in->is_right = false;
}

void input_get(Input* in)
{
    if (IsKeyDown(in->up))
        in->is_up = true; 
    else
        in->is_up = false;

    if (IsKeyDown(in->down))
        in->is_down = true; 
    else
        in->is_down = false;

    if (IsKeyDown(in->left))
        in->is_left = true; 
    else
        in->is_left = false;

    if (IsKeyDown(in->right))
        in->is_right = true; 
    else
        in->is_right = false;
}
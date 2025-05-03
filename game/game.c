/* Headers */
#include <stdio.h>
#include "game.h"

static Game_State state;
static Input in;

int game_init(void* arg, int width, int height)
{
    /* Setup the default keys. */
    in.up    = KEY_W; 
    in.down  = KEY_S;
    in.left  = KEY_A;
    in.right = KEY_D;

    input_init(&in);

    state.x = width / 2;
    state.y = height / 2;

    return 0;
}

int game_update(void* arg, int width, int height)
{
    game_control(width, height);

    return 0;
}

int game_draw(void* arg, int width, int height)
{
    /* Draw */
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircle(state.x, state.y, 2, RED);

    EndDrawing();

    return 0;
}

void game_control(int width, int height)
{
    /* Handle Input */
    input_get(&in);

    if (in.is_up)
    {
        state.y -= 1;
        if (state.y == 0)
            state.y += 1;
    }

    if (in.is_down)
    {
        state.y += 1;
        if (state.y > height)
            state.y -= 1;
    }

    if (in.is_left)
    {
        state.x -= 1;
        if (state.x < 0)
            state.x += 1;
    }

    if (in.is_right)
    {
        state.x += 1;
        if (state.x > width)
            state.x -= 1;
    }
}
#ifndef _GAME_H
#define _GAME_H

#include <stdint.h>
#include <stdio.h>
#include "../source/headers/rayengine.h"
#include "../raylib/include/raylib.h"

typedef struct _game_state
{
    int x;
    int y;

} Game_State;

int game_init(int width, int height);
int game_update(int width, int height);
int game_draw(int width, int height);

void game_control();

#endif // _GAME_H
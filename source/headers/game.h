#ifndef _GAME_H
#define _GAME_H

#include <stdint.h>
#include "../../raylib/include/raylib.h"
#include "input.h"
#include "entity.h"

typedef struct _game_state
{
    int x;
    int y;

} Game_State;

int game_init(void* arg, int width, int height);
int game_update(void* arg, int width, int height);
int game_draw(void* arg, int width, int height);

void game_control();

#endif // _GAME_H
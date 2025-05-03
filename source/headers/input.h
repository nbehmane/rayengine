#ifndef _INPUT_H
#define _INPUT_H
#include <stdint.h>
#include "../../raylib/include/raylib.h"

typedef struct _input
{
    int up;
    int down;
    int left;
    int right;

    bool is_up;
    bool is_down;
    bool is_left;
    bool is_right;

} Input;

void input_init(Input* in);
void input_get(Input* in);

#endif // _INPUT_H

#ifndef _MONITOR_H
#define _MONITOR_H
#include <stdint.h>
#include "../../raylib/include/raylib.h"

#define MONITOR_PRIMARY 0

int monitor_get_count();

int monitor_get_render_width();
int monitor_get_render_height();

int monitor_get_screen_width();
int monitor_get_screen_height();

int monitor_get_width(int index);
int monitor_get_height(int index);

int monitor_get_refresh_rate(int index);

Vector2 monitor_get_position(int index);

#endif // _MONITOR_H

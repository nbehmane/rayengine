/* Includes */
#include "headers/monitor.h"

int monitor_get_count()
{
    int count = GetMonitorCount();
    return count;
}

int monitor_get_render_width()
{
    return (GetRenderWidth());
}

int monitor_get_render_height()
{
    return (GetRenderHeight());
}

int monitor_get_screen_width()
{
    return (GetScreenWidth());
}

int monitor_get_screen_height()
{
    return (GetScreenHeight());
}

int monitor_get_width(int index)
{
    return (GetMonitorWidth(index));
}

int monitor_get_height(int index)
{
    return (GetMonitorHeight(index));
}

int monitor_get_refresh_rate(int index)
{
    return (GetMonitorRefreshRate(index));
}

Vector2 monitor_get_position(int index)
{
    return (GetMonitorPosition(index));
}
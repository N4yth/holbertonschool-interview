#include <stddef.h>
#include <stdio.h>

void go_right(int *line, size_t size)
{
    size_t i = size;
    size_t y;
    while (i != 0)
    {
        i--;
        y = i;
        while (y > 0)
        {
            if (line[y - 1] == line[i])
            {
                line[y - 1] = 0;
                line[i] = line[i] * 2;
                break;
            }
            else if (line[y - 1] != 0)
            {
                break;
            } 
            y--;
        }
        y = i;
        while (y <= size)
        {
            if (line[y + 1] == 0 && y + 1 < size)
            {
                line[y + 1] = line[y];
                line[y] = 0;
            }
            else
                break;
            y++;
        }
    }
}

void go_left(int *line, size_t size)
{
    size_t i = 0;
    size_t y;
    while (i != size)
    {
        y = i + 1;
        while (y < size)
        {
            if (line[y] == line[i])
            {
                line[y] = 0;
                line[i] = line[i] * 2;
                break;
            }
            else if (line[y] != 0)
            {
                break;
            }
            y++;
        }
        y = i;
        while (y > 0)
        {
            if (line[y - 1] == 0 && y - 1 < size)
            {
                line[y - 1] = line[y];
                line[y] = 0;
            }
            else
                break;
            y--;
        }
        i++;
    }
}

int slide_line(int *line, size_t size, int direction)
{
    if (direction != SLIDE_LEFT || direction != SLIDE_RIGHT)
    {
        return 0;
    }
    if (direction)
        go_right(line, size);
    else
        go_left(line, size);
    return 1;
}




#include <stdio.h>
#include <stdlib.h>


#include "search.h"

size_t skiplist_size(const skiplist_t *list)
{
    size_t count = 0;

    while (list != NULL)
    {
        count++;
        list = list->next;
    }

    return count;
}


skiplist_t *linear_skip(skiplist_t *list, int value)
{
    int interval = 0;
    size_t width;

    width = skiplist_size(list);

    interval = sqrt(width);
    while (list->express != NULL)
    {
        if(list->express->n == value)
            return(list->express);
        else if(list->express->n < value)
            list = list->express;
        else
        {
            for (int i = 0 ; i < interval ; i++)
            {
                if(list->next->n == value)
                    return(list->next);
                else
                    list = list->next;
            }
            return(NULL);
        }
    }
    return(NULL);
}


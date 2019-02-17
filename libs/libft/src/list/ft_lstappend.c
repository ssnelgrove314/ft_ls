#include "libft.h"

void        ft_lstappend(t_list **begin_list, void const *content, size_t contentsize)
{
    t_list *list;

    list = *begin_list;
    if (!list)
    {
        *begin_list = ft_lstnew(content, contentsize);
    }
    else
    {
        while ((list)->next)
            list = list->next;
        list = ft_lstnew(content, contentsize);
    }
}

#include "ft_mergesort.h"

static t_node *sorted_merge(t_node *a, t_node *b, int (*cmp)(void *, void *))
{
    t_node *res;

    res = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (cmp(a->content, b->content) <= 0)
    {
        res = a;
        res->next = sorted_merge(a->next, b, cmp);
    }
    else
    {
        res = b;
        res->next = sorted_merge(a, b->next, cmp);
    }
    return (res);
}

static void front_back_split(t_node *src, t_node **front_ref, t_node **back_ref)
{
    t_node *fast;
    t_node *slow;

    slow = src;
    fast = src->next;
    while(fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front_ref = src;
    *back_ref = slow->next;
    slow->next = NULL;
}

void ft_mergesort(t_node **head_ref, int (*cmp)(void *, void *))
{
    t_node *head = *head_ref;
    t_node *a;
    t_node *b;

    if ((head == NULL) || (head->next == NULL))
        return ;
    front_back_split(head, &a, &b);
    ft_mergesort(&a, cmp);
    ft_mergesort(&b, cmp);
    *head_ref = sorted_merge(a, b, cmp);
}
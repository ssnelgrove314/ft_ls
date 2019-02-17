#ifndef FT_LIST_H
#define FT_LIST_H
#include "../../libft.h"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alist, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alist, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alist, t_list *lnew);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstappend(t_list **begin_list, void const *content, size_t contentsize);

#endif
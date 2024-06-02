#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_val;

	if (!f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_val = ft_lstnew(f(lst->content));
		if (!new_val)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_val);
		lst = lst->next;
	}
	return (new_list);
}

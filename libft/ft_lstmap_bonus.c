/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 16:38:35 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 14:18:34 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*tmp;

	ret = (t_list *)malloc(sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	tmp = ret;
	if (lst)
		while (lst)
		{
			tmp->content = f(lst->content);
			lst = lst->next;
			tmp->next = ft_lstnew((void *)0);
			if (tmp->next == NULL)
			{
				ft_lstclear(&ret, del);
				return (NULL);
			}
			tmp = tmp->next;
		}
	return (ret);
}

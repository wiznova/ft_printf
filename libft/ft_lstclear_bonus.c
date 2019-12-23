/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 15:02:33 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 14:17:50 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst)
		if (*lst)
		{
			while (*lst != NULL)
			{
				del((*lst)->content);
				tmp = (*lst)->next;
				free(*lst);
				*lst = tmp;
			}
			*lst = 0;
		}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: skhalil <skhalil@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 21:56:08 by skhalil        #+#    #+#                */
/*   Updated: 2019/12/01 14:18:19 by skhalil       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	**ret;

	ret = &lst;
	if (lst)
		while ((**ret).next != NULL)
			*ret = (**ret).next;
	return (*ret);
}

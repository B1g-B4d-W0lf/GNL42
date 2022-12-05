/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:40:26 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/06 00:14:12 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*res;

	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;
	return (res);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	last = lst;
	return (last);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && *lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
	*lst = new;
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int		ft_lstiter(t_list *lst, int (*f)(char  *))
{
	int	index;

	index = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		index = index + (*f)(lst->content);
		lst = lst->next;
	}
	return (index);
}

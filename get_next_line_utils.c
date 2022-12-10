/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:40:26 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/10 00:25:25 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = malloc(((ft_strlen(content, 0, 1) + 1) * sizeof(char)));
	if (!res->content)
		return (NULL);
	while (content[i])
	{
		res->content[i] = content[i];
		i++;
	}
	res->content[i] = '\0';
	res->next = NULL;
	return (res);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && *lst)
	{
		while ((*lst)->next != NULL)
			*lst = (*lst)->next;
		temp = *lst;
		temp->next = new;
	}
	else
		*lst = new;
}

int	ft_strlen(char *str, t_list *tab, int boolean)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (!boolean)
	{
		while (tab)
		{
			temp = tab;
			tab = tab->next;
			free(temp->content);
			free(temp);
		}
		return (0);
	}
	while (str[i])
		i++;
	return (i);
}

int	ft_lstiter(t_list *lst, int (*f)(char *, t_list *tab, int boolean))
{
	int		index;

	index = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		index = index + (*f)(lst->content, 0, 1);
		lst = lst->next;
	}
	return (index);
}

int	checkbuffer(char c, char const *set)
{
	int		i;

	i = 0;
	if (!set)
		return (2);
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:39:47 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/04 17:01:20 by wfreulon         ###   ########.fr       */
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int	ft_lstiter(t_list *lst, int (*f)(char  *))
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

char	*fillstr(t_list *tab, int index)
{
	int 	i;
	int		j;
	char	*str;
	
	i = 0;
	j = 0;
	str = malloc((index + 1) * (sizeof (char)));
	if (!str)
		return (NULL);
	while (tab)
	{
		while (tab->content[j])
		{
			str[i] = tab->content[j];
			i++;
			j++;
		}
		tab = tab->next;
		j = 0;
	}
	str[i] = '\0';
	return (str);
}

/*char	*bufferloop(char *str, int *buffer)
{
	char	*lol
	while (str != "\n")
	{
	lol = ft_lstnew((char[buffersize]) str);
		ft_lstadd_back(&tab, ft_lstnewlol));
	lol = '\0';
		str[buffersize]++;
	}
	return lol);
}*/

char	*get_next_line(char *str)
{
	t_list	*tab = NULL;
	char	*string;
	int		index = 0;
	t_list	*temp;

	string = NULL;
	tab = ft_lstnew(str);
	ft_lstadd_back(&tab, ft_lstnew(next));
	if (tab)
		index = ft_lstiter(tab, &ft_strlen);
	printf("%d\n", index);
	string = fillstr(tab, index);
	return (string);
	while (tab)
	{
		temp = tab;
		tab = tab->next;
		free(temp);
	}
	free (string);
	return (0);
}

int	main(void)
{
	char	*str =  "Hello Goodbye Bitch\n Ho Ho HO Motherfucker\n";
	printf("%s\n", get_next_line(str));
	return (0);
}
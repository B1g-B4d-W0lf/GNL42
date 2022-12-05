/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:39:47 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/06 00:12:35 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
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
	int fd;
	fd = open("uhuh", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return (0);
}
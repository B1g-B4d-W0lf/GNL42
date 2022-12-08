/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:39:47 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/08 02:18:47 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fillstr(t_list *tab, int index)
{
	int		i;
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

int	checkbuffer(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	t_list		*tab;
	t_list		*temp;
	static char	west[BUFFER_SIZE + 1];
	char		*string;
	char		str[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	int			index;
	int			i;
	//int		j;

	string = NULL;
	tab = NULL;
	index = 0;
	i = -1;
	if (west)
	{
		
	}
	read(fd, buffer, BUFFER_SIZE);
	buffer[ft_strlen(buffer)] = '\0';
	while (checkbuffer('\n', buffer) != 1)
	{
		ft_lstadd_back(&tab, ft_lstnew(buffer));
		read(fd, buffer, BUFFER_SIZE);
		buffer[ft_strlen(buffer)] = '\0';
	}
	if (checkbuffer('\n', buffer) == 1)
	{
		while (buffer[++i] != '\n')
			str[i] = buffer[i];
		str[i] = '\0';
		while (buffer[++i] != '\0')
			west[i] = buffer[i];
		west[i] = '\0';
			
	}
	ft_lstadd_back(&tab, ft_lstnew(str));
	if (tab)
		index = ft_lstiter(tab, &ft_strlen);
	string = fillstr(tab, index);
	while (tab)
	{
		temp = tab;
		tab = tab->next;
		free(temp->content);
		free(temp);
	}
	return (string);
}

int	main(void)
{	
	int fd;
	char *str;
	
	fd = open("uhuh", O_RDONLY);
	str = get_next_line(fd);
	printf("final %s\n", str);
	free(str);
	return (0);
}
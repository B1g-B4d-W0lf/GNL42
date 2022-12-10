/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:39:47 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/10 00:31:53 by wfreulon         ###   ########.fr       */
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
	str = malloc((index + 1) * (sizeof(char)));
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

void	writeover(char *strdest, char *strsrc)
{
	int		i;

	i = 0;
	while (strsrc[i])
	{
		strdest[i] = strsrc[i];
		i++;
	}
	strdest[i] = '\0';
}

int	writetemp(char *temp, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = str[i];
	i++;
	temp[i] = '\0';
	return (i);
}

void	readit(int fd, char *west, t_list *tab)
{
	char	buffer[BUFFER_SIZE + 1];
	char	temp[BUFFER_SIZE + 1];
	int		i;
	int		output;

	output = read(fd, buffer, BUFFER_SIZE);
	buffer[output] = '\0';
	while (checkbuffer('\n', buffer) != 1)
	{
		ft_lstadd_back(&tab, ft_lstnew(buffer));
		output = read(fd, buffer, BUFFER_SIZE);
		buffer[output] = '\0';
	}
	if (checkbuffer('\n', buffer) == 1)
	{
		i = writetemp(temp, buffer);
		ft_lstadd_back(&tab, ft_lstnew(temp));
		writeover(west, &buffer[i]);
	}
}

char	*get_next_line(int fd)
{
	t_list		*tab;
	static char	west[BUFFER_SIZE + 1];
	char		*string;
	char		temp[BUFFER_SIZE + 1];
	int			i;

	string = NULL;
	tab = NULL;
	i = 0;
	if (checkbuffer('\n', west) == 0 || checkbuffer('\n', west) == 1)
	{
		i = writetemp(temp, west);
		ft_lstadd_back(&tab, ft_lstnew(temp));
		writeover(west, &west[i]);
	}
	if (checkbuffer('\n', tab->content) != 1)
	{
		readit(fd, west, tab);
	}
	if (tab)
		i = ft_lstiter(tab, &ft_strlen);
	string = fillstr(tab, i);
	ft_strlen(0, tab, 0);
	return (string);
}

int	main(void)
{
	int fd;
	int	i = 0;
	int	j = 17;
	char *str;
	
	fd = open("uhuh", O_RDONLY);
	while (i <= j)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	if (close(fd) == -1)
		printf("CLOSE FAILED");
	return (0);
}
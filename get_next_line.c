/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:39:47 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/09 03:28:53 by wfreulon         ###   ########.fr       */
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

void	freetab(t_list *tab)
{
	t_list		*temp;
	
	while (tab)
	{
		temp = tab;
		tab = tab->next;
		free(temp->content);
		free(temp);
	}
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

char	*get_next_line(int fd)
{
	t_list		*tab;
	static char	west[BUFFER_SIZE + 1];
	char		*string;
	char		str[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	int			index;
	int			i;
	
	string = NULL;
	tab = NULL;
	index = 0;
	i = 0;
	if (checkbuffer('\n', west) == 0 || checkbuffer('\n', west) == 1)
	{
		while (west[i] != '\n' && west[i])
		{
			str[i] = west[i];
			i++;
		}
		str[i] = west[i];
		i++;
		str[i] = '\0';
		ft_lstadd_back(&tab, ft_lstnew(str));
		writeover(west, &west[i]);
	}
	if (checkbuffer('\n', tab->content) != 1)
	{
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
			i = 0;
			while (buffer[i] != '\n' && buffer[i])
			{
				str[i] = buffer[i];
				i++;
			}
			str[i] = buffer[i];
			i++;
			str[i] = '\0';
			ft_lstadd_back(&tab, ft_lstnew(str));
			writeover(west, &buffer[i]);
		}	
	}
	if (tab)
		index = ft_lstiter(tab, &ft_strlen);
	string = fillstr(tab, index);
	freetab(tab);
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
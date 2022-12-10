/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:04:16 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/10 23:56:30 by wfreulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strlen(char *str, t_list *tab, int boolean);
int		ft_lstiter(t_list *lst, int (*f)(char *, t_list *tab, int boolean));
char	*fillstr(t_list *tab, int index);
char	*get_next_line(int fd);
int		checkbuffer(char c, char const *set);
char	*readit(int fd, char *west, t_list **tab);
int		writetemp(char *temp, char *str);
void	writeover(char *strdest, char *strsrc);

#endif
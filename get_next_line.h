/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:04:16 by wfreulon          #+#    #+#             */
/*   Updated: 2022/12/06 00:17:35 by wfreulon         ###   ########.fr       */
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

#	define BUFFER_SIZE 42

# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

#endif

t_list	*ft_lstnew(char *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_strlen(char *str);
int		ft_lstiter(t_list *lst, int (*f)(char  *));
char	*fillstr(t_list *tab, int index);
char	*get_next_line(int fd);
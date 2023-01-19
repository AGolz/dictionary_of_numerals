/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_course.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 04:09:09 by emaksimo          #+#    #+#             */
/*   Updated: 2022/10/19 00:00:43 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rush.h"

void	dict_error(void)
{
	write(1, "(＃＞＜) Dict error\n", 24);
	exit (1);
}

char	*ft_get_nbr(int fd)
{
	int		i;
	char	ch[1];
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!str)
	{
		write(1, "Error (×﹏×)\n", 17);
		exit (1);
	}
	i = 0;
	if ((read(fd, ch, 1) == 0))
		dict_error();
	while (ch[0] >= '0' && ch[0] <= '9')
	{
		str[i] = ch[0];
		read(fd, ch, 1);
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_get_str(int fd, char *ch)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * 128);
	if (!str)
		write(1, "Error (×﹏×)\n", 17);
		exit (1);
	i = 0;
	while (ch[0] != '\n')
	{
		str[i] = ch[0];
		if ((read(fd, ch, 1) == 0))
			dict_error();
		i++;
	}
	return (str);
}

static void	read_dict(t_list *tab, int fd, int i)
{
	char	ch[1];
	char	*tmp;

	tab[i].nb = ft_atoi(ft_get_nbr(fd));
	read(fd, ch, 1);
	while (ch[0] == ' ')
		read(fd, ch, 1);
	if (ch[0] == ':')
		read(fd, ch, 1);
	while (ch[0] == ' ')
		read(fd, ch, 1);
	tmp = ft_get_str(fd, ch);
	tab[i].val = ft_strdup(tmp);
	free(tmp);
}

t_list	*course(char *file)
{
	int		i;
	int		fd;
	t_list	*tab;

	fd = open(file, O_RDONLY);
	tab = malloc(sizeof(t_list) * 42);
	if (fd == -1 || !tab)
		dict_error();
	i = 0;
	while (i < 41)
	{
		read_dict(tab, fd, i);
		i++;
	}
	close(fd);
	return (tab);
}

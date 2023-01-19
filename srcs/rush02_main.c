/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 02:52:46 by emaksimo          #+#    #+#             */
/*   Updated: 2022/10/18 23:15:07 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	str_is_num(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_stlen(str);
	if ((len > 1 && str[0] == '0') || len > 37)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	f1(char	**argv, unsigned long long *fst, t_list *tab)
{
	if (str_is_num(argv[1]) == 1)
	{
		write(1, "Error (×﹏×)\n", 17);
		return (0);
	}
	tab = course(DICTIONARY);
	if (atoi(argv[1]) == 0)
	{
		ft_nbr_print(ft_atoi(argv[1]), tab, fst);
		write(1, "\n", 1);
		return (0);
	}
	more_billion(argv[1], tab, fst);
	write(1, "\n", 1);
	return (0);
}

int	f2(char	**argv, unsigned long long *fst, t_list *tab)
{
	if (str_is_num(argv[2]) == 1)
	{
		write(1, "Error (×﹏×)\n", 17);
		return (0);
	}
	tab = course(argv[1]);
	if (atoi(argv[2]) == 0)
	{
		ft_nbr_print(ft_atoi(argv[2]), tab, fst);
		write(1, "\n", 1);
		return (0);
	}
	more_billion(argv[2], tab, fst);
	write(1, "\n", 1);
	return (0);
}

int	main(int argc, char **argv)
{
	unsigned long long	adr_fst;
	unsigned long long	*fst;
	t_list				*tab;

	adr_fst = 1;
	fst = &adr_fst;
	tab = NULL;
	if (argc < 2 || argc > 3)
	{
		write(1, "┐(￣ヘ￣)┌ Sorry, I need one or two arguments...\n", 57);
		return (0);
	}
	if (argc == 2)
		return (f1(argv, fst, tab));
	if (argc == 3)
		return (f2(argv, fst, tab));
	return (0);
}

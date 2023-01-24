/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 06:04:39 by emaksimo          #+#    #+#             */
/*   Updated: 2022/10/18 22:59:27 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static int	get_decade(unsigned long long nbr)
{
	if (nbr >= 90)
		return (90);
	else if (nbr >= 80)
		return (80);
	else if (nbr >= 70)
		return (70);
	else if (nbr >= 60)
		return (60);
	else if (nbr >= 50)
		return (50);
	else if (nbr >= 40)
		return (40);
	else if (nbr >= 30)
		return (30);
	else if (nbr >= 20)
		return (20);
	else if (nbr <= 29)
		return (nbr);
	else
		return (0);
}

static unsigned long long	get_more_hundred(unsigned long long nbr)
{
	if (nbr >= 1000000000)
		return (1000000000);
	else if (nbr >= 1000000)
		return (1000000);
	else if (nbr >= 1000)
		return (1000);
	else if (nbr >= 100)
		return (100);
	else
		return (get_decade(nbr));
}

void	ft_nbr_print(unsigned long long n, t_list *tab, \
										unsigned long long	*fst)
{
	int					i;
	unsigned long long	more_hundred;

	i = 0;
	more_hundred = get_more_hundred(n);
	if (more_hundred >= 100)
		ft_nbr_print(n / more_hundred, tab, fst);
	if (*fst == 0)
		write(1, " ", 1);
	*fst = 0;
	while (tab[i].nb != more_hundred)
	{
		if (i > 42)
			dict_error();
		i++;
	}
	ft_putstr(tab[i].val);
	if (more_hundred != 0 && n % more_hundred != 0)
		ft_nbr_print(n % more_hundred, tab, fst);
}

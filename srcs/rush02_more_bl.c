/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02_more_bl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:20:20 by emaksimo          #+#    #+#             */
/*   Updated: 2022/10/18 23:29:53 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

static void	uneven_value(int len, char *str, int num_dict, t_list *tab, \
													unsigned long long *fst)
{
	int		i;
	int		j;
	char	dest[3];
	char	*adr;

	i = (len % 3) - 1;
	j = 0;
	while (j <= i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	ft_nbr_print(ft_atoi(dest), tab, fst);
	adr = &str[i + 1];
	write(1, " ", 1);
	ft_putstr(tab[num_dict].val);
	more_billion(adr, tab, fst);
}

static void	even_value(char *str, int num_dict, t_list *tab, \
											unsigned long long *fst)
{
	int		i;
	int		j;
	char	dest[3];
	char	*adr;

	i = 2;
	j = 0;
	while (j <= i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	ft_nbr_print(ft_atoi(dest), tab, fst);
	adr = &str[i + 1];
	ft_putstr(tab[num_dict].val);
	more_billion(adr, tab, fst);
}

void	more_billion(char *str, t_list *tab, unsigned long long *fst)
{
	int		i;
	int		len;
	char	*adr;
	int		num_dict;

	len = ft_stlen(str);
	if (len > 19)
	{
		if (str[0] == '0')
		{
			i = 0;
			while (str[i] > 49)
				i++;
			adr = &str[i + 1];
			more_billion(adr, tab, fst);
		}
		else if (len <= 37 && len > 34)
		{
			if (len % 3 != 0)
			{
				num_dict = 40;
				uneven_value(len, str, num_dict, tab, fst);
			}
			else if (len <= 36)
			{
				num_dict = 40;
				even_value(str, num_dict, tab, fst);
			}
		}
		else if (len <= 34 && len > 31)
		{
			if (len % 3 != 0)
			{
				num_dict = 39;
				uneven_value(len, str, num_dict, tab, fst);
			}
			else if (len <= 33)
			{
				num_dict = 39;
				even_value(str, num_dict, tab, fst);
			}
		}
		else if (len <= 31 && len > 28)
		{
			if (len % 3 != 0)
			{
				num_dict = 38;
				uneven_value(len, str, num_dict, tab, fst);
			}
			else if (len <= 30)
			{
				num_dict = 38;
				even_value(str, num_dict, tab, fst);
			}
		}
		else if (len <= 28 && len > 25)
		{
			if (len % 3 != 0)
			{
				num_dict = 37;
				uneven_value(len, str, num_dict, tab, fst);
			}
			else if (len <= 27)
			{
				num_dict = 37;
				even_value(str, num_dict, tab, fst);
			}
		}
		else if (len <= 25 && len > 22)
		{
			if (len % 3 != 0)
			{
				num_dict = 36;
				uneven_value(len, str, num_dict, tab, fst);
			}
			else if (len <= 24)
			{
				num_dict = 36;
				even_value(str, num_dict, tab, fst);
			}
		}
		else if (len <= 22)
		{
			if (len % 3 != 0)
			{
				num_dict = 35;
				uneven_value(len, str, num_dict, tab, fst);
			}
			else if (len <= 21)
			{
				num_dict = 35;
				even_value(str, num_dict, tab, fst);
			}
		}		
	}
	else if (str[0] == '0' && len > 1)
	{
		i = 0;
		while (str[i] > 48)
			i++;
		adr = &str[i + 1];
		more_billion(adr, tab, fst);
	}
	else if (str[0] != '0')
		ft_nbr_print(ft_atoi(str), tab, fst);
}

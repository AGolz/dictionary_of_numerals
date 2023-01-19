/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 05:08:02 by emaksimo          #+#    #+#             */
/*   Updated: 2022/10/18 21:42:44 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define DICTIONARY "numbers.dict"

typedef struct s_list
{
	unsigned long long	nb;
	char				*val;
}				t_list;

t_list				*course(char *file);
unsigned long long	ft_atoi(char *str);
int					ft_stlen(char *str);
int					get_mlt(int nbr);
int					tr_is_num(char *str);

char				*ft_strdup(char *str);
char				*ft_get_nbr(int fd);
char				*ft_get_str(int fd, char *ch);

void				ft_putstr(char *str);
void				dict_error(void);
void				ft_nbr_print(unsigned long long n, t_list *tab, \
												unsigned long long	*fst);
void				more_billion(char *str, t_list *tab, \
												unsigned long long *fst);

#endif

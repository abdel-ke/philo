/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:25:07 by abdel-ke          #+#    #+#             */
/*   Updated: 2021/07/26 15:42:16 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checker(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (av[i][j] <= '0' || av[i][j] >= '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	stock_args(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = 0; 
		while (av[i][j])
		{
			j++;
		}
		i++;
	}
}

int	check_args(char **av)
{
	if (!ft_checker(av))
		return (0);
	return (1);
}

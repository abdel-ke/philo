/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:25:07 by abdel-ke          #+#    #+#             */
/*   Updated: 2021/07/27 15:38:13 by abdel-ke         ###   ########.fr       */
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

int	stock_args(t_philo *philo, char **av)
{
	int		i;
	int		j;
	int		cp;

	i = 0;
	cp = 0;
	while (av[i])
	{
		j = 0; 
		while (av[i][j])
		{
			while (av[i][j] == ' ' || av[i][j] == '\t')
				j++;
			if (ft_isdigit(av[i][j]))
			{
				philo->args[cp] = ft_atoi(av[i] + j);
				cp++;
				if (cp > 4)
					return (0);
				while (ft_isdigit(av[i][j]))
					j++;
			}
		}
		i++;
	}
	if (cp != 4)
		return (0);
	return (1);
}

int	check_args(t_philo *philo, char **av)
{
	if (!ft_checker(av))
		return (0);
	if (!stock_args(philo, av))
		return (0);
	return (1);
}

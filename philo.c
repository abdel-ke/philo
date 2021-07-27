/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:54:35 by abdel-ke          #+#    #+#             */
/*   Updated: 2021/07/27 15:24:54 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *msg, int ret)
{
	ft_putstr_fd(msg, 0);
	return (ret);
}

int main(int ac, char **av)
{
	t_philo	philo;

	ac--;
	if (ac != 4)
		return (ft_error("Error Args", 0));
	else
	{
		if (!check_args(&philo, av));
			return (ft_error("Error Args", 0));
	}
}

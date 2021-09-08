/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:54:35 by abdel-ke          #+#    #+#             */
/*   Updated: 2021/09/04 17:21:07 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *msg, int ret)
{
	ft_putstr_fd(msg, 0);
	return (ret);
}

void	init(t_args *philo)
{
	philo->args[0] = 1337;
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	t_args	*args;

	args = NULL;
	philo = (t_philo*)arg;
	args = philo->args;
	while (1)
	{
		// take fork;
		printf("%d has taken a fork\n", philo->index);
		pthread_mutex_lock(&args->fork[philo->index]);
		printf("%d has taken a fork\n", philo->index);
		pthread_mutex_lock(&philo->args->fork[philo->rfork]);
		// eat ;
		printf("%d is eating\n", philo->index);
		usleep(args->args[2] * 1000);
		// unlock forks
		pthread_mutex_unlock(&philo->args->fork[philo->index - 1]);
		pthread_mutex_unlock(&philo->args->fork[philo->index]);
		// sleep;
		printf("%d is sleeping\n", philo->index);
		usleep(args->args[2] * 1000);
		// think ;
		printf("%d is thinking\n", philo->index);
	}
	return NULL;	
}

int	main(int ac, char **av)
{
	t_args	*args;
	int		i;
	pthread_t th;

	i = 0;
	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		printf("alloc error\n");
	init(args);
	if (!check_args(args, ++av))
		return (ft_error("Error Args\n", 0));
	args->philo = malloc(sizeof(args->philo) * args->args[0]);
	args->fork = malloc(sizeof(pthread_mutex_t) * args->args[0]);
	while (i < args->args[0])
	{
		args->philo[i].index = i + 1;
		args->philo[i].args = args;
		args->philo[i].rfork = args->philo[i].index % args->args[0];
		if (pthread_mutex_init(&args->fork[i], NULL))
			perror("init fork error");

		i++;
	}
	i = 0;

	pthread_mutex_init(&args->main, NULL);
	pthread_mutex_lock(&args->main);
	while (i < args->args[0])
	{
		if (pthread_create(&th, NULL,  routine,
				(void *)(&args->philo[i])))
			perror("creation thread failed");
		usleep(100);
		pthread_detach(th);
		i++;
	}
	pthread_mutex_lock(&args->main);
}

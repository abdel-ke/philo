/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:54:37 by abdel-ke          #+#    #+#             */
/*   Updated: 2021/07/29 15:09:45 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_C
#define PHILO_C

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

FILE *file;

typedef	enum	e_philo_cycle
{
	nbr_philo,
	eating,
	thinking,
	sleeping
}				t_philo_cycle;

typedef struct	s_philo
{
	struct s_args *args;
	int 	index;
	int		rfork;
}				t_philo;

typedef struct	s_args
{
	int				args[4];
	int				value;
	pthread_mutex_t	*fork;
	pthread_mutex_t	main;
	t_philo *philo;	
}				t_args;

/* libft */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_error(char *msg, int ret);

/*	checker	*/
int		check_args(t_args *philo, char **av);
#endif

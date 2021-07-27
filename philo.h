/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:54:37 by abdel-ke          #+#    #+#             */
/*   Updated: 2021/07/27 19:56:15 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_C
#define PHILO_C

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

FILE *file;

typedef	enum	e_args
{
	nbr_philo,
	eating,
	thinking,
	sleeping
}				t_args;

typedef struct	s_philo
{
	int		args[3];
	int		fork;
}				t_philo;

/* libft */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_error(char *msg, int ret);

/*	checker	*/
int		check_args(t_philo *philo, char **av);
#endif

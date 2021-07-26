/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ke <abdel-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:54:37 by abdel-ke          #+#    #+#             */
/*   Updated: 2021/07/26 15:35:39 by abdel-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_C
#define PHILO_C

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_philo
{
	int		nbr_philo;
	int		eating;
	int		thinking;
	int		sleeping;
	int		fork;
}				t_philo;

/* libft */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif
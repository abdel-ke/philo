#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_simulation
{
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*message;
	pthread_mutex_t		*death;
	pthread_mutex_t		*stop;
	unsigned int		start;
	int					philo_numbers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_counter;
	int					max_eat;
	int					is_dead;
	int					current_eat;
}				t_simulation;

typedef struct s_philo
{
	pthread_mutex_t	*eat;
	t_simulation	*data;
	unsigned int	eating_time;
	unsigned int	next_meal;
	int				index;
	int				right_hand;
	int				left_hand;
	int				is_dead;
	int				eat_counter;
}				t_philo;

#endif

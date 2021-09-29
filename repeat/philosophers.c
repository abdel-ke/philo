
#include "philosophers.h"

int main(int ac, char **av)
{
	t_philo			*philo;
	t_simulation	sm;
	int				i;

	i = 0;
	if (ac == 5 || av == 6)
	{
		if (ft_parsing(av, &sm))
			return (0);
	}
}

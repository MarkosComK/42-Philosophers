/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:31:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 15:34:28 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(void *arg)
{
	t_philos	*philo = (t_philos *)arg;
	printf("Hi, i'm thread with id: %i\n", philo->id);
	print_philo(philo);
	return (arg);
}

void	philos_input_data(t_philos *philos, char **av)
{
	philos->num_philos = ft_atoi(av[1]);
	philos->time_die = ft_atoi(av[2]);
	philos->time_eat = ft_atoi(av[3]);
	philos->time_sleep = ft_atoi(av[4]);
	philos->last_meal = 1; //get_current_time();
	philos->sleep = 0;
	philos->eaten = 0;
	philos->dead = &philos->table->dead_flag;
}

void	init_philos(t_table *table, t_philos *philos, char **av)
{
	size_t	i;

	i = 0;
	while (i < (size_t)ft_atoi(av[1]))
	{
		philos[i].id = i + 1;
		philos[i].table = table;
		philos_input_data(&philos[i], av);
		i++;
	}
}

void	init_table(t_table *table, t_philos *philos, char **av)
{
	size_t	i;
	pid_t	pid;
	
	i = 0;
	table->num_philos = ft_atoi(av[1]);
	while (i < table->num_philos)
	{
		pid = fork();
		if (pid == -1)
		{
			printf(RED "Error while forking\n" DEFAULT);
			exit(1);
		}
		else if (pid == 0)
		{
			printf(GREEN "Child process %zi created with pid: %i\n" DEFAULT, i + 1, getpid());
			pthread_create(&philos[i].philo, NULL, routine, &philos[i]);
			pthread_join(philos[i].philo, NULL);
			sleep(1);
			exit(0);
		}
		i++;
	}
	waitpid(-1, 0, 0);
}

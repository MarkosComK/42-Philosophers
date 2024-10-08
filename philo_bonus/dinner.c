/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:38:12 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 19:11:49 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_dinner(t_table *table, t_philos *philos, char **av)
{
	size_t	i;

	i = 0;
	table->num_philos = ft_atoi(av[1]);
	table->time = get_current_time();
	while (i < table->num_philos)
	{
		philos[i].pid = fork();
		if (philos[i].pid == -1)
		{
			printf(RED "Error while forking\n" DEFAULT);
			exit(1);
		}
		else if (philos[i].pid)
		{
			routine(&philos[i].philo);
			sleep(1);
			exit(0);
		}
		i++;
	}
	waitpid(-1, NULL, 0);
}

void	finish_dinner(t_table *table)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (1)
	{
		if (table->num_of_meals != -1)
		{
			while (j < table->num_philos)
			{
				sem_wait(table->meals);
				j++;
			}
			j = -1;
			while (++j < table->num_philos)
				kill(table->philos[j].pid, SIGINT);
		}
		sem_close(table->dead);
		sem_close(table->forks);
		sem_close(table->print);
		sem_close(table->meals);
		exit(0);
	}
}

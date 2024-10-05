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
	size_t	j;
	
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
		else if (philos[i].pid == 0)
		{
			printf(GREEN "Child process %zi created with pid: %i\n" DEFAULT, i + 1, philos[i].pid);
			routine(&philos[i].philo);
			sem_wait(table->dead);
			sleep(1);
			exit(0);
		}
		i++;
	}
	i = 0;
	j = 0;
	while (1)
	{
		sem_wait(table->dead);
		while (j < table->num_philos)
		{
			kill(table->philos[j].pid, SIGKILL);
			j++;
		}
		exit(0);
	}
	//waitpid(-1, 0, 0);
}

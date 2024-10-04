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
	pid_t	pid;
	
	i = 0;
	table->num_philos = ft_atoi(av[1]);
	table->time = get_current_time();
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

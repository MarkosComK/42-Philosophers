/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:31:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/03 19:32:43 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(void *arg)
{
	int	id = (intptr_t)arg;
	printf("Hi, i'm thread with id: %i\n", id);
	return (arg);
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
			pthread_create(&philos[i].philo, NULL, routine, (void *)i+1);
			pthread_join(philos[i].philo, NULL);
			sleep(1);
			exit(0);
		}
		i++;
	}
	waitpid(-1, 0, 0);
}

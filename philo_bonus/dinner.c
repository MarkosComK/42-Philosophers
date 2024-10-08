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

void	start_dinner(t_table *table, char **av)
{
	size_t	i;

	i = 0;
	table->num_philos = ft_atoi(av[1]);
	table->time = get_current_time();
	while (i < table->num_philos)
	{
		table->philos[i].pid = fork();
		if (table->philos[i].pid == -1)
		{
			printf(RED "Error while forking\n" DEFAULT);
			exit(1);
		}
		else if (table->philos[i].pid)
		{
			routine(&table->philos[i]);
		}
		i++;
	}
	finish_dinner(table);
	i = 0;
	int	status;
	while (i < table->num_philos)
	{
		waitpid(table->philos[i].pid, &status, 0);
		i++;
	}
	free(table->philos);
	free_table(table);
	sem_unlink("forks");
	sem_unlink("finish");
	sem_unlink("waiter");
}

void	finish_dinner(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->num_philos)
	{
		sem_wait(table->finish);
		i++;
	}
	i = 0;
	while (i < table->num_philos)
	{
		kill(table->philos[i].pid, SIGTERM);
		i++;
	}
}

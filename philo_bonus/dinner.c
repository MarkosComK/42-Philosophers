/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:16:52 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/12 15:51:57 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_dinner(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->philo_count)
	{
		table->philos[i].pid = fork();
		if (table->philos[i].pid == -1)
			return ;
		if (table->philos[i].pid == 0)
			philo_process(&table->philos[i]);
		i++;
	}
	kill_processes(table);
	wait_processes(table);
	free(table->philos);
	free_table(table);
}

void	kill_processes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		sem_wait(table->finish);
		i++;
	}
	i = 0;
	while (i < table->philo_count)
	{
		kill(table->philos[i].pid, SIGKILL);
		i++;
	}
}

void	wait_processes(t_table *table)
{
	int	i;
	int	status;

	i = 0;
	while (i < table->philo_count)
	{
		waitpid(table->philos[i].pid, &status, 0);
		i++;
	}
}

void	free_table(t_table *table)
{
	if (table)
	{
		if (table->forks)
			sem_close(table->forks);
		if (table->finish)
			sem_close(table->finish);
		if (table->waiter)
			sem_close(table->waiter);
		free(table);
	}
}

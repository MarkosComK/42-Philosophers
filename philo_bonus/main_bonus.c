/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:15:02 by mariaoli          #+#    #+#             */
/*   Updated: 2024/10/01 18:30:12 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int	main(int argc, char **argv)
{
	int		i;
	t_table	*table;

	if (!check_args(argc, argv))
		return (1);
	table = init_table(argv);
	if (!table)
		return (1);
	i = 0;
	start_dinner(table);
	unlink_sem();
	return (0);
}

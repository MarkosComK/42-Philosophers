/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:30:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 16:52:56 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_table	*table;
	size_t	i;

	if (check_args(ac, av))
		return (1);
	table = init_table(av);
	i = 0;
	while (i < (size_t)ft_atoi(av[1]))
	{
		init_philos(table, &table->philos[i], av, i);
		i++;
	}
	start_dinner(table, av);
	finish_dinner(table);
	return (0);
}

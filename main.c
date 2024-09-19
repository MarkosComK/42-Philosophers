/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:30:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/15 11:23:38 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_table		table;
	t_philos	philos[MAX_PHILOS];

	if (check_args(ac, av))
		return (1);
	prepare_table(philos, &table, av);
	init_philos(&table, philos, av);
	print_philos(philos);
	start_meal(&table, philos, av);
	end_meal(&table, philos, av);
	return (0);
}

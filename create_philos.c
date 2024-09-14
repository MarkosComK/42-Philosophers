/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:58:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/14 12:39:26 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	printf("routine");
	return (arg);
}

void	birth_sophos(t_table *table, t_philos *philos, char **av)
{
	int	i;

	i = 0;
	pthread_create(&table->table, NULL, routine, NULL);
	while (i++ < table->philos->num_philos)
		pthread_create(&table->philos[i].thread, NULL, routine, NULL);
	printf("receiv %p\n", philos);
	printf("amount of philos:%i\n", ft_atoi(av[1]));
	i = 0;
	while (i++ < table->philos->num_philos)
		pthread_join(table->philos[i].thread, NULL);
}

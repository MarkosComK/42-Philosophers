/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:17:40 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/15 13:28:40 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prepare_table(t_philos *philos, t_table *table, char **av)
{
	(void) av;
	table->philos = philos;
	pthread_mutex_init(&table->mutex, NULL);
}

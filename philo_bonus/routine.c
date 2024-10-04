/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:42:02 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 15:45:52 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*routine(void *arg)
{
	t_philos	*philo = (t_philos *)arg;
	printf("Hi, i'm thread with id: %i\n", philo->id);
	//print_philo(philo);
	return (arg);
}

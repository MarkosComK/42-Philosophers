/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:24:12 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/04 15:35:47 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_philo(t_philos *philo)
{
	printf(YELLOW"philo->id:"GREEN"        [% 8i]\n", philo->id);
	printf(YELLOW"philo->num_philos:"GREEN"[% 8i]\n", philo->num_philos);
	printf(YELLOW"philo->time-die:"GREEN"  [% 8zi]\n", philo->time_die);
	printf(YELLOW"philo->time-eat:"GREEN"  [% 8zi]\n", philo->time_eat);
	printf(YELLOW"philo->time-sleep:"GREEN"[% 8zi]\n", philo->time_sleep);
	printf(YELLOW"philo->sleep:"GREEN"     [% 8i]\n", philo->sleep);
	printf(YELLOW"philo->eat:"GREEN"       [% 8i]\n", philo->eaten);
	printf(YELLOW"philo->dead:"GREEN"      [% 8i]\n", *philo->dead);
	printf("\n"DEFAULT);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:54:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/14 11:31:27 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return(printf(RED"Usage:\n"GREEN"./philo"" 5 500 600 800\n" DEFAULT));
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > MAX_PHILOS)
		return (printf(RED"Invalid number of philosophers\n"DEFAULT));
	if (ft_atoi(av[2]) <= 0 || ft_atoi(av[1]) > MAX_PHILOS)
		return (printf(RED"Invalid number of philosophers\n"DEFAULT));
	return (0);
}

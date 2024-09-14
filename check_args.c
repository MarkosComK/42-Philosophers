/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:54:23 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/14 11:47:34 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return(printf(RED"Usage:\n"GREEN"./philo"" 5 500 600 800\n" DEFAULT));
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > MAX_PHILOS)
		return (printf(RED"Invalid number of philosophers\n"DEFAULT));
	if (ft_atoi(av[2]) <= 0 || ft_isnum(av[2]))
		return (printf(RED"Invalid time_to_die\n"DEFAULT));
	if (ft_atoi(av[3]) <= 0 || ft_isnum(av[3]))
		return (printf(RED"Invalid time_to_eat\n"DEFAULT));
	if (ft_atoi(av[4]) <= 0 || ft_isnum(av[4]))
		return (printf(RED"Invalid time_to_sleep\n"DEFAULT));
	if (ac == 6 && (ft_atoi(av[5]) <= 0 || ft_isnum(av[5])))
		return (printf(RED"Invalid eat_times\n"DEFAULT));
	return (0);
}

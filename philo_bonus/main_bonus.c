/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:51:32 by marsoare          #+#    #+#             */
/*   Updated: 2024/10/12 15:51:33 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (check_args(argc, argv))
		return (1);
	table = init_table(argv);
	if (!table)
		return (1);
	start_dinner(table);
	unlink_sem();
	return (0);
}

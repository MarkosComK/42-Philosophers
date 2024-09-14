/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marsoare <marsoare@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:30:56 by marsoare          #+#    #+#             */
/*   Updated: 2024/09/14 11:26:53 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (check_args(ac, av))
		return (1);
	printf("ac: %i\n", ac);
	while (*av)
		printf("%s\n", *av++);
	printf("first commit XD\n");
}

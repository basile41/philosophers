/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:52:59 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/06 21:32:03 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_philos()
{
}

int	main(int argc, char **argv)
{
	struct timeval	time;
	int				ret;

	if (argc != 5 && argc != 6)
	ret = gettimeofday(&time, 0);
	if (ret < 0)
		perror("gettimeofday");
	
}

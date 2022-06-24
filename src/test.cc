/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:01:56 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/23 13:53:44 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define NB_THREAD 100000

void	*ft_routine(void *arg)
{
	printf("%d\n", ft_get_time());
	sleep(1);
	printf("%d\n", ft_get_time());
	return (arg);
}

int	main()
{
	pthread_t	thread[NB_THREAD];
	int			i;

	printf("%d\n", ft_get_time());
	i = 0;
	while (i < NB_THREAD)
	{
		pthread_create(&thread[i], 0, ft_routine, 0);
		i++;
	}
	i = 0;
	while (i < NB_THREAD)
	{
		pthread_join(thread[i], 0);
		i++;
	}
}

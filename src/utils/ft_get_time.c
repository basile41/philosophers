/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:27:29 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/11 13:17:00 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//if d == 0 : init or return time in ms else destroy mutex
int	ft_get_time(int d)
{
	static struct timeval	init_time;
	struct timeval			time;
	static pthread_mutex_t	mutex;
	int						msec;

	if (d)
	{
		return (pthread_mutex_destroy(&mutex));
		memset(&init_time, 0, sizeof(init_time));
	}
	if (init_time.tv_usec == 0)
	{
		if (gettimeofday(&init_time, 0) == -1)
			return (ft_return_error("gettimeofday error"));
		pthread_mutex_init(&mutex, 0);
		return (0);
	}
	pthread_mutex_lock(&mutex);
	if (gettimeofday(&time, 0) == -1)
		return (ft_return_error("gettimeofday error"));
	msec = (time.tv_sec - init_time.tv_sec) * 1000
		+ (time.tv_usec - init_time.tv_usec) / 1000;
	pthread_mutex_unlock(&mutex);
	return (msec);
}

// int main()
// {
// 	printf("%d\n", ft_get_time());
// 	usleep(42000);
// 	printf("%d\n", ft_get_time());
// }

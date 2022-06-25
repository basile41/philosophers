/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:47:42 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/25 19:50:14 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	p->start = -1;
	while (42)
	{
		if (p->state == THINKING)
			ft_try_to_eat(p);
		else if (p->state == EATING && ft_get_time(p->start) >= p->arg.t_to_eat)
			ft_start_to_sleep(p);
		else if (p->state == SLEEPING)
			ft_sleeping(p);

		usleep(100);
	}
	return (0);
}

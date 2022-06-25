/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:47:42 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/25 22:03:57 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_die(t_philo *p)
{
	*p->is_end = 1;
	ft_safe_print(p->id, "died", p->print_mutex);
}

void	*ft_philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	// if (p->id % 2 == 0)
	// 	usleep(10000);
	ft_safe_print(p->id, "coucou", p->print_mutex);
	p->start = -1;
	while (42)
	{
		if (p->state == THINKING)
			ft_try_to_eat(p);
		else if (p->state == EATING && ft_get_time(p->start) >= p->arg.t_to_eat)
			ft_start_to_sleep(p);
		else if (p->state == SLEEPING)
			ft_sleeping(p);
		if (ft_get_time(p->last_meal) >= p->arg.t_to_die)
			ft_die(p);
		if (*p->is_end)
			break ;
		usleep(100);
	}
	return (0);
}

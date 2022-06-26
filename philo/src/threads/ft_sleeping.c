/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:07:24 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/26 20:09:04 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_to_sleep(t_philo *p)
{
	p->start = ft_safe_print(p, "is sleeping");
	p->eaten++;
	if (p->eaten == p->arg.nb_of_meal)
		ft_nb_of_meal(p);
	ft_release_fork(p->my_fork[RIGHT]);
	ft_release_fork(p->my_fork[LEFT]);
	
	p->hand[RIGHT] = 0;
	p->hand[LEFT] = 0;
	p->state = SLEEPING;
}

void	ft_sleep(t_philo *p, int sleep_time)
{
	int	time_to_die;

	time_to_die = p->arg.t_to_die - ft_get_time(p->last_meal);
	if (time_to_die < sleep_time)
		sleep_time = time_to_die;
	usleep(900 * sleep_time);
}

void	ft_sleeping(t_philo *p)
{
	int	sleep_time;

	sleep_time = p->arg.t_to_sleep - ft_get_time(p->start);
	if (sleep_time <= 0)
	{
		p->state = THINKING;
		ft_safe_print(p, "is thinking");
	}
	else
		ft_sleep(p, sleep_time);
}

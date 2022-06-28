/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:47:42 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/28 12:10:47 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_die(t_philo *p)
{
	ft_safe_print(p, "died");
	pthread_mutex_lock(p->print_mutex);
	*p->is_end = p->id;
	pthread_mutex_unlock(p->print_mutex);
}

int	ft_is_end(t_philo *p)
{
	int	r;

	r = 0;
	pthread_mutex_lock(p->print_mutex);
	if (*p->is_end)
		r = 1;
	pthread_mutex_unlock(p->print_mutex);
	return (r);
}

void	*ft_philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		ft_sleep(p, p->arg.t_to_eat);
	// else if (p->id == p->arg.nb_of_philo)
	// 	usleep(10000 + p->arg.t_to_eat);
	// ft_safe_print(p->id, "coucou", p->print_mutex);
	p->last_meal = 0;
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
		usleep(100);
		if (ft_is_end(p))
			break ;
	}
	return (0);
}

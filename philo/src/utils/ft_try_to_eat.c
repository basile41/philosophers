/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_to_eat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:56 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/25 20:12:34 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_release_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->status = 0;
	pthread_mutex_unlock(&fork->mutex);
}

int	ft_take_fork(t_philo *p, t_fork *fork)
{
	int	success;

	success = 1;
	pthread_mutex_lock(&fork->mutex);
	if (fork->status == 0)
		fork->status = 1;
	else
		success = 0;
	pthread_mutex_unlock(&fork->mutex);
	if (success)
		ft_safe_print(p->id, "has taken a fork", p->print_mutex);
	return (success);
}

void	ft_try_to_eat(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		if (p->hand[RIGHT] == 0)
			p->hand[RIGHT] = ft_take_fork(p, p->my_fork[RIGHT]);
		if (p->hand[RIGHT])
			p->hand[LEFT] = ft_take_fork(p, p->my_fork[LEFT]);
	}
	else
	{
		if (p->hand[LEFT] == 0)
			p->hand[LEFT] = ft_take_fork(p, p->my_fork[LEFT]);
		if (p->hand[LEFT])
			p->hand[RIGHT] = ft_take_fork(p, p->my_fork[RIGHT]);
	}
	if (p->hand[RIGHT] && p->hand[LEFT])
	{
		p->start = ft_safe_print(p->id, "is eating", p->print_mutex);
		p->last_meal = p->start;
		p->state = EATING;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:56 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/24 17:42:57 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_release_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mutex);
	fork->status = 0;
	pthread_mutex_unlock(&fork->mutex);
}

int	ft_take_fork(t_philo *philo, t_fork *fork)
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
		ft_safe_print(philo->id, "has taken a fork", philo->print_mutex);
	return (success);
}

int	ft_try_to_eat(t_philo *philo)
{
	int	time;

	time = -1;
	if (philo->id % 2 == 0)
	{
		if (philo->hand[RIGHT] == 0)
			philo->hand[RIGHT] = ft_take_fork(philo, philo->my_fork[RIGHT]);
		if (philo->hand[RIGHT])
			philo->hand[LEFT] = ft_take_fork(philo, philo->my_fork[LEFT]);
	}
	else
	{
		if (philo->hand[LEFT] == 0)
			philo->hand[LEFT] = ft_take_fork(philo, philo->my_fork[LEFT]);
		if (philo->hand[LEFT])
			philo->hand[RIGHT] = ft_take_fork(philo, philo->my_fork[RIGHT]);
	}
	if (philo->hand[RIGHT] && philo->hand[LEFT])
		time = ft_safe_print(philo->id, "is eating", philo->print_mutex);
	return (time);
}

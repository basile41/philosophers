/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:47:42 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/24 18:24:00 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *arg)
{
	t_philo	*p;
	int		hand[2];
	int		time;

	p = (t_philo *)arg;
	p->start_of_meal = -1;
	// ft_safe_print(p->id, "has taken a fork\n", p->print_mutex);
	while (42)
	{
		if (p->start_of_meal == -1)
			p->start_of_meal = ft_try_to_eat(p);
		else if (ft_get_time() - p->start_of_meal >= p->arg.t_to_die)
		{
			p->eaten++;
			ft_release_fork(p->my_fork[RIGHT]);
			ft_release_fork(p->my_fork[LEFT]);
		}

	}
	return (0);
}

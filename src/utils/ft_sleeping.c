/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleeping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:07:24 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/25 19:53:17 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_start_to_sleep(t_philo *p)
{
	p->start = ft_safe_print(p->id, "is sleeping", p->print_mutex);
	ft_release_fork(p->my_fork[RIGHT]);
	ft_release_fork(p->my_fork[LEFT]);
	p->eaten++;
	p->state = SLEEPING;
}

void	ft_sleeping(t_philo *p)
{
	if (ft_get_time(p->start >= p->arg.t_to_sleep))
	{
		p->state = THINKING;
		ft_safe_print(p->id, "is thinking", p->print_mutex);
	}
}

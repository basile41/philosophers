/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_of_meal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:40:41 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/26 20:39:40 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_nb_of_meal(t_philo *p)
{
	static int	count;

	pthread_mutex_lock(p->print_mutex);
	count++;
	if (count == p->arg.nb_of_philo)
		*p->is_end = -1;
	pthread_mutex_unlock(p->print_mutex);
}

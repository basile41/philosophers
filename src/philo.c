/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:59:21 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/07 00:53:41 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_philo *p)
{

}

void	*ft_philo(void *arg)
{
	t_philo	*p;

	p = arg;
	while (p->eaten != p->arg->nb_of_meal && !ft_is_dead(p))
	{
		
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:42 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/29 12:32:39 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_threads_join(t_data *data)
{
	int		i;
	t_philo	*p;

	p = data->philo_tab;
	i = 0;
	while (i < data->arg.nb_of_philo)
	{
		pthread_join(p->th, 0);
		i++;
		p++;
	}
}

void	ft_destroy(t_data *data)
{
	int		i;

	pthread_mutex_destroy(&data->print_mutex);
	i = 0;
	while (i < data->arg.nb_of_philo)
	{
		pthread_mutex_destroy(&data->fork_tab[i].mutex);
		i++;
	}
	free(data->philo_tab);
	free(data->fork_tab);
}

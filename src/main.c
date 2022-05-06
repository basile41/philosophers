/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:52:59 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/07 00:49:52 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init(t_data *data, t_arg *arg)
{
	int		i;
	t_philo	*p;

	// p_tab = malloc(arg->nb_of_philo * sizeof(t_philo));
	// data->fork_tab = malloc(arg->nb_of_philo * sizeof(int));
	// if (p_tab == NULL || data->fork_tab == NULL)
	// 	return (ft_return_error("malloc error"));
	// data->philo_tab = p_tab;
	i = 0;
	while (i < arg->nb_of_philo)
	{
		p = data->philo_tab + i;
		p->arg = arg;
		p->id = i + 1;
		p->my_fork[LEFT] = &data->fork_tab[i];
		p->my_fork[RIGHT] = &data->fork_tab[i + 1];
		if (p->id == arg->nb_of_philo)
			p->my_fork[RIGHT] = &data->fork_tab[0];
		i++;
	}
	return (0);
}

void	ft_set_arg(t_arg *arg, int argc, char **argv)
{
	arg->nb_of_philo = ft_atoi(argv[1]);
	arg->t_to_die = ft_atoi(argv[2]);
	arg->t_to_sleep = ft_atoi(argv[3]);
	if (argc == 6)
		arg->nb_of_meal = ft_atoi(argv[4]);
	else
		arg->nb_of_meal = -1;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_arg	arg;
	int		ret;

	if (argc == 5 || argc == 6)
	{
		memset(&data, 0, sizeof(data));
		ret = gettimeofday(&data.time, 0);
		if (ret < 0)
			ft_return_error("gettimeofday error");
		ft_set_arg(&arg, argc, argv);
	}
}

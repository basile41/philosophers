/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:52:59 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/29 15:15:56 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		memset(&data, 0, sizeof(data));
		ft_get_time(0);
		ft_set_arg(&data.arg, argc, argv);
		ft_init(&data);
		ft_threads_join(&data);
		ft_destroy(&data);
		// if (data.is_end > 0)
		// 	printf("%05d %d %s\n",ft_get_time(0), data.is_end, "died");
	}
}

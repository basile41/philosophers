/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:53:58 by bregneau          #+#    #+#             */
/*   Updated: 2022/05/06 21:47:48 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>
# include <ctype.h>

typedef struct s_philo
{
	int	id;
	int	*right;
	int	*left;
	int	eaten;
	int	nb_of_meal;
}	t_philo;

typedef struct s_data
{
	struct timeval	time;
	int				nb_of_philo;
	int				t_to_die;
	int				t_to_sleep;
	int				nb_of_meal;
}	t_data;

void	*ft_philo(void *arg);

#endif
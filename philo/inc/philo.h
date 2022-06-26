/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:53:58 by bregneau          #+#    #+#             */
/*   Updated: 2022/06/26 15:49:45 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define RIGHT 0
# define LEFT 1

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define DEAD 3

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>
# include <ctype.h>

typedef struct s_arg
{
	int	nb_of_philo;
	int	t_to_eat;
	int	t_to_die;
	int	t_to_sleep;
	int	nb_of_meal;
}	t_arg;

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	pthread_t		th;
	pthread_mutex_t	*print_mutex;
	t_fork			*my_fork[2];
	int				hand[2];
	int				state;
	int				start;
	int				last_meal;
	int				eaten;
	int				*is_end;
	t_arg			arg;
}	t_philo;

typedef struct s_data
{
	t_arg			arg;
	int				is_end;
	pthread_mutex_t	print_mutex;
	t_philo			*philo_tab;
	t_fork			*fork_tab;
}	t_data;

int		ft_init(t_data *data);

//threads

void	*ft_philo_routine(void *arg);

//utils

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);

int		ft_take_fork(t_philo *philo, t_fork *fork);
void	ft_release_fork(t_fork *fork);
void	ft_try_to_eat(t_philo *philo);
void	ft_start_to_sleep(t_philo *p);
void	ft_sleeping(t_philo *p);
void	ft_sleep(t_philo *p, int sleep_time);

int		ft_return_error(char *message);
int		ft_get_time(int start);
// void	ft_putstr_mutex(char *str, pthread_mutex_t *mutex);
int		ft_safe_print(int x, char *str, pthread_mutex_t *mutex);

#endif
#include "philo.h"

pthread_mutex_t lock[10];
int	counter;

long long	ft_get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
	{
		printf("ft_get_time error: gettimeofday\n");
		return (-1);
	}
	return (1);
}

void *do_something(void *args)
{
	pthread_mutex_lock(&lock[0]);

	pthread_mutex_unlock(&lock[0]);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t tid[2];
	
	for (int i = 0; i < 10; i += 1)
		pthread_mutex_init(&lock[i], NULL);

	for (int i = 0; i < 2; i += 1)
		pthread_create(&tid[i], NULL, &do_something, NULL);

	for (int i = 0; i < 2; i += 1)
		pthread_join(tid[i], NULL);

	printf("Counter is %i\n", counter);
	return (0);
}

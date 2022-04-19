#include "philo.h"

pthread_mutex_t lock;
int	counter;

void *do_something(void *args)
{
	pthread_mutex_lock(&lock);
	printf("Job %i is starting\n", counter);

	int i = 0;
	while (i < 10000000)
		i += 1;

	counter += 1;
	printf("Job %i is finishing\n", counter);
	pthread_mutex_unlock(&lock);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t tid[2];
	
	pthread_mutex_init(&lock, NULL);

	int i = 0;
	while (i < 2)
	{
		pthread_create(&tid[i], NULL, &do_something, NULL);
		i += 1;
	}

	i = 0;
	while (i < 2)
	{
		pthread_join(tid[i], NULL);
		i += 1;
	}


	return (0);
}

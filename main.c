#include "philo.h"

int g_number;


void	*nani(void *arg)
{
	int i = 0;
	while (i < 10000000)
		i += 1;
	printf("This is child number %i\n", g_number);
	g_number += 1;
}

int	main(int argc, char **argv)
{
	int num = 10;
	pthread_t thread[num];

	int i = 0;
	while (i < num)
	{
		pthread_create(&thread[i], NULL, nani, NULL);
		i += 1;
	}
	

	return (0);
}

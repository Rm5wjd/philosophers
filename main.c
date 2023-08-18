#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count = 0;

void	*p_function(void *data)
{
	pthread_mutex_t *mutex_arr;
	int	i;


	mutex_arr = (pthread_mutex_t *)data;
	i = 0;
	pthread_mutex_lock(&mutex_arr[1]);
	while (i++ != 100)
		count++;
	//pthread_mutex_unlock(&mutex_arr[1]);
	return (data);
}

int	main()
{
	pthread_mutex_t	*mutex_arr;
	pthread_t		pthread[2];
	int				status;

	mutex_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 5);
	for (int i = 0; i < 5; i++)
	{
		pthread_mutex_init(&(mutex_arr[i]), NULL);
	}
	pthread_create(&pthread[0], NULL, p_function, mutex_arr);
	pthread_create(&pthread[1], NULL, p_function, mutex_arr);
	pthread_join(pthread[0], (void **)&status);
	pthread_join(pthread[1], (void **)&status);
	printf("%d", count);
}

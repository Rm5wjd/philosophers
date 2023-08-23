#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

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
	struct timeval now;

	gettimeofday(&now, NULL);
	printf("%ld %d %ld", now.tv_sec, now.tv_usec, (now.tv_sec * 1000 + now.tv_usec / 1000));
}

#include "../includes/philosophers.h"

int mails = 0;
pthread_mutex_t	mutex;

void	routine(void)
{
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

static void	init_philos(t_table *table)
{
	int			i;
	pthread_t	*thread;
	t_philo		*curr_philo;

	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philos);
	while (i < table->nbr_of_philos)
	{
		curr_philo = table->philos + i;
		curr_philo->id = i;
		pthread_create(&(curr_philo->thread), NULL, routine, NULL);
		printf("Thread %d just started\n", i);
		i++;
	}
	i = 0;
	while (i < table->nbr_of_philos)
	{
		curr_philo = table->philos + i;
		pthread_join(curr_philo->thread, NULL);
		printf("Thread %d just quit\n", i);
		i++;
	}
}

static void	init_table(t_table *table, char **argv)
{
	table->nbr_of_philos = atoi(argv[1]);
	init_philos(table);
}

static void	print_error(int err_code)
{
	if (err_code == 1)
	{
		write(2, "Usage: number_of_philos time_to_die time_to_eat " \
			"time_to_sleep [number_of_times_each_philo_eats]\n", 96);
	}
}

static int	valid_args(int params, char **args)
{
	if (params != 4 && params != 5)
	{
		print_error(1);
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_table		table;

	if (!valid_args(argc - 1, argv))
		return (1);
	init_table(&table, argv);
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}

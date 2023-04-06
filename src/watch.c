void	watch(t_info *info)
{
	while (info->end_flag == 0)
	{
	}
	pthread_mutex_destroy()
}

void	watchman(t_info *info)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, (void *)watch, (t_info *)&info);
}

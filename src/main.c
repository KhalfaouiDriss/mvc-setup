#include "../include/mvc.h"

int	setup(const char *project)
{
	if (setup_controllers(project) != 0)
		return (-1);
	if (setup_models(project) != 0)
		return (-1);
	if (setup_views(project) != 0)
		return (-1);
	if (setup_public(project) != 0)
		return (-1);
	if (setup_config(project) != 0)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	const char	*project = av[1];

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s <project_name>\n", av[0]);
		return (1);
	}
	if (create_dir_recursive(project) != 0)
	{
		fprintf(stderr, "Failed to create base project directory: %s\n",
			project);
		return (1);
	}
	if (setup(project) != 0)
	{
		fprintf(stderr, "Setup failed. Project creation aborted.\n");
		return (1);
	}
	printf("\n Project %s created successfully!\n", project);
	return (0);
}

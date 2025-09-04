#ifndef MVC
# define MVC

# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

int	create_dirs_loop(char *tmp);
int	create_dir_recursive(const char *dir);
int	create_file(const char *path, const char *content);

int	setup_controllers(const char *project);
int	setup_models(const char *project);
int	setup_views(const char *project);
int	setup_public(const char *project);
int	setup_config(const char *project);

#endif
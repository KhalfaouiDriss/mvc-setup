#include "../include/mvc.h"

int	create_dirs_loop(char *tmp)
{
	char	*p;

	p = tmp + 1;
	while (*p)
	{
		if (*p == '/')
		{
			*p = '\0';
			if (mkdir(tmp, 0755) != 0 && errno != EEXIST)
			{
				perror("mkdir");
				return (-1);
			}
			*p = '/';
		}
		p++;
	}
	if (mkdir(tmp, 0755) != 0 && errno != EEXIST)
	{
		perror("mkdir");
		return (-1);
	}
	return (0);
}

int	create_dir_recursive(const char *dir)
{
	char	tmp[256];

	if (snprintf(tmp, sizeof(tmp), "%s", dir) >= (int)sizeof(tmp))
	{
		fprintf(stderr, "Error: path too long: %s\n", dir);
		return (-1);
	}
	if (create_dirs_loop(tmp) != 0)
		return (-1);
	printf("[+] Created directory: %s\n", dir);
	return (0);
}

int	create_file(const char *path, const char *content)
{
	FILE *fp = fopen(path, "w");

	if (fp == NULL)
	{
		perror("fopen");
		return (-1);
	}
	if (content != NULL && fprintf(fp, "%s", content) < 0)
	{
		perror("fprintf");
		fclose(fp);
		return (-1);
	}
	if (fclose(fp) != 0)
	{
		perror("fclose");
		return (-1);
	}

	printf("[+] Created file: %s\n", path);
	return (0);
}
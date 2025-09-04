/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourname <yourname@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:00:00 by yourname          #+#    #+#             */
/*   Updated: 2025/09/04 13:00:00 by yourname         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mvc.h"

int	setup_controllers(const char *project)
{
	char	path[256];

	if (snprintf(path, sizeof(path), "%s/app/controllers", project) >=
		(int)sizeof(path))
		return (-1);
	if (create_dir_recursive(path) != 0)
		return (-1);
	if (snprintf(path, sizeof(path), "%s/app/controllers/HomeController.php",
			project) >= (int)sizeof(path))
		return (-1);
	if (create_file(path,
		"<?php\nclass HomeController {\n"
		"    public function index() {\n"
		"        echo 'Hello from HomeController!';\n"
		"    }\n}\n") != 0)
		return (-1);
	return (0);
}

int	setup_models(const char *project)
{
	char	path[256];

	if (snprintf(path, sizeof(path), "%s/app/models", project) >=
		(int)sizeof(path))
		return (-1);
	if (create_dir_recursive(path) != 0)
		return (-1);
	if (snprintf(path, sizeof(path), "%s/app/models/User.php", project) >=
		(int)sizeof(path))
		return (-1);
	if (create_file(path,
		"<?php\nclass User {\n"
		"    // User model code\n}\n") != 0)
		return (-1);
	return (0);
}

int	setup_views(const char *project)
{
	char	path[256];

	if (snprintf(path, sizeof(path), "%s/app/views", project) >=
		(int)sizeof(path))
		return (-1);
	if (create_dir_recursive(path) != 0)
		return (-1);
	if (snprintf(path, sizeof(path), "%s/app/views/home.php", project) >=
		(int)sizeof(path))
		return (-1);
	if (create_file(path, "<h1>Welcome to MVC Project</h1>") != 0)
		return (-1);
	return (0);
}

int	setup_public(const char *project)
{
	char	path[256];

	if (snprintf(path, sizeof(path), "%s/public", project) >=
		(int)sizeof(path))
		return (-1);
	if (create_dir_recursive(path) != 0)
		return (-1);
	if (snprintf(path, sizeof(path), "%s/public/index.php", project) >=
		(int)sizeof(path))
		return (-1);
	if (create_file(path,
		"<?php\nrequire '../app/controllers/HomeController.php';\n"
		"$controller = new HomeController();\n"
		"$controller->index();\n") != 0)
		return (-1);
	return (0);
}

int	setup_config(const char *project)
{
	char	path[256];

	if (snprintf(path, sizeof(path), "%s/config", project) >=
		(int)sizeof(path))
		return (-1);
	if (create_dir_recursive(path) != 0)
		return (-1);
	if (snprintf(path, sizeof(path), "%s/config/database.php", project) >=
		(int)sizeof(path))
		return (-1);
	if (create_file(path,
		"<?php\n// Database config\n"
		"$host = 'localhost';\n$user = 'root';\n"
		"$pass = '';\n$db = 'mydb';\n") != 0)
		return (-1);
	return (0);
}

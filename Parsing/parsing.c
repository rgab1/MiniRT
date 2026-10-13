/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 23:11:53 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/10/13 20:11:06 by adi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		exit_error(OPEN_FAILED, 4);
	return (fd);
} 

static void	parse_into_struct(char *line, t_scene *scene, bool is_light,
		bool is_obj)
{
	if ()
}

t_scene *parse_recursive(int fd, t_scene *scene, int obj_idx, int light_idx)
{
	char	*line;
	bool	is_obj;
	bool	is_light;

	is_light = 0;
	is_obj = 0;
	line = get_next_line(fd);
	if (!line)
	{
		scene = (t_scene *)malloc(sizeof(t_scene));
		if (!scene)
			exit_error(MALLOC_FAILED, 3);
		scene->objects = malloc(sizeof(t_object) * (obj_idx + 1));
		scene->lights = malloc(sizeof(t_light) * (light_idx + 1));
        scene->objects[obj_idx].id = NULL;
        scene->lights[light_idx].id = NULL;
		return (scene);
	}
	check_id(line, &is_light, &is_obj);
	scene = parse_recursive(fd, scene, obj_idx + is_obj, light_idx + is_light);

	parse_into_struct(line, scene);
    // 4. UNWIND: We are coming back up from the base case.
    // The scene and arrays are now allocated. Parse the current line into its slot.
	if (is_obj)
		parse_object_data(line, &scene->objects[obj_idx]);
	else if (is_light)
		parse_light_data(line, &scene->lights[light_idx]);
	else if (is_ambient_identifier(line))
		parse_ambient_data(line, scene); // Stored directly in t_scene
	else if (is_camera_identifier(line))
		parse_camera_data(line, scene);  // Stored directly in t_scene

	free(line);
	return (scene);
}

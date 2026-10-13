/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 18:10:41 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/10/13 18:07:57 by adi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minirt.h>

t_scene	*scene_init(void)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		exit_error(MALLOC_FAILED, 3);
	scene->amn_light = NULL;
	scene->lights = NULL;
	scene->objects = NULL;
	return (scene);
}

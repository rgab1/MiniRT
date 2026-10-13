/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:32:44 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/10/13 18:12:54 by adi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H

# include <utils.h>
# include <errors.h>

# include <stdlib.h>

typedef struct	s_vec3
{
	double			x;
	double			y;
	double			z;
}				t_vec3;

typedef struct	s_light
{
	char			id;
	t_vec3			*coords;
	double			bright;
	unsigned char	*rgb; // bonus
}				t_light;

typedef struct	s_object
{
	char			id; // sum of the chars id of the object
	t_vec3			*coords; // 3 ints
	unsigned char	*rgb; // 3 ints between 0 and 255
	double			*specs; // depends on the object 
}				t_object;

typedef struct	s_camera
{
	t_vec3			*coords;
	t_vec3			*orientation_vector;
	int				*fov;
}				t_camera;

typedef struct	s_scene
{
	t_camera		*camera;
	unsigned char	*amb_light; // 1 int for lighting ratio then 3 ints for rgb
	t_light			*lights;
	t_object		*objects;
}				t_scene;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 16:32:44 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/09/22 17:32:33 by gabinrivault     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <>

typedef struct	s_mini
{
	int	*amb_light; // 1 int for lighting ratio then 3 ints for rgb

}				t_mini;

typedef struct	s_light
{
	int				*coords;
	int				bright;
	int				*rgb;
}				t_light;

typedef struct	s_object
{
	char	*id; // 1-2 chars
	int		*coords; // 3 ints
	int		*rgb; // 3 ints
}				t_object;

#endif

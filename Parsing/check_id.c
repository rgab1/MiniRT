/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi </var/spool/mail/adi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:54:04 by adi               #+#    #+#             */
/*   Updated: 2026/10/13 18:17:08 by adi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	check_id(char *line, int *is_light, int *is_obj)
{
	char	**line_segments;

	if (!line)
		return ; // a gérer
	line_segments = ft_split(line, ' ');
	if (line_segments[0][0] < 64)
		*is_obj = 1;
	else if (line_segments[0][0] == 'L')
		*is_light = 1;
	free(line_segments);
}

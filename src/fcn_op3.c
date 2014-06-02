/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcn_op3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 14:53:16 by jbernabe          #+#    #+#             */
/*   Updated: 2014/02/15 20:35:22 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector		ft_normalize(t_vector pixel_pos)
{
	double		len;
	t_vector	ray;

	len = calcul_t(pixel_pos);
	ray.x_pos = pixel_pos.x_pos / len;
	ray.y_pos = pixel_pos.y_pos / len;
	ray.z_pos = pixel_pos.y_pos / len;
	return (ray);
}

double			calcul_t(t_vector v)
{
	double	t;

	t = sqrt((v.x_pos * v.x_pos) + (v.y_pos * v.y_pos) + (v.z_pos * v.z_pos));
	return ((double)t);
}
	
t_vector		pixel_pos(t_vector view_up_left, t_vector rightvect
						, t_vector upvect, double x, double y)
{
	double		x_indent;
	double		y_indent;
	double		temp1;
	double		temp2;
	t_vector	pixelpos;

	x_indent = CAMERA_LEN / (double)RESO_X;
	y_indent = CAMERA_HEIGHT / (double)RESO_Y;
	temp1 = (double)x * x_indent;
	temp2 = (double)y * y_indent;
	pixelpos = ft_add_vector(view_up_left, ft_double_by_vector(temp1, rightvect));
	pixelpos = ft_subb_vector(pixelpos, ft_double_by_vector(temp2, upvect));
	return (pixelpos);
}

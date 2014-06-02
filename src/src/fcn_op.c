/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcn_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 20:21:34 by jbernabe          #+#    #+#             */
/*   Updated: 2014/02/15 18:44:47 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector		ft_div_vector(t_vector v1, t_vector v2)
{
	t_vector	new_v;

	new_v.x_pos = v1.x_pos / v2.x_pos;
	new_v.y_pos = v1.y_pos / v2.y_pos;
	new_v.z_pos = v1.z_pos / v2.z_pos;
	return (new_v);
}

t_vector		ft_middle_point_vect(t_vector v1, t_vector v2)
{
	t_vector	point;

	point.x_pos = (v1.x_pos + v2.x_pos) / 2;
	point.y_pos = (v1.y_pos + v2.y_pos) / 2;
	point.z_pos = (v1.z_pos + v2.z_pos) / 2;
	return (point);
}

double			ft_distance_vect(t_vector v1, t_vector v2)
{
	double		result;

	result = (double)sqrt((pow(v2.x_pos - v1.x_pos, 2)
				+ pow(v2.y_pos - v2.x_pos, 2)
				+ pow(v2.z_pos - v1.z_pos, 2)));
	return (result);
}

t_vector		ft_mult_vector(t_vector v1, t_vector v2)
{
	t_vector	new_v;

	new_v.x_pos = v1.x_pos * v2.x_pos;
	new_v.y_pos = v1.y_pos * v2.y_pos;
	new_v.z_pos = v1.z_pos * v2.z_pos;
	return (new_v);
}

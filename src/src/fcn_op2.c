/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcn_op2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 13:17:10 by jbernabe          #+#    #+#             */
/*   Updated: 2014/02/15 18:46:13 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

t_vector		ft_double_by_vector(double a, t_vector v1)
{
	t_vector	new_v;

	new_v.x_pos = v1.x_pos * a;
	new_v.y_pos = v1.y_pos * a;
	new_v.z_pos = v1.z_pos * a;
	return (new_v);
}

t_vector		ft_add_vector(t_vector v1, t_vector v2)
{
	t_vector	new_v;

	new_v.x_pos = v1.x_pos + v2.x_pos;
	new_v.y_pos = v1.y_pos + v2.y_pos;
	new_v.z_pos = v1.z_pos + v2.z_pos;
	return (new_v);
}

t_vector		ft_subb_vector(t_vector v1, t_vector v2)
{
	t_vector	new_v;

	new_v.x_pos = v1.x_pos - v2.x_pos;
	new_v.y_pos = v1.y_pos - v2.y_pos;
	new_v.z_pos = v1.z_pos - v2.z_pos;
	return (new_v);
}

t_vector		creat_vector(double x, double y, double z)
{
	t_vector	v;

	v.x_pos = x;
	v.y_pos = y;
	v.z_pos = z;
	return (v);
}

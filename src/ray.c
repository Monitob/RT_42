/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:40:53 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/02 19:06:45 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include <math.h>

void		ft_relize_img(t_univers *u, int x, int y)
{
	ft_ray_shoot(u, x, y);
	u->colors->co1 = 0xff;
	u->colors->co2 = 0xff;
	u->colors->co3 = 0xff;

	mlx_pixel_put (u->mlx, u->win_ray, x, y, 0xffffff);
}

double		ft_draw_sphere(t_vector dir, t_vector orig)
{
	double	a;
	double	b;
	double	c;
	double	det;
	double	t;

	t = -1;
	a = pow(dir.x_pos, 2) + pow(dir.y_pos, 2) + pow(dir.z_pos, 2);
	b = 2 * (dir.x_pos * (orig.x_pos - X_SPHERE)
			+ dir.y_pos * (orig.y_pos - Y_SPHERE)
			+ dir.z_pos * (orig.z_pos - Z_SPHERE));
	c = (pow(orig.x_pos - X_SPHERE, 2) + pow(orig.y_pos - Y_SPHERE, 2)
			+ pow(orig.z_pos - Z_SPHERE, 2) - pow(R_SPHERE, 2));
	det = (b * b) - (4*a*c);
	if (det > 0)
		t = (-b - sqrt(det)) / (2.0 * a);
	return (t);
}

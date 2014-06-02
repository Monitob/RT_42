/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 13:40:53 by jbernabe          #+#    #+#             */
/*   Updated: 2014/02/15 20:48:19 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include <stdio.h>
#include <math.h>

int	init_space(t_univers *u)
{
	u = (t_univers *)malloc(sizeof(t_univers));
	u->camera = (t_camera *)malloc(sizeof(*(u->camera)));
	u->vector = (t_vector *)malloc(sizeof(*(u->vector)));
	u->camera->position = creat_vector((double)CAM_X, (double)CAM_Y
			, (double)CAM_Z);
	u->camera->direction.x_pos = ((double)V_DIREX - (double)CAM_X);
	u->camera->direction.y_pos = ((double)V_DIREY - (double)CAM_Y);
	u->camera->direction.z_pos = ((double)V_DIREZ - (double)CAM_Z);
	u->camera->direction = ft_normalize(u->camera->direction);
	u->camera->upvect = creat_vector((double)0, (double)0, (double)1);
	u->camera->rightvect.x_pos = (u->camera->direction.y_pos * u->camera->upvect.z_pos)
					- (u->camera->direction.z_pos * u->camera->upvect.y_pos);
	u->camera->rightvect.y_pos = (u->camera->direction.z_pos * u->camera->upvect.x_pos)
					- (u->camera->direction.z_pos * u->camera->upvect.y_pos);
	u->camera->rightvect.z_pos = (u->camera->direction.x_pos * u->camera->upvect.y_pos)
					- (u->camera->direction.y_pos * u->camera->upvect.x_pos);
	view_plane_camera(u);
	return (0);
}

		
int		view_plane_camera(t_univers *v)
{
	t_vector	temp1;
	t_vector	temp2;
	t_vector	temp0;

	temp0 = ft_double_by_vector((double)CAMERA_DIST_V, v->camera->direction);
	temp1 = ft_double_by_vector((double)CAMERA_HEIGHT/2, v->camera->upvect);
	temp2 = ft_double_by_vector((double)CAMERA_LEN/2, v->camera->rightvect);
	v->view_up_left  =  ft_add_vector(ft_add_vector(v->camera->position
				, temp0), temp1);
	v->view_up_left = ft_subb_vector(v->view_up_left, temp2);
	ft_windows_detect(v);
	return (0);
}

void		ft_windows_detect(t_univers *u)
{
	int	x;
	int	y;
	
	x = 0;
	while (x < RESO_X)
	{
		y = 0;
		while (y < RESO_Y)
		{
			u->pixel_pos = pixel_pos(u->view_up_left, u->camera->rightvect,
					u->camera->upvect, x , y);
			u->ray_normal = ft_normalize(ft_subb_vector(u->pixel_pos
						, u->camera->position));
			ft_draw_sphere(u->camera->position, u->ray_normal);
			y++;
		}
		x++;
	}
}

double		ft_draw_sphere(t_vector orig, t_vector dir)
{
	double	a;
	double	b;
	double	c;
	double	det;
	double	t;

	a = 1.0 / 4.0; /*pow(dir.x_pos, 2) + pow(dir.y_pos, 2) + pow(dir.z_pos, 2);*/
	b = 2 * (dir.x_pos * (orig.x_pos - X_SPHERE)
			+ dir.y_pos * (orig.y_pos - Y_SPHERE)
			+ dir.z_pos * (orig.z_pos - Z_SPHERE));
	c = (pow(orig.x_pos - X_SPHERE, 2) + pow(orig.y_pos - Y_SPHERE, 2)
			+ pow(orig.z_pos - Z_SPHERE, 2) - pow(R_SPHERE, 2));
	det = (b * b) - (4*a*c);
	printf("%f\n", det);
	if (det >= 0)
	{
		t = (-b - sqrt(det)) / (2.0 * a);
		return (t);
	}
	return (0);
}

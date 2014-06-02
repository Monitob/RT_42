/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 17:24:03 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/02 19:15:19 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv.h"

int			init_space(t_univers *u)
{
	u->camera = (t_camera *)malloc(sizeof(*(u->camera)));
	u->vector = (t_vector *)malloc(sizeof(*(u->vector)));
	u->colors = (t_rgb *)malloc(sizeof(*(u->colors)));
	u->camera->position = creat_vector((double)CAM_X, (double)CAM_Y
			, (double)CAM_Z);
	u->camera->direction.x_pos = ((double)V_DIREX - (double)CAM_X);
	u->camera->direction.y_pos = ((double)V_DIREY - (double)CAM_Y);
	u->camera->direction.z_pos = ((double)V_DIREZ - (double)CAM_Z);
	u->camera->direction = ft_normalize(u->camera->direction);
	u->camera->upvect = creat_vector((double)0, (double)0, (double)1);
	u->camera->rightvect.x_pos =
		(u->camera->direction.y_pos * u->camera->upvect.z_pos)
		- (u->camera->direction.z_pos * u->camera->upvect.y_pos);
	u->camera->rightvect.y_pos = 
		(u->camera->direction.z_pos * u->camera->upvect.x_pos)
		- (u->camera->direction.z_pos * u->camera->upvect.y_pos);
	u->camera->rightvect.z_pos =
		(u->camera->direction.x_pos * u->camera->upvect.y_pos)
		- (u->camera->direction.y_pos * u->camera->upvect.x_pos);
	view_plane_camera(u);
	ft_windows_detect(u);
	return (0);
}


void		view_plane_camera(t_univers *v)
{
	v->view_up_left.x_pos = v->camera->position.x_pos
		+ ((CAMERA_DIST_V * v->camera->direction.x_pos)
		+ (CAMERA_HEIGHT/2) * v->camera->upvect.x_pos)
		- ((CAMERA_LEN/2) * v->camera->rightvect.x_pos);
	v->view_up_left.y_pos = v->camera->position.y_pos
		+ ((CAMERA_DIST_V * v->camera->direction.y_pos)
		+ (CAMERA_HEIGHT/2) * v->camera->upvect.y_pos)
		- ((CAMERA_LEN/2) * v->camera->rightvect.y_pos);
	v->view_up_left.x_pos = v->camera->position.z_pos
		+ ((CAMERA_DIST_V * v->camera->direction.z_pos)
		+ (CAMERA_HEIGHT/2) * v->camera->upvect.z_pos)
		- ((CAMERA_LEN/2) * v->camera->rightvect.z_pos);
}

void		ft_windows_detect(t_univers *u)
{
	int		x;
	int		y;

	x = 0;
	while (x < RESO_X)
	{
		y = 0;
		while (y < RESO_Y)
		{
			if (ft_draw_sphere(u->camera->direction, u->camera->position) > 0)
				ft_relize_img(u, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window( u->mlx, u->win_ray, u->img, x, y );
}
/*passer l'address*/
double		ft_ray_shoot(t_univers *u, int x, int y)
{
		u->pixel_pos.x_pos = (u->view_up_left.x_pos 
				- u->camera->position.x_pos)
				+ u->camera->rightvect.x_pos * CAMERA_HEIGHT / RESO_Y
				* x - u->camera->upvect.x_pos * CAMERA_LEN / RESO_X * y;
		u->pixel_pos.y_pos = (u->view_up_left.y_pos 
				- u->camera->position.y_pos)
				+ u->camera->rightvect.y_pos * CAMERA_HEIGHT / RESO_Y
				* x - u->camera->upvect.y_pos * CAMERA_LEN / RESO_X * y;
		u->pixel_pos.z_pos = (u->view_up_left.z_pos 
				- u->camera->position.z_pos)
				+ u->camera->rightvect.z_pos * CAMERA_HEIGHT / RESO_Y
				* x - u->camera->upvect.z_pos * CAMERA_LEN / RESO_X * y;
		return (0);
}


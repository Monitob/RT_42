/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:49:35 by jbernabe          #+#    #+#             */
/*   Updated: 2014/06/02 18:42:02 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef				RTV_H
# define			RTV_H

# include			<math.h>
# include			<stdio.h>
# include			<mlx.h>
# include			<libft.h>

# define ESCAPE 65307
# define CAMERA_DIST_V	1.0 /*distance entre la cameraet le vieuw plan*/
# define CAMERA_LEN 0.35 /*LARGEUR*/
# define CAMERA_HEIGHT 0.5 /*HAUTERU*/
# define RESO_X 640 
# define RESO_Y 480
# define CAM_X 0.0
# define CAM_Y -10.0
# define CAM_Z 0.0
# define V_DIREX 0.0
# define V_DIREY 1.0
# define V_DIREZ 0.0
# define X_SPHERE 0.0 
# define Y_SPHERE 5.0 
# define Z_SPHERE 16.5 
# define R_SPHERE 4.0 
# define COLOR_SP 0xCC99FF


typedef struct		s_vector
{
	double			x_pos;
	double			y_pos;
	double			z_pos;
}					t_vector;

typedef struct		s_camera
{
	t_vector		position;
	t_vector		direction;
	t_vector		upvect;
	t_vector		rightvect;
}					t_camera;

typedef struct		s_rgb
{
	int				co1;
	int				co2;
	int				co3;
	int				cor1;
	int				cor2;
	int				cor3;
	int				cob1;
	int				cob2;
	int				cob3;
	int				cog1;
	int				cog2;
	int				cog3;
	int				cov1;
	int				cov2;
	int				cov3;
}					t_rgb;

typedef struct		s_univers
{
	int				key_type;
	void			*mlx;
	void			*win_ray;
	void			*img;
	int				bpp;
	int				endian;
	int				s_line;
	char			*data;
	t_camera		*camera;
	t_rgb			*colors;
	t_vector		view_up_left;
	t_vector		pixel_pos;
	t_vector		ray_normal;
	t_vector		*vector;
	
}					t_univers;

void		ft_relize_img(t_univers *u, int x, int y);
double		ft_ray_shoot(t_univers *u, int x, int y);
void		ft_windows_detect(t_univers *u);
int			init_space(t_univers *u);
double		ft_draw_sphere(t_vector dir, t_vector orig);
t_vector	ft_normalize(t_vector pixel_pos);
double		calcul_t(t_vector v);
t_vector	ft_double_by_vector(double a, t_vector v1);
t_vector	pixel_pos(t_vector view_up_left, t_vector rightvect
			, t_vector upvect, double x, double y);
void		view_plane_camera(t_univers *v);
t_vector	ft_mult_vector(t_vector v1, t_vector v2);
t_vector	ft_subb_vector(t_vector v1, t_vector v2);
t_vector	ft_add_vector(t_vector v1, t_vector v2);
t_vector	creat_vector(double x, double y, double z);
int			key_control(int key_code);
int			expose_hook(t_univers *v);
void		init_univers(t_univers *v);
void		init_windows(t_univers *v);

#endif

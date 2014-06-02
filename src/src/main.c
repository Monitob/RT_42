/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:29:10 by jbernabe          #+#    #+#             */
/*   Updated: 2014/02/15 19:06:24 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"

void		init_univers(t_univers *v)
{
	int	bpp;
	int	s_line;
	int	endian;

	bpp = s_line = endian = 0;
	v->img = mlx_new_image(v->mlx, RESO_X, RESO_Y);
	v->data = mlx_get_data_addr(v->img, &(bpp), &(s_line), &(endian));
}

int		key_control(int key_code)
{
	if(key_code == ESCAPE)
		exit(0);
	return (0);
}

int		expose_hook(t_univers *v)
{
		mlx_put_image_to_window(v->mlx, v->win_ray, v->data, 0, 0);
		return (0);
}

int	main(void)
{
	t_univers	uni;

	uni.mlx = mlx_init();
	uni.win_ray = mlx_new_window(uni.mlx, RESO_X, RESO_Y, "Rtv");
	init_univers(&uni);
	init_space(&uni);
	mlx_key_hook(uni.win_ray, &key_control, &uni);
	mlx_expose_hook(uni.mlx, &expose_hook, &uni);
	mlx_loop(uni.mlx);
	return (0);
}

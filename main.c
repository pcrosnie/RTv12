/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:00:36 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/26 16:04:47 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    ft_draw(t_data *ptr, float x, float y)
{
	int     nb;

	nb = (x * ptr->bits) / 8 + (y * ptr->len);
	ptr->data_addr[nb] = ptr->blue;
	ptr->data_addr[nb + 1] = ptr->green;
	ptr->data_addr[nb + 2] = ptr->red;
}

void	ft_set_obj(t_data *ptr)
{
	t_wall *wall;
	//	t_wall *ground;
	t_sph *sph;
	t_spot  *spot;

	spot = (t_spot *)malloc(sizeof(t_spot));
	wall = (t_wall *)malloc(sizeof(t_wall));
	//	ground = (t_wall *)malloc(sizeof(t_wall));
	sph = (t_sph *)malloc(sizeof(t_sph));
	ptr->wall = wall;
	ptr->wall->next = NULL;
	ptr->spot = spot;
	//	ptr->ground = ground;
	//	ft_set_coord(ptr);
	ptr->wall->nx = 0;
	ptr->wall->ny = -5;
	ptr->wall->nz = 0;
	ptr->wall->ax = 3;
	ptr->wall->ay = 0;
	ptr->wall->az = 5;
	ptr->spot->posx = 0;
	ptr->spot->posy = -50;
	ptr->spot->posz = 50;
	sph->cx = 0;
	sph->cy = 0;
	sph->cz = 50;
	sph->rayon = 5;
	sph->next = NULL;
	ptr->posx = 0;
	ptr->posy = 0;
	ptr->posz = 0;
	ptr->red = 255;
	ptr->green = 0;
	ptr->blue = 0;
	ptr->ahor = 0;
	ptr->aver = M_PI_2 + M_PI_4;
	ptr->sph = sph;
}

void    ft_set_window(t_data *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, 1200, 1200, "RTv1");
	ptr->im = mlx_new_image(ptr->mlx, 1200, 1200);
	ptr->data_addr = mlx_get_data_addr(ptr->im, &(ptr->bits), &(ptr->len), &(ptr->endian));
	ft_set_obj(ptr);
	ft_pixel_test(ptr);
//	ft_set_sphere(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->im, 0, 0);
//	mlx_hook(ptr->win, 2, 1L << 0, ft_move, ptr);
	mlx_loop(ptr->mlx);
}

int		main(void)
{
	t_data	*ptr;

	ptr = (t_data *)malloc(sizeof(t_data));
	ft_set_window(ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:00:36 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/02 11:38:00 by pcrosnie         ###   ########.fr       */
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
	ptr->wall->ny = -1;
	ptr->wall->nz = 0;
	ptr->wall->ax = -1;
	ptr->wall->ay = 0.001;
	ptr->wall->az = 1;
	ptr->spot->posx = 0.001;
	ptr->spot->posy = -30;
	ptr->spot->posz = 30;
	sph->cx = 0;
	sph->cy = 5;
	sph->cz = 30;
	sph->rayon = 5;
	sph->next = NULL;
	ptr->posx = 0;
	ptr->posy = 0;
	ptr->posz = 0;
	ptr->red = 255;
	ptr->green = 0;
	ptr->blue = 0;
	ptr->ahor = 0;
	ptr->aver = 0;
	ptr->sph = sph;
}

int		ft_spot(int button, t_data *ptr)
{
	(button == 53) ? exit(0) : 0;
	(button == 126) ? ptr->spot->posz++ : 0;
	(button == 125) ? ptr->spot->posz-- : 0;
	(button == 124) ? ptr->spot->posx-- : 0;
	(button == 123) ? ptr->spot->posx++ : 0;
	(button == 34) ? ptr->sph->cy++ : 0;
	(button == 40) ? ptr->sph->cy-- : 0;
	(button == 38) ? ptr->sph->cx-- : 0;
	(button == 37) ? ptr->sph->cx++ : 0;
	(button == 78) ? ptr->aver += M_PI / 100 : 0;
	(button == 69) ? ptr->aver -= M_PI / 100 : 0;
	free(ptr->data_addr);
	ptr->im = mlx_new_image(ptr->mlx, 1200, 1200);
	ptr->data_addr = mlx_get_data_addr(ptr->im, &(ptr->bits), &(ptr->len), &(ptr->endian));
	ft_rot_x(ptr);
//	ft_pixel_test(ptr);
//	ft_set_sphere(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->im, 0, 0);
	return (0);
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
	mlx_hook(ptr->win, 2, 1L << 0, ft_spot, ptr);
	mlx_loop(ptr->mlx);
}

int		main(void)
{
	t_data	*ptr;

	ptr = (t_data *)malloc(sizeof(t_data));
	ft_set_window(ptr);
}

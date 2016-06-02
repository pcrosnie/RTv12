/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:22:19 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/02 11:31:24 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_wall_rot(t_wall *wall, double angle, t_data *ptr)
{
	double	tmp;
	double	tmp2;
	double	tmp3;
	double	tmp4;

	tmp = wall->ny;
	tmp2 = wall->nz;
	tmp3 = wall->ay;
	tmp4 = wall->az;
	wall->ny = wall->ny * cos(angle) - (wall->nz * sin(angle));
	wall->nz = wall->ny * sin(angle) + (wall->nz * cos(angle));
	wall->ay = wall->ay;
	wall->az = wall->az;
	ft_pixel_test(ptr);
	wall->ny = tmp;
	wall->nz = tmp2;
	wall->ay = tmp3;
	wall->az = tmp4;
}

void	ft_sphere_rot(t_sph *sph, double angle, t_data *ptr)
{
	double tmp;
	double tmp2;

	tmp = sph->cy;
	tmp2 = sph->cz;
	sph->cy = sph->cy * cos(angle) - (sph->cz * sin(angle));
	sph->cz = sph->cy * sin(angle) + (sph->cz * cos(angle));
	ft_wall_rot(ptr->wall, ptr->aver, ptr);
	sph->cy = tmp;
	sph->cz = tmp2;
}

void	ft_spot_rot(t_spot *spot, double angle, t_data *ptr)
{
	double tmp;
	double tmp2;

	tmp = spot->posy;
	tmp2 = spot->posz;
	spot->posy = spot->posy * cos(angle) - (spot->posz * sin(angle));
	spot->posz = spot->posy * sin(angle) + (spot->posz * cos(angle));
	ft_sphere_rot(ptr->sph, ptr->aver, ptr);
	spot->posy = tmp;
	spot->posz = tmp2;
}

void	ft_rot_x(t_data *ptr)
{
	ft_spot_rot(ptr->spot, ptr->aver, ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_and_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:51:34 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/27 16:22:29 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_set_sphere_light(t_data *ptr, double rx, double ry, double rz)
{
//	double	dist_min;
	double	coeff;
	double	sol;

	sol = ptr->spot->sol;
	ptr->spot->distance_max = sqrt(((ptr->spot->posx - ptr->sph->cx) * (ptr->spot->posx - ptr->sph->cx)) + ((ptr->spot->posy - ptr->sph->cy) * (ptr->spot->posy - ptr->sph->cy)) + ((ptr->spot->posz - ptr->sph->cz) * (ptr->spot->posz - ptr->sph->cz))) - ptr->sph->rayon;
	coeff = sqrt(((ptr->spot->posx - (ptr->posx + (rx * sol))) * (ptr->spot->posx - (ptr->posx + (rx * sol)))) + ((ptr->spot->posy - (ptr->posy + (ry * sol))) * (ptr->spot->posy - (ptr->posy + (ry * sol)))) + ((ptr->spot->posz - (ptr->posz + (rz * sol))) * (ptr->spot->posz - (ptr->posz + (rz * sol))))) - ptr->spot->distance_max;
//	ptr->blue = coeff / 1.5 + 100;
	ptr->red = (coeff * 10) + 50;
	if ((coeff * 10) + 50 > 255 || !coeff)
	{
//		ptr->blue = 255;
		ptr->red = 255;
	}
	else if ((coeff * 10) + 50 < 0)
	{
//		ptr->blue = 0;
		ptr->red = 0;
	}
}


void	ft_set_light(t_data *ptr, double rx, double ry, double rz)
{
	t_spot *spot;
	double	coeff;
	double	t;
	double	t2;
	
	spot = ptr->spot;
	t = - ((ptr->wall->nx * spot->posx) + (ptr->wall->ny * spot->posy) + (ptr->wall->nz * spot->posz)) / ((ptr->wall->nx * ptr->wall->nx) + (ptr->wall->ny * ptr->wall->ny) + (ptr->wall->nz * ptr->wall->nz));
	ptr->spot->distance_max = sqrt(((spot->posx - (spot->posx + (ptr->wall->nx * t))) * (spot->posx - (spot->posx + (ptr->wall->nx * t)))) + ((spot->posy - (spot->posy + (ptr->wall->ny * t))) * (spot->posy - (spot->posy + (ptr->wall->ny * t)))) + ((spot->posz - (spot->posz + (ptr->wall->nz * t))) * (spot->posz - (spot->posz + (ptr->wall->nz * t)))));
	t2 = -(ptr->wall->nx + ptr->wall->ny + (ptr->wall->nz)) / ((ptr->wall->nx * rx) + (ptr->wall->ny * ry) + (ptr->wall->nz * rz));
	coeff = sqrt(((ptr->spot->posx - (rx * t2)) * (ptr->spot->posx - (rx * t2))) + ((ptr->spot->posy - (ry *t2)) * (ptr->spot->posy - (ry * t2))) + ((ptr->spot->posz - (rz * t2)) * (ptr->spot->posz - (rz * t2))));
//	printf("%f\n", coeff);
	ptr->blue = coeff * 10 - 950;
	printf("%f\n", t2);
	if (ptr->blue > 255 || t2 > 65)
	{
		ptr->blue = 0;
//		ptr->red = 255;
	}
	else if (ptr->blue < 0)
	{
		ptr->blue = 0;
//		ptr->red = 0;
	}
}

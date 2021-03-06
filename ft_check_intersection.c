/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:08:42 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/06/02 11:40:04 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double  ft_solve_poly(t_data *ptr, double rx, double ry, double rz)
{
	double  d;
	double  b;
	double  sol1;
	double  sol2;
		b = 2 * ((rx * (ptr->posx - ptr->sph->cx) + (ry * (ptr->posy - ptr->sph->cy)) + (rz * (ptr->posz - ptr->sph->cz)
						)));
		        d = (b * b) - (4 * ((rx * rx) + (ry * ry) + (rz * rz))) * (((ptr->posx - ptr->sph->cx) * (ptr->posx - ptr->sph->
								cx)) + ((ptr->posy - ptr->sph->cy) * (ptr->posy - ptr->sph->cy)) + ((ptr->posz - ptr->sph->cz) * (ptr->posz - ptr->sph->
									cz)) - (ptr->sph->rayon * ptr->sph->rayon));
	if (d == 0)
	{
		sol1 = (b * (-1)) / (2 * ((rx * rx) + (ry * ry) + (rz * rz)));
		ptr->spot->sol = sol1;
	}
	else if (d >= 0)
	{
		sol1 = ((b * (-1)) - sqrt(d)) / (2 * ((rx * rx) + (ry * ry) + (rz * rz)));
		sol2 = ((b * (-1)) + sqrt(d)) / (2 * ((rx * rx) + (ry * ry) + (rz * rz)));
		if (sol1 > sol2)
		{
//			printf("%f : %f\n", sol1, ptr->spot->sol);
//			if (ptr->spot->sol < sol1 - 1 && ptr->spot->sol > 0)
//				return (-1);
			ptr->spot->sol = sol1;
			if (ptr->distance < sol1 && ptr->distance != 0)
				return (-1);
		}
		else
		{
//			if (ptr->spot->sol < sol2 - 1 && ptr->spot->sol > 0)
//				return (-1);
			ptr->spot->sol = sol2;
			if (ptr->distance < sol2 && ptr->distance != 0)
				return (-1);
		}
	}
	return (d);
}

double	ft_check_intersection(t_data *ptr, double rx, double ry, double rz)
{
	t_sph *sph;
	int		elem; // 0 = rien 1 = Sphere, 2 = Mur, 3 = Cylindre 4 = cone
	int		pos;
   	double	d;	// pos ds liste chainee;
	double a;

	a = 0;
	sph = ptr->sph;
	elem = 0;
	pos = 0;
	d = 0;
	ptr->spot->sol = 0;
	while (sph != NULL)
	{
			ptr->red = 0;
			ptr->blue = 255;
			ptr->green = 0;
			a = ft_set_wall(ptr, rx, ry, rz);
			ft_set_light(ptr, rx, ry, rz);
		d = ft_solve_poly(ptr, rx, ry, rz);
		if (d >= 0)
		{
			ptr->red = 255;
			ptr->blue = 0;
			ptr->green = 0;
			ft_set_sphere_light(ptr, -rx, ry, rz);
//			return (d);
		}
		else
			return (a);
		pos++;
		sph = sph->next;
	}
	return (d);
}

void    vector_normalize(double *rx, double *ry, double *rz)
{
	int		mod;

	mod = sqrt((*rx * *rx) + (*ry * *ry) + (*rz * *rz));
	*rx /= mod;
	*ry /= mod;
	*rz /= mod;
}

void	ft_set_rays(t_data *ptr, double x, double y)
{
	double	rx;
	double	ry;
	double	rz;

	rx = 600 - x;
	ry = 600 - y;
	rz = 2000;
	vector_normalize(&rx, &ry, &rz);
	if (ft_check_intersection(ptr, rx, ry, rz) >= 0)
	{
		ft_draw(ptr, x, y);
	}
}

void	ft_pixel_test(t_data *ptr)
{
	double	x;
	double	y;

	x = 0;
	while (x < 1200)
	{
		y = 0;
		while (y < 1200)
		{
			ft_set_rays(ptr, x, y);
			y++;
		}
		x++;
	}
}




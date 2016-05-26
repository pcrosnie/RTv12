/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light_and_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:51:34 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/26 16:33:04 by pcrosnie         ###   ########.fr       */
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
	ptr->red = (coeff * 10) + 100;
	if ((coeff * 10) + 100 > 255 || !coeff)
	{
//		ptr->blue = 255;
		ptr->red = 255;
	}
	else if ((coeff * 10) + 100 < 0)
	{
//		ptr->blue = 0;
		ptr->red = 0;
	}
}


void	ft_set_light(t_data *ptr)
{
	double	coeff;
	double sol;

	sol = ptr->spot->sol;
	ptr->spot->distance_max = ptr->spot->posy;
	coeff = ptr->spot->sol - ptr->spot->distance_max;
	ptr->blue = (coeff * 2) + 100;
//	printf("%f\n", ptr->blue);
	if ((coeff * 10) + 100 > 255 || !coeff)
	{
		ptr->blue = 255;
//		ptr->red = 255;
	}
	else if ((coeff * 10) + 100 < 0)
	{
		ptr->blue = 0;
//		ptr->red = 0;
	}
}

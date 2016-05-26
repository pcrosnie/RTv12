/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:18:22 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/05/26 16:32:56 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_set_wall(t_data *ptr, double rx, double ry, double rz)
{
	double	a;
	double	b;
	double	t;

	a = (ptr->wall->nx * ptr->wall->ax) + (ptr->wall->ny * ptr->wall->ay) + (ptr->wall->nz * ptr->wall->az);
	b = (ptr->wall->nx * rx) + (ptr->wall->ny * ry) + (ptr->wall->nz * rz);
	t = a / b;
	ptr->spot->sol = t;
	printf("%f\n", t);
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo_floatcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 16:52:46 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/22 16:54:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geo.h"

int		geo_floatcmp(float a, float b)
{
	if ((a < b) || (a > b))
		return (0);
	return (1);
}

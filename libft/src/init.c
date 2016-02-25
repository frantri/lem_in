/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:06:28 by ftriquet          #+#    #+#             */
/*   Updated: 2016/01/06 18:11:40 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	init_2int(int *i1, int v1, int *i2, int v2)
{
	*i1 = v1;
	*i2 = v2;
}

void	init_0(int *i1, int *i2, int *i3, int *i4)
{
	if (i1)
		*i1 = 0;
	if (i2)
		*i2 = 0;
	if (i3)
		*i3 = 0;
	if (i4)
		*i4 = 0;
}

void	init_ptr(void **ptr1, void **ptr2, void **ptr3, void **ptr4)
{
	if (ptr1)
		*ptr1 = NULL;
	if (ptr2)
		*ptr2 = NULL;
	if (ptr3)
		*ptr3 = NULL;
	if (ptr4)
		*ptr4 = NULL;
}

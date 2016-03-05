/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:31:43 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/02 20:31:43 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <unistd.h>
#include <stdlib.h>

int		main(void)
{
	t_map	map;

	map = parse_file(0);
	put_weights(&map);
	check_map(&map);
	reprint_map(&map, NULL);
	write(1, "\n", 1);
	play(&map);
	return (0);
}

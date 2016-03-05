/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 20:31:42 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/02 20:31:42 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <stdlib.h>
#include <ft_printf.h>

t_parsing_msg	exit_error(char *msg)
{
	ft_dprintf(2, "ERROR%s\n", msg);
	exit(1);
}

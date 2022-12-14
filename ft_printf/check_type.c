/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:31:20 by dokim2            #+#    #+#             */
/*   Updated: 2022/08/13 01:04:44 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char n_arg)
{
	if (n_arg == 'c' || n_arg == 's' || n_arg == 'p'
		|| n_arg == 'd' || n_arg == 'i' || n_arg == 'u'
		|| n_arg == 'x' || n_arg == 'X')
		return (n_arg);
	else
		return (0);
}

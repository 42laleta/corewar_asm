/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbennie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:20:25 by dbennie           #+#    #+#             */
/*   Updated: 2019/08/27 14:20:26 by dbennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapptr(void **a, void **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

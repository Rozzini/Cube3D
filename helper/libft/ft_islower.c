/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:48:38 by gabdoush          #+#    #+#             */
/*   Updated: 2021/11/01 10:48:40 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_islower(int n)
{
	if (n >= 'a' && n <= 'z')
	{
		return (1);
	}
	return (0);
}
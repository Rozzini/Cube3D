/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@42ABUDHABI.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 10:47:58 by gabdoush          #+#    #+#             */
/*   Updated: 2021/11/01 10:48:00 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isblank(int n)
{
	if (n == ' ' || n == '\t')
	{
		return (1);
	}
	return (0);
}
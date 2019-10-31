/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clianne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:49:25 by clianne           #+#    #+#             */
/*   Updated: 2019/09/08 10:52:30 by clianne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int nb)
{
	int value;

	value = nb;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb <= 1)
		return (1);
	return (value * ft_factorial(nb - 1));
}

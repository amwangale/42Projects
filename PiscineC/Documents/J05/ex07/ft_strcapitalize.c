/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtedgui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 19:00:28 by dtedgui           #+#    #+#             */
/*   Updated: 2015/08/12 10:28:55 by dtedgui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 97 && str[i] <= 122)
			&& (str[i - 1] < 48 || (str[i - 1] > 57 && str[i - 1] < 65)
			|| (str[i - 1] > 90 && str[i - 1] < 97) || str[i - 1] > 122))
			str[i] -= 32;
		if ((str[i] >= 65 && str[i] <= 90)
			&& ((str[i - 1] >= 48 && str[i - 1] <= 57)
			|| (str[i - 1] >= 65 && str[i - 1] <= 90)
			|| (str[i - 1] >= 97 && str[i - 1] <= 122)))
			str[i] += 32;
		i++;
	}
	return (str);
}

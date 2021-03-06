/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_len_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/17 09:39:07 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 10:47:09 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

/*
**	Return len tab
*/

int			ft_len_tab(char **tabl)
{
	int		i;

	i = 0;
	if (tabl == NULL)
		return (0);
	while (tabl[i])
		i++;
	return (i);
}

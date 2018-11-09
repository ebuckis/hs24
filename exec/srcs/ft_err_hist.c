/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_err_hist.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: yoginet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/09 10:01:38 by yoginet      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 11:21:22 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

int			history_usage(void)
{
	ft_putstr_fd("history: usage: history [-c] [-d offset] [n] or ", 2);
	ft_putstr_fd("history -awrn [filename] or history -ps [arg...]\n", 2);
	return (1);
}

int			history_out(char *str, int i)
{
	ft_putstr_fd("42sh: history: ", 2);
	if (str == NULL)
		ft_putnbr_fd(i, 2);
	else
		ft_putstr_fd(str + i, 2);
	ft_putstr_fd(": history position out of range\n", 2);
	return (0);
}
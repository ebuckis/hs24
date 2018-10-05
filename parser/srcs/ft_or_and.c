/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_or_and.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 11:12:33 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 14:29:39 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_is_or_and(t_parse *p)
{
	int		i;

	i = p->i;
	printf("|%c|-|%c|\n", p->s[i], p->s[i + 1]);
	if (p->s[i] && p->s[i] == '&' && p->s[i + 1] && p->s[i] == p->s[i + 1])
		return (1);
	else if (p->s[i] && p->s[i] == '|' && p->s[i + 1] && p->s[i] == p->s[i + 1])
		return (1);
	printf("return : 0\n");
	return (0);
}

int			ft_or_and(t_parse *p)
{
	int		i;
	int		id;
	char	*pr;

	p->ident = ft_realloc(p->ident, 1);
	p->str = ft_realloc(p->str, 1);
	ft_add_space(p);
	id = (p->s[p->i] == '&') ? AND : OR;
	pr = (p->s[p->i] == '&') ? "cmdand> " : "cmdor> ";
	i = p->i;
	while (i != 0)
	{
		if (!ft_is_white(p->s[i]))
			break ;
		i--;
	}
	if (p->i == 0)
		return (-1);
	ft_end_while(p, id);
	ft_end_while(p, id);
	i = p->i;
	while (p->s[i])
	{
		if (!ft_is_white(p->s[i]))
			break ;
		i++;
	}
	p->ident = ft_realloc(p->ident, 1);
	p->str = ft_realloc(p->str, 1);
	ft_add_space(p);
	if (p->s[i])
		return (1);
	if (!(ft_suite_line(p, 2, pr)))
		return (0);
	return (1);
}
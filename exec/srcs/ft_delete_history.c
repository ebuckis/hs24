/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_delete_history.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 13:57:57 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:00:31 by yoginet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/exec.h"

/*
**	Delete History
**	Ne suprime rien dans le fichier .bash_history (sauf a la fermeture du shell)
*/

int			delete_history(void)
{
	t_hist	*h;

	h = NULL;
	printf("%s START\n", __func__);
	h = ft_close_hist(GET_HIST, NULL);
	if (h && h->next)
		ft_free_hist(&(h->next));
//	ft_close_hist(SAVE_HIST, NULL);
	printf("%s END\n", __func__);
	return (0);
}

/*
**	Delete an line of history
*/

int			delete_line_history(int id)
{
	int		max;

	max = info_histsize();
	if (id <= 0 || id > max)
		history_out(id);
	printf("DELETE LINE History : %d\n", id);
	return (0);
}

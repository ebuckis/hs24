/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_historique.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 19:03:29 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 15:49:29 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_edition.h"

static t_hist	*ft_init_hist(void)
{
	t_hist	*h;

	if (!(h = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	h->str = NULL;
	h->next = NULL;
	h->prev = NULL;
	h->id = -1;
	return (h);
}

/*
** fonction d'initialisation de la stucture d'historique
*/

static t_hist	*ft_new_hist(char *s, t_hist *m_prev, t_hist *m_next, int id)
{
	t_hist		*h;

	if (!(h = (t_hist *)malloc(sizeof(t_hist))))
		return (NULL);
	if (!(h->str = ft_strdup(s)))
		return (NULL);
	h->id = id;
	h->next = m_next;
	h->prev = m_prev;
	if (m_next)
		m_next->prev = h;
	return (h);
}

/*
** creation d'un nouveau maillon sur liste doublement chainee
*/

int				ft_add_hist(char *s)
{
	t_hist		*h;
	static int	id = 0;

	g_nav.max_id = id;
	h = ft_close_hist(GET_HIST, NULL);
	if (!h || !s)
		return (0);
	if (!h->next)
	{
		if (!(h->next = ft_new_hist(s, h, h->next, id)))
			return (0);
		id++;
	}
	else if (ft_strcmp(s, h->next->str) != 0)
	{
		if (!(h->next = ft_new_hist(s, h, h->next, id)))
			return (0);
		id++;
	}
	return (1);
}

/*
** permet d'add une ligne
** on le recupere et on verifie qu'il exite et qu'on a qqch a save
** si c'est le 1er hist on le save direct
** sinon on verifie qu'il n'est pas identique au predecent
*/

int				ft_open_hist(void)
{
	t_hist	*h;

	if (!(h = ft_close_hist(GET_HIST, NULL)))
	{
		if (!(h = ft_init_hist()))
			return (0);
		ft_give_hist(SAVE_HIST, h);
		ft_close_hist(SAVE_HIST, h);
		ft_file_to_list();
	}
	else
		ft_give_hist(SAVE_HIST, h);
	return (1);
}

/*
** premier appel -> creation de l'historique
** donc si ft_close_hist de connait pas h on l'initialise et on le save
** sinon on le redonne a give_hist
*/

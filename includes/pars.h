/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:22:45 by rababaya          #+#    #+#             */
/*   Updated: 2026/02/07 15:27:23 by rababaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_id
{
	int	so;
	int	no;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_id;

typedef struct s_flags
{
	int		seen_content;
	int		ids_complete;
	int		map_started;
	int		line_count;
	t_id	*id;
}	t_flags;

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:22:45 by rababaya          #+#    #+#             */
/*   Updated: 2026/03/07 16:56:21 by rababaya         ###   ########.fr       */
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

typedef struct s_configs
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
}	t_configs;

typedef struct s_flags
{
	int			seen_content;
	int			ids_complete;
	int			map_started;
	int			line_count;
	t_id		*id;
	t_configs	*configs;
}	t_flags;

int		textures_not_set(t_configs *c);
int		colors_not_set(t_configs *c);
int		textures_are_complete(t_configs *c);
int		colors_are_complete(t_configs *c);
int		check_first_arg(char *arg);
void	init_id(t_flags *flags);
void	init_configs(t_flags *flags);
int		ft_is_whitespace(char c);
int		only_nl(char *str);
void	free_split(char **split);
int		is_id_line(char *str, t_flags *flags);
int		parse_id_line(char *str, t_flags *flags);

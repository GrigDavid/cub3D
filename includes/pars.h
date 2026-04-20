/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rababaya <rababaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:22:45 by rababaya          #+#    #+#             */
/*   Updated: 2026/04/20 22:55:28 by rababaya         ###   ########.fr       */
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

typedef struct s_map_list
{
	char				*row;
	struct s_map_list	*next;
}	t_map_list;

typedef struct s_map
{
	char	**map;
	int		max_width;
	int		height;
}	t_map;

typedef struct s_configs
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	t_map	*map;
}	t_configs;

typedef struct s_flags
{
	int			seen_content;
	int			ids_complete;
	int			map_started;
	int			line_count;
	t_id		*id;
}	t_flags;

int			textures_not_set(t_configs *c);
int			colors_not_set(t_configs *c);
int			textures_are_complete(t_configs *c);
int			colors_are_complete(t_configs *c);
int			is_player(char c);
int			is_valid_char(char c);
int			check_player_pos(t_map *map, int x, int y);
void		init_id(t_flags *flags);
t_map		*init_map(int height);
void		init_configs(t_configs *configs);
t_map_list	*new_node(char **val);
int			ft_is_whitespace(char c);
int			only_nl(char *str);
int			ft_inset(char target, char *src);
void		free_split(char **split);
int			is_id_line(char *str, t_flags *flags);
int			parse_id_line(char *str, t_flags *flags, t_configs *configs);
int			parse_map(t_configs *config, char **first_line, int fd);
void		free_map_lst(t_map_list *head);
void		free_map(t_map *map, int size);


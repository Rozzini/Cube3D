/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:20:54 by mraspors          #+#    #+#             */
/*   Updated: 2022/12/25 05:41:53 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define COIN "./img/coin.xpm"
# define EXIT "./img/exit.xpm"
# define ME1 "./img/me1.xpm"
# define ME2 "./img/me2.xpm"
# define PASS "./img/pass.xpm"
# define WALL "./img/wall.xpm"

typedef struct s_rgb {
	int		r;
	int		g;
	int		b;	
}				t_rgb;

typedef struct s_game {
	int		p_x;
	int		p_y;
	int		w;
	int		h;
	char	*NO_texture;
	char	*SO_texture;
	char	*WE_texture;
	char	*EA_texture;
	char	*C_color;
	char	*F_color;
	char	**map_data;
	char	**map;
	t_rgb	C;
	t_rgb	F;
	void	*img;
	void	*mlx;
	void	*mlx_win;
}				t_game;

void	check_file_name(int argc, char *s, t_game *game);
int		call_checkers(char *s, t_game *map);
int		read_map(char *file, t_game *game);
void	read_check_map(char *s, t_game *game);
void	init_struct(t_game *game);
void	free_if_er(t_game *game);
void	save_map_config(t_game *game);
void	check_map_config(t_game *game);
#endif
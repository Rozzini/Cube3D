/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:25:04 by gabdoush          #+#    #+#             */
/*   Updated: 2023/02/04 20:51:45 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*=======================================================================*/
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./helper/mlx/mlx.h"
# include "./helper/get_next_line/get_next_line.h"
# include "./helper/libft/libft.h"
# include <math.h>
//# include <pthread.h>
//# include <sndfile.h>


# define	NO	0
# define	SO	0
# define	WE	0
# define	EA	0
# define	C	0
# define	F	0

# define pi 3.141592653
/*=======================================================================*/
/**
 ** Keys: */

# define	W		13
# define	S		1
# define	A		0
# define	D		2
# define	Q		12
# define	E		14
# define	SP		49

# define	UP 		126
# define	DOWN	125
# define	LEFT	123
# define	RIGHT	124


/*=======================================================================*/
/**
 ** Image struct for my_put_pixel */
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/*=======================================================================*/
typedef struct s_content
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	c;
	int	f;
}			t_content;

/*=======================================================================*/
typedef struct s_map
{
	struct s_map	*prev;
	char			*line;
	struct s_map	*next;
}			t_map;

/*=======================================================================*/
typedef struct s_map_cont
{
	struct s_map_cont	*prev;
	char				*name;
	char				*value;
	struct s_map_cont	*next;
}			t_map_cont;

/*=======================================================================*/

typedef struct s_map_real
{
	struct s_map_real	*prev;
	char				*str;
	struct s_map_real	*next;
}			t_map_real;

/*=======================================================================*/

/**
 ** The Line drawing algorithm struct for all the rays and vectors */
typedef struct	s_line {
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	col;
	int	row;
}				t_line;

/*=======================================================================*/
/**
 ** The color struct for the floor and ceiling.*/
typedef struct	s_colors {
	int			floor_red;
	int			floor_green;
	int			floor_blue;

	int			ceiling_red;
	int			ceiling_green;
	int			ceiling_blue;

	int			floor_color;
	int			ceiling_color;
}				t_colors;

/*=======================================================================*/
/**
 * All the variables for the 3D projection of the map.*/
typedef struct	s_vars_3D {
	double		proj_plane_dist;
	int			mid_plane_y;
	int			fov;

	double		wall_top_x;
	double		wall_top_y;
	double		wall_down_x;
	double		wall_down_y;

	double		slice_hight;

	double		ceiling_top_x;
	double		ceiling_top_y;
	double		ceiling_down_x;
	double		ceiling_down_y;

	double		floor_top_x;
	double		floor_top_y;
	double		floor_down_x;
	double		floor_down_y;

}				t_vars_3D;

/*=======================================================================*/
/**
 ** All the variables for the 3D projection of the map.*/
typedef struct s_check
{
	/*----------------------------------------*/
	// movement_variables;
	double		mv_speed;
	double		mv_x;
	double		mv_y;
	
	double		mv_right_x;
	double		mv_right_y;
	
	double		mv_left_x;
	double		mv_left_y;
	
	double		mv_rev_x;
	double		mv_rev_y;
	/*----------------------------------------*/
	// Wall Checkers Coordinates;
	double		wall_check_dist;

	double		wall_check_front_x;
	double		wall_check_front_y;

	double		wall_check_right_x;
	double		wall_check_right_y;

	double		wall_check_left_x;
	double		wall_check_left_y;

	double		wall_check_rev_x;
	double		wall_check_rev_y;
}			t_check;

/*=======================================================================*/
/**
 ** The Rays struct for all the rays variables */
typedef struct	s_ray {
	double		ray_start_x;
	double		ray_start_y;
	
	double		ray_dist;
	double		ray_dist_x;
	double		ray_dist_y;
	double		ray_angle;
	double		ray_angle_rotation;
	double		pend_dist;
	double		pend_angle;
}				t_ray;

/*=======================================================================*/
/**
 ** Mouse struct for all the mouse variables */
typedef struct	s_mouse {
	int			mouse_x;
	int			mouse_y;
	int			mouse_key;
	int			move;
	double		mouse_rotation;
}				t_mouse;

/*=======================================================================*/
/**
 ** The Rays struct for all the rays variables */
typedef struct	s_gun {
	void		*gun_img;
	void		*curser_img;

	char		*gun_path;
	char		*curser_path;

	int			gun_x;
	int			gun_y;
	
	int			gun_w;
	int			gun_h;
}				t_gun;

/*=======================================================================*/
/**
 ** The Rays struct for all the rays variables */
typedef struct	s_border {
	void		*border_img;
	
	char		*minimap_border_path;
	
	int			border_x;
	int			border_y;

	int			border_w;
	int			border_h;
}				t_border;
/*=======================================================================*/
/**
 ** Minimap struct for all the Minimap variables */
typedef struct	s_minimap {
	double		minimap_img_size;
	double		minimap_chara_size;
	int			minimap_blocks;
	double		scale;

	int			player_pos_x;
	int			player_pos_y;
		
	int			start_x;
	int			start_y;
		
	int			end_x;
	int			end_y;
	
	int			row;
	int			col;
	
	double		vec_len;
	double		vec_x;
	double		vec_y;
	
	int			mini_win_start_x;
	int			mini_win_start_y;
	int			mini_win_end_x;
	int			mini_win_end_y;

}				t_minimap;

/*=======================================================================*/
typedef struct s_base
{
	void		*mlx;
	void		*win;
	int			win_h;
	int			win_w;
	int			start_game;
	int			faster;
	/*----------------------------------------*/
	double		vec_angle;
	double		rotation_angle;
	/*----------------------------------------*/
	int			width;
	int			height;
	/*----------------------------------------*/
	// Image (x , y)
	double		img_x;
	double		img_y;
	double		img_size;
	/*----------------------------------------*/
	// Player (x , y)
	double		char_x;
	double		char_y;
	double		player_x;
	double		player_y;
	char		player_dir;
	double		chara_size;
	/*----------------------------------------*/
	t_map		*map;
	t_map_cont	*t_map_content;
	t_map_real	*real_map;
	char		**raw_map;
	int			map_h;
	int			map_w;
	/*----------------------------------------*/

	/**
 	** @brief Image struct for my put_pixel */
	t_img		*img;
	/*----------------------------------------*/

	/**
	 ** @brief The Rays struct for all the 2D rays variables */
	t_ray		*ray;
	/*----------------------------------------*/

	/**
	 ** @brief The Line drawing algorithm struct */
	t_line		*line;
	/*----------------------------------------*/
	
	/**
	 ** @brief All the variables for the 3D projection of the map.*/
	t_vars_3D		*vars_3D;
	/*----------------------------------------*/

	/**
	 ** @brief All the variables for the movement and wall checking.*/
	t_check		*checker;
	/*----------------------------------------*/

	/**
	 ** @brief The color struct for the floor and ceiling.*/
	t_colors		*colors;
	/*----------------------------------------*/

	/**
	 ** @brief Mouse struct for all the mouse variables.*/
	t_mouse			*mouse;
	/*----------------------------------------*/

	/**
	 ** @brief Mouse struct for all the mouse variables.*/
	t_gun			*gun;
	/*----------------------------------------*/

	/**
	 ** @brief Minimap struct for all the Minimap variables.*/
	t_minimap		*minimap;
	/*----------------------------------------*/
	/**
	 ** @brief Mouse struct for all the mouse variables.*/
	t_border			*border;
	/*----------------------------------------*/


}		t_base;

/*=======================================================================*/
/*----------------------- Memory Management -----------------------------*/
/*=======================================================================*/

void	init_vals(t_base *data);
void	allocate_memory(t_base *data);
/**
** @brief Free the whole struct.
* @param t_base* (data) the struct that contains the program variables.*/
void	free_structs(t_base *data);
void	free_2d(char **data);
void	free_list(t_map *data);
/*=======================================================================*/
/*------------------------- Errors Utils --------------------------------*/
/*=======================================================================*/

/**
** @brief Check whether the extension is supported by the program.
** <it should be .cub>
* @param argc from main (int argc, char **argv)
* @param argv from main (int argc, char **argv) */
void	check_extension(int argc, char **argv);
/**
** @brief printing error message whenever we call the function.
*/
void	extension_error(void);

/*=======================================================================*/
/*------------------------- Reading File --------------------------------*/
/*=======================================================================*/

/**
** @brief Reading the data from the file with .cub extension.
** then save it to the data list.
** @param map_file The argument from the main() which is argv[1]
*/
void	read_file(char *map_file, t_base *base);
/**
 * @brief checking map from main list t_base; it prints RESUlt is = 
 * 
 * @param data 
 */
void	ft_print_list(t_base data);
void	ft_print_map_cont(t_base data);

/**
 * @brief it will check map content is valid or not, 
 * if is valid it will store "t_map_content" data struct;
 * also t_map_content is inside t_base struct exist;
 * 
 */
int		get_map_content(t_base *base);
int		ft_check_cf_value(t_base base);
void	ft_get_map_content(t_base *data);
int		ft_array_length(char **arr);
void	ft_init(t_content *data);
int		ft_break_point(char **arr);
int		ft_check_isdigit(char *str);
int		ft_count_comma(char *str);
char	*ft_remove_nl(char *str);
int		ft_check_direction_value(t_base base);

int		get_real_map(t_base *base);
void	ft_remove_new_line(t_base base);
void	ft_get_real_map(t_base *base);
int 	check_map_border(t_base base);
int 	check_zero_round(t_base base);
/**
** @brief Extract the raw map from the (map) list to (raw_map) 2d array
* @param t_base* (data) the struct that contains the program variables.*/
void	extracting_raw_map(t_base *data);

/*=======================================================================*/
/*------------------------- List Utils ----------------------------------*/
/*=======================================================================*/

void	append(t_map **head_ref, char *str);
void	append_sec(t_map_real **head_ref, char *str);
void	ft_add_back(char *name, char *value, t_map_cont **head_ref);
/**
** @brief Deleting the Doubly Linked list data, and free the memory.
* @param t_map* */
void	delete_list(t_map *map);
void	delete_list2(t_map_real *map);
void	delete_list3(t_map_cont *map);


/*=======================================================================*/
/*--------------------------- Drawing Player ----------------------------*/
/*=======================================================================*/

/**
 * @brief init the vector angle for the player
* @param t_base* (data) the struct that contains the program variables.*/
void	init_vec_angle(t_base *data);

/**
** @brief Draw the player on the minimap
* @param t_base* (data) the struct that contains the program variables.*/
void	assemble_player(t_base *data);

/**
** @brief Draw a circle around the player in the minimap.
* @param t_base* (data) the struct that contains the program variables.
* @param double (xm) x coordinate for the center of the circle
* @param double (ym) y coordinate for the center of the circle
* @param double (r) radius of the circle */
void	draw_circle (t_base *data, int xm, int ym, int r, int color);


/*=======================================================================*/
/*-------------------------- Drawing Mini Map ---------------------------*/
/*=======================================================================*/
/**
 * @brief Draw the minimap with all the component.
* @param t_base* (data) the struct that contains the program variables. */
void	draw_minimap(t_base *data);

void	draw_border(t_base *data);
void	vec_cord(t_base* data);
void	draw_minimap_player(t_base *data);
/*=======================================================================*/
/*-------------------------- Drawing Map --------------------------------*/
/*=======================================================================*/

/**
** @brief Draw the mini map with my_mlx_put_pixel, (floors, walls, player)
* @param t_base* (data) the struct that contains the program variables.*/
void	draw_map(t_base *data);

/**
** @brief edited version of mlx_put_pixel (faster version)
* @param t_base* (data) the struct that contains the program variables. 
* @param int x (x) coordinate for the printed pixel
* @param int y (y) coordinate for the printed pixel
* @param int color */
void	my_mlx_pixel_put(t_base *data, int x, int y, int color);

/**
 ** @brief Helper function for draw_line(), it fined all the required values
 ** and save them inside the line struct.
 * 
 * @param t_base* (data) the struct that contains the program variables.
 * @param int (start_x) x coordinate for the start point of the line
 * @param int (start_y) y coordinate for the start point of the line
 * @param int (end_x) x coordinate for the end point of the line
 * @param int (end_y) coordinate for the end point of the line
 */
void	set_line_vals(t_base *data, int start_x, int start_y, int end_x, int end_y);

/**
 ** @brief Get The player position from the map (Just in the start of the game).
 * @param t_base* (data) the struct that contains the program variables.*/
void	get_player_position(t_base *data);

/**
 ** @brief Initialize The player coordinates and the player direction.
 * @param t_base* (data) the struct that contains the program variables.
 * @param int (i) The row of the map.
 * @param int (j) The column of the map. */
void	put_player(t_base *data, int i, int j);

/*=======================================================================*/
/*----------------------- MLX Keys Utils --------------------------------*/
/*=======================================================================*/

/**
** @brief Fined the coordinates for each direction of the player.
* @param t_base* (data) the struct that contains the program variables.*/
void	movement_coordinates(t_base *data);

/**
* @brief Fined the coordinates of the end point of the vision vector.
* (data->vec->dest_x, data->vec->dest_y)
* @param t_base* (data) the struct that contains the program variables. */
void	movement_coordinates_forward(t_base* data);

/**
* @brief Fined the coordinates of the start point of the reverse vision vector.
* @param t_base* (data) the struct that contains the program variables. */
void	movement_coordinates_reverse(t_base* data);

/**
* @brief Fined the coordinates of the start point of the future right vision vector.
* @param t_base* (data) the struct that contains the program variables. */
void	movement_coordinates_right(t_base* data);

/**
* @brief Fined the coordinates of the start point of the future left vision vector.
* @param t_base* (data) the struct that contains the program variables. */
void	movement_coordinates_left(t_base* data);

int		handle_moving(int key, t_base *data);
/**
** @brief Closing the program when the user press ESC.
* @param t_base* (data) the struct that contains the program variables.
* @return int */
void	closing_esc(int key, t_base *data);

/**
** @brief Closing the program when the user press the red cross using the mouse.
* @param t_base* (data) the struct that contains the program variables.
* @return int */
int		closing_x(t_base *data);

/*=======================================================================*/
/*-------------------------- Key Movement -------------------------------*/
/*=======================================================================*/

/**
** @brief Movement keys for the player
* @param t_base* (data) the struct that contains the program variables. */
void	key_W(t_base *data);
void	key_D(t_base *data);
void	key_A(t_base *data);
void	key_S(t_base *data);
void	key_left(t_base *data, double angle_type);
void	key_right(t_base *data, double angle_type);
void	key_up(t_base *data);
void	key_down(t_base *data);
int		mouse_movement(int x, int y, t_base *data);
void	speed_up(t_base *data);

/*=======================================================================*/
/*-------------------------- Casting Rays -------------------------------*/
/*=======================================================================*/

int		check_assets(t_base *data);
void	casting_rays(t_base *data);
void	draw_one_ray(t_base *data, int start_x, int start_y, int end_x, int end_y);
void	fined_ray_end_point(t_base* data);
void	find_ray_len(t_base *data);
void	draw_2d(t_base *data);

/*=======================================================================*/
/*------------------------- Wall Collusion ------------------------------*/
/*=======================================================================*/

void	wall_check_coordinates_front(t_base* data);
void	wall_check_coordinates(t_base *data);
int		clear_front(t_base *data);
int		clear_front(t_base *data);
int		clear_back(t_base *data);
int		clear_right(t_base *data);
int		clear_left(t_base *data);

/*=======================================================================*/
/*--------------------------- 3D Drawing --------------------------------*/
/*=======================================================================*/

void	calc_pend_angle(t_base *data);
void	draw_3d_wall(t_base *data);
void	draw_3d_floor(t_base *data);
void	draw_3d_ceiling(t_base *data);
void	rgb_to_int(t_base *data);
void	draw_3d(t_base *data);
void	draw_slice(t_base *data, int start_x, int start_y, int end_x, int end_y, int color);

void	hold_gun(t_base *data);

/*=======================================================================*/

#endif
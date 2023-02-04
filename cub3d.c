/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:25:09 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 03:32:02 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"



/*============================================================================*/
static void	entrance(void)
{
	printf("|-------------------------------|\n");
	printf("| ⠀⠀⠀⠀⠀⠀⠀⣴⣾⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⠀⠀⠀⠀⠀⠀⠐⣿⣿⣿⣿⣿⠃⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀ |\n");
	printf("| ⠀⠀⠀⠀⣠⣶⣾⣿⣿⣿⣿⣿⣦⣼⣿⣶⣶⣾⣶⣶⣶⣶⣶⣶⣶⠿⠦⠤⠤ |\n");
	printf("| ⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⡟⢋⣽⡿⠋⠁⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣄⣩⣵⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⠻⣿⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⢠⣷⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⡏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⠀⠠⣿⣿⣿⣿⣿⣿⣿⠿⠛⠁⢸⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⠀⠀⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⢸⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⠀⠸⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠿⢿⣿⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("| ⠀⠀⠻⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ |\n");
	printf("|-------------------------------|\n");
}

/*============================================================================*/
void	allocate_memory(t_base *data)
{
	data->line = malloc(sizeof(t_line));
	data->ray = malloc(sizeof(t_ray));
	data->img = malloc(sizeof(t_img));
	data->vars_3D = malloc(sizeof(t_vars_3D));
	data->checker = malloc(sizeof(t_check));
	data->colors = malloc(sizeof(t_colors));
	data->mouse = malloc(sizeof(t_mouse));
	data->gun = malloc(sizeof(t_gun));
	data->minimap = malloc(sizeof(t_minimap));
	data->border = malloc(sizeof(t_border));
}

/*============================================================================*/
static void	start_game(t_base *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, "Cube_3d");
	rgb_to_int(data);
	init_vec_angle(data);
	draw_map(data);
	hold_gun(data);
	draw_border(data);
	mlx_hook(data->win, 17, 1L << 2, closing_x, data);
	mlx_hook(data->win, 02, 1L << 0, handle_moving, data);
	mlx_hook(data->win, 6, 1L<<6, &mouse_movement, data);
	mlx_loop(data->mlx);
}

/*============================================================================*/
int	main(int argc, char **argv)
{
	t_base	data;

	entrance();
	check_extension(argc, argv);
	allocate_memory(&data);
	init_vals(&data);
	read_file(argv[1] , &data);

	if (get_map_content(&data) || get_real_map(&data))
	{
		write(1, "map content error\n", 18);
		free_structs(&data);
		return (EXIT_FAILURE);
	}
	extracting_raw_map(&data);
	start_game(&data);
	free_structs(&data);
	return (EXIT_SUCCESS);
}

/*============================================================================*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:52:11 by gabdoush          #+#    #+#             */
/*   Updated: 2022/12/30 01:57:33 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

/*=======================================================================*/
/** @brief bresenham algorithm explained
	*!|=============|
	*!| Pseudo code:|
	*!|=============|
	*========================================================================================================
	*? Step 1 : Except the two end points of Line from User.
	*
	*? Step 2 : Calculate the slope(m) of the required Line.
	*
	*? Step 3 : Identify the value of slope(m).
	*
	**	Step 3.1
	**		If slope(m) is Less than 1 i.e: m < 1
	**			Step 3.1.1
	*						Calculate the constants dx, dy, 2dy, and (2dy – 2dx) and get the 
	*						first value for the decision parameter as:
	*						p0 = 2dy − dx
	**			Step 3.1.2
	*						At each Xk along the line, starting at k = 0,
	*						perform the following test:
	*							If pk < 0, 
	*								the next point to plot is (xk + 1,yk) and (pk+1 = pk + 2dy)
	*							else
	*								plot (xk,yk + 1)
	*								pk+1 = pk + 2dy − 2dx
	**			Step 3.1.3
	*					Repeat step 4(dx - 1) times.
	*========================================================================================================
	**	Step 3.2
	**		If slope(m) is greater than or equal to 1 i.e: m >= 1
	**			Step 3.2.1
	*						Calculate the constants dx, dy, 2dy, and (2dy – 2dx) 
	*						and get the first value for the decision parameter as:
	*							p0 = 2dx − dy
	**			Step 3.2.2
	*						At each Yk along the line, starting at k = 0, perform the following test:
	*							If pk < 0, 
	*								the next point to plot is (xk,yk + 1) and (pk+1 = pk + 2dx)
	*							else
	*								plot (xk + 1,yk)
	*								pk+1 = pk + 2dx − 2dy
	**			Step 3.2.3
	*					Repeat step 4(dy - 1) times.
	**	Step 3.3 : Exit.
	=========================================================================================================
 */

/*============================================================================*/
void	set_line_vals(t_base *data, int start_x, int start_y, int end_x, int end_y)
{
	data->line->dx = abs(end_x - start_x);
	data->line->dy = abs(end_y - start_y);
	if (start_x < end_x)
		data->line->sx = 1;
	else
		data->line->sx = -1;
	if (start_y < end_y)
		data->line->sy = 1;
	else
		data->line->sy = -1;
	if (data->line->dx > data->line->dy)
		data->line->err = data->line->dx / 2;
	else
		data->line->err = -(data->line->dy / 2);	
}

/*============================================================================*/
void	my_mlx_pixel_put(t_base *data, int x, int y, int color)
{
	char	*dst;

	if (x >= data->win_w || y >= data->win_h || y < 0 || x < 0)
		return ;
	dst = data->img->addr + (y * data->img->line_length + x * (data->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*=======================================================================*/
void	draw_one_ray(t_base *data, int start_x, int start_y, int end_x, int end_y)
{
	set_line_vals(data, start_x, start_y, end_x, end_y);
	data->line->col = start_y / data->img_size;
	data->line->row = start_x / data->img_size;

	while (data->raw_map[data->line->col][data->line->row] != '1')
	{
		data->line->col = start_y / data->img_size;
		data->line->row = start_x / data->img_size;
		if (check_assets(data))
		{
			if (data->raw_map[data->line->col][data->line->row] == '1')
			{
				data->ray->ray_dist_x = start_x;
				data->ray->ray_dist_y = start_y;
				break;
			}
		 }
		else
			break;
		data->line->e2 = data->line->err;
		if (data->line->e2 > -(data->line->dx))
		{
			data->line->err -= data->line->dy;
			start_x += data->line->sx;
		}
		if (data->line->e2 < data->line->dy)
		{
			data->line->err += data->line->dx;
			start_y += data->line->sy;
		}
	}
}

/*============================================================================*/
void	draw_slice(t_base *data, int start_x, int start_y, int end_x, int end_y, int color)
{
	int		dx;
	int		dy;
	int		steps;
	float	Xinc;
	float	Yinc;
	float	X;
	float	Y;
	int		i;

	i = 0;
	// Calculate the distance between the two points
	dx = end_x - start_x;
	dy = end_y - start_y;
	// Calculate the number of steps required to draw the line
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	// Calculate the increment in x and y for each step
	Xinc = dx / (float) steps;
	Yinc = dy / (float) steps;
	// Start drawing the line from the first point
	X = start_x;
	Y = start_y;

	while (i <= steps)
	{
		my_mlx_pixel_put(data, X, Y, color);  // Draw the pixel
		X += Xinc;			// Increment x by Xinc
		Y += Yinc;			// Increment y by Yinc
		i++;
	}
}

/*============================================================================*/
void	draw_circle(t_base *data, int x, int y, int r, int color)
{
	int	r2;
	int	area;
	int	rr;
	int	i;
	int	tx;
	int	ty;

	r2 = r * r;
	area = r2 << 2;
	rr = r << 1;
	i = 0;
	while (i < area)
	{
		tx = (i % rr) - r;
		ty = (i / rr) - r;
		if (tx * tx + ty * ty <= r2)
			my_mlx_pixel_put (data, x + tx, y + ty, color);
		i++;
	}
}

/*============================================================================*/
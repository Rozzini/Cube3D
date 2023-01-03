/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:21:19 by mraspors          #+#    #+#             */
/*   Updated: 2023/01/03 06:05:14 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

// Set the width and height of the minimap
#define MINIMAP_WIDTH 200
#define MINIMAP_HEIGHT 200

// Set the width and height of the window that will display the minimap
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

// Set the size of each cell in the minimap
#define CELL_SIZE 20

// Set the colors to use for the minimap
#define WALL_COLOR 0x0ABC00 // black
#define FLOOR_COLOR 0xFFFFFF // white
#define PLAYER_COLOR 0x012345
#define GRID_COLOR 0x000000
// Set the number of rows and columns in the minimap
#define NUM_ROWS 9
#define NUM_COLS 29

// Set the initial position of the player on the minimap
#define INITIAL_PLAYER_ROW 1
#define INITIAL_PLAYER_COL 1

// Set the initial orientation of the player on the minimap
#define INITIAL_PLAYER_ORIENTATION 'N' // north

// Set the keys to use for moving the player on the minimap
#define KEY_UP 13 // 'w' key
#define KEY_LEFT 0 // left arrow key
#define KEY_DOWN 1 // 's' key
#define KEY_RIGHT 2 // right arrow key

// Set the key to use for quitting the program
#define KEY_QUIT 53 // 'ESC' key

int player_row = INITIAL_PLAYER_ROW;
int player_col = INITIAL_PLAYER_COL;
char   player_orientation = INITIAL_PLAYER_ORIENTATION;
	char **map;
	 void *mlx;
  void *window;

void draw_minimap(void *mlx, void *window, char **map) {
  int x, y, i, j;

  // Clear the window
  mlx_clear_window(mlx, window);

  // Draw the minimap on the window
  for (y = 0; y < NUM_ROWS; y++) {
    for (x = 0; x < NUM_COLS; x++) {
      // Set the color of the cell based on its type
      if (map[y][x] == '1') {
        for (i = 0; i < 20; i++) {
          for (j = 0; j < 20; j++) {
            mlx_pixel_put(mlx, window, x * CELL_SIZE + i, y * CELL_SIZE + j, WALL_COLOR);
          }
        }
      } else {
        for (i = 0; i < 20; i++) {
          for (j = 0; j < 20; j++) {
            mlx_pixel_put(mlx, window, x * CELL_SIZE + i, y * CELL_SIZE + j, FLOOR_COLOR);
          }
        }
      }
    }
  }

  // Draw the player on the minimap
  for (i = 0; i < 20; i++) {
    for (j = 0; j < 20; j++) {
      mlx_pixel_put(mlx, window, player_col * CELL_SIZE + i, player_row * CELL_SIZE + j, PLAYER_COLOR);
    }
  }

    // Draw the grid for the minimap
  for (x = 0; x < NUM_COLS; x++) {
    for (y = 0; y < NUM_ROWS; y++) {
      for (i = 0; i < 20; i++) {
        mlx_pixel_put(mlx, window, x * CELL_SIZE, y * CELL_SIZE + i, GRID_COLOR);
        mlx_pixel_put(mlx, window, x * CELL_SIZE + i, y * CELL_SIZE, GRID_COLOR);
      }
    }
  }
}


// Function to move the player on the minimap
void move_player(char **map, int direction) {
  // Update the player's position based on the direction
  if (direction == KEY_UP) {
    if (player_row > 0 && map[player_row - 1][player_col] != '1') {
      player_row--;
    }
  } else if (direction == KEY_DOWN) {
    if (player_row < NUM_ROWS - 1 && map[player_row + 1][player_col] != '1') {
      player_row++;
    }
  } else if (direction == KEY_LEFT) {
    if (player_col > 0 && map[player_row][player_col - 1] != '1') {
      player_col--;
    }
  } else if (direction == KEY_RIGHT) {
    if (player_col < NUM_COLS - 1 && map[player_row][player_col + 1] != '1') {
      player_col++;
    }
  }
}

// Function to handle key press events
int handle_key_press(int key, void *param) {
  // Update the player's position based on the key pressed
  param = NULL;
  if (key == KEY_UP) {
    move_player(map, KEY_UP);
  } else if (key == KEY_DOWN) {
    move_player(map, KEY_DOWN);
  } else if (key == KEY_LEFT) {
    move_player(map, KEY_LEFT);
  } else if (key == KEY_RIGHT) {
    move_player(map, KEY_RIGHT);
  }
  // Redraw the minimap
  draw_minimap(mlx, window, map);
  return 0;
}


	  
int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	init_struct(game);
	check_file_name(argc, argv[1], game);
	read_check_map(argv[1], game);
	map = game->map;
  int x, y;
  

  // Initialize the player's position and orientation on the minimap

  


  // Read the map from a file or elsewhere and store it in the 'map' array
  // ...

  // Initialize the miniLibX library
  mlx = mlx_init();

  // Create a window to display the minimap
  window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Minimap");

  // Set the event loop to handle key presses
  mlx_key_hook(window, handle_key_press, NULL);

  // Draw the minimap on the window
  for (y = 0; y < NUM_ROWS; y++) {
    for (x = 0; x < NUM_COLS; x++) {
      // Set the color of the cell based on its type
      if (map[y][x] == '1') {
        mlx_pixel_put(mlx, window, x * CELL_SIZE, y * CELL_SIZE, WALL_COLOR);
      } else {
        mlx_pixel_put(mlx, window, x * CELL_SIZE, y * CELL_SIZE, FLOOR_COLOR);
      }
    }
  }
  // Display the window
  mlx_loop(mlx);

  return 0;
}
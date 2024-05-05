
void	ft_hook(mlx_key_data_t keys, void *game)
{
	t_game	*bomb;
	int		keycode;

	bomb = (t_game *)game;
	keycode = keys.key;
	if (keys.action == MLX_PRESS || keys.action == MLX_REPEAT)
	{
		if (keycode == ESC)
		{
			free_all(bomb);
			mlx_close_window(bomb->mlx);
			ft_putendl_fd("Game Closed", 1);
			exit(EXIT_SUCCESS);
		}
		else if (keycode == KEY_UP)
			up_move(bomb);
		else if (keycode == KEY_DOWN)
			down_move(bomb);
		else if (keycode == KEY_LEFT)
			left_move(bomb);
		else if (keycode == KEY_RIGHT)
			right_move(bomb);
	}
}

#include "../fractol.h"

void	handle_mouse(int button, int x, int y, t_config *config)
{
	mlx__get_mouse_pos(x, y, config);
	if (button == 4)
	{
		config->zoom /= 1.1;
		config->offset_x += (x - WIDTH / 2) * 0.1 * config->zoom;
		config->offset_y += (y - HEIGHT / 2) * 0.1 * config->zoom;
	}
	else if (button == 5)
	{
		config->zoom *= 1.1;
		config->offset_x -= (x - WIDTH / 2) * 0.1 * config->zoom;
		config->offset_y -= (y - HEIGHT / 2) * 0.1 * config->zoom;
	}
	redraw(config, &config->vars);
}
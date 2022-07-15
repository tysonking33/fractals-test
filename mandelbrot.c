#include "mlx.h"
#include <math.h>

void	draw_mandelbrot(void *mlx_ptr, void	*win_ptr, 
int	draw_line(void *mlx_ptr, void *win_ptr, int beginX, int beginY, int endX, int endY, int colour)
{
	double	deltaX;
	double	deltaY;
	int		pixels;
	double	pixelX;
	double	pixelY;

	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = beginX;
	pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, pixelX, pixelY, colour);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

int main()
{
	void	*mlx_ptr = mlx_init();
	void	*win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mandelbrot set");
	draw_line(mlx_ptr, win_ptr, 0, 500, 1000, 500, 0xFFFFFF);
	mlx_loop(mlx_ptr);
}

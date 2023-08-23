#include "lib/MLX42/include/MLX42/MLX42.h"

#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 480
#define ZOOM_FACTOR   2

typedef struct s_data
{
	void *mlx;
	void *win;
	void *img;
	char *img_data;
} t_data;

void zoomImage(char *originalImage, int originalWidth, int originalHeight, char *zoomedImage, int zoomedWidth, int zoomedHeight) 
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	originalPixel;
	t_data 	data;

	i = 0;
	char originalImage[WINDOW_WIDTH * WINDOW_HEIGHT * 4];
	int zoomedWidth = WINDOW_WIDTH * ZOOM_FACTOR;
	int zoomedHeight = WINDOW_HEIGHT * ZOOM_FACTOR;
	char zoomedImage[zoomedWidth * zoomedHeight * 4]; 
	while (i < originalHeight) 
	{
		j = 0;
		while (j < originalWidth)
		{
			originalPixel = originalImage[i * originalWidth + j];
			k = 0;
			while (k < ZOOM_FACTOR)
			{
				l = 0;
				while (l < ZOOM_FACTOR)
				{
					zoomedImage[(i * ZOOM_FACTOR + k) * zoomedWidth \
					+ (j * ZOOM_FACTOR + l)] = originalPixel;
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i++ < zoomedHeight * zoomedWidth * 4)
		data.img_data[i] = zoomedImage[i];
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}

int main()
{
	t_data data;

	data.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MLX42", 1);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH * ZOOM_FACTOR, WINDOW_HEIGHT * ZOOM_FACTOR, "Zoomed Image");
	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH * ZOOM_FACTOR, WINDOW_HEIGHT * ZOOM_FACTOR);

	// Initialize originalImage with your image data
	// Assuming 4 bytes per pixel (RGBA)

	// Perform zooming
	// Assuming 4 bytes per pixel (RGBA)
	zoomImage(originalImage, WINDOW_WIDTH, WINDOW_HEIGHT, zoomedImage, zoomedWidth, zoomedHeight);

	// Copy zoomedImage data to img_data
	

	

	return 0;
}

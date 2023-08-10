
#include "minirt.h"

t_minirt *get_minirt(void)
{
	static t_minirt* minirt;

	if (!minirt)
		minirt = ft_calloc(1, sizeof(t_minirt));
	return (minirt);
}

void minirt(int fd)
{
	mlx_t* mlx;
	mlx_image_t *image;


	get_minirt();
	parse(fd);

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	get_minirt()->mlx = mlx;
	get_minirt()->image = image;

	ray_launcher();
	mlx_loop(mlx);

	
	mlx_terminate(mlx);
	free_minirt();
}

int main(int argc, char **argv)
{
	int fd;
	
	check_args_validity(argc);
	check_file_validity(argv[1]);
	fd = open(argv[1], O_RDONLY);
	minirt(fd);
	close(fd);
	return (0);
}

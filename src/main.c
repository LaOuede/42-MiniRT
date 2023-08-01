#include "../include/miniRT.h"
#include "../include/math.h"

/* void	*ft_get_ms(void *ptr)
{
	static void	*ms = NULL;

	if (ptr)
		ms = ptr;
	return (ms);
}

void	ft_init_ms(t_rt *ms)
{
	printf("salut\n");
	ms = ft_calloc(sizeof(t_rt), 1);
	ft_get_ms(ms);
}

int	main(int argc, char **argv)
{
	t_rt	ms;

	if (argc != 2)
		printf("Usage : ./miniRT <scene.rt>\n	-> One argument is needed <-\n");
	else
	{
		ft_init_ms(&ms);
		ms.mlx = mlx_init(WIDTH, HEIGHT, argv[1], 0);
		ms.image = mlx_new_image(ms.mlx, WIDTH, HEIGHT);
		mlx_image_to_window(ms.mlx, ms.image, 0, 0);
	}
	return (0);
} */

int	main(void)
{
	t_vec3	test = {4, 3, 7};
	t_vec3	res;

	res = vec_norm(test);
	printf("x = %f\ny = %f\nz = %f\n", res.x, res.y, res.z);
	return (0);
}


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
	get_minirt();
	parse(fd);
	free_minirt();
}

/* int main(int argc, char **argv)
{
	int fd;
	
	check_args_validity(argc);
	check_file_validity(argv[1]);
	fd = open(argv[1], O_RDONLY);
	minirt(fd);
	return (0);
} */

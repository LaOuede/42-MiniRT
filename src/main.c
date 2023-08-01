
#include "minirt.h"


void free_minirt(void)
{
	t_minirt *minirt;

	minirt = get_minirt();
	ft_lstclear(&minirt->objects);
	ft_lstclear(&minirt->lights);
	free(minirt);
}

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

int main(int argc, char **argv)
{
	int fd;
	
	check_args_validity(argc);
	fd = open(argv[1], O_RDONLY);
	minirt(fd);
	close(fd);	
	return (0);
}

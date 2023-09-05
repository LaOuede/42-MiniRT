
#include "minirt.h"


//readability helper in parsing.c/new_struct()
int is_object(char *type)
{
	if (!ft_strncmp(type, "cy", 3)
		|| !ft_strncmp(type, "sp", 3)
		|| !ft_strncmp(type, "pl", 3)
		|| !ft_strncmp(type, "co", 3))
		return (TRUE);
	return (FALSE);
}

//readability helper in parsing.c/new_struct()
int is_scene_info(char *type)
{
	if (!ft_strncmp(type, "A", 2)
		|| !ft_strncmp(type, "L", 2)
		|| !ft_strncmp(type, "C", 2))
		return (TRUE);
	return (FALSE);
}

//free helper in parsing.c/new_struct()
void free_splitted_line(char **line)
{
	int i;

	if (!line)
		return ;
	i = 0;
	while (line[i])
		free(line[i++]);
	free(line);
}
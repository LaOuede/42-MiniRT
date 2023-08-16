
#include "minirt.h"


//Directs to the right parsing function depending on
//the kind of objecti
void new_obj(char **line)
{
	t_object *object;

	object = ft_calloc(1, sizeof(t_object));
	if (!ft_strncmp(line[0], "sp", 3))
	{
		object->type = SPHERE;
		object->obj = ft_calloc(1, sizeof(t_sphere));
		parse_sphere(line, object);
	}
	else if (!ft_strncmp(line[0], "pl", 3))
	{
		object->type = PLAN;
		object->obj = ft_calloc(1, sizeof(t_plan));
		parse_plane(line, object);
	}
	else if (!ft_strncmp(line[0], "cy", 3))
	{
		object->type = CYLINDRE;
		object->obj = ft_calloc(1, sizeof(t_cylindre));
		parse_cylinder(line, object);
	}
	ft_lstadd_back(&get_minirt()->objects, ft_lstnew(object));
}

//Directs to the right parsing function depending on the
//kind of scene info object
void new_scene_info(char **line)
{
	if (!ft_strncmp(line[0], "A", 2))
	{
		parse_ambiant_light(line);
	}
	else if (!ft_strncmp(line[0], "C", 2))
	{
		parse_camera(line);
	}
	else if (!ft_strncmp(line[0], "L", 2))
	{
		parse_light(line);
	}
}

//redirects to the right parsing functions 
void new_struct(char **line)
{
	if (is_object(line[0]))
	{
		new_obj(line);
	}
	else if (is_scene_info(line[0]))
	{
		new_scene_info(line);
	}
	else if (!ft_strncmp(line[0], "#", 1))
	{
	}
	else
	{
		error(line, INVALID_OBJECT, NULL);
	}
	free_splitted_line(line);
}

//Helper to parse(). Cleans up output of get_next_line()
char *trim_gnl(char *str)
{
	int i;
	int count;
	char *output;

	if (!str)
		return (NULL);
	i = 1;
	count = 1;
	while (str[i])
	{
		if (!((str[i] == ' ' || str[i] == '	')
			&& (str[i - 1] == ' ' || (str[i - 1] == '	')))
			&& str[i] != '\n')
			count++;
		i++;
	}
	output = ft_calloc(sizeof(char), count + 1);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (!((str[i] == ' ' || str[i] == '	')
			&& (str[i - 1] == ' ' || (str[i - 1] == '	')))
			&& str[i] != '\n')
		{
			if (str[i] == '	')
				str[i] = ' ';
			output[count++] = str[i];
		}
		i++;
	}
	str = ft_freenull(str);
	return (output);
}

//entry parsing function, reads lines with gnl
//and calls the struct constructor
void parse(int fd)
{
	char *next_line;
	char **splitted_line;

	next_line = trim_gnl(get_next_line(fd));
	while (next_line)
	{
		if (next_line[0])
		{
			splitted_line = ft_split(next_line, ' ');
			new_struct(splitted_line);
		}
		if (next_line)
			next_line = ft_freenull(next_line);
		next_line = trim_gnl(get_next_line(fd));
	}
	close(fd);
}

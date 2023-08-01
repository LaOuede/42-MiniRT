
#include "../include/minirt.h"


//parses line input to the light struct
void parse_light(char **line)
{
	t_light *new_light;
	
	if (error_(line, EXPECTED_LIGHT))
		return ;

	new_light = ft_calloc(1, sizeof(t_light));
	parse_coordinates(line[1], &new_light->position);
	new_light->intensity = ft_atof(line[2]);
	parse_colors(line[3], &new_light->color);
	ft_lstadd_back(&get_minirt()->lights, ft_lstnew(new_light));
}

//parses line input to the camera struct
void parse_camera(char **line)
{
	if (get_minirt()->camera.exists)
		get_minirt()->error_code = ERROR;
		
	if (error_(line, EXPECTED_CAMERA))
		return ;
	

	parse_coordinates(line[1], &get_minirt()->camera.position);
	parse_coordinates(line[2], &get_minirt()->camera.direction);
	get_minirt()->camera.field_of_view = ft_atof(line[3]);
	get_minirt()->camera.exists = TRUE;
}

//parses line input to the ambiant light struct
void parse_ambiant_light(char **line)
{
	if (get_minirt()->ambiant_light.exists)
		get_minirt()->error_code = ERROR;
	if (error_(line, EXPECTED_AMB_LIGHT))
		return ;
		
	get_minirt()->ambiant_light.intensity = ft_atof(line[1]);
	parse_colors(line[2], &get_minirt()->ambiant_light.color);
	get_minirt()->ambiant_light.exists = TRUE;
}

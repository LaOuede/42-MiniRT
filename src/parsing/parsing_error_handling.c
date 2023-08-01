

#include "minirt.h"

int expected_arg_count(int type)
{
	if (type == SPHERE || type == PLAN || type == LIGHT
		|| type == CAMERA)
		return (4);
	else if (type == CYLINDRE)
		return (6);
	else if (type == AMBIANT_LIGHT)
		return(3);
	return(0);
}

//error 
int bad_arg_count(char **line, int type)
{
	int nb_args;

	nb_args = 0;
	while (line[nb_args])
		nb_args++;
	if (nb_args != expected_arg_count(type))
	{
		get_minirt()->error_code = ERROR;
		return (TRUE);
	}
	else
		return (FALSE);
}

// int invalid_coords(char *coords, float min, float max)
// {

// }

// int invalid_arg(char **line, int type)
// {

// }

int error_(char **line, int type)
{
	static int error_prints = 0;
	
	if (bad_arg_count(line, type)
		|| get_minirt()->error_code == ERROR)
		// || invalid_arg(line, type))
	{
		if (error_prints == 0)
		{
			perror("Input Error");
			error_prints = 1;
		}
		get_minirt()->error_code = ERROR;
		return (TRUE);
	}
	return (FALSE);
}



#include "../include/minirt.h"

//error 
int bad_arg_count(char **line, int expected_nb)
{
	int nb_args;

	nb_args = 0;
	while (line[nb_args])
		nb_args++;
	if (nb_args != expected_nb)
	{
		get_minirt()->error_code = ERROR;
		return (TRUE);
	}
	else
		return (FALSE);
}

int error_(char **line, int expected)
{
	static int error_prints = 0;
	
	if (bad_arg_count(line, expected)
		|| get_minirt()->error_code == ERROR)
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

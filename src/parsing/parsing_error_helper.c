#include "minirt.h"


//helper in parsing_error_handling.c/bad_arg_count()
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

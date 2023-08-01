#include "../include/miniRT.h"

/*
COPY
*/
t_vec3	vec_copy(t_vec3 v)
{
	t_vec3	copy;

	copy.x = v.x;
	copy.y = v.y;
	copy.z = v.z;
	return (copy);
}

/*
RESET
*/
void	vec_reset(t_vec3 v)
{
	v.x = 0;
	v.y = 0;
	v.z = 0;
}

/*
NEGATE
*/
void	vec_negate(t_vec3 v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
}

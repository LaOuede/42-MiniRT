#include "minirt.h"

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
void	vec_reset(t_vec3 *v)
{
	v->x = 0;
	v->y = 0;
	v->z = 0;
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

t_vec3 generate_vector(float x, float y, float z)
{
	t_vec3 null_vector;

	null_vector.x = x;
	null_vector.y = y;
	null_vector.z = z;
	return (null_vector);
}

t_vec3 up_guide(void)
{
	t_vec3 up_guide;

	up_guide.x = 0.0f;
	up_guide.y = 1.0f;
	up_guide.z = 0.0f;
	return (up_guide);
}
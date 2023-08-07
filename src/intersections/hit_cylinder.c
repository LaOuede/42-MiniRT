#include "minirt.h"

/*

Supposons que l'on a une structure t_ray qui contient 2 vectors (origin et direction)
typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray

Une autre structure qui serait accessible depuis l'objet permet de garder les infos pertinentes en lien avec les hits
typedef struct	s_hit
{
	t_vec3	col; // coord du point de collision
	float	t; //distance au point de collision
	t_vec3	norm; //sphere normal
}	t_hit

Equation :

RUN "make int" to see informations

*/
bool	hit_cylinder(t_ray ray, t_cylinder *cylinder, t_hit *hit)
{
	//Need to check hit with cylinder, top disk and bottom disk
}

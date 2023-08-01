#ifndef MINIRT_H
# define MINIRT_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/include/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

/* --------------------SETTINGS-------------------- */
# define WIDTH 1920
# define HEIGHT 1080

/* ------------------- STRUCTURE ------------------- */

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_rt
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	keys_t		*keys;
}	t_rt;

/* ------------------- FUNCTIONS ------------------- */
t_vec3	vec_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2);
float	vec_dot(t_vec3 v1, t_vec3 v2);
float	vec_mag(t_vec3 v1);
t_vec3	vec_mult(t_vec3 v1, t_vec3 v2);
t_vec3	vec_norm(t_vec3 v);
t_vec3	vec_scale(t_vec3 v, float scale);
t_vec3	vec_subs(t_vec3 v1, t_vec3 v2);

#endif
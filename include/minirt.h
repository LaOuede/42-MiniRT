
#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/include/libft.h"
# include <libc.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>

/* --------------------SETTINGS-------------------- */
/* # define WIDTH 1920
# define HEIGHT 1080 */

#define ERROR -1

//***************
//GENERAL STRUCTS
//***************

//commençons par dealer avec une seule ambiant light/ light / camera

//même struct que vec3 - on pourrait changer le type au début pour que ça marche avec les fonctions de vecteurs ?
typedef struct s_position
{
	float			x;
	float			y;
	float			z;
}					t_position;

typedef struct s_color
{
	//between 0 and 255 for each (R,G,B)
	float			r;
	float			g;
	float			b;
}					t_color;

//********************
//OBJECTS STRUCTS INFO
//********************

//types of objects
# define INVALID 0
# define SPHERE 1
# define CYLINDRE 2
# define PLAN 3
# define AMBIANT_LIGHT 4
# define LIGHT 5
# define CAMERA 6

# define EXPECTED_SPHERE 4
# define EXPECTED_CYLINDER 6
# define EXPECTED_PLANE 4
# define EXPECTED_LIGHT 4
# define EXPECTED_AMB_LIGHT 3
# define EXPECTED_CAMERA 4

//error codes
# define INVALID_OBJECT 1
# define BAD_ARG_COUNT_SPHERE 2
# define BAD_ARG_COUNT_PLANE 3
# define BAD_ARG_COUNT_CYLINDER 4
# define BAD_ARG_COUNT_LIGHT 5
# define BAD_ARG_COUNT_AMB_LIGHT 6
# define BAD_ARG_COUNT_CAMERA 7
# define BAD_ARGS_SPHERE 7
# define BAD_ARGS_PLANE 8
# define BAD_ARGS_CYLINDER 9
# define BAD_ARGS_AMB_LIGHT 10
# define BAD_ARGS_LIGHT 11
# define BAD_ARGS_CAMERA 12



typedef struct s_ambiant_light
{
	float			intensity; //between 0 and 1
	t_color			color;
	int				exists;
}					t_ambiant_light;

typedef struct s_light
{
	float			intensity; //between 0 and 1
	t_color			color;   //******pas utilisé dans la partie obligatoire******
	t_position		position;
}					t_light;

typedef struct s_camera
{
	float			field_of_view;  //values between 0 and 180
	t_position		direction; //vector values between 0 and 1
	t_position		position;
	int				exists;
}					t_camera;

typedef struct s_object
{
	int				type;
	void			*obj;
}					t_object;

typedef struct s_sphere
{
	float			rayon; //faire (diametre en input) / 2
	t_color			color;
	t_position		position;
}					t_sphere;

typedef struct s_plan
{
	t_color			color;
	t_position		direction; //vector values between 0 and 1
	t_position		position;
}					t_plan;

typedef struct s_cylindre
{
	float			rayon;
	float			hauteur;
	t_color			color;
	t_position		direction; //vector values between -1 and 1
	t_position		position;
}					t_cylindre;

typedef struct s_minirt
{
	t_list			*objects;
	t_ambiant_light	ambiant_light;
	t_list			*lights; //multiple lights?
	t_camera		camera;
	int				error_code;
}					t_minirt;

//vector
typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

//matrix
typedef struct s_mat4
{
	float	p[4][4];
}	t_mat4;

//parsing
void				parse(int fd);
void				parse_to_struct(t_list **objects, char **line);
void				parse_sphere(char **line, t_object *object);
void				parse_cylinder(char **line, t_object *object);
void				parse_plane(char **line, t_object *object);
void free_parse_functions(char **split);
void parse_coordinates(char *coordinates, t_position *position);
void parse_colors(char *coordinates, t_color *color);
void parse_ambiant_light(char **line);
void parse_camera(char **line);
void parse_light(char **line);

//parsing error handling
int check_obj_arg_count(char **line, int expected_nb);
void check_file_validity(char *file);
void check_invalid_arg(char **line, int type, void *to_free);
void error(char **line, int error_code, void *to_free);
void check_bad_arg_count(char **line, int type, void *to_free);
void check_error(char **line, int type, void *to_free);
int expected_arg_count(int type);

//object errors
void check_sphere_args(char **line, void *to_free);
void check_cylinder_args(char **line, void *to_free);
void check_plane_args(char **line, void *to_free);
void check_amb_light_args(char **line, void *to_free);
void check_light_args(char **line, void *to_free);
void check_camera_args(char **line, void *to_free);

//error value input
int invalid_value(char *coords);
int invalid_value_limited(char *coords, float min, float max);
int invalid_coords(char *coords);
int invalid_coords_limited(char *coords, float min, float max);
int nb_of_split(char **splits);


//parsing utils
int					is_scene_info(char *type);
int					is_object(char *type);
void free_splitted_line(char **line);
int is_all_digit_dot(char *str);

//utils
void	ft_free_lst(t_list **lst);
void check_args_validity(int argc);
float ft_atof(char *str);
double ft_atod(char *str);
t_minirt *get_minirt(void);
void free_minirt(void);

//vector
t_vec3	vec_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2);
float	vec_dot(t_vec3 v1, t_vec3 v2);
float	vec_mag(t_vec3 v1);
t_vec3	vec_mult(t_vec3 v1, t_vec3 v2);
t_vec3	vec_norm(t_vec3 v);
t_vec3	vec_scale(t_vec3 v, float scale);
t_vec3	vec_subs(t_vec3 v1, t_vec3 v2);

//matrices
t_mat4	identity_matrix(void);
t_mat4	matrix_copy(t_mat4 mat);
t_mat4	matrix_mult(t_mat4 mat1, t_mat4 mat2);
t_mat4	matrix_rotx(float angle);
t_mat4	matrix_roty(float angle);
t_mat4	matrix_rotz(float angle);
t_mat4	matrix_scale(float sx, float sy, float sz);
t_mat4	matrix_translation(float tx, float ty, float tz);
t_vec3	matrix_vec_mult(t_mat4 mat, t_vec3 v);

//colors
t_color	add_2_colors(t_color col1, t_color col2);
t_color	add_3_colors(t_color col1, t_color col2, t_color col3);
t_color	color_scale(t_color col1, float scale);
t_color	sub_2_colors(t_color col1, t_color col2);
t_color	sub_3_colors(t_color col1, t_color col2, t_color col3);
int		get_rgba(float r, float g, float b, float a);

#endif

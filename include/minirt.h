
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

/* -------------------SETTINGS------------------- */
/* # define WIDTH 1920
# define HEIGHT 1080 */

#define ERROR -1
// #define WIDTH 2560
// #define HEIGHT 1440
// #define WIDTH 1920
// #define HEIGHT 1080
// #define WIDTH 1280
// #define HEIGHT 720
#define WIDTH 640
#define HEIGHT 480

#define	NUMBER_OF_REFLEXIONS 4
#define THREAD_COUNT (HEIGHT / 4)
#define SHINY_FACTOR 1000

//***************
//GENERAL STRUCTS
//***************

//commençons par dealer avec une seule ambiant light/ light / camera

//même struct que vec3 - on pourrait changer le type au début pour que ça marche avec les fonctions de vecteurs ?

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
# define CONE 7

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
# define BAD_ARG_COUNT_CONE 5
# define BAD_ARG_COUNT_LIGHT 6
# define BAD_ARG_COUNT_AMB_LIGHT 7
# define BAD_ARG_COUNT_CAMERA 8
# define BAD_ARGS_SPHERE 9
# define BAD_ARGS_PLANE 10
# define BAD_ARGS_CYLINDER 11
# define BAD_ARGS_AMB_LIGHT 12
# define BAD_ARGS_LIGHT 13
# define BAD_ARGS_CAMERA 14
# define BAD_ARGS_CONE 15

# define NO_MAT 0
# define MOON 1
# define EARTH 2
# define WOOD 3
# define SUN 4
# define NO_MAT2 5
# define DAMIER 6
# define TEXTURE_COUNT 7 //always ajust to be last texture index + 1 or leakks

# define NORMAL 1
# define SUPER 2

//texture
typedef struct s_material
{
	int				id;
	mlx_texture_t	*texture;
	mlx_texture_t	*norm_map;
	int				shine;
	float			specular_factor;
	float			reflexion;
}				t_material;

//vector
typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_ray_info
{
	float width;
	float height;
	float x;
	float y;
	int px;
	int py;
	t_vec3 d;
	t_vec3 forward;
	t_vec3 right;
	t_vec3 up;
	bool first_hit;
}		t_ray_info;

// Quadratic
typedef struct s_qdt
{
	float	a;
	float	b;
	float	half_b;
	float	c;
	float	t;
	float	t1;
	float	m;
	float	k;
	float	discriminant;
	t_vec3	disp;
	t_vec3	d;
	t_vec3	origin;
}			t_qdt;

//matrix
typedef struct s_mat4
{
	float	p[4][4];
}	t_mat4;

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
	t_vec3			position;
}					t_light;

typedef struct s_camera
{
	float			field_of_view;  //values between 0 and 180
	t_vec3			direction; //vector values between 0 and 1
	t_vec3			position;
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
	t_vec3			position;
	t_material		*material;

}					t_sphere;

typedef struct s_cone
{
	t_vec3			position;
	t_vec3			direction;
	float			angle;
	float			hauteur;
	t_color			color;
	t_material		*material;
}					t_cone;

typedef struct s_plan
{
	t_color			color;
	t_vec3			direction; //vector values between 0 and 1
	t_vec3			position;
	t_material		*material;
}					t_plan;

typedef struct s_cylindre
{
	float			rayon;
	float			hauteur;
	t_color			color;
	t_vec3			direction; //vector values between -1 and 1
	t_vec3			position;
	t_material		*material;
}					t_cylindre;

typedef struct s_disk
{
	float			rayon;
	t_color			color;
	t_vec3			direction; //vector values between -1 and 1
	t_vec3			position;
	t_material		*material;
}					t_disk;

typedef struct s_minirt
{
	t_list			*objects;
	t_ambiant_light	ambiant_light;
	t_list			*lights; //multiple lights?
	t_camera		camera;
	t_mat4			cam_matrix;
	int				error_code;
	mlx_t			*mlx;
	mlx_image_t		*image;
	keys_t			*keys;
	t_object		*obj_selected;
	int				selected;
	int				mode;
	t_material		material[7];////////////////////////////////////////////// to change
}					t_minirt;

typedef struct s_shading
{
	t_color		color;
	float		intensity;
}				t_shading;

typedef struct s_hit
{
	float			t;
	t_object		*obj;
	t_vec3			normal;
	t_vec3			hit_point;
	unsigned int	u_px;
	unsigned int	v_py;
}				t_hit;

typedef struct s_thread
{
	pthread_t	thread;
	t_ray_info	ray;
	t_hit		closest_hit;
	int			index;
	int scr_height;
	int scr_width;
}				t_thread;


//parsing
void	parse(int fd);
void	parse_to_struct(t_list **objects, char **line);
void	parse_sphere(char **line, t_object *object);
void	parse_cylinder(char **line, t_object *object);
void	parse_plane(char **line, t_object *object);
void	free_parse_functions(char **split);
void	parse_coordinates(char *coordinates, t_vec3 *position);
void	parse_colors(char *coordinates, t_color *color);
void	parse_ambiant_light(char **line);
void	parse_camera(char **line);
void	parse_light(char **line);
void	parse_cone(char **line, t_object *object);
void	fill_sphere_info(t_object *object, char **line);
void	fill_plane_info(t_object *object, char **line);
void	fill_cylinder_info(t_object *object, char **line);
void	fill_cone_info(t_object *object, char **line);
char	*trim_gnl(char *str);

//parsing error handling
int check_obj_arg_count(char **line, int expected_nb);
void check_file_validity(char *file);
void check_invalid_arg(char **line, int type, void *to_free);
void error(char **line, int error_code, void *to_free);
void check_bad_arg_count(char **line, int type, void *to_free);
void check_error(char **line, int type, void *to_free);
int expected_arg_count(int type);

//intersections
void	hit_cone(t_vec3 d, t_object *packed_cone, t_hit *hit, t_vec3 origin);
void	hit_cylinder(t_vec3 d, t_object *packed_cylinder, t_hit *hit, t_vec3 origin);
void	hit_plane(t_vec3 d, t_object *obj_actuel, t_hit *hit, t_vec3 origin);
void	hit_sphere(t_vec3 d, t_object *packed_sphere, t_hit *hit, t_vec3 origin);

//get object info
t_vec3 get_camera_direction(t_object *object);
void	change_direction(t_object *object, t_vec3 new_direction);
void	change_position(t_object *object, t_vec3 new_position);
t_vec3 get_position(t_object *object);
t_vec3 get_light_position(void *packed_light);
float get_light_intensity(void *packed_light);
t_color get_light_color(void *packed_light);
t_color get_obj_color(t_object *obj);
t_vec3 get_plane_direction(t_object *object);
t_vec3 get_cylinder_direction(t_object *object);
t_vec3 get_cone_direction(t_object *object);
float	*get_angle(t_object *object);
t_material *get_obj_material(t_object *obj);
float	*get_height(t_object *object);
float	*get_radius(t_object *object);



//object errors
void check_sphere_args(char **line, void *to_free);
void check_cylinder_args(char **line, void *to_free);
void check_plane_args(char **line, void *to_free);
void check_amb_light_args(char **line, void *to_free);
void check_light_args(char **line, void *to_free);
void check_camera_args(char **line, void *to_free);
void check_cone_args(char **line, void *to_free);

//error value input
int invalid_value(char *coords);
int invalid_value_limited(char *coords, float min, float max);
int invalid_coords(char *coords);
int invalid_coords_limited(char *coords, float min, float max);
int nb_of_split(char **splits);


//parsing utils
int		is_scene_info(char *type);
int		is_object(char *type);
void	free_splitted_line(char **line);
int		is_all_digit_dot(char *str);

//utils
void	ft_free_lst(t_list **lst);
void check_args_validity(int argc);
float ft_atof(char *str);
double ft_atod(char *str);
t_minirt *get_minirt(void);
void free_minirt(void);
void	map_erase(t_minirt *minirt);
bool	is_file_empty(int fd);

//vector
t_vec3	vec_add(t_vec3 v1, t_vec3 v2);
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2);
float	vec_dot(t_vec3 v1, t_vec3 v2);
float	vec_mag(t_vec3 v1);
t_vec3	vec_mult(t_vec3 v1, t_vec3 v2);
t_vec3	vec_norm(t_vec3 v);
t_vec3	vec_scale(t_vec3 v, float scale);
t_vec3	vec_subs(t_vec3 v1, t_vec3 v2);
t_vec3	vec_unit_vec(t_vec3 v1, t_vec3 v2);
void	vec_reset(t_vec3 *v);
t_vec3	generate_vector(float x, float y, float z);
t_vec3 get_normal_vec(t_hit *hit);
t_vec3	vec_copy(t_vec3 v);
t_vec3	up_guide(void);


//matrices
t_mat4	identity_matrix(void);
t_mat4	init_cam_matrix(t_vec3 right, t_vec3 up, t_vec3 forward);
t_mat4	matrix_copy(t_mat4 mat);
t_mat4	matrix_rotx(float angle);
// t_mat4 matrix_rotate_arbitrary(t_vec3 axis, float angle);
t_mat4	matrix_roty(float angle);
t_mat4	matrix_rotz(float angle);
t_mat4	matrix_scale(float sx, float sy, float sz);
t_mat4	matrix_translation(float tx, float ty, float tz);
t_vec3	matrix_vec_mult(t_mat4 mat, t_vec3 v);

//colors
t_color	add_2_colors(t_color col1, t_color col2);
t_color	sub_2_colors(t_color col1, t_color col2);
t_color	sub_3_colors(t_color col1, t_color col2, t_color col3);
int		get_rgba(t_color color, float a);
t_color	no_color(void);
t_color	get_specular_color(t_color obj_color, t_hit *hit, float color_intensity);
t_color	max_color(t_color color);
t_color	color_scale(t_color v, float scale);
t_color	color_add(t_color v1, t_color v2);
t_color	shading_color(t_hit *hit, t_shading *shade, int *refl, t_vec3 v);

//ray launcher
void		ray_launcher();
void		find_closest_hit(t_ray_info ray, t_hit *closest_hit, t_vec3 origin);
t_shading	single_ray(t_ray_info ray, t_hit *closest_hit);
void		find_hit(t_vec3 d, t_object *object, t_hit *hit, t_vec3 origin);
void		*super_routine(void *package);
t_vec3		get_d(t_ray_info ray);

//shading
t_shading	shading(t_hit *hit);
void		calc_reflexion(t_hit *hit, t_vec3 v, t_shading *shade, int *refl);
float		shading_intensity(t_hit *hit, t_vec3 n, t_shading *shade, int refl);
t_vec3	get_light_dir(t_hit *hit, void *current_light);
float	get_geo_term(t_hit *hit, void *current_light, t_vec3 n);
void	init_shadow_rays(t_vec3 *d, float *t, t_list **light, t_hit *hit);
bool	shadow_ray_hits(t_hit *hit, t_list **light);


//materials && textures
void	load_moon(void);
void	load_earth(void);
void	load_wood(void);
void	load_no_material(void);
void	load_sun(void);
void	load_materials(void);
void	load_no_material2(void);
void	load_damier(void);
t_color	get_texture_color(t_hit *hit);
void	uv_map_sphere(t_hit *hit, unsigned int *px, unsigned int *py, mlx_texture_t *image);
void	uv_map(t_hit *hit, unsigned int *px, unsigned int *py, mlx_texture_t *image);
t_color	get_normap_value(t_hit *hit);

//hooks
void	camera_rotation_yaw(t_minirt *minirt, keys_t key);
void	camera_rotation_pitch(t_minirt *minirt, keys_t key);
void	camera_translation_x(t_minirt *minirt, keys_t key);
void	camera_translation_y(t_minirt *minirt, keys_t key);
void	camera_translation_z(t_minirt *minirt, keys_t key);
void	cyl_rotation(t_minirt *minirt, keys_t key);
void	cone_rotation(t_minirt *minirt, keys_t key);
void	find_closest_object(t_ray_info *ray, t_hit *closest_hit);
bool	first_hit_mouse(bool action);
void	init_hit_mouse(t_hit *closest_hit, t_hit *hit);
void	keys_camera(mlx_key_data_t keydata, void *param);
void	keys_cylinder(mlx_key_data_t keydata, void *param);
void	keys_light(mlx_key_data_t keydata, void *param);
void	keys_object1(mlx_key_data_t keydata, void *param);
void	keys_object2(mlx_key_data_t keydata, void *param);
void	keys_rotation(mlx_key_data_t keydata, void *param);
void	keys_sphere(mlx_key_data_t keydata, void *param);
void	keys_translation(mlx_key_data_t keydata, void *param);
void	light_translation(t_minirt *minirt, keys_t key, char axis);
void	minirt_keys(mlx_key_data_t keydata, void *param);
void	minirt_mouse(mouse_key_t button, action_t action, modifier_key_t mods, void* param);
t_vec3	move_init(t_minirt *minirt, char axis);
void	new_pos(t_vec3 *pos, t_vec3 move, char c);
void	object_selected(t_hit hit);
void	object_translation(t_minirt *minirt, keys_t key, char axis);
void	plane_rotation(t_minirt *minirt, keys_t key);
void	print_cmd_menu1(void);
void	print_cmd_menu2(void);
void	resize_image(int32_t width, int32_t height, void* param);
void	update_closest_hit_mouse(t_hit *closest_hit, t_hit hit);
t_vec3	up_guide_mouse(void);

t_vec3	get_light_position(void *packed_light);

#endif

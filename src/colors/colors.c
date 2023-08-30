#include "minirt.h"

/*
Combines four individual channel bytes into a single integer using
bit-shifting
Use with mlx_put_pixel as 4th param (uint_32 color)

*** I think we don't need a so it will be silenced and assigned to 0 ???***

*/
int	get_rgba(t_color color, float a)
{
	return ((int)color.r << 24 | (int)color.g << 16 | (int)color.b << 8 | (int)a);
}

t_color no_color(void)
{
	t_color color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	return(color);
}

t_color generate_color(float r, float g, float b)
{
	t_color color;
	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color get_specular_color(t_color obj_color, t_hit *hit, t_shading *shade)/////////////////play around here
{
	t_color specular_color;
	// t_color basic_spec_color;
	// float color_intensity;
	specular_color = generate_color(100.0f, 100.0f, 100.0f);
	specular_color = color_add(obj_color, specular_color);
	specular_color = max_color(specular_color);
	specular_color = color_scale(specular_color, get_obj_material(hit->obj)->specular_factor);
	shade = NULL;
	// color_add_ = obj_color;
	// color_intensity = pow((shade->intensity / 255.0f), 1.2) * get_obj_material(hit->obj)->specular_factor;
	// basic_spec_color = color_scale(generate_color(100, 100, 100), color_intensity);
	// color_add_ = color_scale(color_add_, color_intensity);

	// obj_color = color_add(basic_spec_color, color_add_);

	return(specular_color);
}

t_color max_color(t_color color)
{
	float	big_color;
	float	div_factor;

	big_color = MAX(MAX(color.r, color.g), color.b);

	if (big_color > 255.0f)
	{
		div_factor = big_color / 255.0f;
		color.r = color.r / div_factor;
		color.g = color.g / div_factor;
		color.b = color.b / div_factor;
	}
	if (color.r > 255.0f)
		color.r = 255.0f;
	if (color.g > 255.0f)
		color.g = 255.0f;
	if (color.b > 255.0f)
		color.b = 255.0f;
	
	return (color);
}

t_color max_out_color(t_color color)
{
	float	big_color;
	float	div_factor;

	big_color = MAX(MAX(color.r, color.g), color.b);

	// if (big_color > 255.0f)
	// {
		div_factor = big_color / 255.0f;
		color.r = color.r / div_factor;
		color.g = color.g / div_factor;
		color.b = color.b / div_factor;
	// }
	if (color.r > 255.0f)
		color.r = 255.0f;
	if (color.g > 255.0f)
		color.g = 255.0f;
	if (color.b > 255.0f)
		color.b = 255.0f;
	
	return (color);
}

t_color	color_scale(t_color v, float scale)
{
	t_color	res;

	res.r = v.r * scale;
	res.g = v.g * scale;
	res.b = v.b * scale;
	return (res);
}

t_color	color_add(t_color v1, t_color v2)
{
	t_color	res;

	res.r = v1.r + v2.r;
	res.g = v1.g + v2.g;
	res.b = v1.b + v2.b;
	return (res);
}

t_color	data_to_rgb(const unsigned int color)
{
	t_color		rgb;

	rgb.r = ((color >> 16) & 0xFF) / 255.0;
	rgb.g = ((color >> 8) & 0xFF) / 255.0;
	rgb.b = ((color) & 0xFF) / 255.0;
	return (rgb);
}

/*
SCALE
*/
// int	color_scale(t_color col1, float scale)
// {
// 	t_color	new;

// 	new.r = col1.r * scale;
// 	new.g = col1.g * scale;
// 	new.b = col1.b * scale;
// 	return (get_rgba(new.r, new.g, new.b, 0));
// }

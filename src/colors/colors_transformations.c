#include "minirt.h"

/*
BLEND 2 colors
*/
t_color	blend(t_color col1, t_color col2)
{
	t_color	new;

	new.r = col1.r * col2.r;
	new.g = col1.g * col2.g;
	new.b = col1.b * col2.b;
	return (get_rgba(new.r, new.g, new.b, 0));
}

/*
ADD 2 colors
*/
t_color	add_2_colors(t_color col1, t_color col2)
{
	t_color	new;

	new.r = col1.r + col2.r;
	new.g = col1.g + col2.g;
	new.b = col1.b + col2.b;
	return (get_rgba(new.r, new.g, new.b, 0));
}

/*
ADD 3 colors
*/
t_color	add_3_colors(t_color col1, t_color col2, t_color col3)
{
	t_color	new;

	new.r = col1.r + col2.r + col3.r;
	new.g = col1.g + col2.g + col3.g;
	new.b = col1.b + col2.b + col3.b;
	return (get_rgba(new.r, new.g, new.b, 0));
}

/*
SUBSTRACT 2 colors
*/
t_color	sub_2_colors(t_color col1, t_color col2)
{
	t_color	new;

	new.r = col1.r - col2.r;
	new.g = col1.g - col2.g;
	new.b = col1.b - col2.b;
	return (get_rgba(new.r, new.g, new.b, 0));
}

/*
SUBSTRACT 3 colors
*/
t_color	sub_3_colors(t_color col1, t_color col2, t_color col3)
{
	t_color	new;

	new.r = col1.r - col2.r - col3.r;
	new.g = col1.g - col2.g - col3.g;
	new.b = col1.b - col2.b - col3.b;
	return (get_rgba(new.r, new.g, new.b, 0));
}
#include "minirt.h"
// /*
// ADD 3 colors
// */
t_color	add_3_colors(t_color col1, t_color col2, t_color col3)
{
	t_color	new;

	new.r = col1.r + col2.r + col3.r;
	new.g = col1.g + col2.g + col3.g;
	new.b = col1.b + col2.b + col3.b;
	return (new);
}

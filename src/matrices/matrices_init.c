#include "minirt.h"

t_mat4	init_cam_matrix(t_vec3 right, t_vec3 up, t_vec3 forward, t_vec3 origin)
{
	t_mat4	cam_mat;

	// normaliser les vecteurs
	cam_mat = identity_matrix();
	cam_mat.p[0][0] = right.x;
	cam_mat.p[0][1] = right.y;
	cam_mat.p[0][2] = right.z;
	cam_mat.p[1][0] = up.x;
	cam_mat.p[1][1] = up.y;
	cam_mat.p[1][2] = up.z;
	cam_mat.p[2][0] = forward.x;
	cam_mat.p[2][1] = forward.y;
	cam_mat.p[2][2] = forward.z;
	cam_mat.p[0][0] = get_minirt()->camera.position.x;
	cam_mat.p[0][1] = get_minirt()->camera.position.y;
	cam_mat.p[0][2] = get_minirt()->camera.position.z;
	return (cam_mat);
}

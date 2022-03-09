#include "../includes/minirt.h"

t_vect	*new_vector(float x, float y, float z)
{
	t_vect	*vec;

	vec = malloc(sizeof(t_vect));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vect	*vec_subtraction(t_vect *vec1, t_vect *vec2)
{
	if (!vec1 && !vec2)
		return (NULL);
	if (!vec1)
		return(new_vector(vec2->x, vec2->y, vec2->z));
	if (!vec2)
		return(new_vector(vec1->x * -1, vec1->y * -1, vec1->z * -1));
	return (new_vector(vec1->x - vec2->x,
		   vec1->y - vec2->y, vec1->z - vec2->z));
}

t_vect	*vec_sum(t_vect *vec1, t_vect *vec2)
{
	if (!vec1 && !vec2)
		return (NULL);
	if (!vec1)
		return(new_vector(vec2->x, vec2->y, vec2->z));
	if (!vec2)
		return(new_vector(vec1->x, vec1->y, vec1->z));
	return (new_vector(vec1->x + vec2->x,
		   vec1->y + vec2->y, vec1->z + vec2->z));
}

float vect_len(t_vect *vec)
{
	float	len;

	if (!vec)
		return (0);
	len = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	return (len);
}

void vect_normalize(t_vect *vec)
{
	float	len;

	len = vect_len(vec);
	if (len == 0 || len == 1)
		return ;
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

float dot_product(t_vect *vec1, t_vect *vec2)
{
	float	res;

	res = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return (res);
}

void vect_multipl_on(t_vect *vec, float num)
{
	vec->x *= num;
	vec->y *= num;
	vec->z *= num;
}

void vect_del_on(t_vect *vec, float num)
{
	vec->x /= num;
	vec->y /= num;
	vec->z /= num;
}

t_vect *cross_product(t_vect *vec1, t_vect *vec2)
{
	float	x;
	float	y;
	float	z;
	t_vect	*res;

	x = (vec1->x * vec2->z) - (vec1->z * vec2->y);
	y = (vec1->z * vec2->x) - (vec1->x * vec2->z);
	z = (vec1->x * vec2->y) - (vec1->y * vec2->x);
	res = new_vector(x, y, z);
	return (res);
}

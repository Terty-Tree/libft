#include <stdlib.h>

#include "cp_vec.h"
#include "libft.h"

t_cp_vec	*cp_vec_add(t_cp_vec *vec, char *val)
{
	t_cp_vec	*tmp;

	if (vec->size + 1 > vec->capacity)
	{
		tmp = vec;
		vec = cp_vec_new(tmp->capacity + 1);
		vec = cp_vec_cpy(vec, tmp);
		cp_vec_free(&tmp);
	}
	vec->vals[vec->size] = ft_strdup(val);
	vec->size += 1;
	return (vec);
}

t_cp_vec	*cp_vec_rm(t_cp_vec *vec, int index)
{
	t_cp_vec	*tmp;
	char		*val;

	if (index < 0 || index >= vec->size)
		return (vec);
	if ((val = cp_vec_get(vec, index)) != NULL)
		free(val);
	while (index + 1 < vec->size)
	{
		vec->vals[index] = vec->vals[index + 1];
		++index;
	}
	if ((vec->size -= 1) < (int)(vec->capacity * LOAD_FACTOR))
	{
		tmp = cp_vec_new(vec->capacity * LOAD_FACTOR);
		tmp = cp_vec_cpy(tmp, vec);
		cp_vec_free(&vec);
		vec = tmp;
	}
	return (vec);
}

char		*cp_vec_get(t_cp_vec *vec, int index)
{
	if (index < 0 || index >= vec->size)
		return (NULL);
	return (vec->vals[index]);
}

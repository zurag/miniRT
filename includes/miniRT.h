/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zurag <zurag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:47:20 by zurag             #+#    #+#             */
/*   Updated: 2022/02/16 21:01:06 by zurag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include "vector.h"
# include "sphere.h"
# include "camera.h"
# include "scene.h"
# include "view_plane.h"
# include "intersect.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>



void	print_vect(t_vect *vec, char *name);


#endif 

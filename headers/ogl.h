/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ogl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 07:24:26 by snicolet          #+#    #+#             */
/*   Updated: 2016/10/25 21:25:51 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OGL_H
# define OGL_H
# include "draw.h"
# include "libft.h"
# include <SOIL2.h>
# include <GLFW/glfw3.h>
# define POINTS 24

typedef struct			s_pt_c
{
	t_v3f				pos;
	unsigned int		color;
	t_v2f				uv;
	unsigned char		tx_enabled;
}						t_pt_c;

typedef struct			s_vertex_pack
{
	t_v3f				*vertex;
	t_v2f				*uv;
	unsigned char		*flags;
	size_t				points;
	t_v3i				*faces;
	size_t				faces_count;
	t_v3f				center;
}						t_vertex_pack;

int						keyboard(GLFWwindow *window);
void					framebuffer_size_callback(GLFWwindow *window,
	int width, int height);

t_vertex_pack			*load_obj(const char *filepath);
void					display(const GLuint texture, t_vertex_pack *pack);
void					error_handler(int id, const char *str);
void					vertex_debug(t_printf *pf);
void					faces_debug(t_printf *pf);
t_v3i					*load_faces(t_list *faces, const int max,
	size_t *faces_count);
void					clean_pack(t_vertex_pack *pack);

#endif
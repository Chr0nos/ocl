/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:16:55 by snicolet          #+#    #+#             */
/*   Updated: 2017/05/27 18:35:36 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ogl.h"
#include <GLFW/glfw3.h>

int				keyboard(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		return (1);
	return (0);
}

void			framebuffer_size_callback(GLFWwindow *window,
	int width, int height)
{
	t_m4f			proj;

	(void)width;
	(void)height;
	proj = geo_mk4_tof(get_projection(window, DISPLAY_FOV, 1.0, 1000.0));
	glUniformMatrix4fv(get_pack(NULL)->uniforms.proj, 1, GL_FALSE,
		(const float *)&proj);
	glViewport(0, 0, width, height);
}

static void		key_press(GLFWwindow *window, t_vertex_pack *pack, int key)
{
	t_uniforms		*u;

	(void)window;
	u = &pack->uniforms;
	if (key == GLFW_KEY_C)
	{
		if ((u->texture_switch_mode == FLAG_SW_NONE) &&
				(u->texture_switch_val < 1.0f))
			u->texture_switch_mode = FLAG_SW_OUT;
		else
			u->texture_switch_mode = FLAG_SW_IN;
	}
	else if (key == GLFW_KEY_I)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	else if (key == GLFW_KEY_O)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (key == GLFW_KEY_P)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

static void		light_move(int key, t_vertex_pack *pack, const float speed)
{
	t_v3f	*pos;

	pos = &pack->light.position;
	if (key == GLFW_KEY_KP_8)
		pos->y += speed;
	else if (key == GLFW_KEY_KP_5)
		pos->y += -speed;
	else if (key == GLFW_KEY_KP_4)
		pos->x += -speed;
	else if (key == GLFW_KEY_KP_6)
		pos->x += speed;
	else if (key == GLFW_KEY_KP_7)
		pos->z += -speed;
	else if (key == GLFW_KEY_KP_9)
		pos->z += speed;
	else
		return ;
	ft_printf("new light position: %f %f %f\n", (double)pos->x, (double)pos->y,
		(double)pos->z);
	glUniform3fv(pack->uniforms.light_pos, 1,
		(const GLfloat*)&pack->light.position);
}

void			key_callback(GLFWwindow *window, int key, int scancode,
		int action)
{
	(void)scancode;
	if (action == 1)
		key_press(window, get_pack(NULL), key);
	light_move(key, get_pack(NULL), 0.5f);
}

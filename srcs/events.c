/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:16:55 by snicolet          #+#    #+#             */
/*   Updated: 2018/09/26 04:07:40 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ogl.h"
#include <GLFW/glfw3.h>

static void		update_fov(GLFWwindow *window, t_vertex_pack *pack,
	const double value)
{
	pack->fov += value;
	if (pack->fov < 20.0)
		pack->fov = 20.0;
	else if (pack->fov > 180.0)
		pack->fov = 180.0;
	update_projection(window, pack);
}

static int		change_polygon_mode(const int key)
{
	if (key == GLFW_KEY_I)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	else if (key == GLFW_KEY_O)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else if (key == GLFW_KEY_P)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	else
		return (0);
	return (1);
}

static void		key_press(GLFWwindow *window, t_vertex_pack *pack, int key,
	t_uniforms *u)
{
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	else if (key == GLFW_KEY_C)
	{
		if ((u->texture_switch_mode == FLAG_SW_NONE) &&
				(u->texture_switch_val < 1.0f))
			u->texture_switch_mode = FLAG_SW_OUT;
		else
			u->texture_switch_mode = FLAG_SW_IN;
	}
	else if (change_polygon_mode(key))
		;
	else if (key == GLFW_KEY_R)
		reset_camera(pack);
	else if (key == GLFW_KEY_T)
		reset_model(&pack->object);
	else if (key == GLFW_KEY_M)
		update_fov(window, pack, 5.0);
	else if (key == GLFW_KEY_N)
		update_fov(window, pack, -5.0);
	else if (key == GLFW_KEY_L)
		flag_toggle(pack, FLAG_SH_NLIGHT);
	else if (key == GLFW_KEY_K)
		flag_toggle(pack, FLAG_SH_NMAP);
}

void			key_callback(GLFWwindow *window, int key, int scancode,
		int action, int mods)
{
	t_vertex_pack		*pack;

	(void)scancode;
	pack = get_pack(NULL);
	if (action == GLFW_PRESS)
	{
		if (mods & GLFW_MOD_ALT)
			light_move(key, pack, 0.5f);
		else
		{
			key_press(window, pack, key, &pack->uniforms);
			if (key == GLFW_KEY_SPACE)
				pack->input ^= INPUT_AUTOROT;
		}
	}
	else if ((action == GLFW_REPEAT) && (mods & GLFW_MOD_ALT))
		light_move(key, pack, 0.5f);
}

void			dragndrop(GLFWwindow *window, int count, const char **files)
{
	ft_printf("received event for %p : %d files\n", window, count);
	while (count--)
		ft_printf("file %2d : %s\n", count, files[count]);
}

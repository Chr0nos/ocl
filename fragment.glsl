#version 400 core
uniform sampler2D texture_sampler;
uniform float tex_switch;
uniform int tex_mode;

in		vec2 uv;
in		vec4 fcolor;
in		vec3 fnormal;

out		vec4 frag_color;

void main() {
	vec4 lightcolor = vec4(1.0, 1.0, 1.0, 0.5);
	vec4 color = vec4(0.5, 0.2, 0.5, 1.0);

	color = texture(texture_sampler, uv);
	color = mix(color, fcolor, clamp(tex_switch, 0, 1));
	//color *= fcolor;
	//color.x *= uv.x;
	//color.y *= (uv.y + 0.7);
	frag_color = color * lightcolor;
}

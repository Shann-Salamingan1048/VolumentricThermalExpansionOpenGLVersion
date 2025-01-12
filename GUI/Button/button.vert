#version 330 core
layout (location = 0) in vec3 aPos; // Positions
layout (location = 1) in vec2 aTexCoord; // the coordinates
layout (location = 2) in vec3 aColor; // colors

out vec2 TexCoord; 
out vec3 Color;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	Color = aColor;
	TexCoord = aTexCoord;
}
#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix  = mat4(1.0);
uniform mat4 modelMatrix = mat4(1.0);

out vec4 theColor;

void main(){
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position,1.0);
	theColor = color * vec4(0.5,0.5,0.5,1.0);
}
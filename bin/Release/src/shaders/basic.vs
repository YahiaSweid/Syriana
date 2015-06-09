#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uvs;
layout (location = 2) in float texid;
layout (location = 3) in vec4 color;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix  = mat4(1.0);
uniform mat4 modelMatrix = mat4(1.0);

out vec4 thePosition;
out vec2 theUVs;
out float theTexid;
out vec4 theColor;

void main(){
	gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(position,1.0);
	thePosition = modelMatrix * vec4(position,1.0);
	theUVs = uvs;
	theTexid = texid;
	theColor = color * vec4(1.0,1.0,1.0,1.0);
}
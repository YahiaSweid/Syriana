#version 330 core

out vec4 outputColor;

in vec4 theColor;
in vec2 theUVs;
in float theTexid;

uniform sampler2D textures[10];

void main(){
    vec4 texColor = theColor;
    if(theTexid > 0){
        int texid = int(theTexid);
        texColor = texture(textures[texid],theUVs);
    }
    outputColor =   texColor * theColor;
}
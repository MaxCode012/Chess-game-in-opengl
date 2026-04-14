#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform float aspect;
uniform vec2 offset;
out vec2 TexCoord;

void main() {
    vec2 pos = aPos.xy * 0.2; 
    gl_Position = vec4((pos.x + offset.x) / aspect, pos.y + offset.y, 0.0, 1.0);
    
    TexCoord = aTexCoord; 
}
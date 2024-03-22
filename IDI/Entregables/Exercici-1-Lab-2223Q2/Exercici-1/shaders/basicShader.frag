#version 330 core

uniform  vec3 color_in;
out vec4 FragColor;


void main() {
    FragColor = vec4(color_in,1);
}

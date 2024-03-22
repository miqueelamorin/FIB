#version 330 core

in vec3 vertex;
uniform float scale;

void main()  {
    gl_Position = vec4 (vertex*scale, 1.0);
}

#version 330 core

in vec3 vertex;
uniform mat4 TG;
uniform mat4 TGE;

void main()  {
    gl_Position = TGE * TG * vec4 (vertex, 1.0);
}

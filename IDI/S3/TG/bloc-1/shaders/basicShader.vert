#version 330 core

in vec3 vertex;
uniform mat4 TG;
in vec3 colorin;
out vec3 colorout;

void main()  {
    gl_Position = TG*vec4 (vertex, 1.0);
    colorout = colorin;
}

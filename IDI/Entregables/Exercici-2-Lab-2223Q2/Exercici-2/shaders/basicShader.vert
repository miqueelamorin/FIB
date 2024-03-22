#version 330 core

in vec3 vertex;
in vec3 color;

uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;
uniform vec3 ColorCamera;
uniform vec3 ColorInvisible;
uniform bool es_invisible;

out vec3 fcolor;

void main() {
    if (es_invisible) fcolor = ColorInvisible;
    else fcolor = color*ColorCamera;
    gl_Position = Proj * View * TG * vec4 (vertex, 1.0);
}

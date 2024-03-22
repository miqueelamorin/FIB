#version 330 core

out vec4 FragColor;
in vec3 colorout;

void main() {
    FragColor = vec4(colorout, 1.0);
}


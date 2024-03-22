#version 330 core

in vec3 vertex; //aqui rep els vertexs del VBO un a un
in vec3 colorin;
out vec3 colorout;

void main()  {
    gl_Position = vec4 (vertex, 1.0); //estem afegint una coord
    colorout = colorin;
}

#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

out vec3 Fmatamb;
out vec3 Fmatdiff;
out vec3 Fmatspec;
out float Fmatshin;

out vec3 normSCO;
out vec3 vertSCO;

void main()
{
    Fmatdiff = matdiff;
    Fmatamb = matamb;
    Fmatspec = matspec;
    Fmatshin = matshin;

    //NormalMatrix i posem la normal en coords del OBS
    mat3 NormalMatrix = inverse (transpose (mat3 (view * TG)));
    normSCO = NormalMatrix*normal;

    //Passem a observador el vertex
    vertSCO = (view * TG * vec4(vertex, 1.0f)).xyz;

    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}

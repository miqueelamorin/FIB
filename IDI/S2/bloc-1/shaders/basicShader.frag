#version 330 core

out vec4 FragColor; //sortida principal de cada color de cada pixel
in vec3 colorout;

void main() {
    FragColor = vec4(colorout, 1.0);
    //if (mod(gl_FragCoord.y,22) < 11) discard;
    //if (gl_FragCoord.x < 354. && gl_FragCoord.y < 354.) FragColor = vec4(1.,1.,0.,1.);
    //else if (gl_FragCoord.x > 354. && gl_FragCoord.y < 354.) FragColor = vec4(0.,1.,0.,1.);
    //else if (gl_FragCoord.x > 354. && gl_FragCoord.y > 354.) FragColor = vec4(0.,0.,1.,1.);
}


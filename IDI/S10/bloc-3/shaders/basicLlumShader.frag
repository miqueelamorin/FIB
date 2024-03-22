#version 330 core

out vec4 FragColor;

in vec3 Fmatamb;
in vec3 Fmatdiff;
in vec3 Fmatspec;
in float Fmatshin;

in vec3 normSCO;
in vec3 vertSCO;

// Valors per als components que necessitem del focus de llum
// vec3 colorFocus = vec3(0.8, 0.8, 0.8);
// vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
// vec3 posFocus = vec3(0, 0, 0);  // en SCO

uniform vec3 colorFocusCam;
uniform vec3 colorFocusEscena;
uniform vec3 posFocusCam;
uniform vec3 posFocusEscena;
uniform vec3 llumAmbient;

vec3 Ambient() {
    return llumAmbient * Fmatamb;
}

vec3 Difus (vec3 n, vec3 L, vec3 colFocus)
{
    // Tant sols retorna el terme difús
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats
    vec3 colRes = vec3(0);
    // Càlcul component difusa, si n'hi ha
    if (dot (L, n) > 0)
      colRes = colFocus * Fmatdiff * dot (L, n);
    return (colRes);
}

vec3 Especular (vec3 n, vec3 L, vec4 vertSCO, vec3 colFocus)
{
    // Tant sols retorna el terme especular!
    // Els vectors rebuts com a paràmetres (n i L) estan normalitzats
    vec3 colRes = vec3 (0);
    // Si la llum ve de darrera o el material és mate no fem res
    if ((dot(n,L) < 0) || (Fmatshin == 0))
      return colRes;  // no hi ha component especular

    // Calculem R i V
    vec3 R = reflect(-L, n); // equival a: 2.0*dot(n,L)*n - L;
    vec3 V = normalize(-vertSCO.xyz); // perquè la càmera està a (0,0,0) en SCO

    if (dot(R, V) < 0)
      return colRes;  // no hi ha component especular

    // Calculem i retornem la component especular
    float shine = pow(max(0.0, dot(R, V)), Fmatshin);
    return (Fmatspec * colFocus * shine);
}

void main()
{	
    //normalitzem la normalSCO i calculem i norm L
    vec3 n = normalize(normSCO);
    vec3 L1 = posFocusCam - vertSCO;
    L1 = normalize(L1);
    vec3 L2 = posFocusEscena - vertSCO;
    L2 = normalize(L2);
    vec3 fcolor = Ambient() + Difus(n, L1, colorFocusCam) + Especular(n, L1, vec4(vertSCO, 1.0f), colorFocusCam) + Difus(n, L2, colorFocusEscena) + Especular(n, L2, vec4(vertSCO, 1.0f), colorFocusEscena);
	FragColor = vec4(fcolor,1);	
}

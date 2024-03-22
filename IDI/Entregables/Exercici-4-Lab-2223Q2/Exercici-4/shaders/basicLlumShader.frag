#version 330 core

in vec3  fmatamb;
in vec3  fmatdiff;
in vec3  fmatspec;
in float fmatshin;
in vec3  fvertex;
in vec3  fnormal;

uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;

uniform vec3 posFocusVermell;
uniform vec3 posFocusVerd;
uniform vec3 posFocusBlau;
uniform vec3 posFocusGroc;
uniform vec3 colFocusVermell;
uniform vec3 colFocusVerd;
uniform vec3 colFocusBlau;
uniform vec3 colFocusGroc;
uniform mat4 TGFocus;
uniform vec3 colFocusEscena;

//Valors per als components que necessitem del focus de llum
const vec3 llumAmbient = vec3(0.1, 0.1, 0.1);

out vec4 FragColor;

vec3 Ambient() {
  return llumAmbient*fmatamb;
}

vec3 Difus (vec3 NormSCO, vec3 L, vec3 colFocus)
{
  // Fixeu-vos que SOLS es retorna el terme de Lambert!
  // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats
  vec3 colRes = vec3(0);
  if (dot (L, NormSCO) > 0)
    colRes = colFocus * fmatdiff * dot (L, NormSCO);
  return (colRes);
}

vec3 Especular (vec3 NormSCO, vec3 L, vec3 vertSCO, vec3 colFocus)
{
  // Fixeu-vos que SOLS es retorna el terme especular!
  // Assumim que els vectors estan normalitzats
  vec3 colRes = vec3 (0);
  // Si la llum ve de darrera o el material és mate no fem res
  if ((dot(NormSCO,L) < 0) || (fmatshin == 0))
    return colRes;  // no hi ha component especular

  vec3 R = reflect(-L, NormSCO); // equival a: 2.0*dot(NormSCO,L)*NormSCO - L;
  vec3 V = normalize(-vertSCO); // perquè la càmera està a (0,0,0) en SCO

  if (dot(R, V) < 0)
    return colRes;  // no hi ha component especular

  float shine = pow(max(0.0, dot(R, V)), fmatshin);
  return (colRes + fmatspec * colFocus * shine);
}

void main()
{
    //normalitzem la normalSCO i calculem i norm L
    vec3 n = normalize(fnormal);
    vec3 LEscena = normalize((View * vec4(5, 10, 5, 1)).xyz - fvertex);
    vec3 fcolorEscena = Difus(n, LEscena, colFocusEscena) + Especular(n, LEscena, fvertex, colFocusEscena);

    vec3 LVermell = normalize((View * TGFocus * vec4(posFocusVermell,1)).xyz - fvertex);
    vec3 fcolorVermell = Difus(n, LVermell, colFocusVermell) + Especular(n, LVermell, fvertex, colFocusVermell);

    vec3 LVerd = normalize((View * TGFocus * vec4(posFocusVerd,1)).xyz - fvertex);
    vec3 fcolorVerd = Difus(n, LVerd, colFocusVerd) + Especular(n, LVerd, fvertex, colFocusVerd);

    vec3 LBlau = normalize((View * TGFocus * vec4(posFocusBlau,1)).xyz - fvertex);
    vec3 fcolorBlau = Difus(n, LBlau, colFocusBlau) + Especular(n, LBlau, fvertex, colFocusBlau);

    vec3 LGroc = normalize((View * TGFocus * vec4(posFocusGroc,1)).xyz - fvertex);
    vec3 fcolorGroc = Difus(n, LGroc, colFocusGroc) + Especular(n, LGroc, fvertex, colFocusGroc);

    vec3 fcolor = Ambient() + fcolorEscena + fcolorVermell + fcolorVerd + fcolorBlau + fcolorGroc;

    FragColor = vec4(fcolor, 1);
}

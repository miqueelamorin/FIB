// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

int MyGLWidget::printOglError(const char file[], int line, const char func[]) 
{
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
  makeCurrent();
  // Aqui cal que es calculi i s'apliqui la rotacio o el zoom com s'escaigui...
  if (DoingInteractive == ROTATE)
  {
    // Fem la rotació
    angleY += (e->x() - xClick) * M_PI / ample;
    angleX += (e->y() - yClick) * M_PI / alt;
    View = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -2*radiEsc));
    View = glm::rotate(View, angleX, glm::vec3(1, 0, 0));
    View = glm::rotate(View, -angleY, glm::vec3(0, 1, 0));

    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
  }

  xClick = e->x();
  yClick = e->y();

  update ();
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
    makeCurrent();
    switch (event->key()) {
    case Qt::Key_K:
        xfocus -= 0.1;
        initializeGL();
        break;
    case Qt::Key_L:
        xfocus += 0.1;
        initializeGL();
        break;
    case Qt::Key_Left:
        xpat -= 0.1;
        break;
    case Qt::Key_Right:
        xpat += 0.1;
        break;
    case Qt::Key_Up:
        zpat -= 0.1;
        break;
    case Qt::Key_Down:
        zpat += 0.1;
        break;
    case Qt::Key_1:
        ences = true;
        break;
    case Qt::Key_2:
        ences = false;
        break;
    case Qt::Key_B:
        backface = not backface;
        break;

        default: BL3GLWidget::keyPressEvent(event); break;
    }
    update();
}

void MyGLWidget::iniMaterialTerra ()    //EX3 Plastic Brillant
{
  // Donem valors al material del terra
  amb = glm::vec3(0.2,0,0.2);   //llum ambient
  diff = glm::vec3(0,0,1);      //terra blau
  spec = glm::vec3(1,1,1);      //especular (color de la brillantor)
  shin = 100;
}

void MyGLWidget::modelTransformPatricio()
{
    TG = glm::translate(TG, glm::vec3(xpat,-0.85,zpat));
    TG = glm::scale(TG, glm::vec3(escala*0.3/2.0, escala*0.3/2.0, escala*0.3/2.0));     //OJO ESCALA*nova altura/anular el factor 2.0
    TG = glm::translate(TG, -centrePatr);

    glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::initializeGL() //EX5
{
    BL3GLWidget::initializeGL();

    posFocusCamLoc = glGetUniformLocation (program->programId(), "posFocusCam");
    posFocusEscenaLoc = glGetUniformLocation (program->programId(), "posFocusEscena");
    llumAmbientLoc = glGetUniformLocation (program->programId(), "llumAmbient");
    colorFocusCamLoc = glGetUniformLocation (program->programId(), "colorFocusCam");
    colorFocusEscenaLoc = glGetUniformLocation (program->programId(), "colorFocusEscena");

    posFocus = glm::vec3(xpat, 0.5, zpat);
    //glm::vec3 posFocusEscena = View*glm::vec4(posFocus, 1.0f);

    posFocusEscena = View*glm::vec4(posFocus, 1.0f);

    glm::vec3 llumAmbient = glm::vec3(0.2, 0.2, 0.2);
    glm::vec3 colorFocusCam = glm::vec3(0.8, 0.8, 0.8);
    glm::vec3 colorFocusEscena = glm::vec3(1.0, 1.0, 0.0);

    glUniform3fv(posFocusCamLoc, 1, &posFocus[0]);
    glUniform3fv(posFocusEscenaLoc, 1, &posFocusEscena[0]);
    glUniform3fv(llumAmbientLoc, 1, &llumAmbient[0]);
    glUniform3fv(colorFocusCamLoc, 1, &colorFocusCam[0]);
    glUniform3fv(colorFocusEscenaLoc, 1, &colorFocusEscena[0]);
}

void MyGLWidget::paintGL() //EX5
{
    if (backface) glEnable (GL_CULL_FACE);
    else glDisable (GL_CULL_FACE);

    glm::vec3 colorFocusCam = glm::vec3(0.8, 0.8, 0.8);
    glm::vec3 colorFocusEscena = glm::vec3(1.0, 1.0, 0.0);
    if (not ences) {
        colorFocusCam = glm::vec3(0, 0, 0);
        colorFocusEscena = glm::vec3(0, 0, 0);
    }
    glUniform3fv(colorFocusCamLoc, 1, &colorFocusCam[0]);
    glUniform3fv(colorFocusEscenaLoc, 1, &colorFocusEscena[0]);

    posFocus = glm::vec3(xpat, 0.5, zpat);
    posFocusEscena = View*glm::vec4(posFocus, 1.0f);
    glUniform3fv(posFocusCamLoc, 1, &posFocus[0]);
    glUniform3fv(posFocusEscenaLoc, 1, &posFocusEscena[0]);

    BL3GLWidget::paintGL();
}

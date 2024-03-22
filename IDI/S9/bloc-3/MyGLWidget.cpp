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

    case Qt::Key_F:
        focusCamera = not focusCamera;
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

void MyGLWidget::initializeGL() //EX5
{
    BL3GLWidget::initializeGL();

    posFocusLoc = glGetUniformLocation (program->programId(), "posFocus");
    llumAmbientLoc = glGetUniformLocation (program->programId(), "llumAmbient");
    colorFocusLoc = glGetUniformLocation (program->programId(), "colorFocus");

    posFocus = glm::vec3(xfocus, 0.0, 1.0);
    glm::vec3 llumAmbient = glm::vec3(0.2, 0.2, 0.2);
    glm::vec3 colorFocus = glm::vec3(0.8, 0.8, 0.8);

    glUniform3fv(posFocusLoc, 1, &posFocus[0]);
    glUniform3fv(llumAmbientLoc, 1, &llumAmbient[0]);
    glUniform3fv(colorFocusLoc, 1, &colorFocus[0]);  
}

void MyGLWidget::paintGL ()
{

  if (focusCamera) glUniform3fv(posFocusLoc, 1, &posFocus[0]);
  else {
    glm::vec3 posFocusEscena = View*glm::vec4(posFocus, 1.0f);
    glUniform3fv(posFocusLoc, 1, &posFocusEscena[0]);
  }

  BL3GLWidget::paintGL();
}

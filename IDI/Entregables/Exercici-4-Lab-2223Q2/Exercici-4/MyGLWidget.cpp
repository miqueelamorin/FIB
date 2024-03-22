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
    angleX += (e->x() - yClick) * M_PI / alt;

    viewTransform2();
    }

  xClick = e->x();
  yClick = e->y();

  update ();
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
  case Qt::Key_A: {
      angleP += M_PI/4;
    break;
	}
  case Qt::Key_D: {
      angleP -= M_PI/4;
    break;
	}
  case Qt::Key_E: {
      on_escena = not on_escena;
    break;
	}
  case Qt::Key_B: {
      focus_on_off();
    break;
	}	
  case Qt::Key_R: {
      angleB += 5*M_PI/180;
    break;
	}
  case Qt::Key_S: {
      if (not timer_on) timer.start(100);
      else timer.stop();
      timer_on = not timer_on;
    break;
	}	
  default: LL4GLWidget::keyPressEvent(event); break;
  }
  update();
}

void MyGLWidget::viewTransform2()
{
    View = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -2*radiEsc));
    //View = glm::rotate(View, angleX, glm::vec3(1, 0, 0));
    View = glm::rotate(View, -angleY, glm::vec3(0, 1, 0));
    View = glm::translate(View, -centreEsc);

    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::modelTransformDiscoBall ()
{
  glm::mat4 TG;
  TG = glm::translate(glm::mat4(1.f), glm::vec3(5,5,5));
  TG = glm::rotate(TG, angleB, glm::vec3(0, 1, 0));
  TG = glm::scale(TG, glm::vec3(escalaDiscoBall, escalaDiscoBall, escalaDiscoBall));
  TG = glm::translate(TG, -centreBaseDiscoBall);

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformFocus()
{
  glm::mat4 TG = glm::mat4(1.f);
  TG = glm::translate(TG, glm::vec3(5,5,5));
  TG = glm::rotate(TG,angleB, glm::vec3(0,1,0));
  TG = glm::translate(TG, -centreBaseDiscoBall);

  glUniformMatrix4fv (TGFocusLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformMorty ()
{
  glm::mat4 TG;
  TG = glm::translate(glm::mat4(1.f), glm::vec3(5,0,5));
  TG = glm::rotate(TG, angleP, glm::vec3(0, 1, 0));
  TG = glm::scale(TG, glm::vec3(escalaMorty, escalaMorty, escalaMorty));
  TG = glm::translate(TG, -centreBaseMorty);

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::modelTransformFantasma (float posX)
{
  glm::mat4 TG;
  TG = glm::translate(glm::mat4(1.0f), glm::vec3(posX,0.5,5));
  TG = glm::rotate(TG, angleP, glm::vec3(0, 1, 0));
  TG = glm::scale(TG, glm::vec3(escalaFantasma, escalaFantasma, escalaFantasma));
  TG = glm::translate(TG, -centreBaseFantasma);

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::paintGL ()
{
  // En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
  // useu els paràmetres que considereu (els que hi ha són els de per defecte)
  // glViewport (0, 0, ample, alt);

  // Esborrem el frame-buffer i el depth-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // TERRA
  glBindVertexArray (VAO_Terra);
  modelTransformTerra ();
  glDrawArrays(GL_TRIANGLES, 0, 30);

  // MORTY
  glBindVertexArray (VAO_Morty);
  modelTransformMorty ();
  glDrawArrays(GL_TRIANGLES, 0, morty.faces().size()*3);

  // FANTASMES
  glBindVertexArray (VAO_Fantasma);
  modelTransformFantasma (1.0f);
  glDrawArrays(GL_TRIANGLES, 0, fantasma.faces().size()*3);
  modelTransformFantasma (9.0f);
  glDrawArrays(GL_TRIANGLES, 0, fantasma.faces().size()*3);

  // DISCO BALL
  glBindVertexArray (VAO_DiscoBall);
  modelTransformDiscoBall ();
  glDrawArrays(GL_TRIANGLES, 0, discoBall.faces().size()*3);

  //FOCUS
  glm::vec3 cverm = glm::vec3(0.4,0,0);
  glm::vec3 cverd = glm::vec3(0,0.4,0);
  glm::vec3 cblau = glm::vec3(0,0,0.4);
  glm::vec3 cgroc = glm::vec3(0.4,0.4,0);
  
  if(not e_verm) cverm = glm::vec3(0,0,0);
  if(not e_verd) cverd = glm::vec3(0,0,0);
  if(not e_blau) cblau = glm::vec3(0,0,0);
  if(not e_groc) cgroc = glm::vec3(0,0,0);

  glUniform3fv (colFocusVermellLoc, 1, &cverm[0]);
  glUniform3fv (colFocusVerdLoc, 1, &cverd[0]);
  glUniform3fv (colFocusBlauLoc, 1, &cblau[0]);
  glUniform3fv (colFocusGrocLoc, 1, &cgroc[0]);
  
  glm::vec3 p = glm::vec3(1.2,0,0);
  glUniform3fv (posFocusVermellLoc, 1, &p[0]);
  p = glm::vec3(-1.2,0,0);
  glUniform3fv (posFocusVerdLoc, 1, &p[0]);
  p = glm::vec3(0,0,1.2);
  glUniform3fv (posFocusBlauLoc, 1, &p[0]);
  p = glm::vec3(0,0,-1.2);
  glUniform3fv (posFocusGrocLoc, 1, &p[0]);

  glm::vec3 cescena;
  if (on_escena) cescena = glm::vec3(0.4,0.4,0.4);
  else cescena = glm::vec3(0,0,0);
  glUniform3fv (colFocusEscenaLoc, 1, &cescena[0]);

  modelTransformFocus();

  glBindVertexArray(0);
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();

  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  carregaShaders();
  posFocusVermellLoc = glGetUniformLocation (program->programId(), "posFocusVermell");
  posFocusVerdLoc = glGetUniformLocation (program->programId(), "posFocusVerd");
  posFocusBlauLoc = glGetUniformLocation (program->programId(), "posFocusBlau");
  posFocusGrocLoc = glGetUniformLocation (program->programId(), "posFocusGroc");
  colFocusVermellLoc = glGetUniformLocation (program->programId(), "colFocusVermell");
  colFocusVerdLoc = glGetUniformLocation (program->programId(), "colFocusVerd");
  colFocusBlauLoc = glGetUniformLocation (program->programId(), "colFocusBlau");
  colFocusGrocLoc = glGetUniformLocation (program->programId(), "colFocusGroc");
  colFocusEscenaLoc = glGetUniformLocation (program->programId(), "colFocusEscena");

  TGFocusLoc = glGetUniformLocation (program->programId(), "TGFocus");  

  creaBuffersMorty();
  creaBuffersFantasma();
  creaBuffersDiscoBall();
  creaBuffersTerraIParets();

  iniEscena();
  iniCamera2();
}

void MyGLWidget::iniCamera2 ()
{
  angleY = 0.0;
  angleX = 0.0;

  viewTransform2 ();
}

void MyGLWidget::iniEscena ()
{
  LL4GLWidget::iniEscena();
  angleP = 0.0;
  angleB = 0.0;
  on_escena = true;
  e_verm = e_verd = e_blau = e_groc = true;
  timer_on = false;
  connect(&timer, SIGNAL(timeout()), this, SLOT(moure_bola()));
}

void MyGLWidget::moure_bola()
{
  angleB += 5*M_PI/180;
  focus_on_off();
  update();
}

void MyGLWidget::focus_on_off(){
    if (it_focus == 0) e_verm = not e_verm;
    else if (it_focus == 1) e_verd = not e_verd;
    else if (it_focus == 2) e_blau = not e_blau;
    else e_groc = not e_groc;
    ++it_focus;
    if (it_focus > 3) it_focus = 0;
}

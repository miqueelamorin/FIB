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

MyGLWidget::~MyGLWidget()
{

}

void MyGLWidget::RickTransform ()
{
  glm::mat4 TG(1.0f);

  TG = glm::translate(TG, glm::vec3(-2, 0, -2));        //portem al -2,0,-2
  TG = glm::scale(TG, glm::vec3(escalaModels[RICK]));   //escalem a la altura
  TG = glm::rotate(TG, float(M_PI), glm::vec3(0,1,0));  //rotem cap a z neg
  TG = glm::translate(TG, -centreBaseModels[RICK]);     //centrem
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::MortyTransform ()
{
  glm::mat4 TG(1.0f);
  TG = glm::translate(TG, posMorty);
  TG = glm::rotate(TG, anglemorty, glm::vec3(0,1,0));
  TG = glm::scale(TG, glm::vec3(escalaModels[MORTY]));
  TG = glm::translate(TG, -centreBaseModels[MORTY]);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::VideoCameraTransform ()
{
  glm::mat4 TG(1.0f);
  TG = glm::translate(TG, glm::vec3(-4, 3, -4));
  TG = glm::rotate(TG, anglecamera, glm::vec3(0,1,0));
  //TG = glm::rotate(TG, float(M_PI/4), glm::vec3(0,1,0));  //rotem cap a y
  TG = glm::rotate(TG, float(M_PI/4), glm::vec3(1,0,0));  //rotem cap a x
  TG = glm::scale(TG, glm::vec3(escalaModels[VIDEOCAMERA]));
  TG = glm::translate(TG, -centreBaseModels[VIDEOCAMERA]);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::viewTransform ()
{
  // Matriu de posició i orientació de l'observador
  glm::mat4 View(1.0f);

  View = glm::translate (View, glm::vec3(0.f,0.f,-2*radiEscena));         //traslladem cap endarrere
  View = glm::rotate(View, factorAngleX, glm::vec3(1.f,0.f,0.f));          //rotem respecte a les x
  View = glm::rotate(View, factorAngleY, glm::vec3(0.f,1.f,0.f));           //rotem respecte a les y
  View = glm::translate(View,glm::vec3(-vrp.x,-vrp.y,-vrp.z));      //traslladem al VRP

  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::viewTransform2 ()
{
  // Matriu de posició i orientació de l'observador
  glm::mat4 View = glm::lookAt(obs2,vrp2,up);
  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::iniCamera()
{
  vrp = glm::vec3(0, 1.5f, 0);
  obs = glm::vec3(0, 2, 5);
  up = glm::vec3(0, 1, 0);
  fov = 2.0 * asin(radiEscena/(2.0*radiEscena));
  znear =  1;
  zfar  = 30;

  viewTransform();
}

void MyGLWidget::iniCamera2()
{
  obs2 = glm::vec3(-4, 3, -4);
  vrp2 = glm::vec3(sin(anglecamera)+obs2.x, -1+obs2.y, cos(anglecamera)+obs2.z);
  znear = 0.25;
  fov = M_PI/3;

  viewTransform2();
}

void MyGLWidget::iniEscena()
{
  radiEscena = sqrt(4*4+1.5*1.5+4*4);
  centreEscena = glm::vec3(0,1.5f,0);
  anglecamera = float(M_PI/4);
  anglemorty = 0;
  segonacamera = false;
  invisible = false;
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{

  if (DoingInteractive == ROTATE){
    makeCurrent();
    factorAngleY -= M_PI*(e->x() - xClick)/ample;
    factorAngleX += M_PI*(e->y() - yClick)/alt;
    viewTransform();
    xClick = e->x();
    yClick = e->y();
    update ();
  }
}

void MyGLWidget::keyPressEvent(QKeyEvent* event)
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_Up: {
    	posMorty += glm::vec3(sin(anglemorty),0,cos(anglemorty))*glm::vec3(0.1);
      break;
    }
    case Qt::Key_Down: {
        posMorty -= glm::vec3(sin(anglemorty),0,cos(anglemorty))*glm::vec3(0.1);
      break;
    }
    case Qt::Key_Left: {
        anglemorty += (M_PI/4);
      break;
    }
    case Qt::Key_Right: {
        anglemorty -= (M_PI/4);
      break;
    }
    case Qt::Key_Q: {
        if(anglecamera < (M_PI/2)) anglecamera += (M_PI/180);
      break;
    }
    case Qt::Key_E: {
        if(anglecamera > 0) anglecamera -= (M_PI/180);
      break;
    }
    case Qt::Key_C: {
        segonacamera = not segonacamera;
      break;
    }
    case Qt::Key_G: {
        invisible = not invisible;
      break;
    }
    case Qt::Key_R: {
      iniEscena();
      factorAngleX = M_PI/4;
      factorAngleY = M_PI / ample;
      posMorty = glm::vec3(1,0,0);
      break;
    }
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::paintGL ()
{
  glm::vec3 colorcamera(1.f,1.f,1.f);
  glUniform3fv(ColorCameraLoc, 1, &colorcamera[0]);

  glm::vec3 colorinvisible = glm::vec3(0, 1, 0) * glm::vec3(0.8,0.7,1.0);
  glUniform3fv(ColorInvisibleLoc, 1, &colorinvisible[0]);

  iniCamera();
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Si el rick s'ha de dibuixar invisible
  if (invisible) glUniform1i(InvisibleLoc, true);

  //Rick
  glBindVertexArray (VAO_models[RICK]);
  RickTransform();
  glDrawArrays(GL_TRIANGLES, 0, models[RICK].faces().size()*3);
  glUniform1i(InvisibleLoc, false);

  // Morty
  glBindVertexArray (VAO_models[MORTY]);
  MortyTransform();
  glDrawArrays(GL_TRIANGLES, 0, models[MORTY].faces().size()*3);

  // VideoCamera
  glBindVertexArray (VAO_models[VIDEOCAMERA]);
  VideoCameraTransform();
  glDrawArrays(GL_TRIANGLES, 0, models[VIDEOCAMERA].faces().size()*3);

  // Terra
  glBindVertexArray (VAO_Terra);
  identTransform();
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  // Paret
  ParetTransform();
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  //camera secundaria

  if (segonacamera){

        glViewport (ample*0.75, alt*0.75, ample*0.25, alt*0.25);
        iniCamera2();
        colorcamera = glm::vec3(0.f,1.f,0.f);
        glUniform3fv(ColorCameraLoc, 1, &colorcamera[0]);

        //Si el rick s'ha de dibuixar invisible
        if (invisible) glUniform1i(InvisibleLoc, true);

        //Rick
        glBindVertexArray (VAO_models[RICK]);
        RickTransform();
        glDrawArrays(GL_TRIANGLES, 0, models[RICK].faces().size()*3);
        glUniform1i(InvisibleLoc, false);

        // Morty
        glBindVertexArray (VAO_models[MORTY]);
        MortyTransform();
        glDrawArrays(GL_TRIANGLES, 0, models[MORTY].faces().size()*3);

        // VideoCamera
        glBindVertexArray (VAO_models[VIDEOCAMERA]);
        VideoCameraTransform();
        glDrawArrays(GL_TRIANGLES, 0, models[VIDEOCAMERA].faces().size()*3);

        // Terra
        glBindVertexArray (VAO_Terra);
        identTransform();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        // Paret
        ParetTransform();
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  }
  glBindVertexArray (0);

}

void MyGLWidget::carregaShaders()
{
    LL2GLWidget::carregaShaders();
    ColorCameraLoc  = glGetUniformLocation (program->programId(), "ColorCamera");
    ColorInvisibleLoc = glGetUniformLocation (program->programId(), "ColorInvisible");
    InvisibleLoc = glGetUniformLocation (program->programId(), "es_invisible");
}




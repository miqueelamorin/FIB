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

void MyGLWidget::paintGL () 
{
// En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
// useu els paràmetres que considereu (els que hi ha són els de per defecte)
//  glViewport (0, 0, ample, alt);
  
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT);

  glEnable (GL_DEPTH_TEST);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  // Carreguem la transformació de model
  ini_camera();

  //transformem el homer per rotar i escalar
  modelTransform ();

  // Activem el VAO per a pintar la caseta 
  glBindVertexArray (VAO_Homer);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, m.faces().size()*3);

  terraTransform();
  glBindVertexArray (VAO_Terra);
  glDrawArrays (GL_TRIANGLES, 0, 6);

  glBindVertexArray (0);
}

void MyGLWidget::creaBuffers ()
{
  m.load ("./Model/HomerProves.obj");

  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Homer);
  glBindVertexArray(VAO_Homer);

  GLuint VBO_Homer[2];
  glGenBuffers(2, VBO_Homer);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Homer[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces ().size () * 3 * 3, m.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glBindBuffer(GL_ARRAY_BUFFER, VBO_Homer[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces ().size () * 3 * 3,  m.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  glBindVertexArray (0);

  //Creem el buffer i vao del terra
  glm::vec3 pos_terra[6] =
    {
        glm::vec3(-1,-1,1),
        glm::vec3(1,-1,1),
        glm::vec3(-1,-1,-1),

        glm::vec3(-1,-1,-1),
        glm::vec3(1,-1,1),
        glm::vec3(1,-1,-1)
    };

//     glm::vec3 color_terra[6] =
//     {
//         glm::vec3(1,0,0),
//         glm::vec3(0,1,0),
//         glm::vec3(0,0,1),
//         glm::vec3(0,0,1),
//         glm::vec3(0,1,0),
//         glm::vec3(1,0,0)
//     };

    glm::vec3 color_terra = glm::vec3(0.0,0.0,1.0);

    // Creació del Vertex Array Object per pintar
    glGenVertexArrays(1,&VAO_Terra);
    glBindVertexArray(VAO_Terra);

    GLuint VBO_Terra[2];
    glGenBuffers(2, VBO_Terra);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pos_terra), pos_terra, GL_STATIC_DRAW);

    // Activem l'atribut vertexLocs
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_Terra[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color_terra), color_terra, GL_STATIC_DRAW);

    // Activem l'atribut colorLoc
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);

    glBindVertexArray (0);

}

void MyGLWidget::terraTransform() {
    // Matriu de transformació de model
    glm::mat4 transform (1.0f);
    transform = glm::scale(transform, glm::vec3(escala));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransform() {     //homer
    // Matriu de transformació de model
    glm::mat4 transform (1.0f);
    transform = glm::scale(transform, glm::vec3(escala));
    transform = glm::rotate(transform, angle, glm::vec3(0,1,0));
    //transform = glm::rotate(transform, float(M_PI)/4.0f, glm::vec3(0,1,0)); //nidea de pq esta esto
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::projectTransform()
{
    glm::mat4 Proj = glm::perspective (FOV, ra, znear, zfar);
    //glm::mat4 Proj = glm::perspective(float(M_PI/2.0f), 1.f, 0.4f, 3.0f);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform () {
    glm::mat4 View = glm::lookAt (OBS, VRP, UP);
    //glm::mat4 View = glm::lookAt (glm::vec3(0,0,1) glm::vec3(0,0,0), glm::vec3(0,1,0));
    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::carregaShaders()
{
    BL2GLWidget::carregaShaders(); //per cridar a la del pare
    projLoc = glGetUniformLocation(program -> programId(), "proj");
    viewLoc = glGetUniformLocation (program->programId(), "view");
}

void MyGLWidget::ini_camera()
{
    OBS = glm::vec3(0.f,0.f,1.f);
    VRP = glm::vec3(0.f,0.f,0.f);
    UP = glm::vec3(0.f,1.f,0.f);
    FOV = float(M_PI/2.0f);
    ra = 1.f;
    znear = 0.4f;
    zfar = 3.f;
    viewTransform();
    projectTransform();
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
            escala += 0.05;
            break;
    }
    case Qt::Key_D: { // escalar a més petit
        escala -= 0.05;
        break;
    }
    case Qt::Key_R: { // escalar a més gran
      angle += float(M_PI)/4.0f;
      break;
    }
    default:
        event->ignore();
        break;
  }
  update();
}

MyGLWidget::~MyGLWidget() {
}



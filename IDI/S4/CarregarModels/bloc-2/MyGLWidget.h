// MyGLWidget.h
#include "BL2GLWidget.h"
#include "model.h"
#include <QKeyEvent>

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  private:
    int printOglError(const char file[], int line, const char func[]);

    virtual void paintGL ( );

    virtual void creaBuffers ();

    virtual void carregaShaders ();

    virtual void keyPressEvent (QKeyEvent *event);

    void projectTransform();

    void modelTransform();

    void terraTransform();

    void viewTransform();

    void ini_camera();

    Model m;
    GLuint VAO_Homer;
    GLuint VAO_Terra;

    GLuint projLoc;     //finestra FOV, ra, znear, zfar
    GLuint viewLoc;     //VRP, OBS, UP

    glm::vec3 OBS, VRP, UP;
    float FOV, ra, znear, zfar;

    float angle;
};

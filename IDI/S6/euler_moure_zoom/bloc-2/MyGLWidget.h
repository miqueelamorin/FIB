// MyGLWidget.h
#include "BL2GLWidget.h"
#include "model.h"
#include <QKeyEvent>
#include <QMouseEvent>

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

  private:
    int printOglError(const char file[], int line, const char func[]);

    virtual void initializeGL ( );

    virtual void paintGL ( );

    virtual void creaBuffers ();

    virtual void carregaShaders ();

    virtual void keyPressEvent (QKeyEvent *event);

    virtual void resizeGL (int w, int h);

    virtual void mousePressEvent ( QMouseEvent * e );
    virtual void mouseReleaseEvent ( QMouseEvent * e );
    virtual void mouseMoveEvent ( QMouseEvent * e );

    void projectTransform();

    void modelTransform();

    void terraTransform();

    void viewTransform();

    void ini_camera();

    void calcula_centre();

    void calcula_centre_p();

    Model m;
    GLuint VAO_Homer;
    GLuint VAO_Terra;
    GLuint projLoc;
    GLuint viewLoc;

    float scale_h;
    glm::vec3 centre;
    glm::vec3 centre_p;
    glm::vec3 escena_max;
    glm::vec3 escena_min;

    float radi;

    glm::vec3 OBS, VRP, UP;
    float FOV, ra, znear, zfar, FOVini;

    float angle;

    int perspective;

    float left, right, bottom, top;

    float psi, theta;

    bool mouse_apretat;

    int old_x, old_y;
};

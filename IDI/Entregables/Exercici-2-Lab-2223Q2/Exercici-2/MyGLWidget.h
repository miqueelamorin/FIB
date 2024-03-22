#include "LL2GLWidget.h"

#include "model.h"

class MyGLWidget : public LL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : LL2GLWidget(parent) {}
    ~MyGLWidget();

  protected:

  private:

    int printOglError(const char file[], int line, const char func[]);

    virtual void paintGL ();
    virtual void carregaShaders();

    virtual void RickTransform();
    virtual void MortyTransform();
    virtual void VideoCameraTransform();

    virtual void iniCamera ();
    void iniCamera2 ();
    virtual void iniEscena ();
    virtual void viewTransform();
    void viewTransform2 ();

    virtual void mouseMoveEvent (QMouseEvent *event);

    virtual void keyPressEvent (QKeyEvent *event);

    float anglecamera;
    float anglemorty;
    bool segonacamera;
    bool invisible;

    float factorAngleX = M_PI/4;

    glm::vec3 obs2, vrp2;

    GLuint ColorCameraLoc;
    GLuint ColorInvisibleLoc;
    GLuint InvisibleLoc;
};

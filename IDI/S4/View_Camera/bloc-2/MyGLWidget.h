// MyGLWidget.h
#include "BL2GLWidget.h"

class MyGLWidget : public BL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
    ~MyGLWidget();

    virtual void carregaShaders ();

    virtual void paintGL ( );

    void projectTransform();

    void viewTransform();

  private:
    int printOglError(const char file[], int line, const char func[]);
    GLuint projLoc;
    GLuint viewLoc;
};

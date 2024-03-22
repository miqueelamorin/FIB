// MyGLWidget.h
#include "BL3GLWidget.h"

class MyGLWidget : public BL3GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent=0) : BL3GLWidget(parent) {}
    ~MyGLWidget();

  protected:
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void iniMaterialTerra();
    virtual void initializeGL();
    virtual void modelTransformPatricio();
    virtual void paintGL();

    GLuint posFocusCamLoc, colorFocusCamLoc, colorFocusEscenaLoc, llumAmbientLoc, posFocusEscenaLoc;
    float xfocus = 1.0;
    float angleX;
    bool focusCamera = true;
    glm::vec3 posFocus;
    glm::vec3 posFocusEscena;
    float xpat = 0;
    float zpat = 0;
    bool ences = true;
    bool backface = false;

  private:
    int printOglError(const char file[], int line, const char func[]);
};

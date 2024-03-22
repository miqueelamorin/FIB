// MyGLWidget.h
#include "LL4GLWidget.h"
#include <QTimer>

class MyGLWidget : public LL4GLWidget {
  Q_OBJECT
  public:
    MyGLWidget(QWidget *parent=0) : LL4GLWidget(parent) {}
    ~MyGLWidget();
  protected:
    virtual void mouseMoveEvent(QMouseEvent *e);
    virtual void keyPressEvent(QKeyEvent* event);

    void modelTransformDiscoBall();
    void modelTransformFantasma(float posX);
    void modelTransformMorty();
    void paintGL();
    void initializeGL();
    void iniEscena();

    void viewTransform2();
    void iniCamera2();
    void modelTransformFocus();
    void focus_on_off();

    GLuint posFocusVermellLoc;
    GLuint posFocusVerdLoc;
    GLuint posFocusBlauLoc;
    GLuint posFocusGrocLoc;
    GLuint colFocusVermellLoc;
    GLuint colFocusVerdLoc;
    GLuint colFocusBlauLoc;
    GLuint colFocusGrocLoc;
    GLuint TGFocusLoc;
    GLuint colFocusEscenaLoc;

    QTimer timer;
    bool timer_on;
    bool on_escena;
    bool e_verm, e_verd, e_blau, e_groc;
    int it_focus;
    float angleP, angleB;
    float angleX;
  private:
    int printOglError(const char file[], int line, const char func[]);
  
  public slots:
    void moure_bola();
};

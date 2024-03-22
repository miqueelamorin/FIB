#include "MyGLWidget.h"

class NouGLWidget : public MyGLWidget
{
 Q_OBJECT
	   
 public:
  NouGLWidget (QWidget *parent=NULL);
  ~NouGLWidget ();

 public slots:

 signals:

 protected:
  void paintGL ();
  void iniCamera ();
  void iniEscena ();
  void viewTransform ();
  void projectTransform ();
  void modelTransformPatricio ();
  
  void modelTransformPatricio2();
  
  float pat2x;
  float pat2z;
  bool camPlanta;
  
  // keyPressEvent - Es cridat quan es prem una tecla
  void keyPressEvent (QKeyEvent *event);
  
 private:

};

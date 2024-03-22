#include <QLCDNumber>
#include <QTime>
#include <QTimer>

class MyQLCDNumber:public QLCDNumber
{
    Q_OBJECT
        public:
            MyQLCDNumber(QWidget *parent);
            QTime temps, record;
            QTimer tempo;
            bool primera_vegada;
            bool estat_start;

        public slots:
            void iniciar_i_parar();
            void restaurar();
            void mostrar_temps();

        signals:
            void actualitzar_record(QString record);
            void color_temps(QString color);
};

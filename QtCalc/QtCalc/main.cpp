#include "QtCalc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtCalc w;
	w.setWindowFlags(w.windowFlags()& ~Qt::WindowMaximizeButtonHint);//�������
	w.show();
	return a.exec();
}

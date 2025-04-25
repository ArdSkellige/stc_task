#include "qt_app/main_wgt.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWgt_t mw;
	mw.show();
	return a.exec();
}
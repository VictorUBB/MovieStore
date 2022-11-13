#include "Lab10_GUI.h"
#include <QtWidgets/QApplication>
#include "ui.h"
#include "FileRepository.h"
#include "FilmGUI.h"
void start() {
	FileRepository repo{"filme.txt"};
	validation val;
	Service srv{ repo,val };
	ui ui{ srv };
	//ui.test_all();
	ui.run();
}


int main(int argc, char *argv[])
{
	//start();
    QApplication a(argc, argv);
	FileRepository repo{"filme.txt"};
	validation val;
	Cos cos;
	Service srv{ repo,val };
	FilmGUI gui{ srv };
	gui.show();
    return a.exec();
}

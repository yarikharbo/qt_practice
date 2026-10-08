#include "citygamedialog.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    CityGameDialog dialog;
    dialog.show();
    return app.exec();
}
#include <QApplication>
#include "BookInput.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    BookInput window;
    window.setWindowTitle("Book Input");
    window.resize(400, 300);
    window.show();

    return app.exec();
}

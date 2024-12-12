#include <QApplication>
#include "PasswordValidator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    PasswordValidator validator;
    validator.show();

    return app.exec();
}

#include <QApplication>
#include <QLabel>

int main (int argc, char* argv[]) //always have this line
{
    QApplication app(argc, argv); //always have this line
    QLabel* label = new QLabel("Hello my QT!");
    label->show();
    return app.exec(); //always have this line
}

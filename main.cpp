#include <QCoreApplication>
#include "observer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Observer observer( {"C:/Qt/file1.txt", "C:/Qt/file2.txt", "C:/Qt/file3.txt"}); // Создаем объект класса Observer и передаем ему список имен файлов.

    observer.watch(); // Запускаем метод watch() объекта observer, который запускает таймер для проверки файлов.

    return a.exec(); // Запускаем цикл обработки событий в QApplication.
}

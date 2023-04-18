#ifndef OBSERVER_H
#define OBSERVER_H

#include <QObject>
#include <vector>
#include <memory>
#include "file.h"

class QTimer;

class Observer : public QObject {    //Объявляем класс Observer, который наследуется от класса QObject и имеет макрос Q_OBJECT1212312312123123
Q_OBJECT

public:
     Observer(const std::vector<QString> &filenames, QObject *parent = nullptr); //Объявляем публичный конструктор класса Observer, который принимает список имен файлов и родительский объект QObject.

    void watch();    //Объявляем публичный метод класса Observer, который запускает проверку файлов на изменения.

private slots:

    void checkFiles();   //Объявляем приватный слот класса Observer, который будет вызываться при таймере и будет проверять изменения в файлах.

private:                 //Объявляем приватные переменные класса Observer, которые будут хранить список файлов и таймер.
    std::vector<std::shared_ptr<File>> m_files;
    QTimer *m_timer;
};

#endif // OBSERVER_H

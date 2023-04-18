#include <QTimer>
#include <iostream>
#include <memory>
#include "observer.h"
#include "file.h"

Observer::Observer(const std::vector<QString> &filenames, QObject *parent) //вектор строк (имен файлов) и указатель на родительский объект.
        : QObject(parent), m_timer(new QTimer(this)) {  // инициализация родительского класса QObject и создание объекта QTimer с помощью оператора new и указания родительского объекта this.
    for (const auto &filename : filenames) {     // перебор
        m_files.emplace_back(std::make_shared<File>(filename)); // создание и добавление в вектор m_files общих указателей на объекты класса File,
                                                                // каждый из которых создается с помощью функции std::make_shared и передачи имени файла.
    }
    connect(m_timer, &QTimer::timeout, this, &Observer::checkFiles); //подключение сигнала timeout объекта QTimer к слоту checkFiles класса Observer.
}

void Observer::watch() {           //определение метода класса Observer, который запускает таймер для проверки файлов через равные интервалы времени.
    m_timer->start(1000);
}

void Observer::checkFiles() {   //определение метода класса Observer, который проверяет существование и размеры файлов и выводит соответствующие сообщения в консоль.
    for (auto &file : m_files) { // перебор объектов класса File, содержащихся в векторе m_files, с помощью диапазонного for-цикла.
        file->update();          // вызов метода update для каждого объекта класса File
        if (file->exists()) { // проверка существования файла с помощью метода exists и вывод соответствующего сообщения в консоль.
            std::cout << "File " << file->name().toStdString() << " exists, size: " << file->size() << std::endl;
        } else {
            std::cout << "File " << file->name().toStdString() << " does not exist." << std::endl;
        }
    }
    std::cout << "\n";
}

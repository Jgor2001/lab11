#include <QFileInfo>
#include <iostream>
#include "file.h"
#include <QFile>

File::File(const QString &name)
        : m_name(name), m_size(0), m_exists(false) {    //определение конструктора класса File с инициализацией членов класса
    update(); //вызов метода update() для обновления состояния файла при создании объекта класса
}

bool File::exists() const {
    if (QFile(m_name).exists())   // определяем флаг существования
        return true;
     else
        return false;

}

unsigned short File::size() const {        //определение метода size(), возвращающего размер файла
    return m_size;
}

const QString &File::name() const {      //определение метода name(), возвращающего имя файла
    return m_name;
}

void File::update() {
    QFileInfo fileInfo(m_name); // создание экземпляра класса
    if (fileInfo.exists()) {
        m_exists = true;
        unsigned short prev_size = m_size;
        m_size = fileInfo.size();
        if (prev_size != 0 && prev_size != m_size) {
            std::cout << "File " << m_name.toStdString() << " size changed to " << m_size << std::endl;
        }
    } else {
        m_exists = false;
        m_size = 0;
    }
}


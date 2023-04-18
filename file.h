#ifndef FILE_H
#define FILE_H

#include <QString>

class File {
public:
    File(const QString &name);    // Конструктор, принимающий имя файла

    bool exists() const;        // Метод, проверяющий существование файла
    unsigned short size() const;          // Метод, возвращающий размер файла
    const QString &name() const;     // Метод, возвращающий имя файла

    void update();                     // Метод, обновляющий информацию о файле

private:
    QString m_name;                  // Имя файла
    unsigned short m_size;                   // Размер файла
    bool m_exists;                   // Флаг существования файла
};

#endif // FILE_H


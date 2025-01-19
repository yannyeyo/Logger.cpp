#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <ctime>
#include <cstring>

// Перечисление для уровней логирования
enum class LogLevel {
    INFO,
    WARNING,
    ERROR,
    EMPTY
};

// Класс Logger для записи сообщений в файл
class Logger {
private:
    std::ofstream logFile;  // Файловый поток для записи в файл
    LogLevel defaultLevel;  // Уровень логирования по умолчанию
    std::mutex mtx;         // Мьютекс для обеспечения потокобезопасности

public:
    // Конструктор принимает имя файла и уровень логирования по умолчанию
    Logger(const std::string& filename, LogLevel defaultLevel = LogLevel::INFO);

    // Деструктор закрывает файл
    ~Logger();

    // Метод для записи сообщения в лог
    void log(const std::string& message, LogLevel level = LogLevel::INFO);

private:
    // Метод для преобразования уровня логирования в строку
    std::string logLevelToString(LogLevel level);
};

#endif // LOGGER_H

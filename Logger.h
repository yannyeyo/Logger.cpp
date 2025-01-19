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
    std::ofstream logFile;
    LogLevel defaultLevel;
    std::mutex mtx;       

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

#endif

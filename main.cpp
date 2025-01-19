#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include <sstream>
#include "Logger.h"

// Атомарная переменная для контроля работы приложения
std::atomic<bool> running(true);

// Функция для логирования сообщений в отдельном потоке
void logMessage(Logger& logger, const std::string& message, LogLevel level) {
    logger.log(message, level);
}

int main() {
    std::string filename;
    std::string levelStr;
    std::string message;

    // Запрос имени файла журнала
repete_filename:
    std::cout << "Enter log file name: ";
    std::getline(std::cin, filename);
    std::string lastFour = filename.length() >= 4 ? filename.substr(filename.length() - 4, 4) : filename;
    if (lastFour != ".txt") {
        std::cout << "Incorrect filename, need .txt format!\n";
        goto repete_filename;
    }

    // Запрос уровня логирования по умолчанию
again:
    std::cout << "Enter default log level (INFO, WARNING, ERROR): ";
    std::getline(std::cin, levelStr);

    // Установка уровня логирования по умолчанию
    LogLevel defaultLevel = LogLevel::INFO;
    if (levelStr == "WARNING") {
        defaultLevel = LogLevel::WARNING;
    }
    else if (levelStr == "ERROR") {
        defaultLevel = LogLevel::ERROR;
    }
    else if(levelStr != "INFO") {
        std::cout << "Incorrect text, try again!\n";
        goto again;
    }

    // Создаем объект логгера
    Logger logger(filename, defaultLevel);

    // Основной цикл программы
    while (running) {
        std::cout << "Enter message (or type 'QUIT/quit' to exit): ";
        std::getline(std::cin, message);

        if (message == "QUIT" || message == "quit") {
            running = false;  // Завершение программы
        }
        else {
            // Запрос уровня важности для сообщения
    again_2:
            std::cout << "Enter log level for the message (INFO, WARNING, ERROR): ";
            std::getline(std::cin, levelStr);

            LogLevel level = defaultLevel;
            if (levelStr == "WARNING") {
                level = LogLevel::WARNING;
            }
            else if (levelStr == "ERROR") {
                level = LogLevel::ERROR;
            }
            else if (levelStr == "") {
                level = LogLevel::EMPTY;
            }
            else if (levelStr != "INFO") {
                std::cout << "Incorrect text, try again!\n";
                goto again_2;
            }

            // Создаем поток для логирования сообщения
            std::thread logThread(logMessage, std::ref(logger), message, level);
            logThread.detach();  // Отключаем поток для фоновой работы
        }
    }

    std::cout << "Program terminated." << std::endl;
    return 0;
}

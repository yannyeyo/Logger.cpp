#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <ctime>
#include <cstring>

// ������������ ��� ������� �����������
enum class LogLevel {
    INFO,
    WARNING,
    ERROR,
    EMPTY
};

// ����� Logger ��� ������ ��������� � ����
class Logger {
private:
    std::ofstream logFile;  // �������� ����� ��� ������ � ����
    LogLevel defaultLevel;  // ������� ����������� �� ���������
    std::mutex mtx;         // ������� ��� ����������� ������������������

public:
    // ����������� ��������� ��� ����� � ������� ����������� �� ���������
    Logger(const std::string& filename, LogLevel defaultLevel = LogLevel::INFO);

    // ���������� ��������� ����
    ~Logger();

    // ����� ��� ������ ��������� � ���
    void log(const std::string& message, LogLevel level = LogLevel::INFO);

private:
    // ����� ��� �������������� ������ ����������� � ������
    std::string logLevelToString(LogLevel level);
};

#endif // LOGGER_H

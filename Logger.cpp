#include "Logger.h"
#include <iostream>

// ����������� ��������� ���� ��� ������ � ��������� ���������� ��������
Logger::Logger(const std::string& filename, LogLevel defaultLevel)
    : defaultLevel(defaultLevel) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        std::cerr << "Unable to open log file!" << std::endl;
        exit(1);  // ��������� ��������� ��� ������ �������� �����
    }
}

// ���������� ��������� ����, ���� �� ������
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// ����� ��� ������ ��������� � ����
void Logger::log(const std::string& message, LogLevel level) {
    std::lock_guard<std::mutex> lock(mtx);  // ����������� ������������������
    if (level >= defaultLevel) {
        auto now = std::chrono::system_clock::now();  // �������� ������� �����
        std::time_t time = std::chrono::system_clock::to_time_t(now);
        char timeBuffer[26];
        ctime_s(timeBuffer, sizeof(timeBuffer), &time);  // ����������� ����� � ������
        timeBuffer[std::strlen(timeBuffer) - 1] = '\0';
        logFile << "[" << timeBuffer << "]" << "[" << logLevelToString(level) << "] " << message << std::endl;
    }
}

// �������������� ������ ����������� � ������ ��� ������ � ����
std::string Logger::logLevelToString(LogLevel level) {
    switch (level) {
    case LogLevel::INFO: return "INFO";
    case LogLevel::WARNING: return "WARNING";
    case LogLevel::ERROR: return "ERROR";
    case LogLevel::EMPTY: return "";
    default: return "UNKNOWN";
    }
}

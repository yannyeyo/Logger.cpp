#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <ctime>
#include <cstring>

// Ïåðå÷èñëåíèå äëÿ óðîâíåé ëîãèðîâàíèÿ
enum class LogLevel {
    INFO,
    WARNING,
    ERROR,
    EMPTY
};

// Êëàññ Logger äëÿ çàïèñè ñîîáùåíèé â ôàéë
class Logger {
private:
    std::ofstream logFile;
    LogLevel defaultLevel;
    std::mutex mtx;  

public:
    // Êîíñòðóêòîð ïðèíèìàåò èìÿ ôàéëà è óðîâåíü ëîãèðîâàíèÿ ïî óìîë÷àíèþ
    Logger(const std::string& filename, LogLevel defaultLevel = LogLevel::INFO);

    // Äåñòðóêòîð çàêðûâàåò ôàéë
    ~Logger();

    // Ìåòîä äëÿ çàïèñè ñîîáùåíèÿ â ëîã
    void log(const std::string& message, LogLevel level = LogLevel::INFO);

private:
    // Ìåòîä äëÿ ïðåîáðàçîâàíèÿ óðîâíÿ ëîãèðîâàíèÿ â ñòðîêó
    std::string logLevelToString(LogLevel level);
};

#endif

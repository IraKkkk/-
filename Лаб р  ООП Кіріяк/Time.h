#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Конструктор за замовчуванням
    Time() : hours(0), minutes(0), seconds(0) {}

    // Конструктор ініціалізації числами
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Конструктор ініціалізації рядком
    Time(const std::string& timeStr) {
        std::stringstream ss(timeStr);
        char delimiter;
        ss >> hours >> delimiter >> minutes >> delimiter >> seconds;
    }

    // Конструктор ініціалізації секундами
    Time(int totalSeconds) {
        hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
    }

    // Метод для обчислення різниці між двома моментами часу в секундах
    int differenceInSeconds(const Time& other) const {
        int thisSeconds = hours * 3600 + minutes * 60 + seconds;
        int otherSeconds = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return thisSeconds - otherSeconds;
    }

    // Метод для додавання заданої кількості секунд до часу
    void addSeconds(int secs) {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds + secs;
        hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
    }

    // Метод для вирахування заданої кількості секунд із часу
    void subtractSeconds(int secs) {
        int totalSeconds = hours * 3600 + minutes * 60 + seconds - secs;
        if (totalSeconds < 0) {
            totalSeconds += 86400; // 86400 секунд у добі
        }
        hours = totalSeconds / 3600;
        totalSeconds %= 3600;
        minutes = totalSeconds / 60;
        seconds = totalSeconds % 60;
    }

    // Метод для порівняння двох моментів часу
    bool operator<(const Time& other) const {
        if (hours < other.hours)
            return true;
        if (hours > other.hours)
            return false;
        if (minutes < other.minutes)
            return true;
        if (minutes > other.minutes)
            return false;
        return seconds < other.seconds;
    }

    // Метод для переведення часу у секунди
    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    // Метод для переведення часу у хвилини з округленням
    int toMinutes() const {
        return (hours * 60 + minutes + (seconds >= 30 ? 1 : 0));
    }

    // Метод для виведення часу на екран
    void Display() const {
        std::cout << toString() << std::endl;
    }

    // Метод для перетворення часу в рядок
    std::string toString() const {
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << hours << ":"
            << std::setfill('0') << std::setw(2) << minutes << ":"
            << std::setfill('0') << std::setw(2) << seconds;
        return ss.str();
    }
};


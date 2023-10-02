#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <Windows.h>
#include "Time.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Приклади використання класу Time
    Time t1; // 00:00:00 (за замовчуванням)
    Time t2(12, 30, 45); // 12:30:45
    Time t3("23:59:59"); // 23:59:59
    Time t4(3661); // 01:01:01

    t1.Display(); // Виведе: 00:00:00
    t2.Display(); // Виведе: 12:30:45
    t3.Display(); // Виведе: 23:59:59
    t4.Display(); // Виведе: 01:01:01

    int diff = t3.differenceInSeconds(t2); // Різниця між t3 і t2 у секундах
    std::cout << "Різниця між t3 і t2: " << diff << " секунд" << std::endl;

    t2.addSeconds(300); // Додаємо 300 секунд до t2
    t2.Display(); // Виведе: 12:35:45

    t4.subtractSeconds(61); // Вираховуємо 61 секунд із t4
    t4.Display(); // Виведе: 01:00:00

    bool comparison = t2 < t3; // Порівнюємо час t2 і t3
    std::cout << "t2 менше за t3: " << (comparison ? "Так" : "Ні") << std::endl;

    int seconds = t4.toSeconds(); // Переводимо t4 у секунди
    std::cout << "t4 у секундах: " << seconds << " секунд" << std::endl;

    int minutes = t4.toMinutes(); // Переводимо t4 у хвилини
    std::cout << "t4 у хвилинах: " << minutes << " хвилин" << std::endl;

    return 0;}

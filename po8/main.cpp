#include <iostream>
#include <iomanip>
#include <sstream>
#include "marathon_runner.h"
#include "file_reader.h"
#include "filters.h"
#include "sorts.h"

std::string format_time(int seconds) {
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int sec = seconds % 60;

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << hours << ":"
        << std::setw(2) << std::setfill('0') << minutes << ":"
        << std::setw(2) << std::setfill('0') << sec;
    return ss.str();
}

int main() {
    setlocale(LC_ALL, "Russian");

    auto runners = read_runners("data.txt");

    // Участники Спартака (сортировка пузырьком)
    auto spartak = filter_by_club(runners, "Спартак");
    bubble_sort_by_club_surname(spartak);

    std::cout << "=== Участники из Спартака ===\n";
    for (const auto& r : spartak) {
        std::cout << r.surname << " | Время: " << format_time(r.finish_time - r.start_time) << "\n";
    }

    // Все участники (быстрая сортировка)
    quick_sort_by_time(runners);

    std::cout << "\n=== Все участники ===\n";
    for (const auto& r : runners) {
        std::cout << r.surname << " | Время: " << format_time(r.finish_time - r.start_time) << "\n";
    }

    return 0;
}
#include <iostream>
#include "marathon_runner.h"
#include "file_reader.h"
#include "filters.h"
#include "sorts.h"  // Подключаем заголовочный файл с сортировками

int main() {
    auto runners = read_runners("data.txt");

    // Фильтрация 1: Участники из "Спартака"
    auto spartak = filter_by_club(runners, "Спартак");

    // Сортировка участников из Спартака по времени забега (возрастание)
    quick_sort_by_time(spartak);

    std::cout << "=== Участники из Спартака (отсортированы по времени) ===\n";
    for (const auto& r : spartak) {
        int result = r.finish_time - r.start_time;
        std::cout << r.surname << " " << r.name << " — "
            << result / 3600 << ":"
            << (result % 3600) / 60 << ":"
            << result % 60 << "\n";
    }

    // Фильтрация 2: Результат лучше 2:50:00 (10200 секунд)
    auto best = filter_by_result(runners, 10200);

    // Сортировка лучших результатов по клубу и фамилии (возрастание)
    bubble_sort_by_club_surname(best);

    std::cout << "\n=== Лучшие результаты (отсортированы по клубу и фамилии) ===\n";
    for (const auto& r : best) {
        int result = r.finish_time - r.start_time;
        std::cout << r.surname << " " << r.name << " — "
            << result / 3600 << ":"
            << (result % 3600) / 60 << ":"
            << result % 60 << "\n";
    }

    return 0;
}
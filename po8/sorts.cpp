#include "sorts.h"
#include <algorithm>

// Быстрая сортировка
void quick_sort_by_time(std::vector<MarathonRunner>& runners) {
    std::sort(runners.begin(), runners.end(), [](const auto& a, const auto& b) {
        return (a.finish_time - a.start_time) < (b.finish_time - b.start_time);
        });
}

// Сортировка пузырьком
void bubble_sort_by_club_surname(std::vector<MarathonRunner>& runners) {
    for (size_t i = 0; i < runners.size(); i++) {
        for (size_t j = 0; j < runners.size() - i - 1; j++) {
            if (runners[j].club > runners[j + 1].club ||
                (runners[j].club == runners[j + 1].club && runners[j].surname > runners[j + 1].surname)) {
                std::swap(runners[j], runners[j + 1]);
            }
        }
    }
}
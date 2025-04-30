#include "sorts.h"

// Быстрая сортировка (по времени)
void quick_sort_by_time(std::vector<MarathonRunner>& runners) {
    if (runners.size() <= 1) return;

    int pivot = runners[runners.size() / 2].finish_time - runners[runners.size() / 2].start_time;
    std::vector<MarathonRunner> less, greater, equal;

    for (const auto& r : runners) {
        int time = r.finish_time - r.start_time;
        if (time < pivot) less.push_back(r);
        else if (time > pivot) greater.push_back(r);
        else equal.push_back(r);
    }

    quick_sort_by_time(less);
    quick_sort_by_time(greater);

    runners.clear();
    runners.insert(runners.end(), less.begin(), less.end());
    runners.insert(runners.end(), equal.begin(), equal.end());
    runners.insert(runners.end(), greater.begin(), greater.end());
}

// Сортировка пузырьком (по клубу и фамилии)
void bubble_sort_by_club_surname(std::vector<MarathonRunner>& runners) {
    for (size_t i = 0; i < runners.size(); i++) {
        for (size_t j = 0; j < runners.size() - i - 1; j++) {
            // Сравниваем клубы
            if (runners[j].club > runners[j + 1].club) {
                std::swap(runners[j], runners[j + 1]);
            }
            // Если клубы одинаковые - сравниваем фамилии
            else if (runners[j].club == runners[j + 1].club && runners[j].surname > runners[j + 1].surname) {
                std::swap(runners[j], runners[j + 1]);
            }
        }
    }
}
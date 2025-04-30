#pragma once
#include "marathon_runner.h"
#include <vector>

// Быстрая сортировка (только по времени)
void quick_sort_by_time(std::vector<MarathonRunner>& runners);

// Сортировка пузырьком (только по клубу и фамилии)
void bubble_sort_by_club_surname(std::vector<MarathonRunner>& runners);
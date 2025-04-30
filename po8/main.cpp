#include <iostream>
#include "marathon_runner.h"
#include "file_reader.h"
#include "filters.h"

int main() {
    auto runners = read_runners("data.txt");

    // ‘ильтраци€ 1: ”частники из "—партака"
    auto spartak = filter_by_club(runners, "—партак");
    std::cout << "=== ”частники из —партака ===\n";
    for (const auto& r : spartak) {
        int result = r.finish_time - r.start_time;
        std::cout << r.surname << " " << r.name << " Ч "
            << result / 3600 << ":"
            << (result % 3600) / 60 << ":"
            << result % 60 << "\n";
    }

    // ‘ильтраци€ 2: –езультат лучше 2:50:00 (10200 секунд)
    auto best = filter_by_result(runners, 10200);
    std::cout << "\n=== Ћучшие результаты ===\n";
    for (const auto& r : best) {
        int result = r.finish_time - r.start_time;
        std::cout << r.surname << " " << r.name << " Ч "
            << result / 3600 << ":"
            << (result % 3600) / 60 << ":"
            << result % 60 << "\n";
    }

    return 0;
}
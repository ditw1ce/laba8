#include "marathon_runner.h"
#include <vector>

std::vector<MarathonRunner> filter_by_club(const std::vector<MarathonRunner>& runners, const std::string& club) {
    std::vector<MarathonRunner> result;
    for (const auto& runner : runners) {
        if (runner.club == club) {
            result.push_back(runner);
        }
    }
    return result;
}

std::vector<MarathonRunner> filter_by_result(const std::vector<MarathonRunner>& runners, int max_time) {
    std::vector<MarathonRunner> result;
    for (const auto& runner : runners) {
        int time = runner.finish_time - runner.start_time;
        if (time < max_time) {
            result.push_back(runner);
        }
    }
    return result;
}
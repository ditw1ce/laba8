#include "marathon_runner.h"
#include <fstream>
#include <sstream>
#include <vector>

std::vector<MarathonRunner> read_runners(const std::string& filename) {
    std::vector<MarathonRunner> runners;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        MarathonRunner runner;
        std::istringstream iss(line);
        iss >> runner.id >> runner.surname >> runner.name >> runner.patronymic;

        std::string start_str, finish_str;
        iss >> start_str >> finish_str;
        runner.start_time = time_to_seconds(start_str);
        runner.finish_time = time_to_seconds(finish_str);

        std::getline(iss, runner.club);  // остаток строки название клуба
        runner.club = runner.club.substr(1);  // убрать пробел в начале

        runners.push_back(runner);
    }

    return runners;
}

int time_to_seconds(const std::string& time_str) {
    int hours, minutes, seconds;
    char delimiter;
    std::istringstream iss(time_str);
    iss >> hours >> delimiter >> minutes >> delimiter >> seconds;
    return hours * 3600 + minutes * 60 + seconds;
}
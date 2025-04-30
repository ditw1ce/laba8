#pragma once
#include <string>

struct MarathonRunner {
    int id;
    std::string surname;
    std::string name;
    std::string patronymic;
    int start_time;
    int finish_time;
    std::string club;
};

int time_to_seconds(const std::string& time_str);
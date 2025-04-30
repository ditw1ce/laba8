#pragma once
#include "marathon_runner.h" 
#include <vector>
#include <string>


std::vector<MarathonRunner> read_runners(const std::string& filename);

int time_to_seconds(const std::string& time_str);
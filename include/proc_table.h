#pragma once

#include <string>
#include <vector>

struct ProcessInfo {
    int pid;
    std::string name;
};

std::vector<ProcessInfo> getProcesses();
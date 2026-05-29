#include "../include/proc_table.h"

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

std::vector<ProcessInfo> getProcesses() {

    std::vector<ProcessInfo> processes;

    for (const auto& entry :
         fs::directory_iterator("/proc")) {

        std::string folder =
            entry.path().filename().string();

        if (!isdigit(folder[0]))
            continue;

        std::ifstream file(
            "/proc/" + folder + "/comm");

        if (!file)
            continue;

        ProcessInfo p;

        p.pid = std::stoi(folder);

        std::getline(file, p.name);

        processes.push_back(p);
    }

    return processes;
}
#include "../include/cpu_sampler.h"
#include "../include/mem_parser.h"
#include "../include/proc_table.h"

#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

int main() {

    while (true) {

        system("clear");

        double cpu = getCpuUsage();
        double mem = getMemoryUsage();

        auto processes = getProcesses();

        std::cout << "\n";
        std::cout << "====================================\n";
        std::cout << " Linux System Resource Monitor\n";
        std::cout << "====================================\n\n";

        std::cout << std::fixed
                  << std::setprecision(2);

        std::cout << "CPU Usage    : "
                  << cpu
                  << "%\n";

        std::cout << "Memory Usage : "
                  << mem
                  << "%\n";

        std::cout << "Processes    : "
                  << processes.size()
                  << "\n\n";

        std::cout << "Top Processes\n";
        std::cout << "-----------------------------\n";

        int limit = 10;

        for (auto &p : processes) {

            std::cout
                << p.pid
                << "\t"
                << p.name
                << "\n";

            if (--limit == 0)
                break;
        }

        std::this_thread::sleep_for(
            std::chrono::seconds(1));
    }

    return 0;
}
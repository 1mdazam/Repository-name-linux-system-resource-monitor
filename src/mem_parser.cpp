#include "../include/mem_parser.h"

#include <fstream>
#include <string>

MemInfo getMemInfo() {
    std::ifstream file("/proc/meminfo");

    MemInfo m{};

    std::string key;
    long value;

    while (file >> key >> value) {

        if (key == "MemTotal:")
            m.total = value;

        else if (key == "MemFree:")
            m.free = value;

        else if (key == "MemAvailable:")
            m.available = value;
    }

    return m;
}

double getMemoryUsage() {
    MemInfo m = getMemInfo();

    if (m.total == 0)
        return 0.0;

    return 100.0 *
           (1.0 - ((double)m.available / m.total));
}
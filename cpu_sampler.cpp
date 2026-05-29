#include "../include/cpu_sampler.h"

#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

CpuTicks readCpuTicks() {
    std::ifstream file("/proc/stat");

    std::string cpu;
    long user, nice, system, idle;
    long iowait, irq, softirq, steal;

    file >> cpu >> user >> nice >> system >> idle
         >> iowait >> irq >> softirq >> steal;

    long total =
        user + nice + system + idle +
        iowait + irq + softirq + steal;

    return {idle, total};
}

double getCpuUsage() {
    CpuTicks t0 = readCpuTicks();

    usleep(100000);

    CpuTicks t1 = readCpuTicks();

    long idleDiff = t1.idle - t0.idle;
    long totalDiff = t1.total - t0.total;

    if (totalDiff == 0)
        return 0.0;

    return 100.0 * (1.0 - ((double)idleDiff / totalDiff));
}
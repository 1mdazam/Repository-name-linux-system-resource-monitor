#pragma once

struct CpuTicks {
    long idle;
    long total;
};

CpuTicks readCpuTicks();
double getCpuUsage();
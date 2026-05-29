#pragma once

struct MemInfo {
    long total;
    long free;
    long available;
};

MemInfo getMemInfo();
double getMemoryUsage();
#pragma once

#include <string>

namespace sysinfo {
const std::string getOsVersion();
bool screenIsVGA();
bool screenIsWVGA();
bool screenIsRotate();
}
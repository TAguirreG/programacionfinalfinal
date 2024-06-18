#pragma once

#include <iostream>
#include <string>

namespace utils {

void clearScreen() { std::cout << std::string(100, '\n'); }

} // namespace utils

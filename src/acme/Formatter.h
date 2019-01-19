#pragma once

#include <chrono>
#include <string>

namespace Utils
{

namespace Formatter
{

std::string formatWithThousand(int value, char spaceChar = ' ');
std::string formatWithThousand(std::string value, char spaceChar = ' ');

std::string formatTime(long long time);
std::string formatTimeWithoutMilliseconds(std::chrono::seconds time);

} // namespace Formatter

} /* namespace Utils */

#pragma once

#include <string>
#include <vector>

std::string columnsFormat(std::vector<int> widths, char filler, char separator);

std::string columnHeadFormat(std::string title, int width);

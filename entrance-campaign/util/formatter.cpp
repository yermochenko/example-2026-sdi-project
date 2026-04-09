#include "formatter.h"

std::string columnsFormat(std::vector<int> widths, char filler, char separator)
{
	std::string result = std::string(1, separator);
	for (int width : widths)
	{
		result += std::string(width, filler) + std::string(1, separator);
	}
	return result;
}

std::string columnHeadFormat(std::string title, int width)
{
	if (title.size() < width)
	{
		int gap = width - title.size();
		int leftGap = gap / 2;
		int rightGap = gap - leftGap;
		return std::string(leftGap, ' ') + title + std::string(rightGap, ' ');
	}
	else
	{
		return title;
	}
}

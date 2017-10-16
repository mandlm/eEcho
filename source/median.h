#pragma once

#include <vector>
#include <algorithm>

template<typename VALUE_TYPE>
double median(std::vector<VALUE_TYPE> values) 
{
	if (values.size() == 0)
	{
		return 0.0;
	}

	size_t centerIndex = values.size() / 2;
	std::nth_element(values.begin(), values.begin() + centerIndex, values.end());
	
	if (values.size() % 2 == 1)
	{
		return values[centerIndex];
	}
	else
	{
		std::nth_element(values.begin(), values.begin() + centerIndex + 1, values.end());
		return (values[centerIndex] + values[centerIndex + 1]) / 2.0;
	}
}

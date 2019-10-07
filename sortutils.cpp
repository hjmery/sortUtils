#include "sortutils.hpp"

void initializeRawArrayFromStdArray(
	const std::array<int, HOW_MANY_ELEMENTS>& source, int dest[])
{
	for (int i = 0; i < source.size(); i++)
	{
		dest[i] = source[i];
	}
}

void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS>& data)
{
	std::sort(data.begin(), data.end());

	int middle;

	if (data.size() % 2 == 0)
	{
		middle = (data.size() / 2) - 1;
	}
	else
	{
		middle = data.size() / 2;
	}

	for (int i = middle + 1; i < data.size(); i++)
	{
		int iter = i - middle;
		data[i] = data[i - (iter * 2 - 1)];
	}
}

// time and report how long it takes to sort each of the array types
// HOW_MANY_TIMES each function separately times how long it takes for each
// array type
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted,
					  const SourceArray& reversed, const SourceArray& organPipe,
					  const SourceArray& rotated)
{
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted,
					  const SourceArray& reversed, const SourceArray& organPipe,
					  const SourceArray& rotated)
{
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted,
					   const SourceArray& reversed,
					   const SourceArray& organPipe, const SourceArray& rotated)
{
}
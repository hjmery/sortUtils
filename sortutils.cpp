#include "sortutils.hpp"

void initializeRawArrayFromStdArray(
	const std::array<int, HOW_MANY_ELEMENTS>& source, int dest[])
{
	for (int i = 0; i < source.size(); i++)
	{
		dest[i] = source[i];
	}

	for (int i = 0; i < source.size(); i++)
	{
		std::cout << dest[i] << std::endl;
	}
}

void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS>& data) {}

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
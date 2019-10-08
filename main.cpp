#include "sortutils.hpp"

// TODO
// Figure out how to use the array provided
// --- Figured out??? create a random array, create a sorted array, create a
// reversed array
// --- create an organ pipe array, create a rotated array
// get initializeRaw... function working
// get organPipe function working
// get evaluate functions working

int main()
{
	// This feels wrong plus i'm using a literal buttload of memory
	// for this but its kinda how it seems that its supposed to be
	SourceArray srcArray;
	SourceArray srcArraySorted;
	SourceArray srcArrayReversed;
	SourceArray srcArrayOrganPipe;
	SourceArray srcArrayRotated;

	std::random_device rd;
	std::default_random_engine engine(rd());
	std::uniform_int_distribution<> dist(-10'000'000, 10'000'000);

	for (int i = 0; i < srcArray.size(); i++)
	{
		int num = dist(engine);
		srcArray[i] = num;
	}

	srcArraySorted = srcArray;

	std::sort(srcArraySorted.begin(), srcArraySorted.end());

	for (int i = 0; i < srcArray.size(); i++)
	{
		srcArrayReversed[i] = srcArraySorted[i];
		srcArrayOrganPipe[i] = srcArraySorted[i];
		srcArrayRotated[i] = srcArraySorted[i];
	}

	std::reverse(srcArrayReversed.begin(), srcArrayReversed.end());
	organPipeStdArray(srcArrayOrganPipe);
	std::rotate(srcArrayRotated.begin(), srcArrayRotated.begin() + 1,
				srcArrayRotated.end());

	evaluateRawArray(srcArray, srcArraySorted, srcArrayReversed,
					 srcArrayOrganPipe, srcArrayRotated);
}
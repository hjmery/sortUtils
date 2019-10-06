#include "sortutils.hpp"

// TODO
// Figure out how to use the array provided
// --- Figured out??? create a random array, create a sorted array, create a reversed array
// --- create an organ pipe array, create a rotated array
// get initializeRaw... function working
// get organPipe function working
// get evaluate functions working

int main(int argc, char* argv[])
{
	SourceArray src;

	std::random_device rd;
	std::default_random_engine engine(rd());
	std::uniform_int_distribution<> dist(-10'000'000, 10'000'000);

	for (int i = 0; i < src.size(); i++)
	{
		src[i] = dist(engine);
	}

	// initializeRawArrayFromStdArray();
}
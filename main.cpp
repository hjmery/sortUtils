#include "sortutils.hpp"

// TODO
// Figure out how to use the array provided
// --- Figured out??? create a random array, create a sorted array, create a
// reversed array
// --- create an organ pipe array, create a rotated array
// get initializeRaw... function working
// get organPipe function working
// get evaluate functions working

int main(int argc, char* argv[])
{
	SourceArray srcArray;
	int rawArray[HOW_MANY_ELEMENTS];
	std::vector<int> vectorArray;

	std::random_device rd;
	std::default_random_engine engine(rd());
	std::uniform_int_distribution<> dist(-10'000'000, 10'000'000);

	for (int i = 0; i < srcArray.size(); i++)
	{
		srcArray[i] = dist(engine);
		vectorArray.push_back(srcArray[i]);
	}

	initializeRawArrayFromStdArray(srcArray, rawArray);

	for (int i = 0; i < 100; i++)
	{
		std::cout << srcArray[i] << " " << rawArray[i] << " " << vectorArray[i]
				  << std::endl;
	}
}
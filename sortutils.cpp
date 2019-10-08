#include "sortutils.hpp"

// void initalizeStdArrays(const SourceArray& random, const SourceArray& sorted,
//					   const SourceArray& reversed,
//					   const SourceArray& organPipe, const SourceArray& rotated)
//{
//	std::random_device rd;
//	std::default_random_engine engine(rd());
//	std::uniform_int_distribution<> dist(-10'000'000, 10'000'000);
//
//	for (int i = 0; i < random.size(); i++)
//	{
//		int num = dist(engine);
//		random[i] = num;
//		srcArraySorted[i] = num;
//	}
//
//	std::sort(srcArraySorted.begin(), srcArraySorted.end());
//
//	for (int i = 0; i < srcArray.size(); i++)
//	{
//		srcArrayReversed[i] = srcArraySorted[i];
//		srcArrayOrganPipe[i] = srcArraySorted[i];
//		srcArrayRotated[i] = srcArraySorted[i];
//	}
//
//	std::reverse(srcArrayReversed.begin(), srcArrayReversed.end());
//	organPipeStdArray(srcArrayOrganPipe);
//	std::rotate(srcArrayRotated.begin(), srcArrayRotated.begin() + 1,
//				srcArrayRotated.end());
//}

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
		middle = static_cast<int>((data.size() / 2) - 1);
	}
	else
	{
		middle = static_cast<int>(data.size() / 2);
	}

	for (int i = middle + 1; i < data.size(); i++)
	{
		int iter = i - middle;
		int index = i - (iter * 2 - 1);
		data[i] = data[index];
	}
}

// time and report how long it takes to sort each of the array types
// HOW_MANY_TIMES each function separately times how long it takes for each
// array type
void evaluateRawArray(const SourceArray& random, const SourceArray& sorted,
					  const SourceArray& reversed, const SourceArray& organPipe,
					  const SourceArray& rotated)
{
	using namespace std::chrono;

	int raw[HOW_MANY_ELEMENTS];

	auto randTimeTotal = 0;
	for (int i = 0; i < HOW_MANY_TIMES; i++)
	{
		initializeRawArrayFromStdArray(random, raw);
		auto begin = steady_clock::now();
		std::sort(raw, raw + HOW_MANY_ELEMENTS);
		auto end = steady_clock::now();
		auto randTime = duration_cast<milliseconds>(end - begin);
		randTimeTotal += randTime.count();
	}

	auto sortedTimeTotal = 0;
	for (int i = 0; i < HOW_MANY_TIMES; i++)
	{
		initializeRawArrayFromStdArray(sorted, raw);
		auto begin = steady_clock::now();
		std::sort(raw, raw + HOW_MANY_ELEMENTS);
		auto end = steady_clock::now();
		auto randTime = duration_cast<milliseconds>(end - begin);
		sortedTimeTotal += randTime.count();
	}

	auto reversedTimeTotal = 0;
	for (int i = 0; i < HOW_MANY_TIMES; i++)
	{
		initializeRawArrayFromStdArray(reversed, raw);
		auto begin = steady_clock::now();
		std::sort(raw, raw + HOW_MANY_ELEMENTS);
		auto end = steady_clock::now();
		auto randTime = duration_cast<milliseconds>(end - begin);
		reversedTimeTotal += randTime.count();
	}

	auto organPipeTimeTotal = 0;
	for (int i = 0; i < HOW_MANY_TIMES; i++)
	{
		initializeRawArrayFromStdArray(organPipe, raw);
		auto begin = steady_clock::now();
		std::sort(raw, raw + HOW_MANY_ELEMENTS);
		auto end = steady_clock::now();
		auto randTime = duration_cast<milliseconds>(end - begin);
		organPipeTimeTotal += randTime.count();
	}

	auto rotatedTimeTotal = 0;
	for (int i = 0; i < HOW_MANY_TIMES; i++)
	{
		initializeRawArrayFromStdArray(rotated, raw);
		auto begin = steady_clock::now();
		std::sort(raw, raw + HOW_MANY_ELEMENTS);
		auto end = steady_clock::now();
		auto randTime = duration_cast<milliseconds>(end - begin);
		rotatedTimeTotal += randTime.count();
	}

	std::cout << randTimeTotal << " " << sortedTimeTotal << " "
			  << reversedTimeTotal << " " << organPipeTimeTotal << " "
			  << rotatedTimeTotal << std::endl;
}

// void evaluateStdArray(const SourceArray& random, const SourceArray& sorted,
//					  const SourceArray& reversed, const SourceArray& organPipe,
//					  const SourceArray& rotated)
//{
//	using namespace std::chrono;
//
//	auto begin1 = high_resolution_clock::now();
//	std::sort(random.begin(), random.end());
//	auto end1 = high_resolution_clock::now();
//	auto randTime = duration_cast<milliseconds>(end1 - begin1);
//
//	auto begin2 = high_resolution_clock::now();
//	std::sort(sorted.begin(), sorted.end());
//	auto end2 = high_resolution_clock::now();
//	auto sortedTime = duration_cast<milliseconds>(end2 - begin2);
//
//	auto begin3 = high_resolution_clock::now();
//	std::sort(reversed.begin(), reversed.end());
//	auto end3 = high_resolution_clock::now();
//	auto reversedTime = duration_cast<milliseconds>(end3 - begin3);
//
//	auto begin4 = high_resolution_clock::now();
//	std::sort(organPipe.begin(), organPipe.end());
//	auto end4 = high_resolution_clock::now();
//	auto organPipeTime = duration_cast<milliseconds>(end4 - begin4);
//
//	auto begin5 = high_resolution_clock::now();
//	std::sort(rotated.begin(), rotated.end());
//	auto end5 = high_resolution_clock::now();
//	auto rotatedTime = duration_cast<milliseconds>(end5 - begin5);
//
//	std::cout << randTime.count() << " " << sortedTime.count() << " "
//			  << reversedTime.count() << " " << organPipeTime.count() << " "
//			  << rotatedTime.count() << std::endl;
//}

// void evaluateStdVector(const SourceArray& random, const SourceArray& sorted,
//					   const SourceArray& reversed,
//					   const SourceArray& organPipe, const SourceArray& rotated)
//{
//}
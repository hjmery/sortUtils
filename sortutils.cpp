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
        middle = static_cast<int>((data.size() / 2) - 1);
        for (int i = middle + 1; i < data.size(); i++)
        {
            int iter = i - middle;
            int index = i - (iter * 2 - 1);
            data[i] = data[index];
        }
    }
    else
    {
        middle = static_cast<int>(data.size() / 2);
        for (int i = middle + 1; i < data.size(); i++)
        {
            int iter = i - middle;
            int index = i - (iter * 2);
            data[i] = data[index];
        }
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

    std::cout << "---Raw Array Performance---" << std::endl;
    std::cout << "Random Time       " << randTimeTotal << " ms" << std::endl;
    std::cout << "Sorted Time       " << sortedTimeTotal << " ms" << std::endl;
    std::cout << "Reversed Time     " << reversedTimeTotal << " ms"
              << std::endl;
    std::cout << "Organ Pipe Time   " << organPipeTimeTotal << " ms"
              << std::endl;
    std::cout << "Rotated Time      " << rotatedTimeTotal << " ms" << std::endl;
    std::cout << std::endl;
}

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted,
                      const SourceArray& reversed, const SourceArray& organPipe,
                      const SourceArray& rotated)
{
    using namespace std::chrono;

    auto randTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        auto src = random;
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        randTimeTotal += randTime.count();
    }

    auto sortedTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        auto src = sorted;
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        sortedTimeTotal += randTime.count();
    }

    auto reversedTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        auto src = reversed;
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        reversedTimeTotal += randTime.count();
    }

    auto organPipeTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        auto src = organPipe;
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        organPipeTimeTotal += randTime.count();
    }

    auto rotatedTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        auto src = rotated;
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        rotatedTimeTotal += randTime.count();
    }

    std::cout << "---std::array Performance---" << std::endl;
    std::cout << "Random Time       " << randTimeTotal << " ms" << std::endl;
    std::cout << "Sorted Time       " << sortedTimeTotal << " ms" << std::endl;
    std::cout << "Reversed Time     " << reversedTimeTotal << " ms"
              << std::endl;
    std::cout << "Organ Pipe Time   " << organPipeTimeTotal << " ms"
              << std::endl;
    std::cout << "Rotated Time      " << rotatedTimeTotal << " ms" << std::endl;
    std::cout << std::endl;
}

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted,
                       const SourceArray& reversed,
                       const SourceArray& organPipe, const SourceArray& rotated)
{
    using namespace std::chrono;

    auto randTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> src(random.begin(), random.end());
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        randTimeTotal += randTime.count();
    }

    auto sortedTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> src(sorted.begin(), sorted.end());
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        sortedTimeTotal += randTime.count();
    }

    auto reversedTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> src(reversed.begin(), reversed.end());
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        reversedTimeTotal += randTime.count();
    }

    auto organPipeTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> src(organPipe.begin(), organPipe.end());
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        organPipeTimeTotal += randTime.count();
    }

    auto rotatedTimeTotal = 0;
    for (int i = 0; i < HOW_MANY_TIMES; i++)
    {
        std::vector<int> src(rotated.begin(), rotated.end());
        auto begin = steady_clock::now();
        std::sort(src.begin(), src.end());
        auto end = steady_clock::now();
        auto randTime = duration_cast<milliseconds>(end - begin);
        rotatedTimeTotal += randTime.count();
    }

    std::cout << "---std::vector Performance---" << std::endl;
    std::cout << "Random Time       " << randTimeTotal << " ms" << std::endl;
    std::cout << "Sorted Time       " << sortedTimeTotal << " ms" << std::endl;
    std::cout << "Reversed Time     " << reversedTimeTotal << " ms"
              << std::endl;
    std::cout << "Organ Pipe Time   " << organPipeTimeTotal << " ms"
              << std::endl;
    std::cout << "Rotated Time      " << rotatedTimeTotal << " ms" << std::endl;
    std::cout << std::endl;
}
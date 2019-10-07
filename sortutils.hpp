#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

const std::size_t HOW_MANY_ELEMENTS = 2500;
const std::uint8_t HOW_MANY_TIMES = 25;
const std::size_t TEN = 10;

using SourceArray = std::array<int, HOW_MANY_ELEMENTS>;

void initializeRawArrayFromStdArray(
	const std::array<int, HOW_MANY_ELEMENTS>& source, int dest[]);

void organPipeStdArray(std::array<int, HOW_MANY_ELEMENTS>& data);

void evaluateRawArray(const SourceArray& random, const SourceArray& sorted,
					  const SourceArray& reversed, const SourceArray& organPipe,
					  const SourceArray& rotated);

void evaluateStdArray(const SourceArray& random, const SourceArray& sorted,
					  const SourceArray& reversed, const SourceArray& organPipe,
					  const SourceArray& rotated);

void evaluateStdVector(const SourceArray& random, const SourceArray& sorted,
					   const SourceArray& reversed,
					   const SourceArray& organPipe,
					   const SourceArray& rotated);
#pragma once

#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

const std::size_t HOW_MANY_ELEMENTS = 250000;
const std::uint8_t HOW_MAMY_TIMES = 25;
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
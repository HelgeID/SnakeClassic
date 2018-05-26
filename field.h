//File: field.h
//Author: HelgeID
#pragma once
#include "pixel.h"
#include <vector>

#define SIZE 32

class Field
{
public:
	std::vector<std::vector<Pixel>> field;
	Field(const int, const int);
	~Field();
};

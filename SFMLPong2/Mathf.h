#pragma once

#include <cmath>
#include "vec2.h"

class Mathf
{
	public:
		//Intersect method function takes the position and size of 2 objects and checks if they...well...intersect
		static bool intersect(const vec2& pos1, const vec2& size1, const vec2& pos2, const vec2& sie2);
};


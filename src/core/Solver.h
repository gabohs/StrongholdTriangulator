#pragma once

#include <cmath>
#include "Constants.h"

class Solver
{
private:


public:
    static float calculateDistance(float angle1, float angle2, float perpDist);
    static float normalizeAngle(float angle);
};

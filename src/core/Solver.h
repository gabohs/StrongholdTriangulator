#pragma once

#include <cmath>

class Solver
{
private:
    static constexpr double PI = 3.141592653589793;

public:
    static float calculateDistance(float angle1, float angle2, float perpDist);
    static float normalizeAngle(float angle);
};

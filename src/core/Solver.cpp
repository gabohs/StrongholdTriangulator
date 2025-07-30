#include "Solver.h"

float Solver::calculateDistance(float angle1, float angle2, float perpDist)
{
    float angleDif = std::abs(angle1 - angle2);

    float hypotenuse = perpDist / std::sin( angleDif * (Constants::PI / 180) );

    return hypotenuse;
}

float Solver::normalizeAngle(float angle)
{
    while (angle > 180.0f) 
        angle -= 360.0f;

    while (angle <= -180.0f) 
        angle += 360.0f;

    return angle;
}

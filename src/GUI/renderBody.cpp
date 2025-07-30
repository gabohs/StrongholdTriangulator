#include "GUI.h"

#include <iostream>

void GUI::renderBody()
{
    static float angle1 = 0;
    static float angle2 = 0;

    static float perpDistTraveled = 17.5; 

    ImGui::Text("Angle 1 | Angle 2");

    ImGui::PushItemWidth(panelSize.x / 4);

    ImGui::InputFloat("##Angle1", &angle1);
    ImGui::SameLine();
    ImGui::InputFloat("##Angle2", &angle2);

    ImGui::PopItemWidth();

    ImGui::Dummy({0.f, 3.f});

    ImGui::Text("Distance traveled (perpendicular to 1st eye): ");
    ImGui::InputFloat("##dist", &perpDistTraveled);

    float distInSprintJumps = perpDistTraveled / 4.375; // fix ts magic number later, its the distance of 1 sprint jump
    ImGui::TextColored(Colors::Purple, "That is %.1f sprint jumps", distInSprintJumps);

    ImGui::Dummy({0.f, 3.f});

    float distance = Solver::calculateDistance(angle1, angle2, perpDistTraveled); 

    ImGui::Text("Distance to travel (blocks):");
    ImGui::SameLine();
    ImGui::TextColored(Colors::Green, "%.1f", distance);

    ImGui::Dummy({0.f, 10.f});

    float angleMinus90 = Solver::normalizeAngle(angle1 - 90.0f);
    float anglePlus90 = Solver::normalizeAngle(angle1 + 90.0f);

    ImGui::Text("[INFO]");
    ImGui::Dummy({0.f, 3.f});

    ImGui::TextColored(Colors::BrightRed, "GO TOWARDS %.1f  OR  %.1f to find second angle", angleMinus90, anglePlus90);
    ImGui::Dummy({0.f, 3.f});
    ImGui::TextColored(Colors::Aqua, "Angle dif.: %.1f", std::abs(angle1 - angle2));
}
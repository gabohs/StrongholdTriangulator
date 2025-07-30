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

    float distInSprintJumps = perpDistTraveled / Constants::sprintJump;
    ImGui::TextColored(Colors::Purple, "That is %.1f sprint jumps", distInSprintJumps);

    ImGui::Dummy({0.f, 3.f});

    float distance = Solver::calculateDistance(angle1, angle2, perpDistTraveled); 

    ImGui::Text("You need to travel:");
    ImGui::PushStyleColor(ImGuiCol_Text, Colors::Green);
    ImGui::PushItemWidth(80);
    ImGui::InputFloat("blocks", &distance, 0, 0, "%.1f", ImGuiInputTextFlags_ReadOnly);
    ImGui::PopItemWidth();
    ImGui::PopStyleColor();

    ImGui::Dummy({0.f, 5.f});

    float angleMinus90 = Solver::normalizeAngle(angle1 - 90.0f);
    float anglePlus90 = Solver::normalizeAngle(angle1 + 90.0f);    

    if (ImGui::CollapsingHeader("[INFO]", ImGuiTreeNodeFlags_DefaultOpen))
    {   
        ImGui::Bullet();
        ImGui::Text("Go towards ");
        ImGui::SameLine();
        ImGui::TextColored(Colors::BrightRed, "%.1f", angleMinus90);
        ImGui::SameLine();
        ImGui::Text(" or ");
        ImGui::SameLine();
        ImGui::TextColored(Colors::BrightRed, "%.1f", anglePlus90);
        ImGui::SameLine();
        ImGui::Text(" to find the second angle");

        ImGui::Dummy({0.f, 3.f});

        ImGui::Bullet();
        ImGui::TextColored(Colors::Aqua, "Angle difference: %.1f", std::abs(angle1 - angle2));

        ImGui::Dummy({0.f, 3.f});

        ImGui::Bullet();
        ImGui::TextLinkOpenURL("github", "https://github.com/gabohs/StrongholdTriangulator");
    }  
}
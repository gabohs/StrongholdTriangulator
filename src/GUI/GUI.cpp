#include "GUI.h"

GUI::GUI()
{
}

bool GUI::shouldRender()
{
    return shouldRender_;
}

bool GUI::shouldMinimize()
{
    return shouldMinimize_;
}

void GUI::setShouldMinimize(bool value)
{
    shouldMinimize_ = value;
}

ImVec2 GUI::getWindowPos()
{   
    return lastWindowPos_;
}

ImVec2 GUI::getWindowSize()
{
    return lastWindowSize_;
}

ImVec2 GUI::getMousePos()
{
    return ImGui::GetMousePos();
}

void GUI::render()
{
    ImGui::SetNextWindowSize(panelSize, ImGuiCond_Once);
    ImGui::Begin("MyApp", nullptr, ImGuiWindowFlags_NoTitleBar);

    lastWindowPos_ = ImGui::GetWindowPos();
    lastWindowSize_ = ImGui::GetWindowSize();

    renderCustomTitleBar();
    
    renderBody();

    ImGui::End();

}
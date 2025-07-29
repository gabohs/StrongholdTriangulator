#pragma once

#include <imgui.h>
#include "../../Theme/colors.h"

#include "../core/Solver.h"

class GUI
{
private:
    ImVec2 panelSize = {400, 300};
    ImVec2 lastWindowPos_;
    ImVec2 lastWindowSize_;
    bool shouldRender_ = true;
    bool shouldMinimize_ = false;

private:
    void renderCustomTitleBar();
    void renderBody();

public:
    GUI();
    bool shouldRender();
    bool shouldMinimize();
    void setShouldMinimize(bool value);

    ImVec2 getWindowPos();
    ImVec2 getWindowSize();
    ImVec2 getMousePos();

    void render();
};
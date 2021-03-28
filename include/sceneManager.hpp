#pragma once
#include <vector>

// Scene list:
// 0: Main Menu
// 1: Options
// 2: Map Select
// 3: Loaded Map
void loadScene(int sceneNumber);
void saveLoadedScene();

std::vector<int> getScenes();


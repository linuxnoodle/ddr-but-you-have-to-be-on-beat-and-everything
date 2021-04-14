#pragma once
#include <vector>

// Looks like I don't have enough time left to properly implement scenes, 
// so gonna just use random bools to check if i am in a state. 

// Scene list:
// 0: Main Menu
// 1: Options
// 2: Map Select
// 3: Loaded Map
void loadScene(int sceneNumber);
void saveLoadedScene();

std::vector<int> getScenes();


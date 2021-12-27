#include "params.h"
void Parameters::load() {
    std::fstream configFile;
    configFile.open("config", std::ios::in);
    configFile >> m_gameProperties.window_w >> m_gameProperties.window_h;
    configFile >> m_gameProperties.spiriteSize >> m_gameProperties.scale;
    configFile >> m_gameProperties.projectileSize >> m_gameProperties.projectileScale;
    configFile.close();
}
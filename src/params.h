#pragma oncea
#include "resources.h"
#include <fstream>
class Parameters{
private:
    GameProperties m_gameProperties;
    void load();
public:
    GameProperties getProperties(){load(); return m_gameProperties;};
};
#include "game_object.h"
int GameObject::m_nextID=0;
GameObject::GameObject():m_ID{m_nextID++}{}
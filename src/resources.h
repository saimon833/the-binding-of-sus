#pragma once
struct KeyState {
    bool moveUp = 0, moveDown = 0, moveLeft = 0, moveRight = 0;
};
struct CommonResources {
    KeyState keyState;
};

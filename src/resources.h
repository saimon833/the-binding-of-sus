#pragma once
struct KeyState {
    bool moveUp = 0, moveDown = 0, moveLeft = 0, moveRight = 0;
};
struct WindowProperties {
    int h;
    int w;
};
struct CommonResources {
    KeyState keyState;
    WindowProperties windowProperties;
};

#pragma once
struct KeyState {
    bool moveUp = 0, moveDown = 0, moveLeft = 0, moveRight = 0;
    bool shootUp = 0, shootDown = 0, shootLeft = 0, shootRight = 0;
};
struct GameProperties {
    int window_h;
    int window_w;
    int spiriteSize, scale;
    int projectileSize, projectileScale;
};
struct CommonResources {
    KeyState keyState;
    GameProperties gameProperties;
};

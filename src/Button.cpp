#include "Button.h"

// Constructor: loads a texture from the given image path and sets the button's position
Button::Button(const char* image_path, Vector2 image_position) {
    texture = LoadTexture(image_path);
    this->position = image_position;
}

// Draw method: renders the button texture at its position (does not modify button state)
void Button::draw() {
    DrawTextureV(texture, position, WHITE);
}

// Checks if the button is being pressed based on the mouse position and input state
bool Button::is_pressed(Vector2 mouse_position, bool mouse_pressed) {
    // Define the clickable area based on the button's position and texture size
    Rectangle rect = {
        position.x,
        position.y,
        static_cast<float>(texture.width),
        static_cast<float>(texture.height)
    };

    // Return true if the mouse is over the button and the mouse is pressed
    return CheckCollisionPointRec(mouse_position, rect) && mouse_pressed;
}

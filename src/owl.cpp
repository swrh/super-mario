#include "owl.h"

Owl::Owl(const Point &pos)
    : Enemy("res/images/owl.png", pos)
{
    scaledWidth = bitmap.getWidth() / 2 * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box.resize(Point(scaledWidth, scaledHeight));
    objectType = GameObject::Enemy;

    for (int i = 0; i < 2; i++)
        walk[i] = new Rectangle(bitmap.getWidth() / 2 * i, 0, bitmap.getWidth() / 2, bitmap.getHeight());

    currentFrameNumber = 1;
    dir = Left;
    currentFrame = walk[1];
    moveSpeed = 1;
    gravity = 0.5;
    isCollidable = true;
}

void Owl::update(ALLEGRO_EVENT event) {
    if (dir == Left) {
        if (!isObstacleOnLeft)
            velocity.x = -moveSpeed;
    } else {
        if (!isObstacleOnRight)
            velocity.x = moveSpeed;
    }
    currentFrameNumber += frameChangeSpeed;
    if (currentFrameNumber >= 4)
        currentFrameNumber = 0;
    currentFrame = walk[(int)currentFrameNumber / 2];
}

void Owl::draw() {
    al_draw_scaled_bitmap(bitmap.getImage(), currentFrame->left(), currentFrame->top(), currentFrame->width(), currentFrame->height(), box.left(), box.top(), scaledWidth, scaledHeight, 0);
}

void Owl::moveLeft() {
    box.move(Point(box.left() - 5, box.top()));
}

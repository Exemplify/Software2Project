#include "Player.h"

Player::Player(Vector2D<double>& startPosition)
{
    _position = startPosition;
}

void Player::moveLeft()
{
    vector<double> tempvec = _position.rtpVector();
    auto radius  = tempvec.at(0);
    auto theta = -tempvec.at(1)*_speed;
    auto phi = tempvec.at(2);
    Vector2D<double> temp(radius,theta,phi,VectorType::rtp);
    _position = temp;
}
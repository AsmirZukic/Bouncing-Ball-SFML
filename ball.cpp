#include "ball.hpp"
#include <cstdlib>

Ball::Ball()
{
  //Set the size of the object
  m_size.x = 20;
  m_size.y = 20;

  //Give a random number to each element of the velocity as well as the acceleration
  m_velocity.x = rand() % 30 + 1;
  m_velocity.y = rand() % 30 + 1;
  m_acceleration = rand() % 5 + 1;

  //Starting positon of the ball
  m_position.x = 400;
  m_position.y = 300;

  //Set the size of the ball
  m_Ball.setSize( m_size);
  //Set the origin to the middle of the ball
  m_Ball.setOrigin( m_size.x / 2 , m_size.y / 2);
  //Move the ball to the starting position
  m_Ball.setPosition( m_position.x, m_position.y );

}

//Needed method for sfml syntax
void Ball::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
    target.draw( m_Ball, states );
}

void Ball::move()
{
    //Move the ball on the screen
    m_Ball.setPosition(m_Ball.getPosition().x + m_velocity.x , m_Ball.getPosition().y + m_velocity.y);

    //Add gravity
    m_velocity.y += m_acceleration;

    //Handle colision
    if( m_Ball.getPosition().y >= 560 || m_Ball.getPosition().y <= 20 )
    {
      m_velocity.y *= -0.9;
      m_velocity.x *= 0.95;
    }
    if( m_Ball.getPosition().x >= 760 || m_Ball.getPosition().x <= 20 )
    {
      m_velocity.x *= -0.95;
      m_velocity.y *= 0.95;
    }
}

//Method used to set the positon retroactively
void Ball::setPosition( sf::Vector2f position )
{
  m_Ball.setPosition( position.x, position.y );
}

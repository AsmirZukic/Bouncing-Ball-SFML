#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>


class Ball : public sf::Drawable
{
private:
        //Gravity to pull down the abll
        double m_acceleration;
        //The size fo the object
        sf::Vector2f m_size;
        //The current speed of the object
        sf::Vector2f m_velocity;
        //Position on the screen
        sf::Vector2f m_position;
        //The shape of the object
        sf::RectangleShape m_Ball;

        //Virtual function need to use the normal syntax of SFML ( window.draw(object) )
        virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const;

public:
        //Default consturctior for the object
        Ball();
        //Method to make it move
        void move();
        //Set the positon of the object
        void setPosition( sf::Vector2f position );

};

#endif

#include <SFML/Graphics.hpp>
#include "ball.hpp"


int main()
{
  //Define the dimensions of the window
  sf::VideoMode resolution(800,600);

  //Create a widnwo to render our scene on
  sf::RenderWindow window(resolution, "Bouncing ball");

  //Limit the refresh rate the the monitors refreshreat
  window.setVerticalSyncEnabled(true);

  //Instatiate an object of class Ball
  Ball ball;

  //Main loop
  //While the window is open
  while(window.isOpen())
  {
    //Create an event to handle
    sf::Event event;

    //While the window is open poll the events from it
    while(window.pollEvent(event))
    {
      //If the event type is close window (Click on x)  close the window and end the program
      if(event.type == sf::Event::Closed )
      {
        window.close();
      }
    }
    //Move the ball around the screen
    ball.move();

    //Clear the window with the color black
    window.clear( sf::Color::Black);

    //Draw the ball after clearing
    window.draw(ball);

    //Display all the changes on the window
    window.display();
  }


  return 0;
}

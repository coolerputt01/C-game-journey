#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include <cmath>

int main() {
    // In SFML 3, VideoMode takes a Vector2u
    std::vector<sf::CircleShape> triangles;
    std::vector<sf::CircleShape> smallTriangles;

sf::RenderWindow window(sf::VideoMode({1280, 900}), "SFML in Termux VNC");
   float factor = 60.f;
   float scale_factor = 1.05f;   
   float height = 0.f;
   for(int i = 0; i <= 3;i++){
    sf::CircleShape triangle(80.f,3);
    triangle.setOrigin(sf::Vector2f(triangle.getLocalBounds().size.x / 2.f, triangle.getLocalBounds().size.y / 2.f));
    triangle.setScale({0.9f,0.8f});
    triangle.setFillColor(sf::Color(56, 160, 75));
    triangle.scale({scale_factor , scale_factor});
    triangle.setPosition({380.f,height + 60.f});
    height += factor;
    triangles.insert(triangles.begin(),triangle);
    scale_factor += 0.2;
    if(i == 1){
      float move_factor = 27.3;
      for(float i = 0.f; i <= ceil(triangles.front().getLocalBounds().size.x/30.f) - 1.f;i++){
      sf::CircleShape smallTriangle(80.f,3);
      smallTriangle.setOrigin(sf::Vector2f(smallTriangle.getLocalBounds().size.x - 20.f / 2.f,smallTriangle.getLocalBounds().size.y / 2.f));
      smallTriangle.setScale({0.2f,0.2f});
      smallTriangle.setFillColor(sf::Color(206, 209, 202));
      smallTriangle.scale({1.f,1.f});
      smallTriangle.setPosition({316.f + move_factor , 98.f});
      smallTriangles.insert(smallTriangles.begin(),smallTriangle);
      move_factor += 27.3;
    }
    }
    if(i == 3){
      triangles.front().setFillColor(sf::Color(30, 101, 43));
    }
}
   sf::CircleShape lastTriangle = triangles.front();
   lastTriangle.setFillColor(sf::Color(30, 101, 43));
   sf::RectangleShape rect({80.f,90.f});
   rect.setOrigin(sf::Vector2f(rect.getSize().x / 2.f , rect.getSize().y));
   rect.setScale({1.2,2.f});
   rect.setFillColor(sf::Color(180, 101, 60));
   rect.scale({0.5,0.5});
   sf::FloatRect bounds = lastTriangle.getGlobalBounds();
   rect.setPosition({bounds.position.x + bounds.size.x / 2, bounds.position.y + bounds.size.y + 90.f});
   while (window.isOpen()){
        // pollEvent now returns std::optional<sf::Event>
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

       window.clear(sf::Color(255,255,255));
       for(auto &t : triangles){ 
         window.draw(t);
       }
      for(auto &st : smallTriangles){
         window.draw(st); 
      }
       window.draw(rect);
       window.display();
   }
    return 0;
}

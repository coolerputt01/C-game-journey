#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
int main() {
    // In SFML 3, VideoMode takes a Vector2u
    std::vector<sf::CircleShape> triangles;

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
    triangles.push_back(triangle);
    scale_factor += 0.15;
}
   sf::CircleShape lastTriangle = triangles.back();
   sf::RectangleShape rect({80.f,90.f});
   rect.setOrigin(sf::Vector2f(rect.getSize().x / 2.f , rect.getSize().y));
   rect.setFillColor(sf::Color(180, 101, 60));
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
        window.draw(rect);
        window.display();
    }
    return 0;
}

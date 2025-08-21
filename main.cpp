#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
int main() {
    // In SFML 3, VideoMode takes a Vector2u
    std::vector<sf::CircleShape> triangles;

sf::RenderWindow window(sf::VideoMode({1280, 900}), "SFML in Termux VNC");
   float factor = 40.f;   
   float height = 0.f;
   for(int i = 0; i <= 3;i++){
sf::CircleShape triangle(80.f,3);
    triangle.setFillColor(sf::Color(56, 160, 75));
    triangle.setPosition({40.f,height});
    height += factor;
    triangles.push_back(triangle);
}
    while (window.isOpen()) {
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
        window.display();
    }
    return 0;
}

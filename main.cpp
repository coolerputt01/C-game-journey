#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    // In SFML 3, VideoMode takes a Vector2u
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML in Termux VNC");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        // pollEvent now returns std::optional<sf::Event>
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}

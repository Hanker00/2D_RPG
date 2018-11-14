
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Variables
    float playerMovementSpeed = 2;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Load a sprite to display
    sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile(resourcePath() + Adventurer.png)) {
        return EXIT_FAILURE;
    }
    sf::Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition(window.getSize().x/2, window.getSize().y/2);
    spritePlayer.setTexturerect(sf..IntRect(0, 0, 50, 37));

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            spritePlayer.move(0, -playerMovementSpeed);
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            spritePlayer.move(0,playerMovementSpeed);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            spritePlayer.move(-playerMovementSpeed,0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            spritePlayer.move(playerMovementSpeed,0);
        }


        // Draw the sprite
        window.draw(sprite);

        // Draw the string
        window.draw(text);

        //draw Player
        window.draw(spritePlayer);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}

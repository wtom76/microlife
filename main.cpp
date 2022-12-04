#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>
#include <array>

void draw_circle()
{
    sf::RenderWindow window{sf::VideoMode{200, 200}, "SFML works!"};
    sf::CircleShape shape{100.f};
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
                window.close();
			}
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

// g++ -std=c++11 main.cpp $(pkg-config --libs --cflags sfml-graphics sfml-window)
void draw_pixels()
{
    constexpr unsigned int width{1024};
    constexpr unsigned int height{768};

    // create the window
    sf::RenderWindow window{sf::VideoMode{width, height}, "Some Funky Title"};

    // create a texture
    sf::Texture texture;
    texture.create(width, height);

    // Create a pixel buffer to fill with RGBA data
    std::array<unsigned char, width * height * 4> pixbuff;
    // Create uint32_t pointer to above for easy access as RGBA
    uint32_t* const intptr{reinterpret_cast<uint32_t*>(pixbuff.data())};

    // The colour we will fill the window with
    unsigned char red{0};
    unsigned char blue{255};

    // run the program as long as the window is open
    int frame{0};
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
			{
                window.close();
			}
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // Create RGBA value to fill screen with.
        // Increment red and decrement blue on each cycle. Leave green=0, and make opaque
        const uint32_t RGBA{(++red << 24) | (--blue << 8) | 255u};
        // Stuff data into buffer
        for (int i{0}; i < width * height; ++i)
		{
           intptr[i] = RGBA;
        }
        // Update screen
        texture.update(pixbuff.data());

        sf::Sprite sprite{texture};
        window.draw(sprite);

        // end the current frame
        window.display();
        std::cout << "Frame: " << frame << std::endl;
        if (++frame == 1000)
		{
			break;
		}
    }
}

int main()
{
	draw_pixels();
    return 0;
}
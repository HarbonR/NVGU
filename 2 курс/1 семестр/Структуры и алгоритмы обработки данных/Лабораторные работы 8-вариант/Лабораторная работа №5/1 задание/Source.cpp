#include <SFML/Graphics.hpp>
#include <iostream>

int heshFunction(int letterCode)
{
    return letterCode * 50 + letterCode - 51;
}

int main()
{
    system("chcp 1251");
    system("cls");
    srand(time(0));
    /*for (int i = 192; i < 224; i++)
    {
        std::cout << i << ' ' << unsigned char(i) << '\n';
    }*/
    int numberOfAddresses[800];
    for (int i = 0; i < 800; i++)
    {
        numberOfAddresses[i] = 0;
    }
    for (int i = 0; i < 1000; i++)
    {
        int letterCode = rand() % 33 + 192;
        int tmp = heshFunction(letterCode) % 800;
        if (tmp >= 0 && tmp < 800)
            numberOfAddresses[tmp]++;
    }
    sf::RenderWindow window(sf::VideoMode(800, 600), "Exercise 1");
    sf::CircleShape shape(0.5f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < 800; i++)
        {
            shape.setPosition(sf::Vector2f(i, 500 - numberOfAddresses[i]));
            window.draw(shape);
        }
        window.display();
    }
    return 0;
}
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <bits/stdc++.h>

using namespace std;

#define Width 600
#define Hight 600
#define Dot_size 10

void updateDots(array<array<pair<sf::RectangleShape, bool>, Hight / Dot_size>, Width / Dot_size> &Dots);

int main()
{

    // render window
    sf::RenderWindow window({Width, Hight}, "Sand_Simulator");
    array<array<pair<sf::RectangleShape, bool>, 60>, 60> Dots;
    for (int i = 0; i < Dots.size(); i++)
    {
        for (int j = 0; j < Dots[0].size(); j++)
        {
            Dots[i][j].first.setPosition({i * Dot_size, j * Dot_size});
            Dots[i][j].second = false;
            Dots[i][j].first.setSize({Dot_size - 1, Dot_size - 1});
            Dots[i][j].first.setOutlineColor(sf::Color::Red);
            Dots[i][j].first.setOutlineThickness(1);
            Dots[i][j].first.setFillColor(sf::Color::White);
        }
    }

    window.setFramerateLimit(60);
    int temp = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                mousePos = {(mousePos.x / Dot_size) * Dot_size, (mousePos.y / Dot_size) * Dot_size};
                for (int i = 0; i < Dots.size(); i++)
                {
                    for (int j = 0; j < Dots[0].size(); j++)
                    {
                        if (Dots[i][j].first.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                        {
                            Dots[i][j].second = true;
                        }
                    }
                }
            }
            // clears the window
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
            {
                for (int i = 0; i < Dots.size(); i++)
                {
                    for (int j = 0; j < Dots[0].size(); j++)
                    {
                        Dots[i][j].second = false;
                    }
                }
            }
        }

        window.clear();
        // update dots
        updateDots(Dots);
        
        // render dots
        for (auto &&i : Dots)
        {
            for (auto &&D : i)
            {
                if (D.second)
                {
                    window.draw(D.first);
                    temp++;
                }
            }
        }

        window.display();
    }
    cout << temp;
    return 0;
}
void updateDots(array<array<pair<sf::RectangleShape, bool>, 60>, 60> &Dots)
{
    for (int i = 0; i < Dots.size(); i++)
    {
        for (int j = 0; j < Dots[0].size(); j++)
        {
            if (Dots[i][j].second && !Dots[i][j + 1].second && Dots[i][j].first.getPosition().y + Dot_size < Hight)
            {
                Dots[i][j].second = false;
                Dots[i][j + 1].second = true;
            }

        }
    }

    for (int i = 0; i < Dots.size(); i++) //check for if a sand can fall in side coloms
    {
        for (int j = 0; j < Dots[0].size(); j++)
        {
            if (Dots[i][j].second && !Dots[i + 1][j + 1].second && i + 1 < Dots.size() && j + 1 < Dots[0].size())
            {
                Dots[i][j].second = false;
                Dots[i + 1][j + 1].second = true;
            }
            if (Dots[i][j].second && !Dots[i -1][j + 1].second && i -1 < Dots.size() && j + 1 < Dots[0].size())
            {
                Dots[i][j].second = false;
                Dots[i -1][j + 1].second = true;
            }
        }
    }
}

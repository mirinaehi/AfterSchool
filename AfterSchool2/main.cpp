#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace sf;

const int S = 4;
const int CARD_W = 200;
const int CARD_H = 200;

struct Card {
	RectangleShape sprite;
	int id;
	int type;
};

int main(void)
{
	RenderWindow window(VideoMode(1200, 800), "AfterSchool2");
	window.setFramerateLimit(60);

	Vector2i mouse_pos;
	int click_cnt = 0;		// 마우스 누른 횟수

	Texture t[8 + 1];
	t[0].loadFromFile("./resources/images/ch0.png");
	t[1].loadFromFile("./resources/images/ch1.png");
	t[2].loadFromFile("./resources/images/ch2.png");
	t[3].loadFromFile("./resources/images/ch3.png");
	t[4].loadFromFile("./resources/images/ch4.png");
	t[5].loadFromFile("./resources/images/ch5.png");
	t[6].loadFromFile("./resources/images/ch6.png");
	t[7].loadFromFile("./resources/images/ch7.png");
	t[8].loadFromFile("./resources/images/ch8.png");

	Font font;
	font.loadFromFile("c:/Windows/Fonts/arial.ttf");
	
	Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);
	text.setPosition(0, 0);
	char info[40];
	
	struct Card cards[S][S];
	int n = 0;
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < S; j++)
		{
			cards[i][j].sprite.setSize(Vector2f(CARD_W, CARD_H));
			cards[i][j].sprite.setPosition(j * CARD_W, i * CARD_H);
			cards[i][j].sprite.setTexture(&t[1+n/2]);
			cards[i][j].type = 1 + n / 2;
			cards[i][j].id = n+1;
			n++;
		}
	}

	while (window.isOpen())
	{
		mouse_pos = Mouse::getPosition(window);

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
				// 한 번 누르면 한 번만 적용
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left)
				{
					click_cnt++;
				}
			}
		}

		sprintf(info, "(%d, %d) clicks %d\n"
			, mouse_pos.x, mouse_pos.y, click_cnt);
		text.setString(info);


		window.clear(Color::Black);
		for (int i = 0; i < S; i++)
		{
			for (int j = 0; j < S; j++)
			{
				window.draw(cards[i][j].sprite);
			}
		}

		window.draw(text);

		window.display();
	}

	
	return 0;
}
#include <SFML/Graphics.hpp>

int main()
{
	// ??????, ???????, ??????????, ???????? ??????? ????? ??????????
	RenderWindow window(VideoMode(200, 200), "SFML Works!");

	// ??????? ???? ??????????. ???????????, ???? ??????? ????
	while (window.isOpen())
	{
		// ???????????? ??????? ??????? ? ?????
		Event event;
		while (window.pollEvent(event))
		{
			// ???????????? ????? ?? ????????? ? ????? ??????? ?????
			if (event.type == Event::Closed)
				// ????? ????????? ???
				window.close();
		}
		// ????????? ????	
		window.display();
	}

	return 0;
}
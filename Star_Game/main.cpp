#include <SFML/Graphics.hpp>

int main()
{
<<<<<<< Updated upstream
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(200, 200), "SFML Works!");
=======
										// --
	Game game;
>>>>>>> Stashed changes

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		// ��������� ����	
		window.display();
	}

	return 0;
}
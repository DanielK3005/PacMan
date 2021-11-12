#include "ThePacManGame.h"

int main()
{	
	char choice;
	ThePacManGame game;
	do
	{
		choice = game.printMenu();
		if (choice == '8') {
			game.printManualInstrctions(); continue;
		}
		game.init();
		game.run(choice);
	} while (choice != EXIT);
}
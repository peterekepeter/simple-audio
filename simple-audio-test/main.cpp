
#include <iostream>
#include "../simple-audio/Music.h"

void user_check(const char* message)
{
	std::cout << message;
	while (true) {
		// user confirmation needed
		char c;
		std::cout << " Y/N? ";
		std::cin >> c;
		if (c == 'y' || c == 'Y') {
			std::cout << "\n";
			return;
		}
		if (c == 'n' || c == 'N') {
			std::cout << "\n";
			throw "Test case failed!";
		}
	}
}

void tests() {
	Music::Init("sine-song.it", false);
	Music::Play();
	user_check("Can you hear sinesong.it?");
	Music::Stop();
}

int main() {
	try {
		tests();
		return 0;
	}
	catch (const char* message) {
		std::cout << message << "\n";
		return 1;
	}
}
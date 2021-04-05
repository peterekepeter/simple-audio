
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

void manual_test() {
	Music::Init("sine-song.it", false);
	Music::Play();
	user_check("Can you hear sinesong.it?");
	Music::Stop();
}


void auto_test() {
	// check if library can be called
	Music::Init("");
}


int main(int argc, const char** argv) {
	try {
		if (argc == 2 && strcmp(argv[1], "auto") == 0) {
			auto_test();
		}
		else {
			manual_test();
		}
		return 0;
	}
	catch (const char* message) {
		std::cout << message << "\n";
		return 1;
	}
}
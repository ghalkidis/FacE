#include <SFML/Audio.hpp>
#include <iostream>
#include <string>


void playSound()
{
    // Load a sound buffer from any sound file
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sample.wav")) //in current directory
        return;


    // Create a sound instance and play it
    sf::Sound sound(buffer);
    sound.play();

    // Loop while the sound is playing
    while (sound.getStatus() == sf::Sound::Playing)
    {
        // how quickly the playing time is updated
        sf::sleep(sf::milliseconds(100));

        // Display playing time <--- not necessary but works better
	//with this for some reason
        std::cout << "\rPlaying... " << sound.getPlayingOffset().asSeconds() << " sec        ";
        std::cout << std::flush;
    }
    std::cout << std::endl << std::endl; 
}



int main()
{
    // Play sound
    playSound();

    return EXIT_SUCCESS;
}

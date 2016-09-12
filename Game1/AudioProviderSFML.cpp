#include "stdafx.h"
#include "AudioProviderSFML.h"
#include "SoundFileCache.h"

AudioProviderSFML::AudioProviderSFML() :
	_currentSongName("")
{
}

void AudioProviderSFML::PlaySound(std::string filename)
{
	int availableChannel = -1;
	for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
	{
		if (_currentSounds[i].getStatus() != sf::Sound::Playing)
		{
			availableChannel = i;
			break;
		}
	}

	// If all sound channels are in use, do nothing for now
	if (availableChannel != -1)
	{
		try
		{
			_currentSounds[availableChannel] = _soundFileCache.GetSound(filename);
			_currentSounds[availableChannel].play();
		}
		catch (SoundNotFoundExeception& snfe)
		{
			// ERROR, file wasnt found, should handle error here
			// snfe.what will contain the exception details
		}
	}


}

void AudioProviderSFML::PlaySong(std::string filename, bool looping)
{
	sf::Music * currentSong;
	try
	{
		currentSong = _soundFileCache.GetSong(filename);
	}
	catch (SoundNotFoundExeception&)
	{
		// This one is dire, means we couldn't find or load the selected song
		// So, lets exit!
		return;
	}
	// See if prior song is playing still, if so, stop it
	if (_currentSongName != "")
	{
		try
		{
			sf::Music* priorSong = _soundFileCache.GetSong(_currentSongName);
			if (priorSong->getStatus() != sf::Sound::Stopped)
			{
				priorSong->stop();
			}
		}
		catch (SoundNotFoundExeception&)
		{
			// Do nothing, this exception isn't dire.  It simply means the previous sound we were
			// trying to stop wasn't located.
		}

	}
	_currentSongName = filename;
	currentSong->setLoop(looping);
	currentSong->play();
}

void AudioProviderSFML::StopAllSounds()
{
	for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
	{
		_currentSounds[i].stop();
	}

	if (_currentSongName != "")
	{
		sf::Music * currentSong = _soundFileCache.GetSong(_currentSongName);
		if (currentSong->getStatus() == sf::Sound::Playing)
		{
			currentSong->stop();
		}
	}
}

bool AudioProviderSFML::IsSoundPlaying()
{
	for (int i = 0; i < MAX_SOUND_CHANNELS; i++)
	{
		if (_currentSounds[i].getStatus() == sf::Sound::Playing)
			return true;
	}
	return false;
}


bool AudioProviderSFML::IsSongPlaying()
{
	if (_currentSongName != "")
	{
		return _soundFileCache.GetSong(_currentSongName)->getStatus() == sf::Music::Playing;
	}
	return false;
}


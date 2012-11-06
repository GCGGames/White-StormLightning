/*
This file is part of White - Storm: Lightning (alpha).

	Copyright 2012 Christopher Augustus Greeley

    White - Storm: Lightning (alpha) is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    White - Storm: Lightning (alpha) is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with White - Storm: Lightning (alpha).  If not, see <http://www.gnu.org/licenses/>.
*/
#include "Sound Manager.h"
void WSL::Global::SoundManager::CleanUp()
{
	unsigned int size = sounds.size();
	activeSounds.clear();
	if( size != 0 )
	{
		for( unsigned int i = 0; i < size; ++i )
		{
			{
				WSL::Containers::SoundContainer *temp = sounds[i];
				sounds.erase( sounds.begin() + i );
				delete temp;
			}
		}
	}
}
unsigned int WSL::Global::SoundManager::LoadSound( std::string name, std::string file )
{
	if( name == "" || name == " " )
		name = "Sound";
	bool load = true;
	int timesFound = 0;
	unsigned int size = sounds.size();
	if( size != 0 )
	{
		for( unsigned int i = 0; i < size; ++i )
		{
			if( sounds[i]->GetFile() == file && name == sounds[i]->GetName() )
			{
				load = false;
				return size - 1;
			}
			if( name == sounds[i]->GetName() )
			{
				timesFound++;
				name += timesFound;
				std::cerr<<"The sound's name is the same as anothers\n the sound will be called\n"<<name<<std::endl;
			}
		}
	}
	if( load == true )
		sounds.push_back( new WSL::Containers::SoundContainer( name, file ) );
	return size;
}
unsigned int WSL::Global::SoundManager::PlaySound( unsigned int sound, bool loop )
{
	if( WSL::Algorithmic::Range_Check_bool( sound, sounds.size() ) == true )
	{
		activeSounds.push_back( sf::Sound() );
		unsigned int s = activeSounds.size() - 1;
		activeSounds[s].SetBuffer( *sounds[sound]->GetSound() );
		activeSounds[s].SetLoop( loop );
		activeSounds[s].Play();
		return (s);
	}
	std::cerr<<"No sound found with the element "<<sound<<", 0 returned for method PlaySound( unsigned int, bool ).\n";
	return 0;
}
unsigned int WSL::Global::SoundManager::PlaySound( std::string name, bool loop )
{
	unsigned int size = sounds.size();
	if( size != 0 )
	{
		for( unsigned int i = 0; i < size; ++i )
		{
			if( sounds[i]->GetName() == name )
			{
				sf::Sound sound;
				sound.SetBuffer( *sounds[i]->GetSound() );
				activeSounds.push_back( sound );
				i = activeSounds.size() - 1;
				activeSounds[i].SetLoop( loop );
				activeSounds[i].Play();
				return (i);
			}
		}
	}
	std::cerr<<"No sound found with the name "<<name<<", 0 returned for method PlaySound( std::string, bool ).\n";
	return 0;
}
unsigned int WSL::Global::SoundManager::PlaySoundFromFile( std::string name, std::string file, bool loop )
{
	LoadSound( name, file );
	sf::Sound sound;
	sound.SetBuffer( *sounds[sounds.size() - 1]->GetSound() );
	sound.SetLoop( loop );
	activeSounds.push_back( sound );
	unsigned int s = activeSounds.size() - 1;
	activeSounds[s].Play();
	return (s);
}
bool WSL::Global::SoundManager::SoundIsStopped( unsigned int sound )
{
	sf::Sound *ptr = FindSound( sound );
	if( ptr != NULL )
	{
		if( ptr->GetStatus() == sf::Sound::Stopped )
			return (true);
		return (false);
	}
	std::cerr<<"No sound found with element "<<sound<<", 'false' returned for method SoundIsStopped( unsigned int ).\n";
	return (false);
}
bool WSL::Global::SoundManager::SoundIsPaused( unsigned int sound )
{
	sf::Sound *ptr = FindSound( sound );
	if( ptr != NULL )
	{
		if( ptr->GetStatus() == sf::Sound::Paused )
			return (true);
		return (false);
	}
	std::cerr<<"No sound found with element "<<sound<<", 'false' returned for method SoundIsPaused( unsigned int ).\n";
	return (false);
}
bool WSL::Global::SoundManager::SoundIsPlaying( unsigned int sound )
{
	sf::Sound *ptr = FindSound( sound );
	if( ptr != NULL )
	{
		if( ptr->GetStatus() == sf::Sound::Playing )
			return (true);
		return (false);
	}
	std::cerr<<"No sound found with element "<<sound<<", 'false' returned for method SoundIsPlaying( unsigned int ).\n";
	return (false);
}
void WSL::Global::SoundManager::PauseSound( unsigned int sound )
{
	sf::Sound *ptr = FindSound( sound );
	if( ptr != NULL )
		ptr->Pause();
	else
		std::cerr<<"No sound found with element "<<sound<<", 'false' returned for method PauseSound( unsigned int ).\n";
}
void WSL::Global::SoundManager::UnPauseSound( unsigned int sound )
{
	sf::Sound *ptr = FindSound( sound );
	if( ptr != NULL )
		ptr->Play();
	else
		std::cerr<<"No sound found with element "<<sound<<", 'false' returned for method UnPauseSound( unsigned int ).\n";
}
void WSL::Global::SoundManager::StopSound( unsigned int sound )
{
	sf::Sound *ptr = FindSound( sound );
	if( ptr != NULL )
		ptr->Stop();
	else
		std::cerr<<"No sound found with element "<<sound<<", 'false' returned for method StopSound( unsigned int ).\n";
}
void WSL::Global::SoundManager::Update()
{
	unsigned int size = activeSounds.size();
	if( size != 0 )
	{
		for( unsigned int i = 0; i < size; ++i )
		{
			if( activeSounds[i].GetStatus() == sf::Sound::Stopped )
			{
				activeSounds.erase( activeSounds.begin() + i );
				--size;
				--i;
			}
		}
	}
}
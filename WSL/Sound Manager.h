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
#include "Sound Container.h"
namespace WSL
{
	namespace Global
	{
		//No music quite yet.//
		struct SoundManager
		{
			void CleanUp();
			unsigned int LoadSound( std::string name, std::string file );
			unsigned int PlaySound( unsigned int sound, bool loop );
			unsigned int PlaySound( std::string name, bool loop );
			unsigned int PlaySoundFromFile( std::string name, std::string file, bool loop );
			bool SoundIsStopped( unsigned int sound );
			bool SoundIsPaused( unsigned int sound );
			bool SoundIsPlaying( unsigned int sound );
			void PauseSound( unsigned int sound );
			void UnPauseSound( unsigned int sound );
			void StopSound( unsigned int sound );
			void Update();
		protected:
			std::vector< WSL::Containers::SoundContainer* > sounds;
			std::vector< sf::Sound > activeSounds;
			sf::Sound* FindSound( unsigned int sound )
			{
				if( WSL::Algorithmic::BoolRangeCheck( sound, activeSounds.size() ) == true )
				{
					//Unessery but safer.//
					sf::Sound* ptr = &activeSounds[ sound ];
					return ptr;
				}
				return NULL;
			}
		};
	}
}
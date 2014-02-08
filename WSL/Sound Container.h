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
#include "Input.h"
namespace WSL
{
	namespace Containers
	{
		struct SoundContainer
		{
			inline SoundContainer( std::string name_, std::string file_ ) {
				LoadSound( name_, file_ );
			}
			inline SoundContainer() {
			}
			inline void LoadSound( std::string file_ ) {
				sound.LoadFromFile( file_ );
				file = file;
			}
			inline void LoadSound( std::string name_, std::string file_ )
			{
				name = name_;
				file = file_;
				sound.LoadFromFile( file );
			}
			inline void SetSound( sf::SoundBuffer sound_ ) {
				sound = sound_;
			}
			inline void SetSound( sf::SoundBuffer *sound_ ) {
				sound = *sound_;
			}
			inline void SetFile( std::string file_ ) {
				file = file_;
			}
			inline void SetName( std::string name_ ) {
				name = name_;
			}
			inline sf::SoundBuffer* GetSound() {
				return &sound;
			}
			inline std::string GetName() {
				return name;
			}
			inline std::string GetFile() {
				return file;
			}
		protected:
			sf::SoundBuffer sound;
			std::string name, file;
		};
	}
}
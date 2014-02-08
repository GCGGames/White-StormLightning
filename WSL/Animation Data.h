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
#include "Receiver Node.h"
enum AnimationType
{
	Sheet = false,
	Image = true,
};
namespace WSL
{
	namespace Components
	{
		namespace Algorithimic
		{
			namespace Base
			{
				class AnimationData
				{
				protected:
					std::vector< unsigned int > targates;
					int delay, count, inc;
					bool animate, init, type;
					unsigned int currentFrame, size, frame;
					std::vector< sf::IntRect > frames;
					void Reset__()
					{
						frame = 0;
						type = true;
						init = false;
						currentFrame = 0;
						animate = false;
						delay = 1;
						count = 0;
						inc = 0;
						size = 0;
					}
				public:
					/*
						Respective Encapsulated Methods.
					*/
					//"Getter's".//
					bool GetAnimate();
					unsigned int GetSize();
					int GetDelay();
					bool GetType();
					//"Setter's".//
					void SetType( AnimationType sheetOrImageByImage );
					void SetType( bool type_ );
					void SetCurrentFrame( unsigned int currentFrame_ );
					void SetAnimate( bool animate_ );
					void SetDelay( int delay_ );
				};
			}
		}
	}
}
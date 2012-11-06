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
#include "Non Class Container.h"
namespace WSL
{
	namespace Containers
	{
		namespace Scripting
		{
			namespace Lua
			{
				struct ColorWrap
				{
					inline ColorWrap( unsigned short r, unsigned short g, unsigned short b )
					{
						color = sf::Color( (sf::Uint8)r, (sf::Uint8)g, (sf::Uint8)b );
					}
					inline ColorWrap( sf::Color value )
					{
						color = value;
					}
					inline ColorWrap()
					{
					}
					inline sf::Color GetColor()
					{
						return color;
					}
					inline void SetColor( sf::Color color_ )
					{
						color = color_;
					}
				protected:
					sf::Color color;
				};
			}
		}
	}
}
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
#include "Lightning Sprite.h"
namespace WSL
{
	namespace Math
	{
		namespace Movement
		{
			static WSL::Containers::Base::XYZ VectorMovement( float xOffset, float yOffset, WSL::Containers::Base::XYZ position )
			{
				position.SetX( position.GetX() + floor( 0.5f + xOffset ) );
				position.SetY( position.GetY() + floor( 0.5f + yOffset ) );
				return position;
			}
			static WSL::Containers::Base::XYZ VectorMovement( float xOffset, float yOffset, float zOffset, WSL::Containers::Base::XYZ position )
			{
				position.SetX( position.GetX() + floor( 0.5f + xOffset ) );
				position.SetY( position.GetY() + floor( 0.5f + yOffset ) );
				position.SetZ( position.GetZ() + floor( 0.5f + zOffset ) );
				return position;
			}
			static WSL::Containers::Base::XYZ VectorMovement( WSL::Containers::Base::XYZ offset, WSL::Containers::Base::XYZ position )
			{
				position.SetX( position.GetX() + floor( 0.5f + offset.GetX() ) );
				position.SetY( position.GetY() + floor( 0.5f + offset.GetY() ) );
				position.SetZ( position.GetZ() + floor( 0.5f + offset.GetZ() ) );
				return position;
			}
		}
	}
}
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
#include "Include.h"
namespace WSL
{
	namespace Containers
	{
		namespace Base
		{
			struct XYZB
			{
				inline float getX() { return X; }
				inline float getY() { return Y; }
				inline float getZ() { return Z; }
				inline void setX( float Value ) { X = Value; }
				inline void setY( float Value ) { Y = Value; }
				inline void setZ( float Value ) { Z = Value; }
				protected:
					float X, Y, Z;
			};
			struct XYZ : public XYZB
			{
			public:
				XYZ( float x, float y, float z )
				{
					X = x;
					Y = y; 
					Z = z;
				}
				inline XYZ() { X = 0.f; Y = 0.f; Z = 0.f; }
			};
		}
	}
}
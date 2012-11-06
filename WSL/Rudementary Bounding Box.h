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
#include "Updator.h"
namespace WSL
{
	namespace Collision
	{
		namespace Scan_Area_Collision
		{
			struct Rudementary_Bounding_Box
			{
				float Offset;
				float Points[6];
				void Set_Up( WSL::Containers::Base::XYZ Coord, bool Z )
				{
					Points[0] = Coord.getX() + Offset;
					Points[1] = Coord.getX() - Offset;
					Points[2] = Coord.getY() + Offset;
					Points[3] = Coord.getY() - Offset;
					if( Z == true )
					{
						Points[4] = Coord.getZ() + Offset;
						Points[5] = Coord.getZ() - Offset;
					}
					else
					{
						Points[4] = 0;
						Points[5] = 0;
					}
				}
				void Set_Up( float X, float Y )
				{
					Points[0] = X + Offset;
					Points[1] = X - Offset;
					Points[2] = Y + Offset;
					Points[3] = Y - Offset;
					Points[4] = 0;
					Points[5] = 0;
				}
				void Set_Up( float X, float Y, float Z )
				{
					Points[0] = X + Offset;
					Points[1] = X - Offset;
					Points[2] = Y + Offset;
					Points[3] = Y - Offset;
					Points[4] = Z + Offset;
					Points[5] = Z - Offset;
				}
				bool Check( float X, float Y, bool Debug )
				{
					if( X >= Points[1] && X <= Points[0] && Y >= Points[3] && Y <= Points[2] )
						return true;
					if( X == Points[1] - Offset && Y == Points[3] + Offset )
						return true;
					else
						if( Debug == true )
								std::cout<<"if "<<X<<" >= "<<Points[1]<<" && "<<X<<" <= "<<Points[0]<<" && "<<Y<<" >= "<<Points[3]<<" && "<<Y<<" <= "<<Points[2]<<std::endl;
					return false;
				}
				bool Check_X( float X )
				{
					if( X >= Points[1] && X <= Points[0] )
						return true;
					return false;
				}
				bool Check_Y( float Y )
				{
					if( Y >= Points[3] && Y <= Points[2] )
						return true;
					return false;
				}
				bool Check_Z( float Z )
				{
					if( Z >= Points[5] && Z <= Points[4] )
						return true;
					return false;
				}
				bool Check( float X, float Y, float Z )
				{
					if( X >= Points[1] && X <= Points[0] && Y >= Points[3] && Y <= Points[2] && Z >= Points[5] && Z <= Points[4] )
						return true;
					return false;
				}
			};
		}
	}
}
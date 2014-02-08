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
		namespace ScanAreaCollision
		{
			struct RudementaryBoundingBox
			{
				float offset;
				float points[ 6 ];
				void SetUp( WSL::Containers::Base::XYZ coordinate, bool Z )
				{
					points[ 0 ] = coordinate.GetX() + offset;
					points[ 1 ] = coordinate.GetX() - offset;
					points[ 2 ] = coordinate.GetY() + offset;
					points[ 3 ] = coordinate.GetY() - offset;
					if( Z == true ) {
						points[ 4 ] = coordinate.GetZ() + offset;
						points[ 5 ] = coordinate.GetZ() - offset;
					}
					else {
						points[ 4 ] = 0;
						points[ 5 ] = 0;
					}
				}
				void SetUp( float X, float Y )
				{
					points[ 0 ] = X + offset;
					points[ 1 ] = X - offset;
					points[ 2 ] = Y + offset;
					points[ 3 ] = Y - offset;
					points[ 4 ] = 0;
					points[ 5 ] = 0;
				}
				void SetUp( float X, float Y, float Z )
				{
					points[ 0 ] = X + offset;
					points[ 1 ] = X - offset;
					points[ 2 ] = Y + offset;
					points[ 3 ] = Y - offset;
					points[ 4 ] = Z + offset;
					points[ 5 ] = Z - offset;
				}
				bool Check( float X, float Y, bool Debug )
				{
					if( X >= points[ 1 ] && X <= points[ 0 ] && Y >= points[ 3 ] && Y <= points[ 2 ] )
						return true;
					if( X == points[ 1 ] - offset && Y == points[ 3 ] + offset )
						return true;
					else
					{
						if( Debug == true ) {
								std::cout << "if " << X << " >= " << points[ 1 ] << " && " << X << " <= " << 
										points[ 0 ] << " && " << Y << " >= " << points[ 3 ] << " && " << Y << " <= " << points[ 2 ] << std::endl;
						}
					}
					return false;
				}
				bool CheckX( float X )
				{
					if( X >= points[ 1 ] && X <= points[ 0 ] )
						return true;
					return false;
				}
				bool CheckY( float Y )
				{
					if( Y >= points[ 3 ] && Y <= points[ 2 ] )
						return true;
					return false;
				}
				bool CheckZ( float Z )
				{
					if( Z >= points[ 5 ] && Z <= points[ 4 ] )
						return true;
					return false;
				}
				bool Check( float X, float Y, float Z )
				{
					if( X >= points[ 1 ] && X <= points[ 0 ] && Y >= points[ 3 ] && 
								Y <= points[ 2 ] && Z >= points[ 5 ] && Z <= points[ 4 ] )
						return true;
					return false;
				}
			};
		}
	}
}
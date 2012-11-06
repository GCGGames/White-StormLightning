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
#include "Initilizor.h"
namespace WSL
{
	namespace Collision
	{
		namespace Scan_Area_Collision
		{
			class Updator
			{
				WSL::Containers::Base::XYZ data;
				std::vector<WSL::Containers::Base::XYZ> P, M;
			public:
				Collision::Scan_Area_Collision::Scan_Area Update( Collision::Scan_Area_Collision::Scan_Area s, bool Scale )
				{
					unsigned int i = 0;
					unsigned int size = 0;
					s.setPoints( P );
					s.getCollision_Coords().clear();
					M = s.getMagnitudes();
					size = M.size();
					if( size != 0 )
					{
						i = 0;
						while( i < size )
						{
							if( Scale == true )
							{
								if( s.getZ() != s.getLast_Move() )
								{
									float Change = s.getZ() - s.getLast_Move();
									if( M[i].getX() < 0 )
										M[i].setX( M[i].getX() + Change );
									else
										M[i].setX( M[i].getX() - Change );
									if( M[i].getY() < 0 )
										M[i].setY( M[i].getY() + Change );
									else
										M[i].setY( M[i].getY() - Change );
									s.setLast_Move( s.getZ() );
									s.setMagnitudes( M );
								}
							}
							data.setX( s.getX() + M[i].getX() );
							data.setY( s.getY() + M[i].getY() );
							data.setZ( s.getZ() + M[i].getZ() );
							s.Add_Point( data );
							i++;
						}
					}
					M.clear();
					return s;
				}

			};
		}
	}
}
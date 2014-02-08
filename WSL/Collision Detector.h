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
#include "Pointable Vector.h"
namespace WSL
{
	namespace Collision
	{
		namespace ScanAreaCollision
		{
			struct CollisionDetector
			{
				Collision::ScanAreaCollision::RudementaryBoundingBox boundingBox;
				bool x, y, z, collision;
				float X1, Y1, X2, Y2, Z1, Z2;
				WSL::Containers::BoolXYZ bx;
				unsigned int ia, ib, sizea, sizeb;
				std::vector< WSL::Containers::Base::XYZ > A, B;
			public:
				inline CollisionDetector() {
					boundingBox.offset = 4;
				}
				/*		I found that the collision data
					can not be compaired properly
					with a logicle and oporator therefore
					it is nessesary to compare the x, y
					and occasionally z coorinates sepratle
					and store if there was a collision in a boolean
					value.*/
				void Check( WSL::Containers::Base::XYZ b )
				{
					boundingBox.SetUp( b, false );
					x = boundingBox.CheckX( X1 );
					y = boundingBox.CheckY( Y1 );
				}
				void CheckZ( WSL::Containers::Base::XYZ b )
				{
					boundingBox.SetUp( b, true );
					x = boundingBox.CheckX( X1 );
					y = boundingBox.CheckY( Y1 );
					z = boundingBox.CheckZ( Z1 );
				}
				WSL::Containers::BoolXYZ DetectCollision( Collision::ScanAreaCollision::ScanArea a, Collision::ScanAreaCollision::ScanArea b, bool Z, bool Debug )
				{
					//Set varibles to default values.//
					ia = 0;
					ib = 0;
					y = false;
					x = y;
					z = x;
					collision = false;
					bx.SetBooleanValue( false );
					/*Calling these std::vectors lags beacuse they
					  contain so much data so this eliminates
					  any furthur calls to them for this method.*/
					A = a.GetCollionsCoordinates();
					B = b.GetCollionsCoordinates();
					//This is done for the same reason as the last.//
					sizea = A.size();
					sizeb = B.size();
					if( sizea > 0 && sizeb > 0 )
					{
						while( ia < sizea )
						{
							X1 = A[ ia ].GetX();
							Y1 = A[ ia ].GetY();
							if( Z == true )
							{
								Z1 = A[ ia ].GetZ();
								while( ib < sizeb )
								{
									CheckZ( B[ ib ] );
									if( x == true && y == true && z == true )
										collision = true;
									if( collision == true )
										break;
									ib++;
								}
								ib = 0;
							}
							else
							{
								while( ib < sizeb )
								{
									Check( B[ ib ] );
									if( x == true && y == true )
										collision = true;
									if( collision == true )
										break;
									ib++;
								}
								ib = 0;
							}
							ia++;
						}
						if( collision == true )
						{
							//For debugging.//
							if( Debug == true )
								std::cerr<<"Collision"<<std::endl;
							if( ia >= a.GetCollionsCoordinates().size() )
								ia -= 1;
							WSL::Containers::Base::XYZ vec( b.GetVector() );
							bx.SetCoordinates( vec );
							bx.SetBooleanValue( collision );
							return bx;
						}
						bx.GetCoordinates().SetX( 0 );
						bx.GetCoordinates().SetY( 0 );
						bx.GetCoordinates().SetZ( 0 );
					}
					bx.GetCoordinates().SetX( 0 );
					bx.GetCoordinates().SetY( 0 );
					bx.GetCoordinates().SetZ( 0 );
					return (bx);
				}
			};
		}
	}
}
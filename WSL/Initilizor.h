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
#include "Rotation Calculator.h"
namespace WSL
{
	namespace Collision
	{
		namespace Scan_Area_Collision
		{
			class Initializer
			{
				std::vector<std::string> PreLoaded;
				std::vector<std::vector<WSL::Containers::Base::XYZ>> Stored;
				Collision::Scan_Area_Collision::Rotation_Calculator R_C;
			public:
				Collision::Scan_Area_Collision::Scan_Area Add_Point( Collision::Scan_Area_Collision::Scan_Area s, float X, float Y, float Z )
				{
					WSL::Containers::Base::XYZ a;
					a.setX( X );
					a.setY( Y );
					a.setZ( Z );
					s.Add_Point( a );
					return s;
				}
				Collision::Scan_Area_Collision::Scan_Area Unsafe_Initilization( Collision::Scan_Area_Collision::Scan_Area s, std::vector<WSL::Containers::Base::XYZ> Mags )
				{
					s.Back_Up = Mags;
					unsigned int i = 0;
					while( i < s.Back_Up.size() )
					{
						s = Add_Point( s, s.X + s.Back_Up[i].getX(), s.Y + s.Back_Up[i].getY(), s.Z + s.Back_Up[i].getZ() );
						i++;
					}
					s = R_C.Degree_Rotation( s, -1 );
					s = R_C.Degree_Rotation( s, 1 );
					return s;
				}
				Collision::Scan_Area_Collision::Scan_Area Set_Point_Coordinates( Scan_Area s, std::string Dir )
				{
					std::string Str(Dir);
					unsigned int f = 0;
					while( f < PreLoaded.size() )
					{
						if( Str == PreLoaded[f] )
							return s = Unsafe_Initilization( s, Stored[f]) ;
						f++;
					}
					PreLoaded.push_back(Str);
					bool Load;
					unsigned int i = 0;
					std::vector<float> Read;
					std::ifstream File;
					File.open( Dir.c_str() );
					if( File.is_open() == true )
					{
						while( File.eof() != true )
						{
							i = Read.size();
							{
								float f;
								File >> f;
								Read.push_back( f );
							}
						}
						Load = true;
					}
					else
					{
						std::cout<<"Failed to read file for"<<std::endl;
						std::cout<<"method Set_Point_Coordinates."<<std::endl;
						std::cout<<"(Did you enter a valid file directory?)"<<std::endl;
						Load = false;
					}
					if( Load == true )
					{
						i = 0;
						WSL::Containers::Base::XYZ M;
						while( i < Read.size() && Read.size() != 0 )
						{
							M.setX( Read[i] );
							M.setY( Read[i + 1] );
							M.setZ( Read[i + 2] );
							s.Back_Up.push_back( M );
							i += 3;
						}
						i = 0;
						M.setX( s.X );
						M.setY( s.Y );
						M.setZ( s.Z );
						float px, py, pz;
						while( i < s.Back_Up.size() )
						{
							px = s.X + s.Back_Up[i].getX();
							py = s.Y + s.Back_Up[i].getY();
							pz = s.Z + s.Back_Up[i].getZ();
							s.Add_Point( WSL::Containers::Base::XYZ( px, py, pz ) );
							if( px > s.GetLargeX() )
								s.SetLargeX( px - s.getX() );
							if( px < s.GetSmallX() )
								s.SetSmallX( px - s.getX() );
							if( py > s.GetLargeY() )
								s.SetLargeY( py - s.getY() );
							if( py < s.GetSmallY() )
								s.SetSmallY( py - s.getY() );
							if( pz > s.GetLargeZ() )
								s.SetLargeZ( pz - s.getZ() );
							if( pz < s.GetSmallZ() )
								s.SetSmallZ( pz - s.getZ() );
							i++;
						}
						s.Reset_Scan_Area();
						s.setOrigin( s.getPoint( 0 ) );
						Stored.push_back( s.Back_Up );
						s = R_C.Degree_Rotation( s, -1 );
						s = R_C.Degree_Rotation( s, 1 );
					}
					File.close();
					return s;
				}
			};
		}
	}
}
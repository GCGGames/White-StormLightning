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
#include "Collision Detector.h"
namespace WSL
{
	namespace Collision
	{
		class CollisionEngineBase
		{
		protected:
			WSL::Math::Vector::VectorCalculator Vector_Calc;
			Collision::Scan_Area_Collision::Builder Constructor;
			Collision::Scan_Area_Collision::Collision_Detector Detector;
			Collision::Scan_Area_Collision::Initializer initializer;
			Collision::Scan_Area_Collision::Rotation_Calculator Rotator;
			Collision::Scan_Area_Collision::Updator updator;
			sf::Sprite debug;
		public:
			CollisionEngineBase()
			{
				{WSL::Math::Vector::VectorCalculator *temp = &Vector_Calc;
				Constructor.setCalculator( temp );}
				sf::Image temp;
				temp.LoadFromFile( "bin/Images/ScanDebug.png" );
				debug.SetImage( temp );
				debug.SetScale( 1.f, 1.f );
				debug.SetCenter( 2.f, 2.f );
			}
			inline void Base_Set_Up()
			{
				{WSL::Math::Vector::VectorCalculator *temp = &Vector_Calc;
				Constructor.setCalculator( temp );}
			}
			inline Collision::Scan_Area_Collision::Scan_Area Rotate_Scan_Area( float Degrees, Collision::Scan_Area_Collision::Scan_Area s )
			{
				return Rotator.Degree_Rotation( s, Degrees );
			}
			inline std::vector<WSL::Containers::Base::XYZ> Build_Scan_Area_Points( std::vector<WSL::Containers::Base::XYZ> Points )
			{
				return Constructor.Build( Points );
			}
			inline WSL::Containers::Bool_XYZ Detect_Collision( Collision::Scan_Area_Collision::Scan_Area a, Collision::Scan_Area_Collision::Scan_Area b, bool Three_D, bool Debug )
			{
				return (Detector.Detect_Collision( a, b, Three_D, Debug ));
			}

		     
			bool Check_Collision( WSL::Collision::Scan_Area_Collision::Rectangle rect1, WSL::Collision::Scan_Area_Collision::Rectangle rect2)
			{

				//Temporary code but
				//I needed it for the time beaing thank you Lightdark from the Elysian Shadows chat room!!!!!
				int leftA, leftB;
				int rightA, rightB;
				int topA, topB;
				int bottomA, bottomB;
		     
		     
				leftA = rect1.x;
				rightA = rect1.x + rect1.w;
				topA = rect1.y;
				bottomA = rect1.y + rect1.h;
		     
		     
				leftB = rect2.x;
				rightB = rect2.x + rect2.w;
				topB = rect2.y;
				bottomB = rect2.y + rect2.h;
		     
		     
				if( bottomA <= topB )
				{
					return false;
				}
		     
				if( topA >= bottomB )
				{
					return false;
				}
		     
				if( rightA <= leftB )
				{
					return false;
				}
		     
				if( leftA >= rightB )
				{
					return false;
				}
		     
		     
				return true;
		     
			}

			bool BBChecker( WSL::Collision::Scan_Area_Collision::Scan_Area a, WSL::Collision::Scan_Area_Collision::Scan_Area b, bool ThreeD )
			{
				if( a.getX() <= b.getX() + b.GetLargeX() && a.getX() + a.GetLargeX() >= b.getX() )
				{
					if( a.getY() <= b.getY() + b.GetLargeY() && a.getY() + a.GetLargeY() >= b.getY() )
					{
						if( ThreeD == true )
						{
							if( a.getZ() <= b.getZ() + b.GetLargeZ() && a.getZ() + a.GetLargeZ() >= b.getZ() )
								return true;
							return false;
						}
						return true;
					}
				}
				return false;
			}
			WSL::Containers::Bool_XYZ CheckCollision( WSL::Collision::Scan_Area_Collision::Scan_Area a, WSL::Collision::Scan_Area_Collision::Scan_Area b, bool ThreeD )
			{
				if( Check_Collision( a.GetR() , b.GetR() ) == true )
					WSL::Containers::Bool_XYZ( b.GetVector(), false );
				return WSL::Containers::Bool_XYZ( WSL::Containers::Base::XYZ( 0, 0, 0 ), false );
				/* PROBLEM, collision system has to be fixed!
				if( a.getX() + a.GetSmallX() <= b.getX() + b.GetLargeX() || a.getX() + a.GetLargeX() >= b.getX() + b.GetSmallX() ) {
				if(
					a.getY() + a.GetSmallY() <= b.getY() + b.GetLargeY() || a.getY() + a.GetLargeY() >= b.getY() + b.GetSmallY() )
				{
					if( ThreeD == true )
					{
						if( a.getZ() + a.GetSmallZ() <= b.getZ() + b.GetLargeZ() || a.getZ() + a.GetLargeZ() >= b.getZ() + b.GetSmallZ() )
						{
							if( a.GetBoundingBox() == false )
								a = Calculate_Collision_Points( a );
							if( b.GetBoundingBox() == false )
								b = Calculate_Collision_Points( b );
							return (Detect_Collision( a, b, ThreeD, false ) );
						}
						else
							return WSL::Containers::Bool_XYZ( WSL::Containers::Base::XYZ( 0, 0, 0 ), false );
					}
					else
					{
						a = Calculate_Collision_Points( a );
						b = Calculate_Collision_Points( b );
						return (Detect_Collision( a, b, ThreeD, false ) );
					}
				} }
				return WSL::Containers::Bool_XYZ( WSL::Containers::Base::XYZ( 0, 0, 0 ), false );*/
			}
			Collision::Scan_Area_Collision::Scan_Area Initialize_Scan_Area( Collision::Scan_Area_Collision::Scan_Area s, char *File )
			{
				s = initializer.Set_Point_Coordinates( s, File);
				s = Calculate_Collision_Points( s );
				return s;
			}
			Collision::Scan_Area_Collision::Scan_Area Run( Collision::Scan_Area_Collision::Scan_Area s, bool Scale, float Degree )
			{
				/*COLLISION IS BROKEN!!!!! USING BOUNDING BOX FOR THE TIME BEING!!!s = updator.Update( s, Scale );
				s.setRotated( false );
				if( Degree != 0 )
					s = Rotator.Degree_Rotation( s, Degree );*/
				return s;
			}
			inline Collision::Scan_Area_Collision::Scan_Area Calculate_Collision_Points( Collision::Scan_Area_Collision::Scan_Area s )
			{
				s.setCollision_Coords( Constructor.Build( s.getPoints() ) );
				return s;
			}
		};
	}
}
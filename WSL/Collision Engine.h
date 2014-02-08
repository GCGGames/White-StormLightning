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
#include "Collision detector.h"
namespace WSL
{
	namespace Collision
	{
		class CollisionEngineBase
		{
		protected:
			WSL::Math::Vector::VectorCalculator vectorotationCalculatoralc;
			Collision::ScanAreaCollision::Builder constructor;
			Collision::ScanAreaCollision::CollisionDetector detector;
			Collision::ScanAreaCollision::Initializer initializer;
			Collision::ScanAreaCollision::RotationCalculator rotator;
			Collision::ScanAreaCollision::Updator updator;
			sf::Sprite debug;
		public:
			CollisionEngineBase()
			{
				{WSL::Math::Vector::VectorCalculator* temp = &vectorotationCalculatoralc;
				constructor.SetCalculator( temp );}
				sf::Image temp;
				temp.LoadFromFile( "bin/Images/ScanDebug.png" );
				debug.SetImage( temp );
				debug.SetScale( 1.f, 1.f );
				debug.SetCenter( 2.f, 2.f );
			}
			inline void BaseSetUp() {
				WSL::Math::Vector::VectorCalculator* temp = &vectorotationCalculatoralc;
				constructor.SetCalculator( temp );
			}
			inline Collision::ScanAreaCollision::ScanArea RotateScanArea( float Degrees, Collision::ScanAreaCollision::ScanArea s ) {
				return rotator.DegreeRotation( s, Degrees );
			}
			inline std::vector<WSL::Containers::Base::XYZ> BuildScanAreaPoints( std::vector<WSL::Containers::Base::XYZ> points ) {
				return constructor.Build( points );
			}
			inline WSL::Containers::BoolXYZ DetectCollision( Collision::ScanAreaCollision::ScanArea a, Collision::ScanAreaCollision::ScanArea b, bool threeDimentional, bool debug ) {
				return ( detector.DetectCollision( a, b, threeDimentional, debug ) );
			}
			bool CheckCollision( WSL::Collision::ScanAreaCollision::Rectangle rect1, WSL::Collision::ScanAreaCollision::Rectangle rect2)
			{
				//Temporary code but
				//I needed it for the time beaing thank you Lightdark from the Elysian Shadows chat room!!!!!
				float leftA, leftB;
				float rightA, rightB;
				float topA, topB;
				float bottomA, bottomB;
				float lowA, lowB;
				float highA, highB;
				highA = rect1.z;
				lowA = rect1.z + rect1.l;
				highB = rect2.z;
				lowB = rect2.z + rect2.l;
				leftA = rect1.x;
				rightA = rect1.x + rect1.w;
				topA = rect1.y;
				bottomA = rect1.y + rect1.h;
				leftB = rect2.x;
				rightB = rect2.x + rect2.w;
				topB = rect2.y;
				bottomB = rect2.y + rect2.h;
				if( bottomA <= topB )
					return false;
				if( topA >= bottomB )
					return false;
				if( rightA <= leftB )
					return false;
				if( leftA >= rightB )
					return false;
				if( rect1.l != 0 && rect2.l != 0 )
				{
					if( lowA <= highB )
						return false;
					if( highA >= lowB )
						return false;
				}
				return true;
			}
			bool BBChecker( WSL::Collision::ScanAreaCollision::ScanArea a, WSL::Collision::ScanAreaCollision::ScanArea b, bool ThreeD )
			{
				if( a.GetX() <= b.GetX() + b.GetLargeX() && a.GetX() + a.GetLargeX() >= b.GetX() )
				{
					if( a.GetY() <= b.GetY() + b.GetLargeY() && a.GetY() + a.GetLargeY() >= b.GetY() )
					{
						if( ThreeD == true )
						{
							if( a.GetZ() <= b.GetZ() + b.GetLargeZ() && a.GetZ() + a.GetLargeZ() >= b.GetZ() )
								return true;
							return false;
						}
						return true;
					}
				}
				return false;
			}
			WSL::Containers::BoolXYZ CheckCollision( WSL::Collision::ScanAreaCollision::ScanArea a, WSL::Collision::ScanAreaCollision::ScanArea b, bool ThreeD )
			{
				if( CheckCollision( a.GetR() , b.GetR() ) == true )
					WSL::Containers::BoolXYZ( b.GetVector(), false );
				return WSL::Containers::BoolXYZ( WSL::Containers::Base::XYZ( 0, 0, 0 ), false );
			}
			Collision::ScanAreaCollision::ScanArea InitializeScanArea( Collision::ScanAreaCollision::ScanArea s, char* file )
			{
				s = initializer.SetPointCoordinates( s, file );
				s = CalculateCollisionPoints( s );
				return s;
			}
			Collision::ScanAreaCollision::ScanArea Run( Collision::ScanAreaCollision::ScanArea s, bool scale, float degree ) {
				//COLLISION IS BROKEN!!!!! USING BOUNDING BOX FOR THE TIME BEING!!!//
				return s;
			}
			inline Collision::ScanAreaCollision::ScanArea CalculateCollisionPoints( Collision::ScanAreaCollision::ScanArea s ) {
				s.SetCollionsCoordinates( constructor.Build( s.GetPoints() ) );
				return s;
			}
		};
	}
}
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
		namespace ScanAreaCollision
		{
			class Initializer
			{
				public: 
					//Deprocated.//
					Collision::ScanAreaCollision::ScanArea AddPoint( Collision::ScanAreaCollision::ScanArea s, float X, float Y, float Z ) {
						return s;
					}
					//Deprocated.//
					Collision::ScanAreaCollision::ScanArea UnsafeInitilization( Collision::ScanAreaCollision::ScanArea s, std::vector<WSL::Containers::Base::XYZ> mags ) {
						return s;
					}
					//Deprocated.//
					Collision::ScanAreaCollision::ScanArea SetPointCoordinates( ScanArea s, std::string dir ) {
						return s;
					}
			};
		}
	}
}
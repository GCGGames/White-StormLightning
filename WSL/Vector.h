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
#include "Engine.h"
namespace WSL
{
	namespace Containers
	{
		namespace Math
		{
			class Vector
			{
				WSL::Math::Vector::VectorCalculator vectorCalculator;
				WSL::Containers::Base::XYZ position;
				WSL::Containers::Base::XYZ destination;
				WSL::Containers::Base::XYZ vector;
				bool destinationInitialize, threeDimentional;
				float speed;
			public:
				Vector();
				Vector( WSL::Containers::Base::XYZ position_ );
				Vector( WSL::Containers::Base::XYZ position_, bool threeDimentional_ );
				void CalculateVector();
				bool GetThreeDimentional();
				void Move();
				void SetPosition( WSL::Containers::Base::XYZ position_ );
				void SetDestination( float x, float y );
				void SetDestination( float x, float y, float z );
				void SetDestination( WSL::Containers::Base::XYZ destination_ );
				void SetDestination( float allCoords );
				void SetSpeed( float speed_ );
				void SetThreeDimentional( bool value );
				void SetVector( WSL::Containers::Base::XYZ vector_ );
				float GetDestinationX();
				float GetDestinationY();
				float GetDestinationZ();
				WSL::Containers::Base::XYZ GetDestination();
				WSL::Containers::Base::XYZ GetPosition();
				WSL::Containers::Base::XYZ GetVector();
				float GetX();
				float GetY();
				float GetZ();
				float GetSpeed();
			};
		}
	}
}
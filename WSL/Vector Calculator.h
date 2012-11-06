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
#include "Int Bool.h"
namespace WSL
{
	namespace Math
	{
		namespace Formulas
		{
			class Dot
			{
			public:
				inline float DotProduct( float x, float y, float mag );
				inline float DotProduct( float x, float y, float z, float mag );
			};
		}
		namespace Vector
		{
			struct VectorCalculator
			{
				WSL::Containers::Base::XYZ VectorCalculation( WSL::Containers::Base::XYZ goTo, WSL::Containers::Base::XYZ position, float speed, bool td );
				WSL::Containers::Base::XYZ VectorCalculation( WSL::Containers::Base::XYZ goTo, WSL::Containers::Base::XYZ *position, float speed, bool td );
				VectorCalculator();
				private:
					float x, y, z, magnitude;
					Math::Formulas::Dot magn;
					WSL::Containers::Base::XYZ default_;
			};
		}
	}
}
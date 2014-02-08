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
#include "Double XYZ.h"
namespace WSL
{
	namespace Containers
	{
		class IntBool
		{
			int integervalue;
			bool booleanvalue;
		public:
			inline int GetIntegervalue() {
				return integervalue;
			}
			inline bool GetBooleanValue() {
				return booleanvalue;
			}
			inline void SetIntegervalue( int integervalue_ ) {
				integervalue = integervalue_;
			}
			inline void SetBooleanvalue( bool booleanvalue_ ) {
				booleanvalue = booleanvalue_;
			}
		};
	}
}
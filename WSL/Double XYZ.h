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
#include "XYZ.h"
namespace WSL
{
	namespace Containers
	{
		class DoubleXYZ
		{
			Containers::Base::XYZ first;
			Containers::Base::XYZ second;
		public:
			inline DoubleXYZ( WSL::Containers::Base::XYZ first_, WSL::Containers::Base::XYZ second_ ) {
				first = first_;
				second = second_;
			}
			inline DoubleXYZ() {
			}
			inline void SetFirstXYZ( Containers::Base::XYZ first_ ) {
				first = first_;
			}
			inline void SetSecondXYZ( Containers::Base::XYZ second_ ) {
				second = second_;
			}
			inline Containers::Base::XYZ GetFirstXYZ() {
				return first;
			}
			inline Containers::Base::XYZ GetSecondXYZ() {
				return second;
			}
		};
	}
}
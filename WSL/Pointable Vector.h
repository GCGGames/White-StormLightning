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
//#include "Range_Check.h"
#include "Rudementary Bounding Box.h"
namespace WSL
{
	namespace Containers
	{
		template< typename T >
		struct PointableVector
		{
			std::vector<T> vector;
			inline unsigned int size()
			{
				return vector.size();
			}
			inline void push_back( T t )
			{
				vector.push_back( t );
			}
			inline void clear()
			{
				vector.clear();
			}
			inline void erase( unsigned int i )
			{
				vector.erase( vector.begin() + i );
			}
			inline T operator []( unsigned int element )
			{
				try
				{
					return vector[element];
				}
				catch( std::exception &e )
				{
					std::cerr<<"-----!STL Standard Exception!-----: "<<e.what()<<".\n";
				}
			}
			inline std::vector<T> operator =( std::vector<T> value )
			{
				vector = value;
				return vector;
			}
		};
	}
}
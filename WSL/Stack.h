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
#include "Animation.h"
namespace WSL
{
	namespace Global
	{
		template<typename T>
		struct Stack
		{
			WSL::Algorithmic::SenderNode node;
			std::vector< T > Array;
			std::string type;
			unsigned int size;
			inline void Add( T t ) {
				Array.push_back( t );
				size = Array.size();
			}
			inline void Delete( unsigned int element )
			{
				if( WSL::Algorithmic::BoolRangeCheck( element, Array.size() ) == true ) {
					node.ElementDeleted( element );
					Array.erase( Array.begin() + element );
				}
				else {
					std::cout << "In method ''Delete'' you have attempted to accses a non-existant " << type << "." << std::endl;
					std::cout << "You have tried to accses " << element << " when there are only " << Array.size() << " " << type << "." << std::endl;
				}
				size = Array.size();
			}
		};
	}
}
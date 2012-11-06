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
#include "Polygon.h"
namespace WSL
{
	namespace Algorithmic
	{
		class SenderNode
		{
			unsigned int arrSize;
			bool cycleDone;
			std::vector<unsigned int> deletedPositions;
		public:
			SenderNode()
			{
				cycleDone = false;
			}
			inline void EndCycle()
			{
				deletedPositions.clear();
			}
			/*Tracking added elements is not needed unless we are inserting elements
				which I do not see a need to do.*/
			inline void ElementDeleted( unsigned int element )
			{
				deletedPositions.push_back( element );
			}
			unsigned int GetDeletedPosition( unsigned int pos )
			{
				if( WSL::Algorithmic::Range_Check_bool( pos, deletedPositions.size() ) == true )
					return deletedPositions[pos];
				else
				{
					std::cerr<<"Default value returned for method ''GetDeletedPos'' please remain withing the vector subscript range."<<std::endl;
					return 0;
				}
			}
			inline unsigned int Size()
			{
				return deletedPositions.size();
			}
			inline unsigned int GetArraySize()
			{
				return (arrSize);
			}
			inline void SetArraSize( unsigned int arrSize_ )
			{
				arrSize = arrSize_;
			}
			unsigned int Notify( unsigned int element )
			{
				unsigned int i = 0;
				unsigned int size = deletedPositions.size();
				int change = element;
				//The second test checks for N.A.N's.//
				if( size != 0 && size == size )
				{
					while( i < size )
					{
						if( element > deletedPositions[i] )
								change -= 1;
						i++;
					}
				}
				return change;
			}
		};
	}
}
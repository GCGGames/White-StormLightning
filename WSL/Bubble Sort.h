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
#include "Render Type.h"
namespace WSL
{
	namespace Algorithmic
	{
		
		struct BubbleSort {
			void BubbleSortAlgorithm( WSL::Containers::PointableVector<WSL::Containers::RenderType> *toBeSorted );
		};
#ifndef BSORT
#define BSORT
		template < typename Rfunc >
		static void BubbleSortAlgorithm( std::vector< Rfunc >* toBeSorted )
		{
			unsigned int size, i, j;
			Rfunc transfer;
			size = toBeSorted->size();
			i = 0;
			j = 0;
			while( i < size )
			{
				while( j < size )
				{
					if( j + 1 != size )
					{
						if( toBeSorted->at( j )->GetZ() > toBeSorted->at( j + 1 )->GetZ() )
						{
							transfer = toBeSorted->at( j );
							toBeSorted->at( j ) = toBeSorted->at( j + 1 );
							toBeSorted->at( j + 1 ) = transfer;
						}
					}
					else if( toBeSorted->at( 0 )->GetZ() > toBeSorted->at( j )->GetZ() )
					{
						transfer = toBeSorted->at( 0 );
						toBeSorted->at( 0 ) = toBeSorted->at( j );
						toBeSorted->at( j ) = transfer;
					}
					++j;
				}
				j = 0;
				++i;
			}
		}
#endif
	}
}
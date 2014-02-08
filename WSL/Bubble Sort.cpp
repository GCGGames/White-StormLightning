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
#include "Bubble Sort.h"
void WSL::Algorithmic::BubbleSort::BubbleSortAlgorithm( WSL::Containers::PointableVector< WSL::Containers::RenderType > *toBeSorted )
{
	WSL::Containers::RenderType transfer;
	const unsigned int SIZE = toBeSorted->vector.size();
	for( unsigned int i = 0; i < SIZE; ++i )
	{
		for( unsigned int j = 0; j < SIZE; ++j )
		{
			if( ( j + 1 ) < SIZE )
			{
				if( toBeSorted->vector[ j ].z > toBeSorted->vector[ ( j + 1 ) ].z )
				{
					transfer = toBeSorted->vector[ j ];
					toBeSorted->vector[ j ] = toBeSorted->vector[ ( j + 1 ) ];
					toBeSorted->vector[ j + 1 ] = transfer;
				}
			}
			else if( toBeSorted->vector[ 0 ].z > toBeSorted->vector[ j ].z )
			{
				transfer = toBeSorted->vector[ 0 ];
				toBeSorted->vector[ 0 ] = toBeSorted->vector[ j ];
				toBeSorted->vector[ j ] = transfer;
			}
		}
	}
}
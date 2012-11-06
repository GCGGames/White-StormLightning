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
#include "Collision Engine.h"
namespace WSL
{
	namespace Algorithmic
	{
		struct Store
		{
			unsigned int Size, i;
		};
		static Store Values;
		static unsigned int Range_Check( unsigned int size, unsigned int iterator )
		{
			if( iterator < size && size != 0 && iterator >= 0 )
				return iterator;
			else
				return 0;
		}
		//Make sure you assigned Values.Size to a value.//
		static unsigned int Range_Check( unsigned int iterator )
		{
			if( iterator < Values.Size && Values.Size != 0 && iterator >= 0 )
				return iterator;
			else
				return 0;
		}
		//Make sure you assigned Values.Size and Values.i to a value.//
		static unsigned int Range_Check()
		{
			if( Values.i < Values.Size && Values.Size != 0 && Values.i >= 0 )
				return Values. i;
			else
				return 0;
		}
		//To check before attempting to accsess.//
		static bool Range_Check_bool( unsigned int iterator, unsigned int size )
		{
			if( iterator < size && size != 0 && iterator >= 0 )
				return true;
			else
				return false;
		}
	}
}
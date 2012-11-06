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
#include "Camera.h"
namespace WSL
{
	namespace Containers
	{
		class Key
		{
			bool key;
			std::string name;
		public:
			inline Key( bool key_, std::string name_ )
			{
				key = key_;
				name = name_;
			}
			inline Key( bool key_ )
			{
				key = key;
			}
			inline Key( std::string name_ )
			{
				name = name;
			}
			inline Key()
			{
			}
			inline void SetInfo( bool key_, std::string name_ )
			{
				key = key;
				name = name;
			}
			inline void SetName( std::string name_ )
			{
				name = name_;
			}
			inline void SetKey( bool key_ )
			{
				key = key_;
			}
			inline bool GetKey()
			{
				return key;
			}
			inline std::string GetName()
			{
				return name;
			}
		};
	}
}
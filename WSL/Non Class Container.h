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
#include "Object Tracker.h"
namespace WSL
{
	namespace Containers
	{
		namespace Scripting
		{
			namespace Lua
			{
				template<typename T>
				class LuaBindedType
				{
					std::string name;
					T t;
					int objID, ID;
				public:
					std::string GetName()
					{
						return name;
					}
					void SetName( std::string name_ )
					{
						name = name_;
					}
					void SetObjID( int objID_ )
					{
						objID = objID_;
					}
					void SetID( int ID_ )
					{
						ID = ID_;
					}
					int GetObjID()
					{
						return objID;
					}
					int GetID()
					{
						return ID;
					}
					T Get()
					{
						return t;
					}
					void Set( T t_ )
					{
						t = t_;
					}
				};
			}
		}
	}
}
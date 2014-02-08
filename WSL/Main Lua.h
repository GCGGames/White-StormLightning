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
#include "Color Wrap.h"
namespace WSL
{
	namespace Containers
	{
		namespace Scripting
		{
			struct LuaState
			{
				lua_State *State;
				inline LuaState() {
					State = lua_open();
					luaL_openlibs( State );
				}
				inline ~LuaState() {
					lua_close( State );
				}
			};
			class LuaContainer
			{
				int sentInts, sentBigInts, sentdoubles;
				std::vector< unsigned int > intIndex;
				std::vector< unsigned int > bigIntIndex;
				std::vector< unsigned int > doubleIndex;
				std::vector< std::string > scripts;
				std::vector< WSL::Containers::Scripting::Lua::LuaBindedType< int > > ints;
				std::vector< WSL::Containers::Scripting::Lua::LuaBindedType< long long signed int > > bigInts;
				std::vector< WSL::Containers::Scripting::Lua::LuaBindedType< double > > floats;
				int objID;
				int ID;
			public:
				void SetObjID( int objID_ );
				void SetID( int ID_ );
				std::string currentScript;
				//-----Set the info-----//
				void SetInfo( int objID_, int ID_, std::string currentScript_ )
				{
					objID = objID_;
					ID = ID_;
					currentScript = currentScript_;
				}
				void AddInt( std::string name, int value, bool global );
				void AddLongInt( std::string name, long long signed int value, bool global );
				void AddFloat( std::string name, double value, bool global );
				WSL::Containers::Scripting::Lua::LuaBindedType< int > GetIntegervalue( std::string name );
				WSL::Containers::Scripting::Lua::LuaBindedType< long long signed int > GetLongInt( std::string name );
				WSL::Containers::Scripting::Lua::LuaBindedType< double > GetFloat( std::string name );
				void SetVarible( std::string name, int value );
				void SetVarible( std::string name, long long signed int value );
				void SetVarible( std::string name, double value );
				int GetObjID();
				int GetID();
			};
		}
	}
}
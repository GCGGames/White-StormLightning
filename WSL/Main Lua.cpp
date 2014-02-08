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
#include "Main Lua.h"
void WSL::Containers::Scripting::LuaContainer::SetObjID( int objID_ ) {
	objID = objID_;
}
void WSL::Containers::Scripting::LuaContainer::SetID( int ID_ ) {
	ID = ID_;
}
void WSL::Containers::Scripting::LuaContainer::AddInt( std::string name, int value, bool global )
{
	WSL::Containers::Scripting::Lua::LuaBindedType< int > temp;
	temp.Set( value );
	ints.push_back( temp );
	unsigned int size =  ints.size() - 1;
	ints[ size ].SetName( name );
	if( global == false ) {
		ints[ size ].SetObjID( objID );
		ints[ size ].SetID( ID );
	}
	else {
		ints[ size ].SetObjID( -1 );
		ints[ size ].SetID( -1 );
	}
	scripts.push_back( currentScript );
}
void WSL::Containers::Scripting::LuaContainer::AddLongInt( std::string name, long long signed int value, bool global )
{
	WSL::Containers::Scripting::Lua::LuaBindedType< long long signed int > temp;
	temp.Set( value );
	bigInts.push_back( temp );
	unsigned int size =  bigInts.size() - 1;
	bigInts[ size ].SetName( name );
	if( global == false ) {
		bigInts[ size ].SetObjID( objID );
		bigInts[ size ].SetID( ID );
	}
	else {
		bigInts[ size ].SetObjID( -1 );
		bigInts[ size ].SetID( -1 );
	}
	scripts.push_back( currentScript );
}
void WSL::Containers::Scripting::LuaContainer::AddFloat( std::string name, double value, bool global )
{
	WSL::Containers::Scripting::Lua::LuaBindedType< double > temp;
	temp.Set( value );
	floats.push_back( temp );
	unsigned int size =  floats.size() - 1;
	floats[ size ].SetName( name );
	if( global == false ) {
		floats[ size ].SetObjID( objID );
		floats[ size ].SetID( ID );
	}
	else {
		floats[ size ].SetObjID( -1 );
		floats[ size ].SetID( -1 );
	}
	scripts.push_back( currentScript );
}
WSL::Containers::Scripting::Lua::LuaBindedType< int > WSL::Containers::Scripting::LuaContainer::GetIntegervalue( std::string name )
{
	unsigned int size = ints.size();
	unsigned int i = 0;
	if( size != 0 )
	{
		while( i < size )
		{
			if( ints[ i ].GetName() == name )
			{
				if( ints[ i ].GetObjID() == objID ) {
					if( ints[ i ].GetID() == ID )
						return ints[ i ];
				}
				else {
					if( ints[ i ].GetObjID() == -1 )
						return ints[ i ];
				}
			}
			i++;
		}
	}
	std::cerr<<"There are no stored varibles named "<<name<<" a default value has been returned."<<std::endl;
	return WSL::Containers::Scripting::Lua::LuaBindedType< int >();
}
WSL::Containers::Scripting::Lua::LuaBindedType< long long signed int > WSL::Containers::Scripting::LuaContainer::GetLongInt( std::string name )
{
	unsigned int size, i;
	i = 0;
	size = bigInts.size();
	i = 0;
	if( size != 0 )
	{
		while( i < size )
		{
			if( bigInts[ i ].GetName() == name )
			{
				if( bigInts[ i ].GetObjID() == objID ) {
					if( bigInts[ i ].GetID() == ID )
						return bigInts[ i ];
				}
				else {
					if( bigInts[ i ].GetObjID() == -1 )
						return bigInts[ i ];
				}
			}
			i++;
		}
	}
	std::cerr<<"There are no stored varibles named "<<name<<" a default value has been returned."<<std::endl;
	return WSL::Containers::Scripting::Lua::LuaBindedType< long long signed int >();
}
WSL::Containers::Scripting::Lua::LuaBindedType< double > WSL::Containers::Scripting::LuaContainer::GetFloat( std::string name )
{
	unsigned int i, size;
	size = floats.size();
	i = 0;
	if( size != 0 )
	{
		while( i < size )
		{
			if( floats[ i ].GetName() == name )
			{
				if( floats[ i ].GetObjID() == objID ) {
					if( floats[ i ].GetID() == ID )
						return floats[ i ];
				}
				else {
					if( floats[ i ].GetObjID() == -1 )
						return floats[ i ];
				}
			}
			i++;
		}
	}
	std::cerr<<"There are no stored varibles named "<<name<<" a default value has been returned."<<std::endl;
	return WSL::Containers::Scripting::Lua::LuaBindedType< double >();
}
void WSL::Containers::Scripting::LuaContainer::SetVarible( std::string name, int value )
{
	unsigned int size = ints.size();
	unsigned int i = 0;
	if( size != 0 )
	{
		while( i < size )
		{
			if( ints[ i ].GetName() == name )
			{
				if( ints[ i ].GetObjID() == objID )
				{
					if( ints[ i ].GetID() == ID ) {
						ints[ i ].Set( value );
						break;
					}
				}
				else if( ints[ i ].GetObjID() == -1 ) {
					ints[ i ].Set( value );
					break;
				}
			}
			i++;
		}
	}
}
void WSL::Containers::Scripting::LuaContainer::SetVarible( std::string name, long long signed int value )
{
	unsigned int size = bigInts.size();
	unsigned int i = 0;
	if( size != 0 )
	{
		while( i < size )
		{
			if( bigInts[ i ].GetName() == name )
			{
				if( bigInts[ i ].GetObjID() == objID )
				{
					if( bigInts[ i ].GetID() == ID ) {
						bigInts[ i ].Set( value );
						break;
					}
				}
				else if( bigInts[ i ].GetObjID() == -1 ) {
					bigInts[ i ].Set( value );
					break;
				}
			}
			i++;
		}
	}
}
void WSL::Containers::Scripting::LuaContainer::SetVarible( std::string name, double value )
{
	unsigned int size = floats.size();
	unsigned int i = 0;
	if( size != 0 )
	{
		while( i < size )
		{
			if( floats[ i ].GetName() == name )
			{
				if( floats[ i ].GetObjID() == objID )
				{
					if( floats[ i ].GetID() == ID ) {
						floats[ i ].Set( value );
						break;
					}
				}
				else if( floats[ i ].GetObjID() == -1 ) {
					floats[ i ].Set( value );
					break;
				}
			}
			i++;
		}
	}
}
int WSL::Containers::Scripting::LuaContainer::GetObjID() {
	return objID;
}
int WSL::Containers::Scripting::LuaContainer::GetID() {
	return ID;
}

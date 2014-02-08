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
#include "Level.h"
void WSL::Algorithmic::Level::AddObject( unsigned int id, unsigned int objID )
{
	unsigned int size = refrence->objects.Array.size();
	unsigned int size2 = 0;
	unsigned int i = 0;
	unsigned int j = 0;
	if( size != 0 )
	{
		while( i < size )
		{
			if( refrence->objects.Array[ i ]->GetObjID() == objID && refrence->objects.Array[ i ]->GetID() == id )
			{
				int componentID = 0;
				refrence->currentInfo.SetObjID( objID );
				refrence->currentInfo.SetID( id );
				while( componentID < ( refrence->highestComponentID + 1 ) )
				{
					refrence->currentInfo.SetComponentID( componentID );
					refrence->SearchAlgorithum();
					if( refrence->didNotFindResult == true )
						++componentID;
					else {
						j = refrence->componentTrack;
						break;
					}
				}
				if( refrence->didNotFindResult == true )
				{
					std::cerr << "Failure to add object with Object - ID " << objID;
					std::cerr << " and ID " << id << " to level " << name << std::endl;
					std::cerr << "Did you instantiate the object before trying to";
					std::cerr << "find it, or did you instaintate the level before ";
					std::cerr << "instantiating the object." << std::endl;
				}
				else
					objects.AddObject( j );
				break;
			}
			i++;
			if( i == size )
				std::cerr << "Could not find an object with ID: " << id << "\nand Object - ID: " << objID << ".\n";
		}
	}
}
void WSL::Algorithmic::Level::GetObject( unsigned int id, int objID, int componentID ) {
	refrence->SendObject( id, objID, componentID );
}
WSL::Framework::Standard::Base::BaseEntity* WSL::Algorithmic::Level::GetObject( unsigned int id, int objID, int componentID, bool null ) {
	return refrence->objects.Array[ SearchAlgorithim( id, objID, componentID ) ];
}
void WSL::Algorithmic::Level::SetObject( unsigned int id, int objID, WSL::Framework::Standard::Base::BaseEntity* object ) {
	refrence->objects.Array[ SearchAlgorithim( id, objID, object->GetComponentID() ) ] = object;
}
unsigned int WSL::Algorithmic::Level::SearchAlgorithim( unsigned int id, int objID, int componentID )
{
	const unsigned int SIZE = objects.GetObjects().size();
	Update( refrence->objects.node );
	for( unsigned int i = 0; i < SIZE; ++i ) {
		if( objects.DoesObjectExist( i ) == true )
			return objects.GetObjectElement( i );
	}
	return 0;
}
void WSL::Algorithmic::Level::Update( WSL::Algorithmic::SenderNode node_ )
{
	objects.SetRefrence( refrence->engine );
	objects.Update( node_ );
	objects.DeleteRefrence();
}
bool WSL::Algorithmic::Level::ObjectIsInLevel( unsigned int i )
{
	bool exists = true;
	unsigned int j = 0;
	while( exists == true )
	{
		if( objects.DoesObjectExist( j ) == true ) {
			if( objects.GetObjectElement( j ) == i )
				return true;
		}
		else
			exists = false;
		j++;
	}
	return false;
}
void WSL::Algorithmic::Level::Initialize() {
	if( initialize == true )
		luaL_dofile( refrence->engine->luaContainer->State, initializeScript.c_str() );
}
void WSL::Algorithmic::Level::Refresh() {
	if( refresh == true )
		luaL_dofile( refrence->engine->luaContainer->State, refreshScript.c_str() );
}
void WSL::Algorithmic::Level::Destroy()
{
	if( destroy == true ) {
		luaL_dofile( refrence->engine->luaContainer->State, destroyScript.c_str() );
		DeleteRefrence();
	}
}
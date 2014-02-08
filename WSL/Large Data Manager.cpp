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
#include "Large Data Manager.h"
void WSL::Algorithmic::LargeDataManager::AddObject( unsigned int element )
{
	WSL::Algorithmic::ReceiverNode temp;
	temp.SetElement( element );
	objects.push_back( temp );
}
void WSL::Algorithmic::LargeDataManager::DeleteRefrence() {
	refrence = NULL;
}
void WSL::Algorithmic::LargeDataManager::DeleteTracker( unsigned int element ) {
	if( WSL::Algorithmic::BoolRangeCheck( element, objects.size() ) == true )
		objects.erase( element );
}
void WSL::Algorithmic::LargeDataManager::DeleteTrackerByElement( unsigned int element )
{
	unsigned int size = objects.size();
	if( size != 0 )
	{
		unsigned int i = 0;
		while( i < size )
		{
			if( objects[ i ].GetElement() == element )
				objects.erase( i );
			++i;
		}
	}
}
std::string WSL::Algorithmic::LargeDataManager::GetRefreshScript()
{
	return ( refreshScript );
}
unsigned int WSL::Algorithmic::LargeDataManager::GetObjectElement( unsigned int node )
{
	unsigned int size = objects.size();
	if( WSL::Algorithmic::BoolRangeCheck( node, objects.size() ) == true )
		return (objects[ node ].GetElement());
	else
	{
		std::cerr << "No element (node) found with the index " << node << " a default value has been" << std::endl;
		std::cerr << "returned for method GetObjectElement( unsigned int )." << std::endl;
		return ( 0 );
	}
}
WSL::Containers::PointableVector<WSL::Algorithmic::ReceiverNode> WSL::Algorithmic::LargeDataManager::GetObjects() {
	return ( objects );
}
bool WSL::Algorithmic::LargeDataManager::DoesObjectExist( unsigned int node )
{
	if( WSL::Algorithmic::BoolRangeCheck( node, objects.size() ) == true )
		return ( true );
	else
		return ( false );
}
void WSL::Algorithmic::LargeDataManager::Update( WSL::Algorithmic::SenderNode node )
{
	unsigned int i = 0;
	unsigned int j = 0;
	const unsigned int SIZE = node.Size();
	unsigned int objectsSize = objects.size();
	if( SIZE != 0 && objectsSize != 0 )
	{
		while( j < objectsSize )
		{
			while( i < SIZE )
			{
				if( objects[ j ].GetElement() == node.GetDeletedPosition( i ) )
				{
					objects.erase( j );
					objectsSize -= 1;
					j = 0;
				}
				i++;
			}
			objects[ j ].UpdateStatus( node.Notify( objects[ j ].GetElement() ) );
			i = 0;
			j++;
		}
	}
}
void WSL::Algorithmic::LargeDataManager::Refresh() {
	luaSend();
	luaL_dofile( refrence->luaContainer->State, refreshScript.c_str() );
}
void WSL::Algorithmic::LargeDataManager::SetRefreshScript( std::string refreshScript_ ) {
	refreshScript = refreshScript_;
}
void WSL::Algorithmic::LargeDataManager::SetObjects( std::vector<WSL::Algorithmic::ReceiverNode> objects_ ) {
	objects = objects_;
}
void WSL::Algorithmic::LargeDataManager::SetRefrence( WSL::Engine* engine ) {
	refrence = engine;
}
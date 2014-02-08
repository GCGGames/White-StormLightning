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
#include "Entity.h"
WSL::Framework::Standard::Base::Entity::Entity( int objectID, bool refresh_, bool destroy_, bool initialize_, bool runDestroy,
						std::string refreshScript_, std::string initializeScript_, std::string destroyScript_,
						std::string otherScript_, WSL::Engine* refrence_ )
{
	Construct( objectID, refresh_, destroy_, initialize_, runDestroy, refreshScript_, initializeScript_, destroyScript_,
		otherScript_, refrence_ );
	componentID = 0;
}
WSL::Framework::Standard::Base::Entity::Entity() {
}
WSL::Framework::Standard::Base::Entity::~Entity() {
}
void WSL::Framework::Standard::Base::Entity::InitializeEntity( int objID ) {
	iD = refrence->objectTracker.AddObject( objID, componentID );
}
void WSL::Framework::Standard::Base::Entity::RunScript( std::string script )
{
	RunSubClassMethodBegin();
	SendToLua();
	SendSelf();
	refrence->lua->SetObjID( objID );
	refrence->lua->SetID( iD );
	luaL_dofile( refrence->luaContainer->State, script.c_str() );
	RunSubClassMethodEnd();
}
void WSL::Framework::Standard::Base::Entity::RunInitScript( std::string script )
{
	refrence->lua->SetObjID( objID );
	refrence->lua->SetID( iD );
	luaL_dofile( refrence->luaContainer->State, script.c_str() );
}
void WSL::Framework::Standard::Base::Entity::RunDestroy__( std::string script )
{
	SendSelf();
	refrence->lua->SetObjID( objID );
	refrence->lua->SetID( iD );
	luaL_dofile( refrence->luaContainer->State, script.c_str() );
}
void WSL::Framework::Standard::Base::Entity::SendToLua() {
}
std::string WSL::Framework::Standard::Base::Entity::GetRefreshScript() {
	return refreshScript;
}
std::string WSL::Framework::Standard::Base::Entity::GetInitializeScript() {
	return initializeScript;
}
std::string WSL::Framework::Standard::Base::Entity::GetDestroyScript() {
	return destroyScript;
}
std::string WSL::Framework::Standard::Base::Entity::GetOtherScript() {
	return otherScript;
}
WSL::Containers::CoreInfoContainer WSL::Framework::Standard::Base::Entity::GetChild( unsigned int id, unsigned int objID_ )
{
	unsigned int i = 0;
	unsigned int size = children.size();
	if( size != 0 )
	{
		while( i < size )
		{
			if( id == children[ i ].GetID() && objID_ == children[ i ].GetObjID() ) {
				return children[ i ];
			}
			i++;
		}
	}
	std::cerr << "The information ID: "<< id <<" Object ID: "<< objID_ << std::cerr <<
		"in relevense to ID: " << iD << " Object ID: " << objID << " is ilreelvent in refrence to a child object in method 'GetChild'" << std::endl;
	return ( WSL::Containers::CoreInfoContainer() );
}
void WSL::Framework::Standard::Base::Entity::SetRefrence( WSL::Engine* refrence_ ) {
	refrence = refrence_;
}
void WSL::Framework::Standard::Base::Entity::DeleteRefrence() {
	refrence = NULL;
}
void WSL::Framework::Standard::Base::Entity::SetResfreshScript( std::string script ) {
	refreshScript = script;
}
void WSL::Framework::Standard::Base::Entity::SetInitializeScript( std::string script ) {
	initializeScript = script;
} 
void WSL::Framework::Standard::Base::Entity::SetDestroyScript( std::string script ) {
	destroyScript = script;
}
void WSL::Framework::Standard::Base::Entity::SetOtherScript( std::string script ) {
	otherScript = script;
}
void WSL::Framework::Standard::Base::Entity::SetChild( unsigned int id, unsigned int objID_, WSL::Containers::CoreInfoContainer replacement )
{
	unsigned int i = 0;
	unsigned int size = children.size();
	if( size != 0 )
	{
		while( i < size )
		{
			if( id == children[ i ].GetID() && objID_ == children[ i ].GetObjID() )
				children[ i ] = replacement;
			i++;
		}
	}
	std::cerr << "The information ID: " << id << " Object ID: " << objID_;
	std::cerr << "in relevense to ID: " << iD << " Object ID: " << objID_ << " is ilrelvent in refrence to a child object in method 'SetChild'" << std::endl;
}
int WSL::Framework::Standard::Base::Entity::GetComponentID() {
	return componentID;
}
int WSL::Framework::Standard::Base::Entity::GetObjID() {
	return objID;
}
int WSL::Framework::Standard::Base::Entity::GetID() {
	return iD;
}
void WSL::Framework::Standard::Base::Entity::SetObjID( int objectId_ ) {
	objID = objectId_;
}
void WSL::Framework::Standard::Base::Entity::SetID( int id_ ) {
	iD = id_;
}
void WSL::Framework::Standard::Base::Entity::EntityInitialize() {
	if( initialize == true )
		RunScript( initializeScript );
}
void WSL::Framework::Standard::Base::Entity::EntityRefresh() {
	if( refresh == true )
		RunScript( refreshScript );
}
void WSL::Framework::Standard::Base::Entity::EntityDestroy()
{
	if( destroy == true )
	{
		if( runDestroyScript == true )
			RunDestroy__( destroyScript );
		DeleteIdentification();
	}
}
void WSL::Framework::Standard::Base::Entity::Initialize() {
	EntityInitialize();
}
void WSL::Framework::Standard::Base::Entity::Refresh() {
	EntityRefresh();
}
void WSL::Framework::Standard::Base::Entity::Destroy() {
	EntityDestroy();
}
void WSL::Framework::Standard::Base::Entity::Construct( int objectID, bool refresh_, bool destroy_, bool initialize_, bool runDestroy,
						std::string refeshScript_, std::string initializeScript_, std::string destroyScript_,
						std::string otherScript_, WSL::Engine* refrence_ )
{
	onLuaStack = false;
	refrence = refrence_;
	objID = objectID;
	componentID = 0;
	refresh = refresh_;
	destroy = destroy_;
	initialize = initialize_;
	runDestroyScript = runDestroy;
	refreshScript = refeshScript_;
	initializeScript = initializeScript_;
	destroyScript = destroyScript_;
	otherScript = otherScript_;
	InitializeEntity( objID );
}
void WSL::Framework::Standard::Base::Entity::DeleteIdentification()
{
	bool break_ = false;
	unsigned int i = 0;
	unsigned int o = 0;
	unsigned int size = refrence->objectTracker.ObjectRegisters.size();
	unsigned int idsize = 0;
	while( i < size && break_ == false )
	{
		if( objID == refrence->objectTracker.ObjectRegisters[ i ].ObjID )
		{
			idsize = refrence->objectTracker.ObjectRegisters[ i ].IDs.size();
			while( o < idsize && break_ == false )
			{
				if( refrence->objectTracker.ObjectRegisters[ i ].IDs[ o ] == iD ){
					refrence->objectTracker.ObjectRegisters[ i ].IDs.erase( refrence->objectTracker.ObjectRegisters[ i ].IDs.begin() + o );
					break_ = true;
				}
				++o;
			}
			o = 0;
		}
		++i;
	}
}
bool WSL::Framework::Standard::Base::Entity::GetDestroy() {
	return destroy;
}
void WSL::Framework::Standard::Base::Entity::SetDestroy( bool destroy_ ) {
	destroy = destroy_;
}
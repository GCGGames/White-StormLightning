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
#include "Positional.h"
WSL::Framework::Standard::Positional::Positional( int objectID, bool refresh_, bool destroy_, bool initialize_, bool runDestroy,
	std::string refreshScript_, std::string initializeScript_, std::string destroyScript_,
	std::string otherScript_, std::string physicalBehavior_, WSL::Engine* refrence_ )
{
	physicalBehavior = physicalBehavior_;
	Construct( objectID, refresh_, destroy_, initialize_, runDestroy, refreshScript_, initializeScript_, destroyScript_,
		otherScript_, refrence_ );
	componentID = 1;
	spr = NULL;
	poly = NULL;
	sca = NULL;
	vec = NULL;
}
WSL::Framework::Standard::Positional::Positional() {
}
WSL::Framework::Standard::Positional::~Positional() {
}
void WSL::Framework::Standard::Positional::AddSprite( WSL::Components::LightningSprite* sprite_ )
{
	spr = sprite_;
	spr->SetRefrence( reinterpret_cast< WSL::Base::EngineBase* >( refrence ) );
	refrence->renders.push_back( spr );
	spr->Update( iD, objID, componentID );
	luabind::globals( refrence->luaContainer->State )[ "sprite" ] = spr;
}
void WSL::Framework::Standard::Positional::AddPolygon( WSL::Components::Polygon* polygon_ )
{
	poly = polygon_;
	refrence->renders.push_back( poly );
	poly->Update( iD, objID, componentID );
	luabind::globals( refrence->luaContainer->State )[ "polygon" ] = poly;
}
void WSL::Framework::Standard::Positional::AddScanArea( WSL::Collision::ScanAreaCollision::ScanArea* scanArea_ )
{
	sca = scanArea_;
	refrence->scanAreas.Add( sca );
	sca->Update( iD, objID, componentID );
	luabind::globals( refrence->luaContainer->State )[ "scanArea" ] = sca;
}
void WSL::Framework::Standard::Positional::AddVectorGraphic( WSL::Components::VectorGraphics* vectorGraphi_ )
{
	vec = vectorGraphi_;
	refrence->renders.push_back( vec );
	vec->Update( iD, objID, componentID );
	luabind::globals( refrence->luaContainer->State )[ "vectorGraphi" ] = vec;
}
WSL::Containers::Base::XYZ WSL::Framework::Standard::Positional::GetPosition() {
	return position;
}
float WSL::Framework::Standard::Positional::GetRotation() {
	return rotation;
}
void WSL::Framework::Standard::Positional::Rotate( float degree )
{
	rotation += degree;
	if( spr != NULL )
		spr->Rotate( rotation );
	if( poly != NULL )
		poly->Rotate( rotation );
	if( vec != NULL )
		vec->Rotate( rotation );
	if( sca != NULL )
		*sca = refrence->RotateScanArea( degree, *sca );
}
void WSL::Framework::Standard::Positional::SetComponentPosition( bool twoD ) {
	if( spr != NULL )
		spr->SetPosition( position );
	if( poly != NULL )
		poly->SetPosition( position );
	if( vec != NULL )
		vec->SetPosition( position );
	if( sca != NULL )
	{
		sca->SetX( position.GetX() );
		sca->SetY( position.GetY() );
		if( twoD == false )
			sca->SetZ( position.GetZ() );
	}
}
void WSL::Framework::Standard::Positional::SetPosition( float x, float y, float z )
{
	position.SetX( x );
	position.SetY( y );
	position.SetZ( z );
	SetComponentPosition( false );
}
void WSL::Framework::Standard::Positional::SetPosition( float x, float y )
{
	position.SetX( x );
	position.SetY( y );
	SetComponentPosition( true );
}
void WSL::Framework::Standard::Positional::SetPosition( WSL::Containers::Base::XYZ position_ )
{
	position = position_;
	SetComponentPosition( false );
}
void WSL::Framework::Standard::Positional::SendToLua() {
	PositionalSend();
}
void WSL::Framework::Standard::Positional::SetRotation( float degree )
{
	rotation = degree;
	if( spr != NULL )
		spr->SetRotation( rotation );
	if( poly != NULL )
		poly->SetRotation( rotation );
	if( vec != NULL )
		sca->SetRotation( rotation );
}
void WSL::Framework::Standard::Positional::PositionalInitialize()
{
	if( initialize == true ) {
		RunScript( initializeScript );
		SetPosition( position );
	}
}
void WSL::Framework::Standard::Positional::PositionalRefresh()
{
	if( refresh == true )
	{
		RunScript( refreshScript );
		if( physicalBehavior != "NULL" )
			RunPhysScript( physicalBehavior );
		SetPosition( position );
	}
}
void WSL::Framework::Standard::Positional::PositionalDestroy()
{
	if( destroy == true )
	{
		if( runDestroyScript == true ) {
			SetPosition( position );
			RunDestroy__( destroyScript );
		}
		DeleteComponents();
		DeleteIdentification();
	}
}
void WSL::Framework::Standard::Positional::Initialize() {
	PositionalInitialize();
}
void WSL::Framework::Standard::Positional::Refresh() {
	PositionalRefresh();
}
void WSL::Framework::Standard::Positional::Destroy() {
	PositionalDestroy();
}
void WSL::Framework::Standard::Positional::DeleteComponents() {
	PositionalDelete();
}
void WSL::Framework::Standard::Positional::PositionalSend()
{
	if( spr != NULL ) {
		spr->Update( iD, objID, componentID );
		luabind::globals( refrence->luaContainer->State )[ "sprite" ] = spr;
	}
	if( poly != NULL ) {
		poly->Update( iD, objID, componentID );
		luabind::globals( refrence->luaContainer->State )[ "polygon" ] = poly;
	}
	if( vec != NULL ) {
		vec->Update( iD, objID, componentID );
		luabind::globals( refrence->luaContainer->State )[ "vectorGraphic" ] = vec;
	}
	if( sca != NULL ) {
		sca->Update( iD, objID, componentID );
		luabind::globals( refrence->luaContainer->State )[ "scanArea" ] = sca;
	}
	luabind::globals( refrence->luaContainer->State )[ "position" ] = &position;
}
void WSL::Framework::Standard::Positional::PositionalDelete()
{
	if( spr != NULL )
	{
		spr->DeleteRefrence();
		delete spr;
		spr = NULL;
	}
	if( poly != NULL ) {
		delete poly;
		poly = NULL;
	}
	if( vec != NULL ) {
		delete vec;
		vec = NULL;
	}
	if( sca != NULL ) {
		delete sca;
		sca = NULL;
	}
}
void WSL::Framework::Standard::Positional::RunSubClassMethodBegin()
{
	if( spr != NULL ) {
		spr->SetRefrence( reinterpret_cast< WSL::Base::EngineBase* >( refrence ) );
		refrence->renders.push_back( spr );
	}
	if( poly != NULL )
		refrence->renders.push_back( poly );
	if( vec != NULL )
		refrence->renders.push_back( vec );
	if( sca != NULL )
		refrence->scanAreas.Add( sca );
}
void WSL::Framework::Standard::Positional::RunSubClassMethodEnd() {
	if( spr != NULL )
		spr->DeleteRefrence();
}
std::string WSL::Framework::Standard::Positional::GetPhysicalBehavior() {
	return physicalBehavior;
}
void WSL::Framework::Standard::Positional::SetPhysicalBehavior( std::string physicalBehavior_ ) {
	physicalBehavior = physicalBehavior_;
}
void WSL::Framework::Standard::Positional::DeleteRefrence()
{
	refrence = NULL;
	if( spr != NULL )
		spr->DeleteRefrence();
}
void WSL::Framework::Standard::Positional::RunPhysScript( std::string script )
{
	SendToLua();
	SendSelf();
	refrence->lua->SetObjID( objID );
	refrence->lua->SetID( iD );
	SetScanAreaProperties();
	luaL_dofile( refrence->luaContainer->State, script.c_str() );
}

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
WSL::Framework::Standard::Positional::Positional( int obj_ID, bool Refresh, bool Destroy, bool initialize_, bool RDestroy,
	std::string refresh_Script, std::string initialize_Script, std::string destroy_Script,
	std::string other_Script, std::string physicalBehavior_, WSL::Engine *refrence_ )
{
	physicalBehavior = physicalBehavior_;
	Construct( obj_ID, Refresh, Destroy, initialize_, RDestroy, refresh_Script, initialize_Script, destroy_Script,
		other_Script, refrence_ );
	componentID = 1;
	spr = NULL;
	poly = NULL;
	sca = NULL;
	vec = NULL;
}
WSL::Framework::Standard::Positional::Positional()
{
}
WSL::Framework::Standard::Positional::~Positional()
{
}
void WSL::Framework::Standard::Positional::AddSprite( WSL::Components::Lightning_Sprite sprite_ )
{
	spr = new WSL::Components::Lightning_Sprite;
	*spr = sprite_;
	spr->SetRefrence( reinterpret_cast<WSL::Base::EngineBase*>( refrence[0] ) );
	refrence[0]->renders.push_back( spr );
	spr->Update( iD, objID, componentID );
	luabind::globals( refrence[0]->luaContainer->State )[ "sprite" ] = spr;
}
void WSL::Framework::Standard::Positional::AddPolygon( WSL::Components::Polygon polygon_ )
{
	poly = new WSL::Components::Polygon;
	*poly = polygon_;
	refrence[0]->renders.push_back( poly );
	poly->Update( iD, objID, componentID );
	luabind::globals( refrence[0]->luaContainer->State )[ "polygon" ] = poly;
}
void WSL::Framework::Standard::Positional::AddScanArea( WSL::Collision::Scan_Area_Collision::Scan_Area scanArea_ )
{
	sca = new WSL::Collision::Scan_Area_Collision::Scan_Area;
	*sca = scanArea_;
	refrence[0]->scanAreas.Add( sca );
	sca->Update( iD, objID, componentID );
	luabind::globals( refrence[0]->luaContainer->State )[ "scanArea" ] = sca;
}
void WSL::Framework::Standard::Positional::AddVectorGraphic( WSL::Components::Vector_Graphics vectorGraphi_ )
{
	vec = new WSL::Components::Vector_Graphics;
	*vec = vectorGraphi_;
	refrence[0]->renders.push_back( vec );
	vec->Update( iD, objID, componentID );
	luabind::globals( refrence[0]->luaContainer->State )[ "vectorGraphi" ] = vec;
}
WSL::Containers::Base::XYZ WSL::Framework::Standard::Positional::GetPosition()
{
	return position;
}
float WSL::Framework::Standard::Positional::GetRotation()
{
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
		*sca = refrence[0]->Rotate_Scan_Area( degree, *sca );
}
void WSL::Framework::Standard::Positional::SetComponentPosition( bool twoD )
{
	if( spr != NULL )
		spr->SetPosition( position );
	if( poly != NULL )
		poly->SetPosition( position );
	if( vec != NULL )
		vec->SetPosition( position );
	if( sca != NULL )
	{
		sca->setX( position.getX() );
		sca->setY( position.getY() );
		if( twoD == false )
			sca->setZ( position.getZ() );
	}
}
void WSL::Framework::Standard::Positional::SetPosition( float x, float y, float z )
{
	position.setX( x );
	position.setY( y );
	position.setZ( z );
	SetComponentPosition( false );
}
void WSL::Framework::Standard::Positional::SetPosition( float x, float y )
{
	position.setX( x );
	position.setY( y );
	SetComponentPosition( true );
}
void WSL::Framework::Standard::Positional::SetPosition( WSL::Containers::Base::XYZ position_ )
{
	position = position_;
	SetComponentPosition( false );
}
void WSL::Framework::Standard::Positional::SendToLua()
{
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
	//if( sca != NULL )
		//*sca = refrence[0]->Rotate_Scan_Area( degree - rotation, *sca );
}
void WSL::Framework::Standard::Positional::PositionalInitialize()
{
	if( initialize == true )
	{
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
		{
			RunPhysScript( physicalBehavior );
		}
		SetPosition( position );
	}
}
void WSL::Framework::Standard::Positional::PositionalDestroy()
{
	if( destroy == true )
	{
		if( runDestroyScript == true )
		{
			SetPosition( position );
			RunDestroy__( destroyScript );
		}
		DeleteComponents();
		DeleteIdentification();
	}
}
void WSL::Framework::Standard::Positional::Initialize()
{
	PositionalInitialize();
}
void WSL::Framework::Standard::Positional::Refresh()
{
	PositionalRefresh();
}
void WSL::Framework::Standard::Positional::Destroy()
{
	PositionalDestroy();
}
void WSL::Framework::Standard::Positional::DeleteComponents()
{
	PositionalDelete();
}
void WSL::Framework::Standard::Positional::PositionalSend()
{
	if( spr != NULL )
	{
		spr->Update( iD, objID, componentID );
		luabind::globals( refrence[0]->luaContainer->State )[ "sprite" ] = spr;
	}
	if( poly != NULL )
	{
		poly->Update( iD, objID, componentID );
		luabind::globals( refrence[0]->luaContainer->State )[ "polygon" ] = poly;
	}
	if( vec != NULL )
	{
		vec->Update( iD, objID, componentID );
		luabind::globals( refrence[0]->luaContainer->State )[ "vectorGraphic" ] = vec;
	}
	if( sca != NULL )
	{
		sca->Update( iD, objID, componentID );
		luabind::globals( refrence[0]->luaContainer->State )[ "scanArea" ] = sca;
	}
	luabind::globals( refrence[0]->luaContainer->State )[ "position" ] = &position;
}
void WSL::Framework::Standard::Positional::PositionalDelete()
{
	if( spr != NULL )
	{
		spr->DeleteRefrence();
		//spr->SetParentsToNULL();
		delete spr;
		spr = NULL;
	}
	if( poly != NULL )
	{
		//poly->SetParentsToNULL();
		delete poly;
		poly = NULL;
	}
	if( vec != NULL )
	{
		//vec->SetParentsToNULL();
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
	if( spr != NULL )
	{
		spr->SetRefrence( reinterpret_cast<WSL::Base::EngineBase*>( refrence[0] ) );
		refrence[0]->renders.push_back( spr );
	}
	if( poly != NULL )
		refrence[0]->renders.push_back( poly );
	if( vec != NULL )
		refrence[0]->renders.push_back( vec );
	if( sca != NULL )
		refrence[0]->scanAreas.Add( sca );
}
void WSL::Framework::Standard::Positional::RunSubClassMethodEnd()
{
	if( spr != NULL )
		spr->DeleteRefrence();
}
std::string WSL::Framework::Standard::Positional::GetPhysicalBehavior()
{
	return physicalBehavior;
}
void WSL::Framework::Standard::Positional::SetPhysicalBehavior( std::string physicalBehavior_ )
{
	physicalBehavior = physicalBehavior_;
}
void WSL::Framework::Standard::Positional::DeleteRefrence()
{
	refrence.clear();
	if( spr != NULL )
		spr->DeleteRefrence();
}
void WSL::Framework::Standard::Positional::RunPhysScript( std::string script )
{
	SendToLua();
	SendSelf();
	refrence[0]->lua->SetObjID( objID );
	refrence[0]->lua->SetID( iD );
	SetScanAreaProperties();
	luaL_dofile( refrence[0]->luaContainer->State, script.c_str() );
}
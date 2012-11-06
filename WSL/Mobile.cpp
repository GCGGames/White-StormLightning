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
#include "Mobile.h"
WSL::Framework::Standard::Mobile::Mobile( int obj_ID, bool Refresh, bool Destroy, bool initialize_, bool RDestroy,
						std::string refresh_Script, std ::string initialize_Script, std::string destroy_Script,
						std::string other_Script, std::string physicalBehavior_, WSL::Engine *refrence_ )
{
	physicalBehavior = physicalBehavior_;
	Construct( obj_ID, Refresh, Destroy, initialize_, RDestroy, refresh_Script, initialize_Script, destroy_Script,
		other_Script, refrence_ );
	componentID = 2;
	spr = NULL;
	poly = NULL;
	sca = NULL;
	vec = NULL;
}
WSL::Framework::Standard::Mobile::Mobile()
{
}
WSL::Framework::Standard::Mobile::~Mobile()
{
}
void WSL::Framework::Standard::Mobile::Calculate()
{
	vector.CalculateVector();
}
bool WSL::Framework::Standard::Mobile::GetAutoCalculate()
{
	return autoCalculate.Get();
}
bool WSL::Framework::Standard::Mobile::GetAutoMove()
{
	return autoMove.Get();
}
WSL::Containers::Math::Vector WSL::Framework::Standard::Mobile::GetVector()
{
	return vector;
}
void WSL::Framework::Standard::Mobile::SetAutoCalculate( bool autoCalculate_ )
{
	autoCalculate.Set( autoCalculate_ );
}
void WSL::Framework::Standard::Mobile::SetAutoMove( bool autoMove_ )
{
	autoMove.Set( autoMove_ );
}
void WSL::Framework::Standard::Mobile::SetDestination( WSL::Containers::Base::XYZ destination )
{
	vector.SetDestination( destination );
}
void WSL::Framework::Standard::Mobile::SetDestination( float x, float y, float z )
{
	vector.SetDestination( x, y, z );
}
void WSL::Framework::Standard::Mobile::SetDestination( float x, float y )
{
	vector.SetDestination( x, y );
}
void WSL::Framework::Standard::Mobile::SetDestination( float allCoords )
{
	vector.SetDestination( allCoords );
}
void WSL::Framework::Standard::Mobile::SendToLua()
{
	MobileSend();
}
void WSL::Framework::Standard::Mobile::SetPosition( float x, float y, float z )
{
	position.setX( x );
	position.setY( y );
	position.setZ( z );
	vector.SetPosition( position );
	SetComponentPosition( false );
}
void WSL::Framework::Standard::Mobile::SetPosition( float x, float y )
{
	position.setX( x );
	position.setY( y );
	vector.SetPosition( position );
	SetComponentPosition( true );
}
void WSL::Framework::Standard::Mobile::SetPosition( WSL::Containers::Base::XYZ position_ )
{
	position = position_;
	vector.SetPosition( position );
	SetComponentPosition( false );

}
void WSL::Framework::Standard::Mobile::SetVector( WSL::Containers::Math::Vector vector_ )
{
	vector = vector_;
}
void WSL::Framework::Standard::Mobile::Move()
{
	vector.Move();
	position = vector.GetPosition();
	SetPosition( position );
}
void WSL::Framework::Standard::Mobile::MobileInitialize()
{
	if( initialize == true )
	{
		RunScript( initializeScript );
		vector.SetPosition( position );
		SetPosition( position );
	}
}
void WSL::Framework::Standard::Mobile::MobileRefresh()
{
	if( refresh == true )
	{
		vector.SetPosition( position );
		if( autoCalculate.Get() == true )
			vector.CalculateVector();
		if( sca != NULL )
			sca->SetVector( vector.GetVector() );
		RunScript( refreshScript );
		if( physicalBehavior != "NULL" )
			RunPhysScript( physicalBehavior );
		if( autoMove.Get() == true )
			Move();
		SetPosition( position );
	}
}
void WSL::Framework::Standard::Mobile::MobileDestroy()
{
	if( destroy == true )
	{
		if( runDestroyScript == true )
		{
			SetPosition( position );
			vector.SetPosition( position );
			RunDestroy__( destroyScript );
		}
		DeleteComponents();
		DeleteIdentification();
	}
}
void WSL::Framework::Standard::Mobile::Initialize()
{
	MobileInitialize();
}
void WSL::Framework::Standard::Mobile::Refresh()
{
	MobileRefresh();
}
void WSL::Framework::Standard::Mobile::Destroy()
{
	MobileDestroy();
}
void WSL::Framework::Standard::Mobile::MobileSend()
{
	PositionalSend();
	luabind::globals( refrence[0]->luaContainer->State )[ "vector" ] = &vector;
	luabind::globals( refrence[0]->luaContainer->State )[ "autoMove" ] = &autoMove;
	luabind::globals( refrence[0]->luaContainer->State )[ "autoCalculate" ] = &autoCalculate;
}
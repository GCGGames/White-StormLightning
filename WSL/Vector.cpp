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
#include "Vector.h"
WSL::Containers::Math::Vector::Vector()
{
	destinationInitialize = false;
	threeDimentional = false;
}
WSL::Containers::Math::Vector::Vector( WSL::Containers::Base::XYZ position_ )
{
	position = position_;
	destinationInitialize = false;
	threeDimentional = false;
}
WSL::Containers::Math::Vector::Vector( WSL::Containers::Base::XYZ position_, bool threeDimentional_ )
{
	position = position_;
	destinationInitialize = false;
	threeDimentional = threeDimentional_;
}
float WSL::Containers::Math::Vector::GetDestinationX()
{
	return destination.getX();
}
float WSL::Containers::Math::Vector::GetDestinationY()
{
	return destination.getY();
}
float WSL::Containers::Math::Vector::GetDestinationZ()
{
	return destination.getZ();
}
WSL::Containers::Base::XYZ WSL::Containers::Math::Vector::GetDestination()
{
	return destination;
}
WSL::Containers::Base::XYZ WSL::Containers::Math::Vector::GetPosition()
{
	return position;
}
float WSL::Containers::Math::Vector::GetX()
{
	return position.getX();
}
float WSL::Containers::Math::Vector::GetY()
{
	return position.getY();
}
float WSL::Containers::Math::Vector::GetZ()
{
	return position.getZ();
}
void WSL::Containers::Math::Vector::SetThreeDimentional( bool value )
{
	threeDimentional = value;
}
bool WSL::Containers::Math::Vector::GetThreeDimentional()
{
	return threeDimentional;
}
void WSL::Containers::Math::Vector::CalculateVector()
{
	vector = vectorCalculator.VectorCalculation( destination, position, speed, threeDimentional );
}
void WSL::Containers::Math::Vector::Move()
{
	position.setX( position.getX() + vector.getX() );
	position.setY( position.getY() + vector.getY() );
	position.setZ( position.getZ() + vector.getZ() );
}
void WSL::Containers::Math::Vector::SetPosition( WSL::Containers::Base::XYZ position_ )
{
	position = position_;
}
void WSL::Containers::Math::Vector::SetSpeed( float speed_ )
{
	speed = speed_;
}
void WSL::Containers::Math::Vector::SetDestination( float x, float y )
{
	destination.setX( x );
	destination.setY( y );
	if( destinationInitialize == false )
	{
		destinationInitialize = true;
		destination.setZ( 0 );
	}
}
void WSL::Containers::Math::Vector::SetDestination( float x, float y, float z )
{
	destination.setX( x );
	destination.setY( y );
	destination.setZ( z );
}
void WSL::Containers::Math::Vector::SetDestination( WSL::Containers::Base::XYZ destination_ )
{
	destination = destination_;
}
void WSL::Containers::Math::Vector::SetDestination( float allCoords )
{
	destination.setX( allCoords );
	destination.setY( allCoords );
	destination.setZ( allCoords );
}
void WSL::Containers::Math::Vector::SetVector( WSL::Containers::Base::XYZ vector_ )
{
	vector = vector_;
}
WSL::Containers::Base::XYZ WSL::Containers::Math::Vector::GetVector()
{
	return vector;
}
float WSL::Containers::Math::Vector::GetSpeed()
{
	return speed;
}
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


#include "Vector Calculator.h"
WSL::Math::Vector::VectorCalculator::VectorCalculator()
{
	WSL::Containers::Base::XYZ temp;
	//temp.setX( 1.f );
	//temp.setY( 1.f );
	//temp.setZ( 1.f );
	default_ = temp;
}
WSL::Containers::Base::XYZ WSL::Math::Vector::VectorCalculator::VectorCalculation( WSL::Containers::Base::XYZ goTo, WSL::Containers::Base::XYZ position, float speed, bool td )
{
	float epsilon = std::numeric_limits<float>::epsilon();
	WSL::Containers::Base::XYZ vector;
	//Make sure that the vector doesent have any stray values lying around.//
	vector = default_;
	//Calculate Magnitude.//
	x = goTo.getX() - position.getX();
	y = goTo.getY() - position.getY();
	z = goTo.getZ() - position.getZ();
	if( td == true )
		magnitude = magn.DotProduct( x, y, z, magnitude );
	else
		magnitude = magn.DotProduct( x, y, magnitude );
	//Normilise//
	magnitude = sqrt( magnitude );
	//Make sure we do not divide by zero.//
	if( magnitude >= 0 + epsilon || magnitude <= 0 - epsilon )
	{
		x /= magnitude;
		y /= magnitude;
		if( td == true )
			z /= magnitude;
	}
	//Go The Desired Speed.//
	if( speed >= 0 + epsilon ) {
		x *= speed;
		y *= speed;
	}
	//TO DO: FIX!!//
	if( td == true )
		z *= speed;
	vector.setX( x );
	vector.setY( y );
	vector.setZ( z );
	return vector;
}
WSL::Containers::Base::XYZ WSL::Math::Vector::VectorCalculator::VectorCalculation( WSL::Containers::Base::XYZ goTo, WSL::Containers::Base::XYZ *position, float speed, bool td )
{
	float epsilon = std::numeric_limits<float>::epsilon();
	WSL::Containers::Base::XYZ vector;
	//Make sure that the vector doesent have any stray values lying around.//
	vector = default_;
	//Calculate Magnitude.//
	x = goTo.getX() - position->getX();
	y = goTo.getY() - position->getY();
	z = goTo.getZ() - position->getZ();
	if( td == true )
		magnitude = magn.DotProduct( x, y, z, magnitude );
	else
		magnitude = magn.DotProduct( x, y, magnitude );
	//Normilise//
	magnitude = sqrt( magnitude );
	//Make sure we do not divide by zero.//
	if( magnitude >= 0 + epsilon && magnitude <= 0 - epsilon )
	{
		x /= magnitude;
		y /= magnitude;
		if( td == true )
			z /= magnitude;
	}
	//Go The Desired Speed.//
	if( speed >= 0 + epsilon )
	{
		x *= speed;
		y *= speed;
	}
	if( td == true )
		z *= speed;
	vector.setX( x );
	vector.setY( y );
	vector.setZ( z );
	return vector;
}
inline float WSL::Math::Formulas::Dot::DotProduct( float x, float y, float mag )
{
	return ( mag = ( ( x ) * ( x ) + ( y ) * ( y ) ) );
}
inline float WSL::Math::Formulas::Dot::DotProduct( float x, float y, float z, float mag )
{
	return ( mag = ( ( x ) * ( x ) + ( y ) * ( y ) + ( z ) * ( z ) ) );
}

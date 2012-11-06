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
#include "Vector Graphics Component.h"
void WSL::Components::VectorGraphicsComponent::AddPoint( float x, float y )
{
	representation.Add_Point( WSL::Containers::Base::XYZ( x, y, position.getZ() ) );
	representation.Add_Magnitude( WSL::Containers::Base::XYZ( x, y, position.getZ() ) );
}
void WSL::Components::VectorGraphicsComponent::AddPoint( float x, float y, float z )
{
	representation.Add_Point( WSL::Containers::Base::XYZ( x, y, position.getZ() ) );
	representation.Add_Magnitude( WSL::Containers::Base::XYZ( x, y, z ) );
}
void WSL::Components::VectorGraphicsComponent::AddPoint( WSL::Containers::Base::XYZ Position )
{
	representation.Add_Point( WSL::Containers::Base::XYZ( Position ) );
	representation.Add_Magnitude( WSL::Containers::Base::XYZ( Position ) );
}
void WSL::Components::VectorGraphicsComponent::Build()
{
	std::vector<WSL::Containers::Base::XYZ> temp;
	temp = B->Build( representation.getPoints() );
	representation.setCollision_Coords( temp );
}
void WSL::Components::VectorGraphicsComponent::DeletePoint( unsigned int Elem )
{
	if( Elem >= 0 && Elem < representation.getPoints().size() )
	{
		std::vector<WSL::Containers::Base::XYZ> temp = representation.getPoints();
		temp.erase( temp.begin() + Elem );
		representation.setPoints( temp );
		temp = representation.getMagnitudes();
		temp.erase( temp.begin() + Elem );
		representation.setMagnitudes( temp );
	}
	else
	{
		std::cout<<"You have attempted to delete a non-existant"<<std::endl;
		std::cout<<"element of the std::vector graphics. Please make sure"<<std::endl;
		std::cout<<"you remain within the vector range."<<std::endl;
	}
}
void WSL::Components::VectorGraphicsComponent::Clear()
{
	std::vector<WSL::Containers::Base::XYZ> temp = representation.getPoints();
	temp.clear();
	representation.setPoints( temp );
	representation.setMagnitudes( temp );
	graphics.clear();
}
void WSL::Components::VectorGraphicsComponent::Draw( sf::RenderWindow *window )
{
	Link();
	i = 0;
	size = graphics.size();
	if( size != 0 )
	{
		while( i < size )
		{
			window->Draw( graphics[i] );
			i++;
		}
	}
}
std::vector<sf::Shape> WSL::Components::VectorGraphicsComponent::getGraphics()
{
	return graphics;
}
sf::Shape WSL::Components::VectorGraphicsComponent::getLine( unsigned int Elem )
{
	if( Elem >= 0 && Elem < graphics.size() )
		return graphics[Elem];
	else
	{
		std::cout<<"You have attempted to accses a non-existant element"<<std::endl;
		std::cout<<"of the std::vector Graphics. A defult value has been returned."<<std::endl;
		return sf::Shape();
	}
}
void WSL::Components::VectorGraphicsComponent::Link()
{
	representation.setX( position.getX() );
	representation.setY( position.getY() );
	representation = U.Update( representation, true );
	representation.setRotated( false );
	size = representation.getPoints().size();
	graphics.clear();
	i = 0;
	sf::Shape temp;
	while( i < size )
	{
		if( i < size - 1 )
			temp = sf::Shape::Line( representation.getPoint( i ).getX(), representation.getPoint( i ).getY(), representation.getPoint( i + 1 ).getX(), representation.getPoint( i + 1 ).getY(), thickness, color, outline, outlineColor );
		else
			temp = sf::Shape::Line( representation.getPoint( i ).getX(), representation.getPoint( i ).getY(), representation.getPoint( 0 ).getX(), representation.getPoint( 0 ).getY(), thickness, color, outline, outlineColor );
		graphics.push_back( temp );
		i++;
	}
	i = 0;
}
void WSL::Components::VectorGraphicsComponent::Reload( std::string directory )
{
	representation = I.Set_Point_Coordinates( representation, directory );
	representation.setInitialized( true );
}
void WSL::Components::VectorGraphicsComponent::Rotate( float Degrees )
{
	representation = R.Degree_Rotation( representation, Degrees );
	Link();
}
void WSL::Components::VectorGraphicsComponent::SetRotation( float degree )
{
	float td = degree - representation.GetRotation();
	Rotate( td );
}
void WSL::Components::VectorGraphicsComponent::SetPosition( float x, float y )
{
	representation.setX( x );
	representation.setY( y );
	position.setX( x );
	position.setY( y );
}
void WSL::Components::VectorGraphicsComponent::SetPosition( float x, float y, float z )
{
	representation.setX( x );
	representation.setY( y );
	representation.setZ( z );
	position.setX( x );
	position.setY( y );
	position.setZ( z );
}
void WSL::Components::VectorGraphicsComponent::SetPosition( WSL::Containers::Base::XYZ Position )
{
	representation.setX( Position.getX() );
	representation.setY( Position.getY() );
	representation.setZ( Position.getZ() );
	position = Position;
}
WSL::Components::VectorGraphicsComponent::VectorGraphicsComponent()
{
}
void WSL::Components::VectorGraphicsComponent::Initialize( std::string file )
{
	B = new WSL::Collision::Scan_Area_Collision::Builder;
	thickness = 1;
	outline = 1;
	Scale = false;
	outlineColor = sf::Color( 100, 100, 100 );
	color = sf::Color( 100, 200, 100 );
	Math::Vector::VectorCalculator *temp = new Math::Vector::VectorCalculator;
	B->setCalculator( temp );
	Reload( file );
}
void WSL::Components::VectorGraphicsComponent::CleanUp()
{
	delete B;
}
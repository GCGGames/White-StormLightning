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
void WSL::Components::VectorGraphicsComponent::AddPoint( float x, float y ) {
	representation.AddPoint( WSL::Containers::Base::XYZ( x, y, position.GetZ() ) );
	representation.AddMagnitude( WSL::Containers::Base::XYZ( x, y, position.GetZ() ) );
}
void WSL::Components::VectorGraphicsComponent::AddPoint( float x, float y, float z ) {
	representation.AddPoint( WSL::Containers::Base::XYZ( x, y, position.GetZ() ) );
	representation.AddMagnitude( WSL::Containers::Base::XYZ( x, y, z ) );
}
void WSL::Components::VectorGraphicsComponent::AddPoint( WSL::Containers::Base::XYZ position ) {
	representation.AddPoint( WSL::Containers::Base::XYZ( position ) );
	representation.AddMagnitude( WSL::Containers::Base::XYZ( position ) );
}
void WSL::Components::VectorGraphicsComponent::Build()
{
	std::vector< WSL::Containers::Base::XYZ > temp;
	temp = builder->Build( representation.GetPoints() );
	representation.SetCollionsCoordinates( temp );
}
void WSL::Components::VectorGraphicsComponent::DeletePoint( unsigned int position )
{
	if( position >= 0 && position < representation.GetPoints().size() )
	{
		std::vector< WSL::Containers::Base::XYZ > temp = representation.GetPoints();
		temp.erase( temp.begin() + position );
		representation.SetPoints( temp );
		temp = representation.GetMagnitudes();
		temp.erase( temp.begin() + position );
		representation.SetMagnitudes( temp );
	}
	else
	{
		std::cout << "You have attempted to delete a non-existant" << std::endl;
		std::cout << "positionent of the std::vector graphics. Please make sure" << std::endl;
		std::cout << "you remain within the vector range." << std::endl;
	}
}
void WSL::Components::VectorGraphicsComponent::Clear()
{
	std::vector< WSL::Containers::Base::XYZ > temp = representation.GetPoints();
	temp.clear();
	representation.SetPoints( temp );
	representation.SetMagnitudes( temp );
	graphics.clear();
}
void WSL::Components::VectorGraphicsComponent::Draw( sf::RenderWindow* window )
{
	Link();
	i = 0;
	size = graphics.size();
	if( size != 0 )
	{
		while( i < size ) {
			window->Draw( graphics[ i ] );
			i++;
		}
	}
}
std::vector< sf::Shape > WSL::Components::VectorGraphicsComponent::GetGraphics() {
	return graphics;
}
sf::Shape WSL::Components::VectorGraphicsComponent::GetLine( unsigned int position )
{
	if( position >= 0 && position < graphics.size() )
		return graphics[ position ];
	else
	{
		std::cout << "You have attempted to accses a non-existant positionent" << std::endl;
		std::cout << "of the std::vector Graphics. A defult value has been returned." << std::endl;
		return sf::Shape();
	}
}
void WSL::Components::VectorGraphicsComponent::Link()
{
	representation.SetX( position.GetX() );
	representation.SetY( position.GetY() );
	representation = updator.Update( representation, true );
	representation.SetRotated( false );
	size = representation.GetPoints().size();
	graphics.clear();
	sf::Shape intermedaiteShape;
	for( unsigned int i = 0; i < size; ++i )
	{
		if( i < size - 1 )
			intermedaiteShape = sf::Shape::Line( representation.GetPoint( i ).GetX(), representation.GetPoint( i ).GetY(), representation.GetPoint( i + 1 ).GetX(), representation.GetPoint( i + 1 ).GetY(), thickness, color, outline, outlineColor );
		else
			intermedaiteShape = sf::Shape::Line( representation.GetPoint( i ).GetX(), representation.GetPoint( i ).GetY(), representation.GetPoint( 0 ).GetX(), representation.GetPoint( 0 ).GetY(), thickness, color, outline, outlineColor );
		graphics.push_back( intermedaiteShape );
	}
}
void WSL::Components::VectorGraphicsComponent::Reload( std::string directory ) {
	representation = scanAreaInitializer.SetPointCoordinates( representation, directory );
	representation.SetInitialized( true );
}
void WSL::Components::VectorGraphicsComponent::Rotate( float Degrees ) {
	representation = rotationCalculator.DegreeRotation( representation, Degrees );
	Link();
}
void WSL::Components::VectorGraphicsComponent::SetRotation( float degree ) {
	float td = degree - representation.GetRotation();
	Rotate( td );
}
void WSL::Components::VectorGraphicsComponent::SetPosition( float x, float y )
{
	representation.SetX( x );
	representation.SetY( y );
	position.SetX( x );
	position.SetY( y );
}
void WSL::Components::VectorGraphicsComponent::SetPosition( float x, float y, float z )
{
	representation.SetX( x );
	representation.SetY( y );
	representation.SetZ( z );
	position.SetX( x );
	position.SetY( y );
	position.SetZ( z );
}
void WSL::Components::VectorGraphicsComponent::SetPosition( WSL::Containers::Base::XYZ position )
{
	representation.SetX( position.GetX() );
	representation.SetY( position.GetY() );
	representation.SetZ( position.GetZ() );
	position = position;
}
WSL::Components::VectorGraphicsComponent::VectorGraphicsComponent() {
}
void WSL::Components::VectorGraphicsComponent::Initialize( std::string file )
{
	builder = new WSL::Collision::ScanAreaCollision::Builder;
	thickness = 1;
	outline = 1;
	scale = false;
	outlineColor = sf::Color( 100, 100, 100 );
	color = sf::Color( 100, 200, 100 );
	Math::Vector::VectorCalculator* temp = new Math::Vector::VectorCalculator;
	builder->SetCalculator( temp );
	Reload( file );
}
void WSL::Components::VectorGraphicsComponent::CleanUp() {
	delete builder;
}

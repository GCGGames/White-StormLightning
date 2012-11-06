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
#include "Render Layer.h"
//bool WSL::Algorithmic::RenderLayer::GetActive() {
//	return active;
//}
std::string WSL::Algorithmic::RenderLayer::GetName() {
	return name;
}
//void WSL::Algorithmic::RenderLayer::SetActive( bool active_ ) {
//	active = active_;
//}
void WSL::Algorithmic::RenderLayer::SetName( std::string name_ ) {
	name = name_;
}

/*
WSL::Algorithmic::RenderLayer::~RenderLayer()
{
	std::cerr << "ASDSAD\n";
	while( toRender.size() > 0 )
	{
		RFINDER *temp = toRender[ 0 ];
		toRender.erase( toRender.begin() );
		delete temp;
	}
}
void WSL::Algorithmic::RenderLayer::IndexRender( unsigned int render, std::string type )
{
	if( render < refrence->engine->renders.size() )
	{
		std::cerr << "(((((0)))))\n";
		RFINDER *finder;
		std::cerr << "(((((1)))))\n";
		finder = new RFINDER;
		unsigned int element = toRender.size();
		std::cerr << "(((((2)))))\n";
		finder->originalElement = render;
		std::cerr << "(((((3)))))\n";
		finder->type = type;
		std::cerr << "(((((4)))))\n";
		finder->renderRefrence = refrence->engine->renders[ render ]->GetOriginalPointer();
		std::cerr << "(((((5)))))\n";
		toRender.push_back( finder );
		std::cerr << "(((((6)))))\n";
		toRender[ element ]->GetReg()->AddParent( &toRender[ element ] );
		std::cerr << "(((((7)))))\n";
	}
	else
		std::cerr << "You can not add a render that does not exist!\n";
}
void WSL::Algorithmic::RenderLayer::UnIndexRender( unsigned int render, std::string type )
{
	if( type == "Lightning Sprite" )
		SearchAndDestroy( render, type );
	if( type == "Polygon" )
		SearchAndDestroy( render, type );
	if( type == "Vector Graphic" )
		SearchAndDestroy( render, type );
}
void WSL::Algorithmic::RenderLayer::Render( sf::RenderWindow *window )
{
	std::vector< unsigned int > index;
	for( unsigned int i = 0; i < toRender.size(); ++i ) {
		if( toRender[ i ] == NULL )
			index.push_back( i );
	}
	for( unsigned int i = 0; i < index.size(); ++i )
	{
		if( toRender.size() == 0 )
			return;
		RFINDER *temp = toRender[ index[ i ] ];
		toRender.erase( toRender.begin() + index[ i ] );
		delete temp;
	}
	WSL::Algorithmic::BubbleSortAlgorithm( &toRender );
	for( unsigned int i = 0; i < toRender.size(); ++i )
	{
		WSL::Components::Rendering_System::Base::Render_Functonal *temp = *toRender[ i ]->renderRefrence;
		if( temp != NULL && temp != 0 )
			temp->Draw( window );
	}
}
*/
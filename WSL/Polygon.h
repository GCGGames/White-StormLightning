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
#include "SFML Type.h"
namespace WSL
{
	namespace Components
	{
		class Polygon : public WSL::Components::Rendering_System::Base::SubBase::SFMLType< sf::Shape >
		{
			std::vector< WSL::Containers::Base::XYZ > shapepoints;
		public:
			void SetColor( sf::Color Color ) {
				t.SetColor( Color );
			}
			void SetColor( WSL::Containers::Scripting::Lua::ColorWrap color_ ) {
				t.SetColor( color_.GetColor() );
			}
			void AddPoint( float x, float y ) {
				t.AddPoint( x, y );
				shapepoints.push_back( WSL::Containers::Base::XYZ( x, y, position.GetZ() ) );
			}
			void AddPoint( float x, float y, float z ) {
				t.AddPoint( x, y );
				shapepoints.push_back( WSL::Containers::Base::XYZ( x, y, z ) );
			}
			void AddPoint( WSL::Containers::Base::XYZ point ) {
				t.AddPoint( point.GetX(), point.GetY() );
				shapepoints.push_back( point );
			}
			void SetPointColor( sf::Color Color, unsigned int point )
			{
				if( WSL::Algorithmic::BoolRangeCheck( point, shapepoints.size() ) == true )
					t.SetPointColor( point, Color );
				else
				{
					std::cout << "You have attempted to accses a non-existant point" << std::endl;
					std::cout << "in method ''SetPointColor'' in WSL::Components::Polygon." << std::endl;
					std::cout << "Please attempt to remain within the vector subscript range." << std::endl;
				}
			}
			void SetPointColor( WSL::Containers::Scripting::Lua::ColorWrap color_, unsigned int point )
			{
				if( WSL::Algorithmic::BoolRangeCheck( point, shapepoints.size() ) == true )
					t.SetPointColor( point, color_.GetColor() );
				else
				{
					std::cout << "You have attempted to accses a non-existant point" << std::endl;
					std::cout << "in method ''SetPointColor'' in WSL::Components::Polygon." << std::endl;
					std::cout << "Please attempt to remain within the vector subscript range." << std::endl;
				}
			}
			void SetPointOutlineColor( sf::Color Color, unsigned int point )
			{
				if( WSL::Algorithmic::BoolRangeCheck( point, shapepoints.size() ) == true )
					t.SetPointOutlineColor( point, Color );
				else
				{
					std::cout << "You have attempted to accses a non-existant point" << std::endl;
					std::cout << "in method ''SetPointOutlineColor'' in WSL::Components::Polygon." << std::endl;
					std::cout << "Please attempt to remain within the vector subscript range." << std::endl;
				}
			}
			void SetPointOutlineColor( WSL::Containers::Scripting::Lua::ColorWrap color_, unsigned int point )
			{
				if( WSL::Algorithmic::BoolRangeCheck( point, shapepoints.size() ) == true )
					t.SetPointOutlineColor( point, color_.GetColor() );
				else
				{
					std::cout << "You have attempted to accses a non-existant point" << std::endl;
					std::cout << "in method ''SetPointOutlineColor'' in WSL::Components::Polygon." << std::endl;
					std::cout << "Please attempt to remain within the vector subscript range." << std::endl;
				}
			}
		};
	}
}
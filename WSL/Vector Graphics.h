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
namespace WSL
{
	namespace Components
	{
		class Vector_Graphics : public WSL::Components::Rendering_System::Base::Render_Base<WSL::Components::VectorGraphicsComponent>
		{
			bool delete_;
		public:
			inline Vector_Graphics( std::string file )
			{
				t.Initialize( file );
			}
			inline Vector_Graphics()
			{
			}
			inline void AddPoint( float x, float y )
			{
				t.AddPoint( x, y );
			}
			inline void AddPoint( float x, float y, float z )
			{
				t.AddPoint( x, y, z );
			}
			inline void AddPoint( WSL::Containers::Base::XYZ point )
			{
				t.AddPoint( point );
			}
			inline void DeletePoint( unsigned int Elem )
			{
				t.DeletePoint( Elem );
			}
			inline void Clear()
			{
				t.Clear();
			}
			inline void Build()
			{
				t.Build();
			}
			void SetPosition( float x, float y )
			{
				t.SetPosition( x, y );
			}
			void SetPosition( float x, float y, float z )
			{
				t.SetPosition( x, y, z );
			}
			void SetPosition( WSL::Containers::Base::XYZ Position )
			{
				t.SetPosition( Position );
			}
			void Rotate( float Degree )
			{
				t.Rotate( Degree );
			}
			void SetRotation( float degree )
			{
				t.SetRotation( degree );
			}
			void Draw( sf::RenderWindow *window )
			{
				t.Draw( window );
			}
			void setColor( sf::Color color_ )
			{
				color = color;
				t.setColor( color );
			}
			void setColor( WSL::Containers::Scripting::Lua::ColorWrap color_ )
			{
				color = color_.GetColor();
				t.setColor( color );
			}
		};
	}
}
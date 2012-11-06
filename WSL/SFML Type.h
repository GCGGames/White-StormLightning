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
#include "Vector Graphics.h"
namespace WSL
{
	namespace Components
	{
		namespace Rendering_System
		{		
			namespace Base
			{
				namespace SubBase
				{
					template<typename sfmlType>
					class SFMLType : public WSL::Components::Rendering_System::Base::Render_Base<sfmlType>
					{
					public:
						inline void SetRotation( float degree )
						{
							t.SetRotation( degree );
						}
						inline void SetCenter( float x, float y )
						{
							t.SetCenter( x, y );
						}
						inline void SetCenter( WSL::Containers::Base::XYZ center )
						{
							t.SetCenter( center.getX(), center.getY() );
						}
						void Draw( sf::RenderWindow *window )
						{
							window->Draw( t );
						}
						inline void SetPosition( float x, float y )
						{
							t.SetPosition( x, y );
							position.setX( x );
							position.setY( y );
						}
						inline void SetPosition( float x, float y, float z )
						{
							t.SetPosition( x, y );
							position.setX( x );
							position.setY( y );
							position.setZ( z );
						}
						inline void SetPosition( WSL::Containers::Base::XYZ Position )
						{
							t.SetPosition( Position.getX(), Position.getY() );
							position = Position;
						}
						inline void Scale( float x, float y )
						{
							t.Scale( x, y );
						}
						inline void Scale( float value )
						{
							t.Scale( value, value );
						}
						inline void Rotate( float degree )
						{
							t.Rotate( degree );
						}
					};
				}
			}
		}
	}
}

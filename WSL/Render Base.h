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
#include "Render Functonal.h"
namespace WSL
{
	namespace Components
	{
		namespace Rendering_System
		{
			namespace Base
			{
				template< typename T >
				class Render_Base : public RenderFunctonal
				{
				protected:
					T t;
					float scaleX, scaleY;
					bool draw;
				public:
					Render_Base() {
						InitializeRB();
					}
					inline void SetDraw( bool draw_ ) {
						draw = draw_;
					}
					inline bool GetDraw() {
						return draw;
					}
					inline void InitializeRB()
					{
						render = true;
						scaleToZ = false;
						scaleX = 1.f;
						scaleY = 1.f;
						color = sf::Color( 100, 100, 100 );
						position.SetX( 0 );
						position.SetY( 0 );
					}
					inline T GetComponent() {
						return t;
					}
					inline void SetComponent( T value ) {
						t = value;
					}
				};
			}
		}
	}
}
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
#include "Image Library.h"
namespace WSL
{
	namespace Components
	{
		class VectorGraphicsComponent : public WSL::Components::Rendering_System::Base::Render_Functonal
		{
			std::vector<sf::Shape> graphics;
			Collision::Scan_Area_Collision::Scan_Area representation;
			unsigned int i, size;
			float thickness, outline;
			sf::Color outlineColor;
			bool Scale;
			Collision::Scan_Area_Collision::Initializer I;
			Collision::Scan_Area_Collision::Builder *B;
			Collision::Scan_Area_Collision::Rotation_Calculator R;
			Collision::Scan_Area_Collision::Updator U;
		public:
			VectorGraphicsComponent( std::string file );
			VectorGraphicsComponent();
			void Initialize( std::string file );
			void AddPoint( float x, float y );
			void AddPoint( float x, float y, float z );
			void AddPoint( WSL::Containers::Base::XYZ Position );
			void DeletePoint( unsigned int Elem );
			void Clear();
			void SetPosition( float x, float y );
			void SetPosition( float x, float y, float z );
			void SetPosition( WSL::Containers::Base::XYZ Position );
			void Reload( std::string directory );
			void Build();
			sf::Shape getLine( unsigned int Elem );
			std::vector<sf::Shape> getGraphics();
			void Link();
			void Draw( sf::RenderWindow *window );
			void Rotate( float Degrees );
			void SetRotation( float degree );
			void CleanUp();
		};
	}
}
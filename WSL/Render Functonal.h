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
#include "Main Lua.h"
namespace WSL
{
	namespace Components
	{
		namespace Rendering_System
		{
			namespace Base
			{
				//TO DO: Add "Set Scale" method along with overloads.//
				class Render_Functonal : public WSL::Components::Base::Component
				{
				public:
					virtual void Rotate( float degree )
					{
					}
					virtual void SetRotation( float degree )
					{
					}
					virtual void SetPosition( float x, float y, float z )
					{
						position.setX( x );
						position.setY( y );
						position.setZ( z );
					}
					virtual void SetPosition( float x, float y )
					{
						position.setX( x );
						position.setY( y );
					}
					virtual void Draw( sf::RenderWindow *window )
					{
					}
					virtual void SetPosition( WSL::Containers::Base::XYZ Coords )
					{
						position = Coords;
					}
					virtual void Scale( float x, float y )
					{
					}
					virtual void Scale( float value )
					{
					}
					virtual void Scale_To_Z()
					{
					}
					virtual void Link( float X, float Y, float XScale, float YScale, float Rotation )
					{
					}
					virtual void Refresh_Componet()
					{
					}
					virtual void Implement_Script( char* Directory )
					{
					}
					inline void setColor( sf::Color Color )
					{
						color = Color;
					}
					inline void setColor( WSL::Containers::Scripting::Lua::ColorWrap color_ )
					{
						color = color_.GetColor();
					}
					inline sf::Color getColor()
					{
						return color;
					}
					inline WSL::Containers::Base::XYZ getPosition()
					{
						return position;
					}
					inline float getX()
					{
						return position.getX();
					}
					inline float getY()
					{
						return position.getY();
					}
					inline float getZ()
					{
						return position.getZ();
					}
					inline bool getRender()
					{
						return render;
					}
					inline bool getScale_To_Z()
					{
						return scale_to_z;
					}
					inline void setX( float Value )
					{
						position.setX( Value );
					}
					inline void setY( float Value )
					{
						position.setY( Value );
					}
					inline void setZ( float Value )
					{
						position.setZ( Value );
					}
					inline void setRender( bool Value )
					{
						render = Value;
					}
					inline void setScale_To_Z( bool Value )
					{
						scale_to_z = Value;
					}/*
					void AddParent( WSL::Containers::Finder< Render_Functonal > **newParent ) {
						parent = newParent;
					}
					void SetParentsToNULL() {
						*parent = NULL;
					}
					void SetOriginalPointer( Render_Functonal **originalPointer_ ) {
						originalPointer = originalPointer_;
					}
					Render_Functonal** GetOriginalPointer() {
						return originalPointer;
					}*/
					std::string GetRenderLayerName() {
						return renderLayerName;
					}
					void SetRenderLayerName( std::string renderLayerName_ ) {
						renderLayerName = renderLayerName_;
					}
				protected:
					//Render_Functonal **originalPointer;
					WSL::Containers::Base::XYZ position;
					bool scale_to_z;
					bool render;
					sf::Color color;
					std::string dir;
					//WSL::Containers::Finder< Render_Functonal >** parent;
					std::string renderLayerName;
				};
			}
		}
	}
}
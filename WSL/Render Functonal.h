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
				class RenderFunctonal : public WSL::Components::Base::Component
				{
					public:
						virtual void Rotate( float degree ) {
						}
						virtual void SetRotation( float degree ) {
						}
						virtual void SetPosition( float x, float y, float z )
						{
							position.SetX( x );
							position.SetY( y );
							position.SetZ( z );
						}
						virtual void SetPosition( float x, float y ) {
							position.SetX( x );
							position.SetY( y );
						}
						virtual void Draw( sf::RenderWindow* window ) {
						}
						virtual void SetPosition( WSL::Containers::Base::XYZ position_ ) {
							position = position_;
						}
						virtual void Scale( float x, float y ) {
						}
						virtual void Scale( float value ) {
						}
						virtual void ScaleToZ() {
						}
						virtual void Link( float x, float y, float xScale, float yScale, float rotation ) {
						}
						virtual void RefreshComponet() {
						}
						virtual void ImplementScript( char* Directory ) {
						}
						inline void SetColor( sf::Color color_ ) {
							color = color_;
						}
						inline void SetColor( WSL::Containers::Scripting::Lua::ColorWrap color_ ) {
							color = color_.GetColor();
						}
						inline sf::Color GetColor() {
							return color;
						}
						inline WSL::Containers::Base::XYZ GetPosition() {
							return position;
						}
						inline float GetX() {
							return position.GetX();
						}
						inline float GetY() {
							return position.GetY();
						}
						inline float GetZ() {
							return position.GetZ();
						}
						inline bool GetRender() {
							return render;
						}
						inline bool GetScaleToZ() {
							return scaleToZ;
						}
						inline void SetX( float value ) {
							position.SetX( value );
						}
						inline void SetY( float value ) {
							position.SetY( value );
						}
						inline void SetZ( float value ) {
							position.SetZ( value );
						}
						inline void SetRender( bool render_ ) {
							render = render_;
						}
						inline void SetScaleToZ( bool scaleToZ_ ) {
							scaleToZ = scaleToZ_;
						}
						std::string GetRenderLayerName() {
							return renderLayerName;
						}
						void SetRenderLayerName( std::string renderLayerName_ ) {
							renderLayerName = renderLayerName_;
						}
					protected:
						WSL::Containers::Base::XYZ position;
						bool scaleToZ;
						bool render;
						sf::Color color;
						std::string dir;
						std::string renderLayerName;
				};
			}
		}
	}
}

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
#include "Camera.h"
void WSL::Global::Camera::SetX( float x_ )
{
	x = x_;
}
void WSL::Global::Camera::SetY( float y_ )
{
	y = y_;
}
void WSL::Global::Camera::SetZ( float z_ )
{
	z = z_;
}
void WSL::Global::Camera::SetWidth( float width_ )
{
	width = width_;
}
void WSL::Global::Camera::SetHeight( float height_ )
{
	height = height_;
}
void WSL::Global::Camera::SetDepth( float depth_ )
{
	depth = depth_;
}
void WSL::Global::Camera::SetCamera( sf::View *camera_ )
{
	camera = camera_;
}
float WSL::Global::Camera::GetX()
{
	return x;
}
float WSL::Global::Camera::GetY()
{
	return y;
}
float WSL::Global::Camera::GetZ()
{
	return z;
}
float WSL::Global::Camera::GetWidth()
{
	return width;
}
float WSL::Global::Camera::GetHeight()
{
	return height;
}
float WSL::Global::Camera::GetDepth()
{
	return depth;
}
sf::View* WSL::Global::Camera::GetCamera()
{
	return camera;
}
void WSL::Global::Camera::Zoom( float zOffset )
{
	z += zOffset;
	//Scale zooming will come later.//
}
void WSL::Global::Camera::SetZoom( float z_ )
{
	z -= z_;
	//Scale zooming will come later.//
}
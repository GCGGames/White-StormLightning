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
#include "Input.h"
WSL::Global::Input::Input( WSL::Global::Camera *camera, WSL::Engine* refrence_ )
{
	cameraX = camera->x;
	cameraY = camera->y;
	cameraZ = camera->z;
	sf::Event event_;
	refrence = refrence_;
	while( refrence->window->GetEvent( event_ ) )
	{
		xMouseChange = refrence->window->GetInput().GetMouseX();
		yMouseChange = refrence->window->GetInput().GetMouseY();
		break;
	}
	//TODO: Why...//
	size = 102;
	Map();
}
WSL::Global::Input::Input()
{
}
void WSL::Global::Input::Frame()
{
	i = 0;
	while( i < size ) {
		keys[ i ].SetKey( false );
		i++;
	}
	i = 0;
	sf::Event event_;
	while( refrence->window->GetEvent( event_ ) )
	{
		if( refrence->window->GetInput().IsKeyDown( sf::Key::A ) )
			keys[ 0 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::B ) )
			keys[ 1 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::C ) )
			keys[ 2 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::D ) )
			keys[ 3 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::E ) )
			keys[ 4 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F ) )
			keys[ 5 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::G ) )
			keys[ 6 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::H ) )
			keys[ 7 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::I ) )
			keys[ 8 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::J ) )
			keys[ 9 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::K ) )
			keys[ 10 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::L ) )
			keys[ 11 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::M ) )
			keys[ 12 ].SetKey( true );
		//I still have no idea why, but this generates a compiler error.//
	//	if( refrence->window->GetInput().IsKeyDown( sf::Key::N ) )
	//		keys[ 13 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::O ) )
			keys[ 14 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::P ) )
			keys[ 15 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Q ) )
			keys[ 16 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::R ) )
			keys[ 17 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::S ) )
			keys[ 18 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::T ) )
			keys[ 19 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::U ) )
			keys[ 20 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::V ) )
			keys[ 21 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::W ) )
			keys[ 22 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::X ) )
			keys[ 23 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Y ) )
			keys[ 24 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Z ) )
			keys[ 25 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num0 ) )
			keys[ 26 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num1 ) )
			keys[ 27 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num2 ) )
			keys[ 28 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num3 ) )
			keys[ 29 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num4 ) )
			keys[ 30 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num5 ) )
			keys[ 31 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num6 ) )
			keys[ 32 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num7 ) )
			keys[ 33 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num8 ) )
			keys[ 34 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Num9 ) )
			keys[ 35 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Escape ) )
			keys[ 36 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::LControl ) )
			keys[ 37 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::LShift ) )
			keys[ 38 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::LAlt ) )
			keys[ 39 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::LSystem ) )
			keys[ 40 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::RControl ) )
			keys[ 41 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::RShift ) )
			keys[ 42 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::RAlt ) )
			keys[ 43 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::RSystem ) )
			keys[ 44 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Menu ) )
			keys[ 45 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::LBracket ) )
			keys[ 46 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::RBracket ) )
			keys[ 47 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::SemiColon ) )
			keys[ 48 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Comma ) )
			keys[ 49 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Period ) )
			keys[ 50 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Quote ) )
			keys[ 51 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Slash ) )
			keys[ 52 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::BackSlash ) )
			keys[ 53 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Tilde ) )
			keys[ 54 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Equal ) )
			keys[ 55 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Dash ) )
			keys[ 56 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Space ) )
			keys[ 57 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Return ) )
			keys[ 58 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Back ) )
			keys[ 59 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Tab ) )
			keys[ 60 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::PageUp ) )
			keys[ 61 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::PageDown ) )
			keys[ 62 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::End ) )
			keys[ 63 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Home) )
			keys[ 64 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Insert ) )
			keys[ 65 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Delete ) )
			keys[ 66 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Add ) )
			keys[ 67 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Subtract ) )
			keys[ 68 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Multiply ) )
			keys[ 69 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Divide ) )
			keys[ 70 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Left ) )
			keys[ 71 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Right ) )
			keys[ 72 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Up ) )
			keys[ 73 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Down ) )
			keys[ 74 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad0 ) )
			keys[ 75 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad1 ) )
			keys[ 76 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad2 ) )
			keys[ 77 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad3 ) )
			keys[ 78 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad4 ) )
			keys[ 79 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad5 ) )
			keys[ 80 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad6 ) )
			keys[ 81 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad7 ) )
			keys[ 82 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad8 ) )
			keys[ 83 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Numpad9 ) )
			keys[ 84 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F1 ) )
			keys[ 85 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F2 ) )
			keys[ 86 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F3 ) )
			keys[ 87 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F4 ) )
			keys[ 88 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F5 ) )
			keys[ 89 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F6 ) )
			keys[ 90 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F7 ) )
			keys[ 91 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F8 ) )
			keys[ 92 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F9 ) )
			keys[ 93 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F10 ) )
			keys[ 94 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F11 ) )
			keys[ 95 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F12 ) )
			keys[ 96 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F13 ) )
			keys[ 97 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F14 ) )
			keys[ 98 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::F15 ) )
			keys[ 99 ].SetKey( true );
		if( refrence->window->GetInput().IsKeyDown( sf::Key::Pause ) )
			keys[ 100 ].SetKey( true );
		break;
	}
}
bool WSL::Global::Input::IsKeyDown( std::string key )
{
	i = 0;
	while( i < size )
	{
		if( keys[ i ].GetName() == key )
			return keys[ i ].GetKey();
		i++;
	}
	return false;
}
WSL::Containers::Base::XYZ WSL::Global::Input::GetMousePosition()
{
	return WSL::Containers::Base::XYZ( ( float ) refrence->window->GetInput().GetMouseX(), 
	( float ) refrence->window->GetInput().GetMouseY(), 
	( float ) cameraZ );
}
bool WSL::Global::Input::GetMouseClick( std::string button )
{
	sf::Event E;
	while( refrence->window->GetEvent( E ) )
	{
		if( button == "Left Button" ) {
			if( refrence->window->GetInput().IsMouseButtonDown( sf::Mouse::Left ) )
				return ( true );
		}
		else
		{
			if( button == "Right Button" ) {
				if( refrence->window->GetInput().IsMouseButtonDown( sf::Mouse::Right ) )
				return ( true );
			}
			else if( button == "Middle" ) {
					if( refrence->window->GetInput().IsMouseButtonDown( sf::Mouse::Middle ) )
						return ( true );
			}
		}
		break;
	}
	return ( false );
}
int WSL::Global::Input::GetMouseEvent( std::string mouseEvent )
{
	sf::Event E;
	int x, y;
	x = 0;
	y = x;
	while( refrence->window->GetEvent( E ) )
	{
		if( mouseEvent == "Wheel" ) {
			return E.MouseWheel.Delta;
			break;
		}
		if( mouseEvent == "X - Change" ) {
			x = E.MouseMove.X - xMouseChange;
			break;
		}
		if( mouseEvent == "Y - Change" ) {
			y = E.MouseMove.Y - yMouseChange;
			break;
		}
		break;
	}
	xMouseChange = E.MouseMove.X;
	yMouseChange = E.MouseMove.Y;
	if( x < 0 )
		x *= -1;
	if( y < 0 )
		y *= -1;
	x += ( int ) cameraX;
	y += ( int ) cameraY;
	if( mouseEvent == "X - Change" )
		return x;
	if( mouseEvent == "Y - Change" )
		return y;
	return 0;
}

void WSL::Global::Input::Map()
{
	while( keys.size() < 103 )
	{
		WSL::Containers::Key k( true );
		keys.push_back( k );
	}
	keys[ 0 ].SetName( "a" );
	keys[ 1 ].SetName( "b" );
	keys[ 2 ].SetName( "c" );
	keys[ 3 ].SetName( "d" );
	keys[ 4 ].SetName( "e" );
	keys[ 5 ].SetName( "f" );
	keys[ 6 ].SetName( "g" );
	keys[ 7 ].SetName( "h" );
	keys[ 8 ].SetName( "i" );
	keys[ 9 ].SetName( "j" );
	keys[ 10 ].SetName( "k" );
	keys[ 11 ].SetName( "l" );
	keys[ 13 ].SetName( "m" );
	keys[ 14 ].SetName( "n" );
	keys[ 15 ].SetName( "o" );
	keys[ 16 ].SetName( "q" );
	keys[ 17 ].SetName( "r" );
	keys[ 18 ].SetName( "s" );
	keys[ 19 ].SetName( "t" );
	keys[ 20 ].SetName( "u" );
	keys[ 21 ].SetName( "v" );
	keys[ 22 ].SetName( "w" );
	keys[ 23 ].SetName( "x" );
	keys[ 24 ].SetName( "y" );
	keys[ 25 ].SetName( "z" );
	keys[ 26 ].SetName( "Num0" );
	keys[ 27 ].SetName( "Num1" );
	keys[ 28 ].SetName( "Num2" );
	keys[ 29 ].SetName( "Num3" );
	keys[ 30 ].SetName( "Num4" );
	keys[ 31 ].SetName( "Num5" );
	keys[ 32 ].SetName( "Num6" );
	keys[ 33 ].SetName( "Num7" );
	keys[ 34 ].SetName( "Num8" );
	keys[ 35 ].SetName( "Num9" );
	keys[ 36 ].SetName( "Escape" );
	keys[ 37 ].SetName( "Left Control" );
	keys[ 38 ].SetName( "Left Shift" );
	keys[ 39 ].SetName( "Left Alternate" );
	keys[ 40 ].SetName( "Left System" );
	keys[ 41 ].SetName( "Right Control" );
	keys[ 42 ].SetName( "Right Shift" );
	keys[ 43 ].SetName( "Right Alternate" );
	keys[ 44 ].SetName( "Right System" );
	keys[ 45 ].SetName( "Menu" );
	keys[ 46 ].SetName( "Left Bracket" );
	keys[ 47 ].SetName( "Right Bracket" );
	keys[ 48 ].SetName( "Semi Colon" );
	keys[ 49 ].SetName( "Comma" );
	keys[ 50 ].SetName( "Period" );
	keys[ 51 ].SetName( "Quote" );
	keys[ 52 ].SetName( "Slash" );
	keys[ 53 ].SetName( "Back Slash" );
	keys[ 54 ].SetName( "Tilde" );
	keys[ 55 ].SetName( "Equal" );
	keys[ 56 ].SetName( "Dash" );
	keys[ 57 ].SetName( "Space" );
	keys[ 58 ].SetName( "Return" );
	keys[ 59 ].SetName( "Back" );
	keys[ 60 ].SetName( "Tab" );
	keys[ 61 ].SetName( "Page Up" );
	keys[ 62 ].SetName( "Page Down" );
	keys[ 63 ].SetName( "End" );
	keys[ 64 ].SetName( "Home" );
	keys[ 65 ].SetName( "Insert" );
	keys[ 66 ].SetName( "Delete" );
	keys[ 67 ].SetName( "Add" );
	keys[ 68 ].SetName( "Subtract" );
	keys[ 69 ].SetName( "Multiply" );
	keys[ 70 ].SetName( "Divide" );
	keys[ 71 ].SetName( "Left" );
	keys[ 72 ].SetName( "Right" );
	keys[ 73 ].SetName( "Up" );
	keys[ 74 ].SetName( "Down" );
	keys[ 75 ].SetName( "Numpad0" );
	keys[ 76 ].SetName( "Numpad1" );
	keys[ 77 ].SetName( "Numpad2" );
	keys[ 78 ].SetName( "Numpad3" );
	keys[ 79 ].SetName( "Numpad4" );
	keys[ 80 ].SetName( "Numpad5" );
	keys[ 81 ].SetName( "Numpad6" );
	keys[ 82 ].SetName( "Numpad7" );
	keys[ 83 ].SetName( "Numpad8" );
	keys[ 84 ].SetName( "Numpad9" );
	keys[ 85 ].SetName( "F1" );
	keys[ 86 ].SetName( "F2" );
	keys[ 87 ].SetName( "F3" );
	keys[ 88 ].SetName( "F4" );
	keys[ 89 ].SetName( "F5" );
	keys[ 90 ].SetName( "F6" );
	keys[ 91 ].SetName( "F7" );
	keys[ 92 ].SetName( "F8" );
	keys[ 93 ].SetName( "F9" );
	keys[ 94 ].SetName( "F10" );
	keys[ 95 ].SetName( "F11" );
	keys[ 96 ].SetName( "F12" );
	keys[ 97 ].SetName( "F13" );
	keys[ 98 ].SetName( "F14" );
	keys[ 99 ].SetName( "F15" );
	keys[ 100 ].SetName( "Pause" );
}
void WSL::Global::Input::Update( WSL::Global::Camera *camera )
{
	cameraX = camera->x;
	cameraY = camera->y;
	cameraZ = camera->z;
}
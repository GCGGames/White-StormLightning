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
#include "White Storm Lightning.h"

/*
(To fix later) To Do: 
	* : Make render layers more accsessable to lua and
	have more encapsulation.
	* : FIX SCAN AREA TRANSFORMS!!!!
	* : Scale zooming.
	* : Fix rotation on vector graphics.
*/
/*
(To do in beta short term) To Do: 
	* : Text.
*/
void main()
{
	system( "PAUSE" );
	WSL::externalRegister = false;
	WSL::ExternalLuaRegister = NULL;
	WSL::ExternalRegister = NULL;
	WSL::ExecuteWhiteStormLightning();
}
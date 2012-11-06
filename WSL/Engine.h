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
#include "Renders.h"
namespace WSL
{
	struct Engine : public WSL::Base::EngineBase
	{
		inline Engine( bool null )
		{
			lua = new WSL::Containers::Scripting::Lua_Container;
			imageLibrary = new WSL::Global::Image_Library;
			luaContainer = new WSL::Containers::Scripting::LuaState;
			WSL::Math::Vector::VectorCalculator *temp = new WSL::Math::Vector::VectorCalculator;
			Constructor.setCalculator( temp );
		}
		inline Engine()
		{
		}
		~Engine()
		{
			delete imageLibrary;
			delete luaContainer;
			delete lua;
		}
		void (*luaRegister)(void);
		sf::RenderWindow *window;
		WSL::Algorithmic::ObjectTracker objectTracker;
		WSL::Containers::Scripting::Lua_Container *lua;
		std::vector< WSL::Components::Rendering_System::Base::Render_Functonal* > renders;
		WSL::Global::Stack<WSL::Collision::Scan_Area_Collision::Scan_Area*> scanAreas;
	};
}
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
#include "Lightning Sprite.h"
namespace WSL
{
	struct Engine : public WSL::Base::EngineBase
	{
		inline Engine( bool null )
		{
			lua = new WSL::Containers::Scripting::LuaContainer;
			imageLibrary = new WSL::Global::ImageLibrary;
			luaContainer = new WSL::Containers::Scripting::LuaState;
			WSL::Math::Vector::VectorCalculator* temp = new WSL::Math::Vector::VectorCalculator;
			constructor.SetCalculator( temp );
		}
		inline Engine() {
		}
		~Engine()
		{
			delete imageLibrary;
			delete luaContainer;
			delete lua;
		}
		void (* luaRegister )();
		sf::RenderWindow* window;
		WSL::Algorithmic::ObjectTracker objectTracker;
		WSL::Containers::Scripting::LuaContainer* lua;
		std::vector< WSL::Components::Rendering_System::Base::RenderFunctonal* > renders;
		WSL::Global::Stack< WSL::Collision::ScanAreaCollision::ScanArea* > scanAreas;
	};
}
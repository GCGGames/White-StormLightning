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
#include "Positional.h"
namespace WSL
{
	namespace Framework
	{
		namespace Standard
		{
			class Mobile : public WSL::Framework::Standard::Positional
			{
			protected:
				WSL::Containers::Scripting::Lua::LuaBindedType<bool> autoCalculate, autoMove;
				WSL::Containers::Math::Vector vector;
			public:
				Mobile( int obj_ID, bool Refresh, bool Destroy, bool initialize_, bool RDestroy,
							std::string refesh_Script, std::string initialize_Script, std::string destroy_Script,
							std::string other_Script, std::string physicalBehavior_, WSL::Engine *refrence );
				Mobile();
				~Mobile();
				void Calculate();
				bool GetAutoCalculate();
				bool GetAutoMove();
				WSL::Containers::Math::Vector GetVector();
				void SetAutoCalculate( bool autoCalculate_ );
				void SetAutoMove( bool autoMove_ );
				void SetDestination( WSL::Containers::Base::XYZ destination );
				void SetDestination( float x, float y, float z );
				void SetDestination( float x, float y );
				void SetDestination( float allCoords );
				virtual void SendToLua();
				virtual void SetPosition( float x, float y, float z );
				virtual void SetPosition( float x, float y );
				virtual void SetPosition( WSL::Containers::Base::XYZ position_ );
				void SetVector( WSL::Containers::Math::Vector vector_ );
				void Move();
				virtual void Initialize();
				virtual void Refresh();
				virtual void Destroy();
				void MobileInitialize();
				void MobileRefresh();
				void MobileDestroy();
				void MobileSend();
			};
		}
	}
}
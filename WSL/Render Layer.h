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
#include "Sub Singleton Base.h"
//TODO: //
/*////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////More encapsulation and accsessibility to lua will come later////////////////////////////
//////////////////as of now the project needs to get done, seeing as render layers////////////////////////
//////////////////are currently embeded into the engine and Lua I will return to them/////////////////////
//////////////////in the future and add the more nessasarry features./////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////*/
namespace WSL
{
	namespace Algorithmic
	{
		/*TO DO: 
			* : Add encapsulation to this struct.
			* : Fix "quick and dirty hack".
		*/
		
		typedef WSL::Containers::Finder< WSL::Components::Rendering_System::Base::RenderFunctonal > RFINDER;

		struct RenderLayer : public WSL::Algorithmic::Base::SubSingletonFoundation, public WSL::Algorithmic::BubbleSort
		{
			std::string GetName();
			void SetName( std::string name_ );
			protected:
				std::string name;
		};
	}
}
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
#include "Positional Translator.h"
WSL::DataTranslation::PositionalTranslator::PositionalTranslator() {
	componentID = 1;
}
void WSL::DataTranslation::PositionalTranslator::SendToLua( WSL::Framework::Standard::Base::BaseEntity* entity, WSL::Engine* engine ) {
	WSL::Framework::Standard::Positional* temp = dynamic_cast< WSL::Framework::Standard::Positional* >( entity );
	luabind::globals( engine->luaContainer->State )[ "object" ] = temp;
}
WSL::Framework::Standard::Base::BaseEntity* WSL::DataTranslation::PositionalTranslator::Instantiate( std::string standardScripts[ ], std::vector<std::string> otherScripts, unsigned int size, 
					bool initialize, bool refresh, bool destroy, bool destroyed, int objectID, WSL::Engine* engine )
{
	WSL::Framework::Standard::Positional* temp = new WSL::Framework::Standard::Positional( objectID, refresh, destroyed, initialize, destroy, standardScripts[ 1 ], 
		standardScripts[ 0 ], standardScripts[ 2 ], standardScripts[ 3 ], standardScripts[ 4 ], engine );
	temp->SendSelf = SendObject;
	unsigned int i = 0;
	if( size != 0 )
	{
		while( i < size )
		{
			temp->SetRefrence( engine );
			BaseSend();
			{
				WSL::Framework::Standard::Base::BaseEntity* base = &*temp;
				SendToLua( base, engine );
			}
			temp->RunScript( otherScripts[ i ] );
			temp->DeleteRefrence();
			i++;
		}
	}
	WSL::Framework::Standard::Base::BaseEntity* base = &*temp;
	return base;
}
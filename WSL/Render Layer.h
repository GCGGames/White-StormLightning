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
		
		typedef WSL::Containers::Finder< WSL::Components::Rendering_System::Base::Render_Functonal > RFINDER;

		struct RenderLayer : public WSL::Algorithmic::Base::SubSingletonFoundation, public WSL::Algorithmic::BubbleSort
		{
			//bool GetActive();
			std::string GetName();
			//void SetActive( bool active_ );
			void SetName( std::string name_ );
			protected:
				std::string name;
				//bool active;
			/*RenderLayer() {}
			~RenderLayer();
			void IndexRender( unsigned int render, std::string type );
			void UnIndexRender( unsigned int render, std::string type );
			void Render( sf::RenderWindow *window );
			protected:
				void SearchAndDestroy( unsigned int render, std::string type )
				{
					bool found = false;
					for( unsigned int i = 0; i < toRender.size(); ++i )
					{
						if( toRender[ i ]->type == type && toRender[ i ]->originalElement == render )
						{
							found = true;
							toRender.erase( toRender.begin() + i );
							break;
						}
					}
					if( found == false )
						std::cerr << "In method SearchAndDestroy( unsigned int render, std::string type ), no render of type " << type << "and original element " << render << "could be found.\n";
				}
				std::vector< RFINDER* > toRender;*/
		};
	}
}
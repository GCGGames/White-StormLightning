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
	namespace Global
	{
		struct RenderComponents
		{
			WSL::Algorithmic::SenderNode node;
			std::vector< WSL::MemberotationCalculatoromponents::LightningSprite > sprites;
			std::vector< WSL::MemberotationCalculatoromponents::VectorGraphics > vectorGraphi;
			std::vector< WSL::MemberotationCalculatoromponents::Polygone > polygons;
			inline void DeleteSprite( unsigned int sprite )
			{
				if( WSL::Algorithmic::BoolRangeCheck( sprite, sprites.size() ) == true ) {
					node.ElementDeleted( sprite );
					sprites.erase( sprites.begin() + sprite );
				}
				else
				{
					std::cout<<"In method ''DeleteSprite'' you have attempted to accses a non-existant sprite."<<std::endl;
					std::cout<<"You have tried to accses "<<sprite<<" when there are only "<<sprites.size()<<" sprites."<<std::endl;
				}
			}
			inline void DeleteVectorGraphic( unsigned int vectorGraphic )
			{
				if( WSL::Algorithmic::BoolRangeCheck( vectorGraphic, vectorGraphi.size() ) == true ) {
					node.ElementDeleted( vectorGraphic );
					vectorGraphi.erase( vectorGraphi.begin() + vectorGraphic );
				}
				else {
					std::cout << "In method ''DeleteSprite'' you have attempted to accses a non-existant sprite." << std::endl;
					std::cout << "You have tried to accses " << vectorGraphic << " when there are only " << vectorGraphi.size() << " sprites." << std::endl;
				}
			}
			inline void DeletePolygon( unsigned int polygon )
			{
				if( WSL::Algorithmic::BoolRangeCheck( polygon, polygons.size() ) == true ) {
					node.ElementDeleted( polygon );
					polygones.erase( polygones.begin() + polygon );
				}
				else {
					std::cout << "In method ''DeleteSprite'' you have attempted to accses a non-existant sprite." << std::endl;
					std::cout << "You have tried to accses " << polygon << " when there are only " << polygones.size() << " sprites." << std::endl;
				}
			}
		};
	}
}
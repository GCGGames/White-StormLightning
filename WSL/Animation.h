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
#include "All Animation Data.h"
//#include "Vector Movement.h"
//TO DO: Fix data transfer problem.//
namespace WSL
{
	namespace Components
	{
		namespace Algorithimic
		{
			class Animation : public WSL::Components::Algorithimic::Base::AnimationData
			{
				WSL::Components::Algorithimic::SubBase::AllAnimationData storage;
				WSL::Components::Algorithimic::SubBase::AllAnimationData Exchange( WSL::Components::Algorithimic::SubBase::AllAnimationData returner )
				{
					returner.SetAnimate( animate );
					returner.SetDelay( delay );
					returner.SetType( type );
					returner.SetCount( count );
					returner.SetFrame( frame );
					returner.SetIncrement( inc );
					returner.SetIntilized( init );
					return returner;
				}
			public:
				void AddImage( unsigned int image );
				Animation();
				unsigned int AnimateImages( bool firstToLast );
				sf::IntRect AnimateSheet( bool firstToLast );
				void DeleteImage( unsigned int image );
				WSL::Components::Algorithimic::SubBase::AllAnimationData GatherData();
				void ReplaceData( WSL::Components::Algorithimic::SubBase::AllAnimationData data );
				void Reset();
				void Restore();
				void SetUpSpriteSheet( int Sprite_Width, int Sprite_Height, int Sprite_X, int Sprite_Y, int Offset_X, int Offset_Y, int Param_Width, int Param_Height, bool Change_X, bool Change_Y );
				void SetUpSpriteSheet( int Sprite_Width, int Sprite_Height, int Offset_X, int Offset_Y, int Param_Width, int Param_Height, bool Change_X, bool Change_Y );
			};
		}
	}
}
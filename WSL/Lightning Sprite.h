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
#include "Engine Base.h"
namespace WSL
{
	namespace Components
	{
		class LightningSprite : public WSL::Components::Rendering_System::Base::SubBase::SFMLType< sf::Sprite >
		{
			unsigned int image;
			std::vector< unsigned int > animations;
			WSL::Algorithmic::ReceiverNode node;
			unsigned int currentAnimation;
			bool animate, animateFirstToLast;
			WSL::Base::EngineBase* refrence;
		public:
			inline LightningSprite( bool null )
			{
				currentAnimation = 0;
				animate = false;
				animateFirstToLast = true;
			}
			inline LightningSprite(){}
			void AddAnimation( unsigned int animation );
			//--///////////////////////////////////////////////////
			unsigned int AddAnimationToSingleton();
			//--///////////////////////////////////////////////////
			//There is no debugging for this method.//
			void Animate();
			//--///////////////////////////////////////////////////
			bool GetAnimate();
			//--///////////////////////////////////////////////////
			bool GetAnimateFirstToLast();
			//--///////////////////////////////////////////////////
			unsigned int GetCurrentAnimation();
			unsigned int GetImage();
			//--///////////////////////////////////////////////////
			void DeleteRefrence();
			void Resize( float x, float y );
			void Resize( float size );
			//--///////////////////////////////////////////////////
			void SetAnimate( bool animate_ );
			//--///////////////////////////////////////////////////
			void SetAnimateFirstToLast( bool animateFirstToLast_ );
			//--///////////////////////////////////////////////////
			void SetCurrentAnimation( unsigned int currentAnimation_ );
			void SetImage( unsigned int image_, WSL::Global::ImageLibrary* imgLib );
			void SetUpSprite( float x, float y, bool reScale );
			void SetUpSprite( unsigned int image_, bool reScale, WSL::Global::ImageLibrary *imgLib );
			void SetUpSprite( float x, float y, unsigned int image_, bool reScale, WSL::Global::ImageLibrary *imgLib );
			/////////////////////////////////////////////////////
			void SendAnimation();
			//--///////////////////////////////////////////////////
			void SetRefrence( WSL::Base::EngineBase* refrence_ );
			void UpadateAnimations( WSL::Algorithmic::SenderNode node2 );
			void Draw( sf::RenderWindow *window );
		};
	}
}
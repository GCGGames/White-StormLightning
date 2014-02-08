#include "Animation.h"
void WSL::Components::Algorithimic::Animation::AddImage( unsigned int image )
{
	targates.push_back( image );
	size = targates.size();
};
WSL::Components::Algorithimic::Animation::Animation() {
	Reset__();
}
unsigned int WSL::Components::Algorithimic::Animation::AnimateImages( bool firstToLast )
{
	if( animate == true )
	{
		if( firstToLast == true )
		{
			if( count >= delay )
			{
				count = 0;
				currentFrame++;
				if( currentFrame >= size )
					currentFrame = 0;
			}
			else
				count++;
		}
		else
		{
			if( init == false )
			{
				currentFrame = size - 1;
				init = true;
			}
			if( count >= delay )
			{
				count = 0;
				inc--;
				if( inc < 0 )
					inc = size - 1;
				currentFrame = inc;
			}
			else
				count++;
		}
		return targates[ currentFrame ];
	}
	else
		return 0;
}
sf::IntRect WSL::Components::Algorithimic::Animation::AnimateSheet( bool firstToLast )
{
	if( animate == true && frames.size() != 0 )
	{
		unsigned int FS = frames.size();
		if( count >= delay )
		{
			count = 0;
			if( firstToLast == true )
			{
				if( frame <= FS )
				{
					frame++;
					if( frame > FS )
						frame = 1;
				}
				else
					frame = 1;
				return frames[ frame - 1 ];
			}
			else
			{
				if( init == false ) {
					init = true;
					inc = FS;
				}
				inc--;
				if( inc < 0 )
					inc = FS - 1;
				frame = inc;
				return frames[ inc ];
			}
		}
		else
		{
			count++;
			if( firstToLast == true )
			{
				if( frame == 0 )
					return frames[ 0 ];
				else
					return frames[ frame - 1 ];
			}
			else
			{
				if( frame == FS )
					return frames[ FS - 1 ];
				else
					return frames[ frame ];
			}
		}
	}
	else
		return sf::IntRect( 64, 64, 64, 64 );
}
void WSL::Components::Algorithimic::Animation::DeleteImage( unsigned int image )
{
	if( image < size && image >= 0 )
		targates.erase( targates.begin() + image );
		size = targates.size();
}
//Also resets the data in the animation.//
WSL::Components::Algorithimic::SubBase::AllAnimationData WSL::Components::Algorithimic::Animation::GatherData()
{
	WSL::Components::Algorithimic::SubBase::AllAnimationData temp;
	temp = Exchange( temp );
	Restore();
	return temp;
}
//Also stores the information from the animation.//
void WSL::Components::Algorithimic::Animation::ReplaceData( WSL::Components::Algorithimic::SubBase::AllAnimationData data )
{
	storage = Exchange( storage );
	animate = data.GetAnimate();
	delay = data.GetDelay();
	type = data.GetType();
	count = data.GetCount();
	frame = data.GetFrame();
	inc = data.GetIncrement();
	init = data.GetInitialized();
}
//Reset animation.//
void WSL::Components::Algorithimic::Animation::Reset() {
	Reset();
}
//Return the data to its original state.//
void WSL::Components::Algorithimic::Animation::Restore()
{
	animate = storage.GetAnimate();
	delay = storage.GetDelay();
	type = storage.GetType();
	count = storage.GetCount();
	frame = storage.GetFrame();
	inc = storage.GetIncrement();
	init = storage.GetInitialized();
}
void WSL::Components::Algorithimic::Animation::SetUpSpriteSheet( int spriteWidth, int spriteHeight, int spriteX, int spriteY, int offsetX, int offsetY, int parameterWidth, int parameterHeight, bool changeX, bool changeY )
{
	int currentX, currentY;
	currentX = spriteWidth + spriteX + offsetX;
	currentY = spriteHeight + spriteY + offsetY;
	while( true )
	{
		frames.push_back( sf::IntRect( spriteX, spriteY, spriteX + spriteWidth, spriteY + spriteHeight ) );
		if( changeX == true )
		{
			currentX += spriteWidth + offsetX;
			spriteX = currentX;
			if( currentX >= parameterWidth )
				break;
		}
		if( changeY == true )
		{
			currentY += spriteHeight + offsetY;
			spriteY = currentY;
			if( currentY >= parameterHeight )
				break;
		}
		if( parameterWidth <= 0 || parameterHeight <= 0 )
			break;
	}
}
void WSL::Components::Algorithimic::Animation::SetUpSpriteSheet( int spriteWidth, int spriteHeight, int offsetX, int offsetY, int parameterWidth, int parameterHeight, bool changeX, bool changeY )
{
	int currentX, currentY;
	int spriteX = 0;
	int spriteY = 0;
	currentX = spriteWidth + spriteX + offsetX;
	currentY = spriteHeight + spriteY + offsetY;
	while( true )
	{
		frames.push_back(sf::IntRect( spriteX, spriteY, spriteX + spriteWidth, spriteY + spriteHeight ) );
		if( changeX == true )
		{
			currentX += spriteWidth + offsetX;
			spriteX = currentX;
			if( currentX >= parameterWidth )
				break;
		}
		if( changeY == true )
		{
			currentY += spriteHeight + offsetY;
			spriteY = currentY;
			if( currentY >= parameterHeight )
				break;
		}
		if( parameterWidth <= 0 || parameterHeight <= 0 )
			break;
	}
}
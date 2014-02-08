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
#include "Animation Data.h"
bool WSL::Components::Algorithimic::Base::AnimationData::GetAnimate() {
	return animate;
}
unsigned int WSL::Components::Algorithimic::Base::AnimationData::GetSize() {
	return size;
}
int WSL::Components::Algorithimic::Base::AnimationData::GetDelay() {
	return delay;
}
bool WSL::Components::Algorithimic::Base::AnimationData::GetType() {
	return ( type );
}
void WSL::Components::Algorithimic::Base::AnimationData::SetType( AnimationType  sheetOrImageByImage )
{
	if( sheetOrImageByImage == Sheet )
		type = false;
	else
		type = true;
}
void WSL::Components::Algorithimic::Base::AnimationData::SetType( bool type_ ) {
	type = type_;
}
void WSL::Components::Algorithimic::Base::AnimationData::SetCurrentFrame( unsigned int currentFrame_ ) {
	currentFrame = currentFrame_;
}
void WSL::Components::Algorithimic::Base::AnimationData::SetAnimate( bool animate_ ) {
	animate = animate_;
}
void WSL::Components::Algorithimic::Base::AnimationData::SetDelay( int delay_ ) {
	delay = delay_;
}
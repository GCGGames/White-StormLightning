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
int WSL::Components::Algorithimic::SubBase::AllAnimationData::GetCount()
{
	return count;
}
unsigned int WSL::Components::Algorithimic::SubBase::AllAnimationData::GetFrame()
{
	return frame;
}
int WSL::Components::Algorithimic::SubBase::AllAnimationData::GetIncrement()
{
	return inc;
}
bool WSL::Components::Algorithimic::SubBase::AllAnimationData::GetInitialized()
{
	return init;
}
void WSL::Components::Algorithimic::SubBase::AllAnimationData::SetCount( int value )
{
	count = value;
}
void WSL::Components::Algorithimic::SubBase::AllAnimationData::SetFrame( unsigned int value )
{
	frame = value;
}
void WSL::Components::Algorithimic::SubBase::AllAnimationData::SetIncrement( int value )
{
	inc = value;
}
void WSL::Components::Algorithimic::SubBase::AllAnimationData::SetIntilized( bool value )
{
	init = value;
}
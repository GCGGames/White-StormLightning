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
#include "Component.h"
unsigned int WSL::Components::Base::Component::GetElement()
{
	return element;
}
unsigned int WSL::Components::Base::Component::GetID()
{
	return id;
}
int WSL::Components::Base::Component::GetComponentID()
{
	return componentID;
}
int WSL::Components::Base::Component::GetObjectID()
{
	return objectID;
}
bool  WSL::Components::Base::Component::GetUpdateData()
{
	return updateData;
}
void WSL::Components::Base::Component::SetElement( unsigned int element_ )
{
	element = element_;
}
void WSL::Components::Base::Component::SetUpdateData( bool value )
{
	updateData = value;
}
void WSL::Components::Base::Component::Update( unsigned int id_, int objectID_, int componentID_ )
{
	id = id_;
	objectID = objectID_;
	componentID = componentID_;
}
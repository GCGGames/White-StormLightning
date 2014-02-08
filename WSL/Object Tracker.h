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
#include "Bubble Sort.h"
namespace WSL
{
	namespace Algorithmic
	{
		struct RegisteredObject
		{
			inline RegisteredObject( int objID, int componentID_ )
			{
				ObjID = objID;
				componentID = componentID_;
			//	IDs.push_back( 0 );
			}
			inline RegisteredObject() {
			}
			unsigned int ObjID;
			int componentID;
			std::vector< unsigned int > IDs;
		};
		struct ObjectTracker
		{
			
			std::vector< RegisteredObject > ObjectRegisters;
			int AddObject( int ObjID, int componentID )
			{
				const unsigned int SIZE = ObjectRegisters.size();
				if( SIZE != 0 )
				{
					for( unsigned int i = 0; i < SIZE; ++i )
					{
						if( ObjectRegisters[ i ].ObjID == ObjID )
						{
							int id = ObjectRegisters[ i ].IDs.size();
							ObjectRegisters[ i ].IDs.push_back( id );
							return id;
						}
					}
				}
				ObjectRegisters.push_back( RegisteredObject( ObjID, componentID ));
				ObjectRegisters[ ( ObjectRegisters.size() - 1 ) ].IDs.push_back( 0 );
				return 0;
			}
		};
	}
}
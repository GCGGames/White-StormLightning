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
#include "Singleton Base.h"
namespace WSL
{
	namespace Algorithmic
	{
		class LargeDataManager
		{
		protected:
			WSL::Containers::PointableVector<WSL::Algorithmic::ReceiverNode> objects;
			std::string refreshScript;
			WSL::Engine *refrence;
		public:
			void AddObject( unsigned int element );
			void DeleteRefrence();
			void DeleteTracker( unsigned int element );
			void DeleteTrackerByElement( unsigned int element );
			unsigned int GetObjectElement( unsigned int node );
			WSL::Containers::PointableVector<WSL::Algorithmic::ReceiverNode> GetObjects();
			std::string GetRefreshScript();
			bool DoesObjectExist( unsigned int node );
			virtual void Update( WSL::Algorithmic::SenderNode node );
			virtual void Refresh();
			void SetRefreshScript( std::string refreshScript_ );
			void SetObjects( std::vector<WSL::Algorithmic::ReceiverNode> objects_ );
			void SetRefrence( WSL::Engine *engine );
			void (*luaSend)();
		};
	}
}
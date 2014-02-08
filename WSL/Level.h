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
#include "Render Layer.h"
namespace WSL
{
	namespace Algorithmic
	{
		class Level : public WSL::Algorithmic::Base::SubSingleBase
		{
		protected:
			WSL::Algorithmic::LargeDataManager objects;
			WSL::Algorithmic::ReceiverNode renderLayerNode;
			bool renderLayerDeleted;
		public:
			inline Level( bool null ) {
				renderLayerDeleted = false;
			}
			inline Level(){}
			std::string name;
			void AddObject( unsigned int id, unsigned int objID );
			void GetObject( unsigned int id, int objID, int componentID );
			WSL::Framework::Standard::Base::BaseEntity* GetObject( unsigned int id, int objID, int componentID, bool null );
			void SetObject( unsigned int id, int objID, WSL::Framework::Standard::Base::BaseEntity *object );
			virtual unsigned int SearchAlgorithim( unsigned int id, int objID, int componentID );
			bool ObjectIsInLevel( unsigned int i );
		 	inline void SetRenderLayer( unsigned int element ) {
				renderLayerNode.SetElement( element );
			}
			unsigned int SendRenderLayer()
			{
				unsigned int size = refrence->renderLayers.node.Size();
				for( unsigned int i = 0; i < size; ++i ) {
					if( renderLayerNode.GetElement() == refrence->renderLayers.node.GetDeletedPosition( i ) )
						renderLayerDeleted = true;
				}
				if( renderLayerDeleted == false )
				{
					renderLayerNode.UpdateStatus( refrence->renderLayers.node.Notify( renderLayerNode.GetElement() ) );
					refrence->renderLayers.Array[ renderLayerNode.GetElement() ]->SetRefrence( refrence );
					luabind::globals( refrence->engine->luaContainer->State )[ "defaultRenderLayer" ] = refrence->renderLayers.Array[ renderLayerNode.GetElement() ];
				}
				return renderLayerNode.GetElement();
			}
			inline void SetActive( bool active_ ) {
				active = active_;
			}
			inline void SetRefresh( bool refresh_ ) {
				refresh = refresh_;
			}
			inline void SetDestroy( bool destroy_ ) {
				destroy = destroy_;
			}
			inline void DeleteRenderLayer()
			{
				unsigned int size = refrence->renderLayers.node.Size();
				for( unsigned int i = 0; i < size; ++i ) {
					if( renderLayerNode.GetElement() == refrence->renderLayers.node.GetDeletedPosition( i ) )
						renderLayerDeleted = true;
				}
				if( renderLayerDeleted == false )
				{
					renderLayerNode.UpdateStatus( refrence->renderLayers.node.Notify( renderLayerNode.GetElement() ) );
					WSL::Algorithmic::RenderLayer* toDelete = refrence->renderLayers.Array[ renderLayerNode.GetElement() ];
					refrence->renderLayers.Delete( renderLayerNode.GetElement() );
					delete toDelete;
				}	
			}
			virtual void Update( WSL::Algorithmic::SenderNode node_ );
			void Initialize();
			void Refresh();
			void Destroy();	
		};
	}
}
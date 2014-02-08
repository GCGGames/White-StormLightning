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
#include "Base Entity.h"
namespace WSL
{
	namespace Framework
	{
		namespace Standard
		{
			namespace Base
			{
				class Entity : public WSL::Framework::Standard::Base::BaseEntity
				{
				public:
					Entity( int objectID, bool Refresh, bool Destroy, bool initialize_, bool runDestroy,
						std::string refeshScript, std::string initializeScript, std::string destroyScript,
						std::string otherScript, WSL::Engine* refrence_ );
					Entity();
					~Entity();
					virtual void RunInitScript( std::string script );
					void InitializeEntity( int objID );
					virtual void Construct( int objectID, bool refresh_, bool destroy_, bool initialize_, bool runDestroy,
						std::string refeshScript_, std::string initializeScript_, std::string destroyScript_,
						std::string otherScript_, WSL::Engine* refrence_ );
					void DeleteRefrence();
					std::string GetRefreshScript();
					std::string GetInitializeScript();
					std::string GetDestroyScript();
					std::string GetOtherScript();
					bool GetDestroy();
					void SetDestroy( bool destroy_ );
					WSL::Containers::CoreInfoContainer GetChild( unsigned int id, unsigned int objID_ );
					virtual void SetRefrence( WSL::Engine* refrence_ );
					virtual void SendToLua();
					void SetResfreshScript( std::string script );
					void SetInitializeScript( std::string script );
					void SetDestroyScript( std::string script );
					void SetOtherScript( std::string script );
					void SetChild( unsigned int id, unsigned int objID_, WSL::Containers::CoreInfoContainer replacement );
					int GetComponentID();
					int GetID();
					int GetObjID();
					void SetObjID( int objectId_ );
					void SetID( int id_ );
					virtual void RunScript( std::string script );
					virtual void Initialize();
					virtual void Refresh();
					virtual void Destroy();
					void DeleteIdentification();
					void EntityInitialize();
					void EntityRefresh();
					void EntityDestroy();
					virtual void RunDestroy__( std::string script );
				};
			}
		}
	}
}
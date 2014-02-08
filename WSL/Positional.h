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
#include "Entity.h"
namespace WSL
{
	namespace Framework
	{
		namespace Standard
		{
			class Positional : public WSL::Framework::Standard::Base::Entity
			{
			protected:
				std::string physicalBehavior;
				WSL::Containers::Base::XYZ position;
				float rotation;
				WSL::Components::LightningSprite* spr;
				WSL::Components::Polygon* poly;
				WSL::Collision::ScanAreaCollision::ScanArea* sca;
				WSL::Components::VectorGraphics* vec;
				std::vector<WSL::Containers::CoreInfoContainer> reactors;
				void SetScanAreaProperties()
				{
					if( sca != NULL )
					{
						WSL::Collision::ScanAreaCollision::Rectangle r = sca->GetR();
						r.x = ( int ) position.GetX() - r.w;
						r.y = ( int ) position.GetY() - r.h;
						sca->SetR( r );
					}
				}
			public:
				Positional( int objectID, bool Refresh, bool Destroy, bool initialize_, bool runDestroy,
						std::string refeshScript, std::string initializeScript, std::string destroyScript,
						std::string otherScript, std::string physicalBehavior_, WSL::Engine* refrence_ );
				Positional();
				~Positional();
				virtual void DeleteRefrence();
				WSL::Containers::Base::XYZ GetPosition();
				float GetRotation();
				std::string GetPhysicalBehavior();
				void SetPhysicalBehavior( std::string physicalBehavior_ );
				void AddSprite( WSL::Components::LightningSprite* sprite_ );
				void AddPolygon( WSL::Components::Polygon* polygon_ );
				void AddScanArea( WSL::Collision::ScanAreaCollision::ScanArea* scanArea_ );
				void AddVectorGraphic( WSL::Components::VectorGraphics* vectorGraphi_ );
				virtual void Initialize();
				virtual void Refresh();
				virtual void Destroy();
				void Rotate( float degree );
				void SetComponentPosition( bool twoD );
				virtual void SetPosition( float x, float y, float z );
				virtual void SetPosition( float x, float y );
				virtual void SetPosition( WSL::Containers::Base::XYZ position_ );
				virtual void SendToLua();
				virtual void RunPhysScript( std::string script );
				void DeleteComponents();
				void SetRotation( float degree );
				void PositionalInitialize();
				void PositionalRefresh();
				void PositionalDestroy();
				void PositionalSend();
				void PositionalDelete();
				void RunSubClassMethodBegin();
				void RunSubClassMethodEnd();
				void PositionalSetSubMethods();
			};
		}
	}
}
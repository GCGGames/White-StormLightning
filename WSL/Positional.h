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
				WSL::Components::Lightning_Sprite *spr;
				WSL::Components::Polygon *poly;
				WSL::Collision::Scan_Area_Collision::Scan_Area *sca;
				WSL::Components::Vector_Graphics *vec;
				std::vector<WSL::Containers::CoreInfoContainer> reactors;
				void SetScanAreaProperties()
				{
					if( sca != NULL )
					{
						WSL::Collision::Scan_Area_Collision::Rectangle r = sca->GetR();
						r.x = (int)position.getX() - r.w;
						r.y = (int)position.getY() - r.h;
						sca->SetR( r );
					}
				}
			public:
				Positional( int obj_ID, bool Refresh, bool Destroy, bool initialize_, bool RDestroy,
						std::string refesh_Script, std::string initialize_Script, std::string destroy_Script,
						std::string other_Script, std::string physicalBehavior_, WSL::Engine *refrence_ );
				Positional();
				~Positional();
				virtual void DeleteRefrence();
				WSL::Containers::Base::XYZ GetPosition();
				float GetRotation();
				std::string GetPhysicalBehavior();
				void SetPhysicalBehavior( std::string physicalBehavior_ );
				void AddSprite( WSL::Components::Lightning_Sprite sprite_ );
				void AddPolygon( WSL::Components::Polygon polygon_ );
				void AddScanArea( WSL::Collision::Scan_Area_Collision::Scan_Area scanArea_ );
				void AddVectorGraphic( WSL::Components::Vector_Graphics vectorGraphi_ );
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
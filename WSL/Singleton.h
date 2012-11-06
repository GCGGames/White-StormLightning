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
#include <sstream>
#include "Level.h"
namespace WSL
{
	struct Singleton : public WSL::Base::SingletonBase, public WSL::Algorithmic::BubbleSort
	{
		Singleton( bool null );
		Singleton();
		void LoadImage( std::string name, std::string directory );
		void AddSprite( float x, float y, bool reScale );
		void AddSprite( float x, float y, unsigned int image_, bool reScale );
		void AddSprite( unsigned int image_, bool reScale );
		void AddPolygon();
		void AddPolygon( std::string scanAreaFile );
		void AddVectorGraphic();
		void AddVectorGraphic( std::string scanAreaFile );
		void AddScanArea();
		void AddScanArea( std::string scanAreaFile );
		void GetLevel( unsigned int i );
		void GetLevel( std::string name );
		void SetLevel( WSL::Algorithmic::Level *level, unsigned int i );
		void SetLevel( WSL::Algorithmic::Level *level, std::string name );
		inline void SetDebug( bool value )
		{
			debug = value;
		}
		void SearchAlgorithum();
		void BaseSend();
		void SendObject( unsigned int id, int objID,  int componentID );
		void ThreadObject( unsigned int id, int objID,  int componentID );
		void EndObjectThread();
		void Cycle();
		void DetectCollision();
		void Draw();
		void CleanUp();
		int HeartBeat( unsigned int i );
		void LoadAlgorithim( std::string info );
		void LevelCycle();
		void SendObjectToLua();
		int Instantiate( std::string info );
		int InstantiateLevel( std::string info );
		int InstantiateRenderLayer();
		int InstantiateRenderLayer( std::string name );
		void InitializeTranslators();
		template< typename T >
		void BaseAddComponent( T *t, std::string script )
		{
			luabind::globals( engine->luaContainer->State )[ "new" ] = t;
			objects.Array[componentTrack]->SetRefrence( engine );
			objects.Array[componentTrack]->RunInitScript( script );
		}
		void GetObject( unsigned int id, int objID, int componentID );
		void GetRenderLayer( unsigned int layer );
		void GetRenderLayerByLevel( unsigned int level );
		void GetRenderLayerByLevel( std::string levelName );
		void GetCamera();
		void GetSoundManager();
		WSL::Containers::Base::XYZ GetMousePosition();
		inline bool GetDebug()
		{
			return debug;
		}
		inline bool GetThreeDCollision()
		{
			return (threeDCollision);
		}
		inline void SetThreeDCollision( bool threeDCollision_ )
		{
			threeDCollision = threeDCollision_;
		}
		WSL::Containers::Bool_XYZ CheckCollision( WSL::Collision::Scan_Area_Collision::Scan_Area a, WSL::Collision::Scan_Area_Collision::Scan_Area b, bool ThreeD );
		bool Check_Collision( WSL::Collision::Scan_Area_Collision::Rectangle rect1, WSL::Collision::Scan_Area_Collision::Rectangle rect2);
		unsigned int currentObject;
		std::vector<WSL::DataTranslation::Base::BaseTranslator*> (*SetUpTranslators)(
			std::vector<WSL::DataTranslation::Base::BaseTranslator*> );
		std::string levelScripts[3];
		WSL::Global::Stack<WSL::Algorithmic::Level*> levels;
		WSL::DataTransfer::Lua::SenderBase *sender;
		WSL::Global::SoundManager *soundManager;
	};
}
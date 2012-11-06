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
#include "Sound Manager.h"
namespace WSL
{
	namespace Algorithmic
	{
		struct RenderLayer;
	}
}
namespace WSL
{
	namespace Base
	{
		struct SingletonBase
		{
			WSL::Global::Camera *camera;
			WSL::Engine *engine;
			bool run;
			bool debug;
			virtual void LoadImage( std::string name, std::string directory ){}
			virtual void AddSprite( float x, float y, bool reScale ){}
			virtual void AddSprite( float x, float y, unsigned int image_, bool reScale ){}
			virtual void AddSprite( unsigned int image_, bool reScale ){}
			virtual void AddPolygon(){}
			virtual void AddPolygon( std::string scanAreaFile ){}
			virtual void AddVectorGraphic(){}
			virtual void AddVectorGraphic( std::string scanAreaFile ){}
			virtual void AddScanArea(){}
			virtual void AddScanArea( std::string scanAreaFile ){}
			virtual int InstantiateLevel( std::string info ){ return 0; }
			virtual int InstantiateRenderLayer(){ return 0; }
			virtual int InstantiateObject( std::string info ){ return 0; }
			virtual void SearchAlgorithum(){}
			virtual void BaseSend(){}
			virtual void SendLevel(){}
			virtual void SendObject( unsigned int id, int objID,  int componentID ){}
			virtual void ThreadObject( unsigned int id, int objID,  int componentID ){}
			virtual void EndObjectThread(){}
			virtual void Cycle(){}
			virtual void DetectCollision(){}
			virtual void Draw(){}
			virtual void CleanUp(){}
			virtual int HeartBeat( unsigned int i ){ return (0); }
			virtual void LoadAlgorithim( std::string info ){}
			virtual void LevelCycle(){}
			virtual void GetObject( unsigned int id, int objID, int componentID ){}
			virtual void GetRenderLayer( unsigned int layer ){}
			virtual void GetRenderLayerByLevel( unsigned int level ){}
			virtual void GetRenderLayerByLevel( std::string levelName ){}
			virtual void GetCamera(){}
			virtual void GetSoundManager(){}
			virtual WSL::Containers::Base::XYZ GetMousePosition(){ return WSL::Containers::Base::XYZ(); }
			WSL::Containers::CoreInfoContainer currentInfo;
			bool threeDCollision;
			WSL::Global::Input *input;
			WSL::Global::Stack<WSL::Framework::Standard::Base::BaseEntity*> objects;
			unsigned int componentTrack;
			int highestComponentID;
			bool didNotFindResult;
			WSL::Global::Stack<WSL::Algorithmic::RenderLayer*> renderLayers;
			std::vector<WSL::DataTranslation::Base::BaseTranslator*> translators;
		protected:
			WSL::Containers::CoreInfoContainer componentInfo;
			std::vector<std::string> startScripts;
			std::string standardScripts[5];
			bool refresh, initialize, runDestroy, destroy;
			WSL::Collision::Scan_Area_Collision::Initializer scanInit;
		};
	}
}
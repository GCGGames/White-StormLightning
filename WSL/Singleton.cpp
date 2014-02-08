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
#include "Singleton.h"
WSL::Singleton::Singleton( bool null )
{
	debug = false;
	engine = new WSL::Engine( true );
	engine->window = new sf::RenderWindow( sf::VideoMode( 1000, 600, 32 ), "White - Storm: Lightning" );
	camera = new WSL::Global::Camera( ( float ) engine->window->GetWidth() / 2.f, ( float ) engine->window->GetHeight() / 2.f, 0, ( float ) engine->window->GetWidth(), ( float ) engine->window->GetHeight(), ( float ) 101, &engine->window->GetDefaultView() );
	input = new WSL::Global::Input( camera, engine );
	soundManager = new WSL::Global::SoundManager;
	run = true;
	currentObject = 0;
	highestComponentID = 0;
	threeDCollision = false;
}
WSL::Singleton::Singleton() {
}
void WSL::Singleton::AddSprite( float x, float y, bool reScale )
{
	SearchAlgorithum();
	if( componentInfo.GetComponentID() == 0 ) {
		std::cerr << "You can not add a sprite or anything that can be seen to a entity." << std::endl;
		std::cerr << "In method AddSprite( float, float, bool )." << std::endl;
	}
	else
	{
		WSL::Components::LightningSprite* spriteToAdd = new WSL::Components::LightningSprite( true );
		spriteToAdd->SetUpSprite( x, y, reScale );
		BaseAddComponent( spriteToAdd, "src/Scripts/Engine/Component Control/Add Sprite.lua" );
	}
}
//-----=====-----//
void WSL::Singleton::AddSprite( float x, float y, unsigned int image_, bool reScale )
{
	SearchAlgorithum();
	if( componentInfo.GetComponentID() == 0 ) {
		std::cerr << "You can not add a sprite or anything that can be seen to a entity." << std::endl;
		std::cerr << "In method AddSprite( float, float, unsigned int, bool )." << std::endl;
	}
	else
	{
		WSL::Components::LightningSprite* spriteToAdd = new WSL::Components::LightningSprite( true );
		spriteToAdd->SetUpSprite( x, y, image_, reScale, engine->imageLibrary );
		BaseAddComponent( spriteToAdd, "src/Scripts/Engine/Component Control/Add Sprite.lua" );
	}
}
//-----=====-----//
void WSL::Singleton::AddSprite( unsigned int image_, bool reScale )
{
	SearchAlgorithum();
	if( componentInfo.GetComponentID() == 0 ) {
		std::cerr << "You can not add a sprite or anything that can be seen to a entity." << std::endl;
		std::cerr << "In method AddSprite( unsigned int )." << std::endl;
	}
	else
	{
		WSL::Components::LightningSprite* spriteToAdd = new WSL::Components::LightningSprite( true );
		spriteToAdd->SetUpSprite( image_, reScale, engine->imageLibrary );
		BaseAddComponent( spriteToAdd, "src/Scripts/Engine/Component Control/Add Sprite.lua" );
	}
}
void WSL::Singleton::AddPolygon()
{
	SearchAlgorithum();
	if( componentInfo.GetComponentID() == 0 ) {
		std::cerr << "You can not add a polygon or anything that can be seen or has a position to a entity." << std::endl;
		std::cerr << "In method AddPolygon()." << std::endl;
	}
	else
		BaseAddComponent( new WSL::Components::Polygon, "src/Scripts/Engine/Component Control/Add Polygon.lua" );
}
//-----=====-----//
void WSL::Singleton::AddPolygon( std::string scanAreaFile )
{
	SearchAlgorithum();
	if( componentInfo.GetComponentID() == 0 ) {
		std::cerr << "You can not add a polygon or anything that can be seen or has a position to a entity." << std::endl;
		std::cerr << "In method AddPolygon( std::string )." << std::endl;
	}
	else
	{
		WSL::Components::Polygon* polygonToAdd = new WSL::Components::Polygon;
		WSL::Collision::ScanAreaCollision::ScanArea loader;
		luabind::globals( engine->luaContainer->State )[ "loader" ] = &loader;
		loader.SetX( 0 );
		loader.SetY( 0 );
		loader.SetZ( 0 );
		loader = scanInit.SetPointCoordinates( loader, scanAreaFile );
		unsigned int i = 0;
		unsigned int size = loader.GetPoints().size();
		if( size != 0 )
		{
			while( i < size ) {
				polygonToAdd->AddPoint( loader.GetPoint( i ) );
				i++;
			}
		}
		polygonToAdd->SetCenter( ( -loader.GetLargeX() - loader.GetSmallX() ) / 2.f, ( -loader.GetLargeY() - loader.GetSmallY() ) / 2.f );
		BaseAddComponent( polygonToAdd, "src/Scripts/Engine/Component Control/Add Polygon.lua" );
	}
}
void WSL::Singleton::AddVectorGraphic()
{
	SearchAlgorithum();
	if( componentInfo.GetComponentID() == 0 ) {
		std::cerr << "You can not add a polygon or anything that can be seen or has a position to a entity." << std::endl;
		std::cerr << "In method AddVectorGraphic()." << std::endl;
	}
	else
		BaseAddComponent( new WSL::Components::VectorGraphics, "src/Scripts/Engine/Component Control/Add Vector Graphic.lua" );
}
void WSL::Singleton::AddVectorGraphic( std::string scanAreaFile )
{
	SearchAlgorithum();
	if( componentInfo.GetComponentID() == 0 ) {
		std::cerr << "You can not add a polygon or anything that can be seen or has a position to a entity." << std::endl;
		std::cerr << "In method AddVectorGraphic( std::string )." << std::endl;
	}
	else
	{
		WSL::Components::VectorGraphics* vectorGraphicsToAdd = new WSL::Components::VectorGraphics( scanAreaFile );
		WSL::Collision::ScanAreaCollision::ScanArea loader;
		loader.SetX( 0 );
		loader.SetY( 0 );
		loader.SetZ( 0 );
		loader = scanInit.SetPointCoordinates( loader, scanAreaFile );
		unsigned int i = 0;
		unsigned int size = loader.GetPoints().size();
		if( size != 0 )
		{
			while( i < size ) {
				vectorGraphicsToAdd->AddPoint( loader.GetPoint( i ) );
				i++;
			}
		}
		BaseAddComponent( vectorGraphicsToAdd, "src/Scripts/Engine/Component Control/Add Vector Graphic.lua" );
	}
}
void WSL::Singleton::AddScanArea()
{
	SearchAlgorithum();
	if( componentInfo.GetComponentID() == 0 ) {
		std::cerr << "You can not add a scanArea or anything that has a position to a entity." << std::endl;
		std::cerr << "In method AddScanArea()." << std::endl;
	}
	else
		BaseAddComponent( new WSL::Collision::ScanAreaCollision::ScanArea, "src/Scripts/Engine/Component Control/Add Scan Area.lua" );
}
void WSL::Singleton::AddScanArea( std::string scanAreaFile )
{
	SearchAlgorithum();
	if( componentInfo.GetComponentID() == 0 ) {
		std::cerr << "You can not add a scanArea or anything that has a position to a entity." << std::endl;
		std::cerr << "In method AddScanArea( std::string )." << std::endl;
	}
	else
	{
		WSL::Collision::ScanAreaCollision::ScanArea* scanAreaToAdd = 
				new WSL::Collision::ScanAreaCollision::ScanArea( scanInit.SetPointCoordinates( 
				WSL::Collision::ScanAreaCollision::ScanArea(), scanAreaFile ) );
		BaseAddComponent( scanAreaToAdd, "src/Scripts/Engine/Component Control/Add Scan Area.lua" );
	}
}
void WSL::Singleton::GetObject( unsigned int id, int objID, int componentID ) {
	SendObject( id, objID, componentID );
}
void WSL::Singleton::SearchAlgorithum()
{
	didNotFindResult = false;
	unsigned int size = objects.Array.size();
	bool found = false;
	if( size != 0 )
	{
		unsigned int i = 0;
		unsigned int id = currentInfo.GetID();
		int objID = currentInfo.GetObjID();
		int compID = currentInfo.GetComponentID();
		componentInfo = currentInfo;
		while( i < size )
		{
			if( objects.Array[ i ]->GetComponentID() == compID )
			{
				if( objects.Array[ i ]->GetObjID() == objID )
				{
					if( objects.Array[ i ]->GetID() == id )
					{
						componentTrack = i;
						found = true;
						break;
					}
				}
			}
			i++;
		}
	}
	if( found == false )
		didNotFindResult = true;
}
void WSL::Singleton::Cycle()
{
	engine->renders.clear();
	engine->scanAreas.Array.clear();
	input->refrence = engine;
	input->Update( camera );
	input->Frame();
	LevelCycle();
	soundManager->Update();
	DetectCollision();
	Draw();
}
int WSL::Singleton::HeartBeat( unsigned int i )
{
	if( i < objects.Array.size() )
	{
		currentInfo.SetID( objects.Array[ i ]->GetID() );
		currentInfo.SetObjID( objects.Array[ i ]->GetObjID() );
		currentInfo.SetComponentID( objects.Array[ i ]->GetComponentID() );
		currentObject = i;
		objects.Array[ i ]->SetRefrence( engine );
		if( objects.Array[ i ]->GetDestroy() == false )
		{
			objects.Array[ i ]->Refresh();
			objects.Array[ i ]->DeleteRefrence();
			return 0;
		}
		else
		{
			objects.Array[ i ]->Destroy();
			objects.Array[ i ]->DeleteRefrence();
			WSL::Framework::Standard::Base::BaseEntity* temp = objects.Array[ i ];
			objects.Array.erase( objects.Array.begin() + i );
			objects.node.ElementDeleted( i );
			delete temp;
			return -1;
		}
	}
	return 0;
}
void WSL::Singleton::LevelCycle()
{
	bool break_ = false;
	unsigned int c = 0;
	unsigned int size = levels.Array.size();
	input->refrence = engine;
	if( size != 0 )
	{
		while( c < size && break_ == false )
		{
			if( levels.Array[ c ]->active == true )
			{
				if( levels.Array[ c ]->destroy == true )
				{
					unsigned int objectSize = objects.Array.size();
					for( unsigned int i = 0; i < objects.Array.size() && break_ == false; i++ )
					{
						if( levels.Array[ c ]->ObjectIsInLevel( i ) == true ) {
							if( HeartBeat( i ) == -1 && objects.Array.size() != 1 && i > 0 )
								--objectSize;
						}
					}
					WSL::Algorithmic::Level* temp = levels.Array[ c ];
					temp->SetRefrence( this );
					BaseSend();
					unsigned int clear = temp->SendRenderLayer();
					luabind::globals( engine->luaContainer->State )[ temp->name ] = temp;
					temp->Destroy();
					temp->DeleteRefrence();
					WSL::Algorithmic::RenderLayer* renderLayer = renderLayers.Array[ clear ];
					renderLayer->DeleteRefrence();
					temp->DeleteRenderLayer();
					levels.Delete( c );
					delete temp;
					size -= 1;
				}
				else
				{
					if( levels.Array[ c ]->refresh == true )
					{
						unsigned int objectSize = objects.Array.size();
						for( unsigned int i = 0; i < objects.Array.size() && break_ == false; i++ )
						{
							if( levels.Array[ c ]->ObjectIsInLevel( i ) == true ) {
								if( HeartBeat( i ) == -1 && objects.Array.size() != 1 && i > 0 )
									--objectSize;
							}
						}
						if( levels.Array[ c ]->refreshScript != "NULL" )
						{
							BaseSend();
							levels.Array[ c ]->SetRefrence( this );
							unsigned int clear = levels.Array[ c ]->SendRenderLayer();
							luabind::globals( engine->luaContainer->State )[ levels.Array[ c ]->name ] = levels.Array[ c ];
							levels.Array[ c ]->Refresh();
							levels.Array[ c ]->DeleteRefrence();
							renderLayers.Array[ clear ]->DeleteRefrence();
						}
					}
				}
			}
			//Tee-hee//
			c++;
		}
	}
}
void WSL::Singleton::CleanUp()
{
	unsigned int size = objects.Array.size() - 1;
	unsigned int i = 0;
	if( size != 0 )
	{
		while( ( size + 1 ) - i > 0 )
		{
			input->refrence = engine;
			{
				WSL::Framework::Standard::Base::BaseEntity* temp = objects.Array[ size - i ];
				currentInfo.SetID( temp->GetID() );
				currentInfo.SetObjID( temp->GetObjID() );
				currentInfo.SetComponentID( temp->GetComponentID() );
				temp->SetRefrence( engine );
				temp->Destroy();
				temp->DeleteRefrence();
				objects.Delete( size - i );
				delete temp;
			}
			i++;
		}
	}
	i = 0;
	size = levels.Array.size() - 1;
	while( ( size + 1 ) - i > 0 )
	{
		input->refrence = engine;
		{
			WSL::Algorithmic::Level* temp;
			temp = levels.Array[ size - i ];
			temp->SetRefrence( this );
			luabind::globals( engine->luaContainer->State )[ temp->name ] = temp;
			temp->DeleteRefrence();
			levels.Delete( size - i );
		}
		i++;
	}
	size = renderLayers.Array.size() - 1;
	i = 0;
	input->refrence = engine;
	while( ( size + 1 ) - i > 0 )
	{
		{
			WSL::Algorithmic::RenderLayer* temp = renderLayers.Array[ size - i ];
			renderLayers.Delete( size - i );
		}
		++i;
	}
	soundManager->CleanUp();
	delete engine->window;
	delete engine;
	delete input;
	delete camera;
	delete soundManager;
}
void WSL::Singleton::DetectCollision()
{
	unsigned int i1 = 0;
	unsigned int i2 = 0;
	unsigned int size = engine->scanAreas.Array.size();
	if( size != 0 && size != 1 )
	{
		for( unsigned int i = 0; i < size; ++i ) {
			engine->scanAreas.Array[ i ]->SetCollision( WSL::Containers::BoolXYZ( false ) );
			engine->scanAreas.Array[ i ]->ClearCollisionData();
		}
		while( i1 < size )
		{
			while( i2 < size && engine->scanAreas.Array[ i1 ]->GetCollision().GetBooleanValue() == false )
			{
				if( i2 != i1 )
				{
					engine->scanAreas.Array[ i1 ]->SetCollision( 
						CheckCollision( *engine->scanAreas.Array[ i1 ],
						*engine->scanAreas.Array[ i2 ], threeDCollision )
						);
					engine->scanAreas.Array[ i1 ]->SetVector( engine->scanAreas.Array[ i1 ]->GetCollision().GetCoordinates() );
					if( engine->scanAreas.Array[ i1 ]->GetCollision().GetBooleanValue() == true )
					{
						//It is a quick fix.//
						engine->scanAreas.Array[ i2 ]->AddCollisionData( WSL::Containers::IDXYZ( engine->scanAreas.Array[ i1 ]->GetID(), engine->scanAreas.Array[ i1 ]->GetObjectID(), 
								engine->scanAreas.Array[ i1 ]->GetComponentID(), WSL::Containers::Base::XYZ( engine->scanAreas.Array[ i1 ]->GetX(), engine->scanAreas.Array[ i1 ]->GetY(), 
								engine->scanAreas.Array[ i1 ]->GetZ() ) ) );
						
						engine->scanAreas.Array[ i1 ]->AddCollisionData( WSL::Containers::IDXYZ( engine->scanAreas.Array[ i2 ]->GetID(), engine->scanAreas.Array[ i2 ]->GetObjectID(), 
								engine->scanAreas.Array[ i2 ]->GetComponentID(), WSL::Containers::Base::XYZ( engine->scanAreas.Array[ i2 ]->GetX(), engine->scanAreas.Array[ i2 ]->GetY(), 
								engine->scanAreas.Array[ i2 ]->GetZ() ) ) );

						engine->scanAreas.Array[ i2 ]->SetCollision( WSL::Containers::BoolXYZ( engine->scanAreas.Array[ i2 ]->GetCollision().GetCoordinates(), true ) );
						break;
					}
				}
				i2++;
			}
			i2 = 0;
			i1++;
		}
	}
}
void WSL::Singleton::Draw()
{
	engine->window->Clear( sf::Color( 255,255, 255 ) );
	unsigned int size = renderLayers.Array.size();
	unsigned int rsize = engine->renders.size();
	if( size != 0 && rsize != 0 )
	{
		WSL::Algorithmic::BubbleSortAlgorithm( &engine->renders );
		for( unsigned int i = 0; i < size; ++i )
		{
			for( unsigned int j = 0; j < rsize; ++j )
			{
				if( engine->renders[ j ]->GetRenderLayerName() == renderLayers.Array[ i ]->GetName() &&
						renderLayers.Array[ i ]->GetActive() == true )
					engine->renders[ j ]->Draw( engine->window );
			}
		}
	}
	engine->window->Display();
}
void WSL::Singleton::LoadAlgorithim( std::string info )
{
	startScripts.clear();
	std::ifstream file;
	file.open( info.c_str() );
	std::string pass;
	unsigned int i = 0;
	int trace = 0;
	short c = 0;
	if( file.is_open() == true )
	{
		while( i < 2 )
		{
			file >> trace;
			if( i == 0 )
				currentInfo.SetObjID( trace );
			else
				currentInfo.SetComponentID( trace );
			i++;
		}
		i = 0;
		while( file.eof() == false )
		{
			file >> pass;
			if( pass != "----------" )
			{
				if( pass != "true" && pass != "false" )
					startScripts.push_back( pass );
				else
				{
					if( c == 0 )
					{
						if( pass == "true" )
							initialize = true;
						else
							initialize = false;
					}
					if( c == 1 )
					{
						if( pass == "true" )
							refresh = true;
						else
							refresh = false;
					}
					if( c == 2 )
					{
						if( pass == "true" )
							runDestroy = true;
						else
							runDestroy = false;
					}
					if( c == 3 )
					{ 
						if( pass == "true" )
							destroy = true;
						else
							destroy = false;
					}
					c++;
				}
			}
			else
			{
				if( i < 45)
				{
					file >> pass;		
					standardScripts[ i ] = pass;
					i++;
				}
			}
		}
		i++;
		if( i != 4 )
		{
			while( i < 5 )
			{
				standardScripts[ i ] = "NULL";
				i++;
			}
		}
		file.close();
	}
	else
		std::cerr << "Failure to open file " << info << ".\nPlease make sure you typed the path correctly and the\nfile exists and or exists in the directory specified." << std::endl;
}
void WSL::Singleton::BaseSend()
{
	input->refrence = engine;
	luabind::globals( engine->luaContainer->State )[ "input" ] = input;
	luabind::globals( engine->luaContainer->State )[ "stack" ] = engine->lua;
	GetCamera();
	GetSoundManager();
	sender->SendToLua();
}
void WSL::Singleton::SendObject( unsigned int id, int objID,  int componentID )
{
	currentInfo.SetID( id );
	currentInfo.SetObjID( objID );
	currentInfo.SetComponentID( componentID );
	SearchAlgorithum();
	objects.Array[ componentTrack ]->SetRefrence( engine );
	BaseSend();
	objects.Array[ componentTrack ]->SendSelf();
}
void WSL::Singleton::ThreadObject( unsigned int id, int objID,  int componentID )
{
	currentInfo.SetID( id );
	currentInfo.SetObjID( objID );
	currentInfo.SetComponentID( componentID );
	SearchAlgorithum();
	objects.Array[ componentTrack ]->SetRefrence( engine );
	objects.Array[ componentTrack ]->SendSelf();
}
void WSL::Singleton::EndObjectThread()
{
	unsigned int size =  objects.Array.size();
	for( unsigned int i = 0; i < size; ++i ) {
		objects.Array[ i ]->RunSubClassMethodEnd();
		objects.Array[ i ]->DeleteRefrence();
	}
}
void WSL::Singleton::GetLevel( unsigned int i )
{
	if( WSL::Algorithmic::BoolRangeCheck( i, levels.Array.size() ) == true ) {
		levels.Array[ i ]->SetRefrence( reinterpret_cast< WSL::Base::SingletonBase* >( this ) );
		luabind::globals( engine->luaContainer->State )[ levels.Array[ i ]->name ] = levels.Array[ i ];
	}
}
void WSL::Singleton::GetLevel( std::string name )
{
	unsigned int size = levels.Array.size();
	for( unsigned int i = 0; i < size; i++ )
	{
		if( name == levels.Array[ i ]->name )
		{
			levels.Array[ i ]->SetRefrence( reinterpret_cast< WSL::Base::SingletonBase* >( this ) );
			luabind::globals( engine->luaContainer->State )[ levels.Array[ i ]->name ] = levels.Array[ i ];
			break;
		}
		else if( i + 1 == size ) {
			std::cerr << "No level found with the name " << name << " a NULL value has been returned in method GetLevel( std::string )." << std::endl;
			break;
		}
	}
}
void WSL::Singleton::SetLevel( WSL::Algorithmic::Level* level, unsigned int i )
{
	if( WSL::Algorithmic::BoolRangeCheck( i, levels.Array.size() ) == true )
		levels.Array[ i ] = level;
	else
		std::cerr << "Element " << i << " no such levels, there are currently " << levels.Array.size() << " in existance." << std::endl;
}
void WSL::Singleton::SetLevel( WSL::Algorithmic::Level* level, std::string name )
{
	unsigned int size = levels.Array.size();
	for( unsigned int i = 0; i < size; i++ )
	{
		if( name == levels.Array[ i ]->name )
			levels.Array[ i ] = level;
		else if( i + 1 == size )
			std::cerr << "No level found with the name " << name << " no level was set for method SetLevel( Level*, std::string )." << std::endl;
			
	}
}
void WSL::Singleton::LoadImage( std::string name, std::string directory ) {
	engine->imageLibrary->AddImage( name, directory );
}
void WSL::Singleton::SendObjectToLua()
{
	unsigned int size = translators.size();
	if( size != 0 )
	{
		unsigned int i = 0;
		while( i < size )
		{
			if( translators[ i ]->GetComponentID() == currentInfo.GetComponentID() ) {
				translators[ i ]->SendToLua( objects.Array[ currentObject ], engine );
				break;
			}
			i++;
		}
	}
}
int WSL::Singleton::Instantiate( std::string info )
{
	LoadAlgorithim( info );
	unsigned int size = translators.size();
	if( size != 0 )
	{
		unsigned int i = 0;
		while( i < size )
		{
			if( translators[ i ]->GetComponentID() == currentInfo.GetComponentID() )
			{
				EndObjectThread();
				currentObject = objects.Array.size();
				objects.Add( translators[ i ]->Instantiate( standardScripts, startScripts, startScripts.size(),  
					initialize, refresh, runDestroy, destroy, currentInfo.GetObjID(), engine ) );
				unsigned int j = objects.Array.size() - 1;
				int compID = objects.Array[ j ]->GetComponentID();
				if( compID > highestComponentID )
					highestComponentID = compID;
				currentInfo.SetComponentID( compID );
				currentInfo.SetObjID( objects.Array[ j ]->GetObjID() );
				currentInfo.SetID( objects.Array[ j ]->GetID() );
				objects.Array[ j ]->SetRefrence( engine );
				objects.Array[ j ]->Initialize();
				objects.Array[ j ]->DeleteRefrence();
				break;
			}
			i++;
		}
	}
	return objects.Array.size() - 1;
}
int WSL::Singleton::InstantiateLevel( std::string info )
{
	std::ifstream file;
	file.open( info.c_str() );
	unsigned short int i = 0;
	while( file.eof() != true && file.is_open() == true ) {
		file >> levelScripts[ i ];
		i++;
	}
	WSL::Algorithmic::Level* temp = new WSL::Algorithmic::Level( true );
	temp->initializeScript = levelScripts[ 0 ];
	temp->refreshScript = levelScripts[ 1 ];
	temp->destroyScript = levelScripts[ 2 ];
	if( levelScripts[ 0 ] != "NULL" )
	{
		std::stringstream renderLayerName;
		renderLayerName << "levelRenderLayer";
		renderLayerName << levels.Array.size();
		temp->SetRefrence( this );
		temp->initialize = true;
		BaseSend();
		
		temp->SetRenderLayer( InstantiateRenderLayer( renderLayerName.str() ) );
		temp->SendRenderLayer();
		luabind::globals( engine->luaContainer->State )[ "level" ] = temp;
		temp->Initialize();
		temp->DeleteRefrence();
		if( temp->name == "" )
		{
			std::string name = "level";
			name += levels.Array.size();
			temp->name = name;
		}
	}
	else
	{
		temp->initialize = false;
		temp->name = "level";
	}
	levels.Add( temp );
	return levels.Array.size() - 1;
}
int WSL::Singleton::InstantiateRenderLayer() {
	renderLayers.Add( new WSL::Algorithmic::RenderLayer() );
	return renderLayers.Array.size() - 1;
}
int WSL::Singleton::InstantiateRenderLayer( std::string name )
{
	int times = 0;
	unsigned int size =  renderLayers.Array.size();
	for( unsigned int i = 0; i < size; ++i )
	{
		if( name == renderLayers.Array[ i ]->GetName() )
		{
			std::stringstream s;
			s  <<  name;
			s  <<  times;
			name = s.str();
			std::cerr  <<  "In method InstantiateRenderLayer( std::string ) render layer name "  <<  name  <<  "\n";
			std::cerr  <<  "Already taken replacing with "  <<  name  <<  std::endl;
			++times;
			i = 0;
		}
	}
	WSL::Algorithmic::RenderLayer* layer = new WSL::Algorithmic::RenderLayer;
	layer->SetName( name );
	renderLayers.Add( layer );
	return renderLayers.Array.size() - 1;
}
void WSL::Singleton::InitializeTranslators() {
	translators = SetUpTranslators( translators );
}
void WSL::Singleton::GetRenderLayer( unsigned int layer )
{
	if( WSL::Algorithmic::BoolRangeCheck( layer, renderLayers.Array.size() ) == true ) {
		renderLayers.Array[ layer ]->SetRefrence( this );
		luabind::globals( engine->luaContainer->State )[ "renderLayer" ] = renderLayers.Array[ layer ];
	}
	else
		std::cerr << "No render layer found with index " << layer << " please remain within the vector\nsubscript range for method GetRenderLayer( unsigned int )." << std::endl;
}
void WSL::Singleton::GetRenderLayerByLevel( unsigned int level )
{
	if( WSL::Algorithmic::BoolRangeCheck( level, levels.Array.size() ) == true )
	{
		levels.Array[ level ]->SetRefrence( reinterpret_cast< WSL::Base::SingletonBase* >( this ) );
		levels.Array[ level ]->SendRenderLayer();
		levels.Array[ level ]->DeleteRefrence();
	}
	else
		std::cerr << "No level found with index " << level << " please remain within the vector\nsubscript range for method GetRenderLayerByLevel( unsigned int )." << std::endl;
}
void WSL::Singleton::GetRenderLayerByLevel( std::string levelName )
{
	unsigned int size = levels.Array.size();
	if( size != 0 )
	{
		unsigned int i = 0;
		while( i < size )
		{
			if( levelName == levels.Array[ i ]->name )
			{
				levels.Array[ i ]->SetRefrence( reinterpret_cast< WSL::Base::SingletonBase* >( this ) );
				levels.Array[ i ]->SendRenderLayer();
				levels.Array[ i ]->DeleteRefrence();
				break;
			}
			++i;
		}
		if( i == size )
			std::cerr << "No level found with the name " << levelName << " in method GetRenderLayerByLevel( std::string )." << std::endl;
	}
	else
		std::cerr << "You attempted to accsess a level when none exist! For method GetRenderLayerByLevel( std::string )." << std::endl;
}
void WSL::Singleton::GetCamera() {
	luabind::globals( engine->luaContainer->State )[ "camera" ] = camera;
}
WSL::Containers::Base::XYZ WSL::Singleton::GetMousePosition() {
	sf::Vector2f coords = engine->window->ConvertCoords( engine->window->GetInput().GetMouseX(), engine->window->GetInput().GetMouseY() );
	return WSL::Containers::Base::XYZ( coords.x, coords.y, camera->z );
}
void WSL::Singleton::GetSoundManager() {
	luabind::globals( engine->luaContainer->State )[ "soundManager" ] = soundManager;
}
bool WSL::Singleton::CheckCollision( WSL::Collision::ScanAreaCollision::Rectangle rect1, WSL::Collision::ScanAreaCollision::Rectangle rect2)
{
	//Temporary code but
	//I needed it for the time beaing thank you Lightdark from the Elysian Shadows chat room!!!!!
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;
	float lowA, lowB;
	float highA, highB;
	leftA = rect1.x;
	rightA = rect1.x + rect1.w;
	topA = rect1.y;
	bottomA = rect1.y + rect1.h;
	leftB = rect2.x;
	rightB = rect2.x + rect2.w;
	topB = rect2.y;
	bottomB = rect2.y + rect2.h;
	//////////////////////////////
	highA = rect1.z;
	lowA = rect1.z + rect1.l;
	highB = rect2.z;
	lowB = rect2.z + rect2.l;
	///////////////////////////////
	if( bottomA <= topB )
		return false;
	if( topA >= bottomB )
		return false;
	if( rightA <= leftB )
		return false;
	if( leftA >= rightB )
		return false;
	if( rect1.l != 0 && rect2.l != 0 )
	{
		if( lowA <= highB )
			return false;
		if( highA >= lowB )
			return false;
	}
	//////////////////////////////
	return true;
}
WSL::Containers::BoolXYZ WSL::Singleton::CheckCollision( WSL::Collision::ScanAreaCollision::ScanArea a, WSL::Collision::ScanAreaCollision::ScanArea b, bool ThreeD )
{
	if( CheckCollision( a.GetR() , b.GetR() ) == true )
		return WSL::Containers::BoolXYZ( b.GetVector(), true );
	return WSL::Containers::BoolXYZ( WSL::Containers::Base::XYZ( 0, 0, 0 ), false );
}

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
/*
	Collision::Collision_Engine_Base Engine;
	Collision::Scan_Area_Collision::Scan_Area Scan( 100, 200, 0 );
	Collision::Scan_Area_Collision::Scan_Area Scan2( 500, 400, 0 );
	Collision::Scan_Area_Collision::Scan_Area Scan3( 100, 300, 0 );
	Collision::Scan_Area_Collision::Collision_Detector CD;
	Scan = Engine.Initialize_Scan_Area( Scan, "Scan Areas/Test.txt" );
	Scan2 = Engine.Initialize_Scan_Area( Scan2, "Scan Areas/Odd.txt" );
	Scan3 = Engine.Initialize_Scan_Area( Scan3, "Scan Areas/Scan3.txt" );
	bool Run = true;
	float x, y, z;
	x = Scan.getX();
	y = Scan.getY();
	z = Scan.getZ();
	float Speed = 6;
	sf::Event E;
	float Degree = 0;
	bool Debug = false;
	//WSD::Console K(Graphics::SFML::App);
	while( Run == true )
	{
		//K.GetKeyInput();
		//K.DrawConsole();
		while( Graphics::SFML::App.GetEvent( E ) )
		{
			if( Graphics::SFML::App.GetInput().IsKeyDown( sf::Key::W ) )
				y -= Speed;
			if( Graphics::SFML::App.GetInput().IsKeyDown( sf::Key::S ) )
				y += Speed;
			if( Graphics::SFML::App.GetInput().IsKeyDown( sf::Key::A ) )
				x -= Speed;
			if( Graphics::SFML::App.GetInput().IsKeyDown( sf::Key::D ) )
				x += Speed;
			if( Graphics::SFML::App.GetInput().IsKeyDown( sf::Key::Up ) )
				z += 1;
			if( Graphics::SFML::App.GetInput().IsKeyDown( sf::Key::Down ) )
				z -= 1;
			if( Graphics::SFML::App.GetInput().IsKeyDown( sf::Key::Left ) )
			{
				Degree = -5;
			}
			if( Graphics::SFML::App.GetInput().IsKeyDown( sf::Key::Right ) )
			{
				Degree = 5;
			}
			if( Graphics::SFML::App.GetInput().IsKeyDown( sf::Key::LShift ) )
			{
				if( Debug == false )
				{ std::cout<<"Debug Mode Active!"<<std::endl;				
				Debug = true; }
				else
				{ std::cout<<"Debug Mode Disabled."<<std::endl;
				Debug = false; }
			}
			Scan.setX( x );
			Scan.setY( y );
			Scan.setZ( z );
			break;
		}
		Graphics::SFML::App.Clear();
		Scan = Engine.Run( Scan, true, Degree, true );
		Scan2 = Engine.Run( Scan2, true, 3, true );
		Scan3 = Engine.Run( Scan3, true, 10, true );
		Scan2.setZ( Scan.getZ() );
		CD.Detect_Collision( Scan, Scan2, false, true );
		CD.Detect_Collision( Scan3, Scan, false, true );
		Graphics::SFML::App.Display();
		Degree = 0;
	}
	std::cin.get();
	std::cout<<"Reacing conclusion of Proper: "<<std::endl;
	std::cout<<"	Main Procedure."<<std::endl;
}*/
/*
float xc, yc;
		xc = Scan.getX() + V.getX();
		yc = Scan.getY() + V.getY();
		VO << xc;
		VO << yc;
		Scan.setX( xc );
		Scan.setY( yc );
		float x, y, a, PI2;
		x = V.getX();
		y = V.getY();
		PI2 = 3.14 * 2;
		a = atan2(x, y);
		if(a < 0)
			a+=PI2;
		a *= 180 / 3.14;*/
		//std::cout<<V.getX()<<V.getY()<<std::endl;





	/*WSL::White_Storm_Lightning.Image_Library.Add_Image( "Knight", "Images/Test_Sheet.png" );
	WSL::Main::Viewable Vbl;
	Vbl.Add_Image( 0 );
	Vbl.Set_Image( 0 );
	Vbl.Set_Up_Sprite( 200, 300, 28, 56 );
	unsigned int CA = Vbl.Add_Animation();
	Vbl.setAnimate( CA, true );
	Vbl.Add_Image_To_Animation( CA, 0 );
	Vbl.setAnimate_Beginning_To_End( true );
	Vbl.set_Animation_Type( false, CA );
	Vbl.Set_Up_Sprite_Sheet( 28, 56, 32, 0, 4, 6, 192, 112, true, false, CA );
	Vbl.setAnimation_Animation_Delay( CA, 50 );
	while( true )
	{
		Graphics::SFML::App.Clear();
		Vbl.Rotate( .2 );
		Vbl.Update_Sprite();
		Vbl.Render();
		Graphics::SFML::App.Display();
	}*//*
void WSL::Algorithmic::Level::AddObject( unsigned int id, unsigned int objID )
{
	unsigned int i = 0;
	unsigned int i2;
	unsigned int size2;
	unsigned int size = refrence->engine->objectTracker.ObjectRegisters.size();
	if( size != 0 )
	{
		while( i < size )
		{
			if( refrence->engine->objectTracker.ObjectRegisters[i].componentID == 0 )
			{
				i2 = 0;
				size2 = refrence->entities.Array.size();
				while( i2 < size2 )
				{
					if( objID == refrence->entities.Array[i2]->GetObjID() )
					{
						if( id == refrence->entities.Array[i2]->GetID() )
						{
							entities.AddObject( i2 );
						}
					}
					i2++;
				}
			}
			if( refrence->engine->objectTracker.ObjectRegisters[i].componentID == 1 )
			{
				i2 = 0;
				size2 = refrence->positionals.Array.size();
				while( i2 < size2 )
				{
					if( objID == refrence->positionals.Array[i2]->GetObjID() )
					{
						if( id == refrence->positionals.Array[i2]->GetID() )
						{
							positionals.AddObject( i2 );
						}
					}
					i2++;
				}
			}
			if( refrence->engine->objectTracker.ObjectRegisters[i].componentID == 2 )
			{
				i2 = 0;
				size2 = refrence->mobiles.Array.size();
				while( i2 < size2 )
				{
					if( objID == refrence->mobiles.Array[i2]->GetObjID() )
					{
						if( id == refrence->mobiles.Array[i2]->GetID() )
						{
							mobiles.AddObject( i2 );
						}
					}
					i2++;
				}
			}
			i++;
		}
	}
}*//*
WSL::Framework::Standard::Base::Entity* WSL::Algorithmic::Level::GetEntity( unsigned int id, int objID )
{
	refrence->currentInfo.SetComponentID( 0 );
	refrence->currentInfo.SetID( id );
	refrence->currentInfo.SetObjID( objID );
	unsigned int element = SearchAlgorithim( id, objID, 0 );
	refrence->ThreadEntity();
	return refrence->entities.Array[element];
}
WSL::Framework::Standard::Positional* WSL::Algorithmic::Level::GetPositional( unsigned int id, int objID )
{
	refrence->currentInfo.SetComponentID( 1 );
	refrence->currentInfo.SetID( id );
	refrence->currentInfo.SetObjID( objID );
	unsigned int element = SearchAlgorithim( id, objID, 1 );
	refrence->ThreadPositional();
	return refrence->positionals.Array[element];
}
WSL::Framework::Standard::Mobile* WSL::Algorithmic::Level::GetMobile( unsigned int id, int objID )
{
	refrence->currentInfo.SetComponentID( 2 );
	refrence->currentInfo.SetID( id );
	refrence->currentInfo.SetObjID( objID );
	unsigned int element = SearchAlgorithim( id, objID, 2 );
	refrence->ThreadMobile();
	return refrence->mobiles.Array[element];
}
void WSL::Algorithmic::Level::SetObject( unsigned int id, int objID, WSL::Framework::Standard::Base::Entity *object )
{
	unsigned int element = SearchAlgorithim( id, objID, 0 );
	WSL::Framework::Standard::Base::Entity *temp = refrence->entities.Array[element];
	temp = object;
}
void WSL::Algorithmic::Level::SetObject( unsigned int id, int objID, WSL::Framework::Standard::Positional *object )
{
	unsigned int element = SearchAlgorithim( id, objID, 1 );
	WSL::Framework::Standard::Positional *temp = refrence->positionals.Array[element];
	temp = object;
}
void WSL::Algorithmic::Level::SetObject( unsigned int id, int objID, WSL::Framework::Standard::Mobile *object )
{
	unsigned int element = SearchAlgorithim( id, objID, 1 );
	WSL::Framework::Standard::Base::Entity *temp = refrence->mobiles.Array[element];
	temp = object;
}
/*
unsigned int WSL::Algorithmic::Level::SearchAlgorithim( unsigned int id, int objID, int componentID )
{
	unsigned int size;
	unsigned int i = 0;
	Update( refrence->entities.node, refrence->positionals.node, refrence->mobiles.node );
	if( componentID == 0 )
	{
		size = entities.GetObjects().size();
		if( size != 0 )
		{
			while( i < size )
			{
				if( entities.DoesObjectExist( i ) == true )
					return entities.GetObjectElement( i );
				i++;
			}
		}
	}
	else
	{
		if( componentID == 1 )
		{
			size = positionals.GetObjects().size();
			if( size != 0 )
			{
				while( i < size )
				{
					if( positionals.DoesObjectExist( i ) == true )
						return positionals.GetObjectElement( i );
					i++;
				}
			}
		}
		else
		{
			if( componentID == 2 )
			{
				size = mobiles.GetObjects().size();
				if( size != 0 )
				{
					while( i < size )
					{
						if( mobiles.DoesObjectExist( i ) == true )
							return mobiles.GetObjectElement( i );
						i++;
					}
				}
			}
		}
	}
	return 0;
}
*/
/*
void WSL::Algorithmic::Level::Update( WSL::Algorithmic::SenderNode entityNode, WSL::Algorithmic::SenderNode positionalNode, WSL::Algorithmic::SenderNode mobileNode )
{
	entities.SetRefrence( refrence->engine );
	entities.Update( entityNode );
	entities.DeleteRefrence();
	positionals.SetRefrence( refrence->engine );
	positionals.Update( positionalNode );
	positionals.DeleteRefrence();
	mobiles.SetRefrence( refrence->engine );
	mobiles.Update( mobileNode );
	mobiles.DeleteRefrence();
}*//*
}*/

/*
//-----Refrence-----//
void WSL::Singleton::InstantiateEntity( std::string info )
{
	LoadAlgorithim( info );
	WSL::Framework::Standard::Base::Entity *temp = new WSL::Framework::Standard::Base::Entity( currentInfo.GetObjID(), refresh, 
						destroy, Initialize, runDestroy, standardScripts[1], standardScripts[0],
						standardScripts[2], standardScripts[3], engine );
	RunEntitiyScripts( temp );
	BaseSend();
	temp->SetRefrence( engine );
	luabind::globals( engine->luaContainer->State )[ "entity" ] = temp;
	temp->Initialize();
	temp->DeleteRefrence();
	entities.Add( temp );
}
void WSL::Singleton::InstantiatePositional( std::string info )
{
	LoadAlgorithim( info );
	WSL::Framework::Standard::Positional *temp = new WSL::Framework::Standard::Positional( currentInfo.GetObjID(), refresh, 
						destroy, Initialize, runDestroy, standardScripts[1], standardScripts[0],
						standardScripts[2], standardScripts[3], standardScripts[4], engine );
	RunPositionalScripts( temp );
	BaseSend();
	temp->SetRefrence( engine );
	luabind::globals( engine->luaContainer->State )[ "positional" ] = temp;
	temp->Initialize();
	temp->DeleteRefrence();
	positionals.Add( temp );
}
void WSL::Singleton::InstantiateMobile( std::string info )
{
	LoadAlgorithim( info );
	WSL::Framework::Standard::Mobile *temp = new WSL::Framework::Standard::Mobile( currentInfo.GetObjID(), refresh, 
						destroy, Initialize, runDestroy, standardScripts[1], standardScripts[0],
						standardScripts[2], standardScripts[3], standardScripts[4], engine );
	RunMobileScripts( temp );
	BaseSend();
	temp->SetRefrence( engine );
	luabind::globals( engine->luaContainer->State )[ "mobile" ] = temp;
	temp->Initialize();
	temp->DeleteRefrence();
	mobiles.Add( temp );
}
*/
/*
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
*//*
#include "Vector Calculator.h"
WSL::Math::Vector::VectorCalculator::VectorCalculator()
{
	WSL::Containers::Base::XYZ temp;
	temp.setX( 1.f );
	temp.setY( 1.f );
	temp.setZ( 1.f );
	default_ = temp;
}
WSL::Containers::Base::XYZ WSL::Math::Vector::VectorCalculator::VectorCalculation( WSL::Containers::Base::XYZ destination, WSL::Containers::Base::XYZ position, float speed, bool td )
{
	WSL::Containers::Base::XYZ magnitude;
	if( speed <= 0 + std::numeric_limits<float>::epsilon() )
		speed = 1;
    magnitude.setX( destination.getX() - position.getX() );
    magnitude.setY( destination.getY() - position.getY() );
    magnitude.setZ( destination.getZ() - position.getZ() );
    
    if( magnitude.getX() <= 0 + std::numeric_limits<float>::epsilon()
		&& magnitude.getY() <= 0 + std::numeric_limits<float>::epsilon()
		&& magnitude.getZ() <= 0 + std::numeric_limits<float>::epsilon() )
		return ( WSL::Containers::Base::XYZ() );
    float mag = ( magnitude.getY() * magnitude.getY() ) +
        ( magnitude.getX() * magnitude.getX() ) +
        ( magnitude.getZ() * magnitude.getZ() );
    
    mag = sqrt( mag );
    
    magnitude.setX( ( magnitude.getX() / mag ) * speed );
    magnitude.setY( ( magnitude.getY() / mag ) * speed );
    magnitude.setZ( ( magnitude.getZ() / mag ) * speed );
 */   
   // return magnitude;
	/*//Make sure that the vector doesent have any stray values lying around.//
	vector = default_;
	//Calculate Magnitude.//
	x = goTo.getX() - position.getX();
	y = goTo.getY() - position.getY();
	z = goTo.getZ() - position.getZ();
	if( td == true )
		magnitude = magn.DotProduct( x, y, z, magnitude );
	else
		magnitude = magn.DotProduct( x, y, magnitude );
	if( x == 0 && y == 0 && z == 0 )
		return vector;
	//Normilise//
	magnitude = sqrt( magnitude );
	//Make sure we do not divide by zero.//
	if( magnitude != 0 )
	{
		if( x != 0 )
			x /= magnitude;
		if( x != 0 && x >= 0 )
			std::cerr << "X is good!\n";
		if( y != 0 )	
			y /= magnitude;
		if( td == true )
			if( z != 0 )
				z /= magnitude;
	}
	//Go The Desired Speed.//
	if( speed >=0 )
	{
		x *= speed;
		y *= speed;
	}
	if( td == true )
		z *= speed;
	vector.setX( x );
	vector.setY( y );
	vector.setZ( z );
	return vector;*/
/*}
WSL::Containers::Base::XYZ WSL::Math::Vector::VectorCalculator::VectorCalculation( WSL::Containers::Base::XYZ destination, WSL::Containers::Base::XYZ *position, float speed, bool td )
{
	WSL::Containers::Base::XYZ magnitude;
	if( speed <= 0 + std::numeric_limits<float>::epsilon() )
		speed = 1;
    magnitude.setX( destination.getX() - position->getX() );
    magnitude.setY( destination.getY() - position->getY() );
    magnitude.setZ( destination.getZ() - position->getZ() );
    
    if( magnitude.getX() <= 0 + std::numeric_limits<float>::epsilon()
		&& magnitude.getY() <= 0 + std::numeric_limits<float>::epsilon()
		&& magnitude.getZ() <= 0 + std::numeric_limits<float>::epsilon() )
        return ( WSL::Containers::Base::XYZ() );
    float mag = ( magnitude.getY() * magnitude.getY() ) +
        ( magnitude.getX() * magnitude.getX() ) +
        ( magnitude.getZ() * magnitude.getZ() );
    
    mag = sqrt( mag );
    
    magnitude.setX( ( magnitude.getX() / mag ) * speed );
    magnitude.setY( ( magnitude.getY() / mag ) * speed );
    magnitude.setZ( ( magnitude.getZ() / mag ) * speed );
    
    return magnitude;
*/
	/*//Make sure that the vector doesent have any stray values lying around.//
	vector = default_;
	//Calculate Magnitude.//
	x = goTo.getX() - position->getX();
	y = goTo.getY() - position->getY();
	z = goTo.getZ() - position->getZ();
	if( td == true )
		magnitude = magn.DotProduct( x, y, z, magnitude );
	else
		magnitude = magn.DotProduct( x, y, magnitude );
	if( x == 0 && y == 0 && z == 0 )
		return vector;
	//Normilise//
	magnitude = sqrt( magnitude );
	//Make sure we do not divide by zero.//
	if( magnitude != 0 )
	{
		x /= magnitude;
		y /= magnitude;
		if( td == true )
			z /= magnitude;
	}
	//Go The Desired Speed.//
	if( speed >= 0 )
	{
		x *= speed;
		y *= speed;
	}
	if( td == true )
		z *= speed;
	vector.setX( x );
	vector.setY( y );
	vector.setZ( z );
	return vector;*/
/*}
inline float WSL::Math::Formulas::Dot::DotProduct( float x, float y, float mag )
{
	return ( mag = ( ( x ) * ( x ) + ( y ) * ( y ) ) );
}
inline float WSL::Math::Formulas::Dot::DotProduct( float x, float y, float z, float mag )
{
	return ( mag = ( ( x ) * ( x ) + ( y ) * ( y ) + ( z ) * ( z ) ) );
}
*/
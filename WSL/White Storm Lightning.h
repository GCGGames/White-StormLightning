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
#include "Singleton Sender.h"
namespace WSL
{
	static void ( *Recurse )( WSL::Singleton* );
	static void LuaRegister( WSL::Engine *engine )
	{
		luabind::open( engine->luaContainer->State );
		//-----Component-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Base::Component>( "Component" )
				.def( luabind::constructor<>() )
				.def( "GetElement", &WSL::Components::Base::Component::GetElement )
				.def( "GetID", &WSL::Components::Base::Component::GetID )
				.def( "GetObjectID", &WSL::Components::Base::Component::GetObjectID )
				.def( "GetComponentID", &WSL::Components::Base::Component::GetComponentID )
				.def( "GetUpdateData", &WSL::Components::Base::Component::GetUpdateData )
				.def( "SetElement", &WSL::Components::Base::Component::SetElement )
				.def( "SetUpdateData", &WSL::Components::Base::Component::SetUpdateData )
		];
		//-----sf::Color-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<sf::Color>( "SFMLColor" )
				.def( luabind::constructor<>() )
		];
		//-----Wrapped Color-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Containers::Scripting::Lua::ColorWrap>( "ColorWrap" )
				.def( luabind::constructor< unsigned short, unsigned short, unsigned short >() )
				.def( luabind::constructor< sf::Color >() )
				.def( luabind::constructor<>() )
				.def( "SetColor", &WSL::Containers::Scripting::Lua::ColorWrap::SetColor )
				.def( "GetColor", &WSL::Containers::Scripting::Lua::ColorWrap::GetColor )
		];
		//-----Animation Data-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Algorithimic::Base::AnimationData>( "AnimationData" )
				.def( luabind::constructor<>() )
		];
		//-----All Animaition Data-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Algorithimic::SubBase::AllAnimationData, WSL::Components::Algorithimic::Base::AnimationData>( "AllAnimationData" )
				.def( luabind::constructor<>() )
		];
		//-----Animation-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Algorithimic::Animation, WSL::Components::Algorithimic::Base::AnimationData>( "Animation" )
				.def( luabind::constructor<>() )
				.def( "GetAnimate", &WSL::Components::Algorithimic::Animation::GetAnimate )
				.def( "GetDelay", &WSL::Components::Algorithimic::Animation::GetDelay )
				.def( "GetSize", &WSL::Components::Algorithimic::Animation::GetSize )
				.def( "GetType", &WSL::Components::Algorithimic::Animation::GetType )
				.def( "SetAnimate", &WSL::Components::Algorithimic::Animation::SetAnimate )
				.def( "SetCurrentFrame", &WSL::Components::Algorithimic::Animation::SetCurrentFrame )
				.def( "SetDelay", &WSL::Components::Algorithimic::Animation::SetDelay )
				.def( "SetType", (void(WSL::Components::Algorithimic::Animation::*)(bool))&WSL::Components::Algorithimic::Animation::SetType )
				.def( "AddImage", &WSL::Components::Algorithimic::Animation::AddImage )
				.def( "AnimateImages", &WSL::Components::Algorithimic::Animation::AnimateImages )
				.def( "AnimateSheet", &WSL::Components::Algorithimic::Animation::AnimateSheet )
				.def( "DeleteImage", &WSL::Components::Algorithimic::Animation::DeleteImage )
				.def( "GatherData", &WSL::Components::Algorithimic::Animation::GatherData )
				.def( "ReplaceData", &WSL::Components::Algorithimic::Animation::ReplaceData )
				.def( "Reset", &WSL::Components::Algorithimic::Animation::Reset )
				.def( "Restore", &WSL::Components::Algorithimic::Animation::Restore )
				.def( "SetUpSpriteSheet", (void(WSL::Components::Algorithimic::Animation::*)(int,int,int,int,int,int,bool,bool))&WSL::Components::Algorithimic::Animation::SetUpSpriteSheet )
				.def( "SetUpSpriteSheet", (void(WSL::Components::Algorithimic::Animation::*)(int,int,int,int,int,int,int,int,bool,bool))&WSL::Components::Algorithimic::Animation::SetUpSpriteSheet )
		];
		//-----Render Functional-----//
		luabind::module( engine->luaContainer->State )[
		luabind::class_<WSL::Components::Rendering_System::Base::Render_Functonal, WSL::Components::Base::Component>( "RenderFunctonal" )
			.def( luabind::constructor<>() )
			.def( "SetRenderLayer", &WSL::Components::Rendering_System::Base::Render_Functonal::SetRenderLayerName )
			.def( "GetRenderLayer", &WSL::Components::Rendering_System::Base::Render_Functonal::GetRenderLayerName )
		];
		//-----Lightning Sprite-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Rendering_System::Base::Render_Base<sf::Sprite>, WSL::Components::Rendering_System::Base::Render_Functonal>( "RenderBase" )
				.def( luabind::constructor<>() )
		];
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Rendering_System::Base::SubBase::SFMLType<sf::Sprite>, WSL::Components::Rendering_System::Base::Render_Base<sf::Sprite>>( "SFMLType" )
				.def( luabind::constructor<>() )
		];
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Lightning_Sprite, WSL::Components::Rendering_System::Base::SubBase::SFMLType<sf::Sprite> >( "Lightning_Sprite" )
				.def( luabind::constructor<>() )
				.def( "Rotate", &WSL::Components::Lightning_Sprite::Rotate )
				.def( "Resize", (void(WSL::Components::Lightning_Sprite::*)(float,float))&WSL::Components::Lightning_Sprite::Resize )
				.def( "Resize", (void(WSL::Components::Lightning_Sprite::*)(float))&WSL::Components::Lightning_Sprite::Resize )
				.def( "AddAnimation", &WSL::Components::Lightning_Sprite::AddAnimation )
				.def( "SetImage", &WSL::Components::Lightning_Sprite::SetImage )
				.def( "SetUpSprite", (void(WSL::Components::Lightning_Sprite::*)(float,float,bool))&WSL::Components::Lightning_Sprite::SetUpSprite )
				.def( "SetUpSprite", (void(WSL::Components::Lightning_Sprite::*)(float,float,unsigned int,bool,WSL::Global::Image_Library*))&WSL::Components::Lightning_Sprite::SetUpSprite )
				.def( "SetUpSprite", (void(WSL::Components::Lightning_Sprite::*)(unsigned int,bool, WSL::Global::Image_Library*))&WSL::Components::Lightning_Sprite::SetUpSprite )
				.def( "Scale", (void(WSL::Components::Lightning_Sprite::*)(float,float))&WSL::Components::Lightning_Sprite::Scale )
				.def( "Scale", (void(WSL::Components::Lightning_Sprite::*)(float))&WSL::Components::Lightning_Sprite::Scale)
				.def( "SetImage", &WSL::Components::Lightning_Sprite::SetImage )
				.def( "GetPosition", &WSL::Components::Lightning_Sprite::getPosition )
				.def( "SetPosition", (void(WSL::Components::Lightning_Sprite::*)(float,float))&WSL::Components::Lightning_Sprite::SetPosition )
				.def( "SetPosition", (void(WSL::Components::Lightning_Sprite::*)(float,float,float))&WSL::Components::Lightning_Sprite::SetPosition )
				.def( "SetPosition", (void(WSL::Components::Lightning_Sprite::*)(WSL::Containers::Base::XYZ))&WSL::Components::Lightning_Sprite::SetPosition )
				.def( "SetDraw", &WSL::Components::Lightning_Sprite::SetDraw )
				.def( "GetDraw", &WSL::Components::Lightning_Sprite::GetDraw )
				.def( "AddAnimationToSingleton", &WSL::Components::Lightning_Sprite::AddAnimationToSingleton )
				.def( "AddAnimation", &WSL::Components::Lightning_Sprite::AddAnimation )
				.def( "SetAnimate", &WSL::Components::Lightning_Sprite::SetAnimate )
				.def( "SetCurrentAnimation", &WSL::Components::Lightning_Sprite::SetCurrentAnimation )
				.def( "SetAnimateFistToLast", &WSL::Components::Lightning_Sprite::SetAnimateFirstToLast )
				.def( "SetRefrence", &WSL::Components::Lightning_Sprite::SetRefrence )
				.def( "GetAnimate", &WSL::Components::Lightning_Sprite::GetAnimate )
				.def( "GetCurrentAnimation", &WSL::Components::Lightning_Sprite::GetCurrentAnimation )
				.def( "GetAnimateFirstToLast", &WSL::Components::Lightning_Sprite::GetAnimateFirstToLast )
				.def( "DeleteRefrence", &WSL::Components::Lightning_Sprite::DeleteRefrence )
				.def( "SendAnimation", &WSL::Components::Lightning_Sprite::SendAnimation )
		];
		//-----Polygon-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Rendering_System::Base::Render_Base<sf::Shape>, WSL::Components::Rendering_System::Base::Render_Functonal>( "RenderBase" )
				.def( luabind::constructor<>() )
				.def( "AddPoint", (void(WSL::Components::Polygon::*)(float,float,float))&WSL::Components::Polygon::AddPoint)
				.def( "AddPoint", (void(WSL::Components::Polygon::*)(float,float))&WSL::Components::Polygon::AddPoint)
				.def( "AddPoint", (void(WSL::Components::Polygon::*)(WSL::Containers::Base::XYZ))&WSL::Components::Polygon::AddPoint)
				.def( "Rotate", &WSL::Components::Polygon::Rotate )
				.def( "SetDraw", &WSL::Components::Polygon::SetDraw )
				.def( "GetDraw", &WSL::Components::Polygon::GetDraw )
				.def( "SetColor", (void(WSL::Components::Polygon::*)(WSL::Containers::Scripting::Lua::ColorWrap))&WSL::Components::Polygon::SetColor )
				.def( "SetColor", (void(WSL::Components::Polygon::*)(sf::Color))&WSL::Components::Polygon::SetColor )
				.def( "GetColor", &WSL::Components::Polygon::getColor )
		];
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Rendering_System::Base::SubBase::SFMLType<sf::Shape>, WSL::Components::Rendering_System::Base::Render_Base<sf::Shape>>( "SFMLType" )
				.def( luabind::constructor<>() )
		];
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Polygon, WSL::Components::Rendering_System::Base::SubBase::SFMLType<sf::Shape> >( "Lightning_Sprite" )
				.def( luabind::constructor<>() )
				.def( "Rotate", &WSL::Components::Polygon::Rotate )
				.def( "Scale", (void(WSL::Components::Polygon::*)(float,float))&WSL::Components::Polygon::Scale )
				.def( "Scale", (void(WSL::Components::Polygon::*)(float))&WSL::Components::Polygon::Scale )
				.def( "GetPosition", &WSL::Components::Polygon::getPosition )
				.def( "SetPosition", (void(WSL::Components::Polygon::*)(float,float))&WSL::Components::Polygon::SetPosition )
				.def( "SetPosition", (void(WSL::Components::Polygon::*)(float,float,float))&WSL::Components::Polygon::SetPosition )
				.def( "SetPosition", (void(WSL::Components::Polygon::*)(WSL::Containers::Base::XYZ))&WSL::Components::Polygon::SetPosition )
				.def( "SetDraw", &WSL::Components::Polygon::SetDraw )
				.def( "GetDraw", &WSL::Components::Polygon::GetDraw )
		];
		//-----Vector Graphics-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::VectorGraphicsComponent, WSL::Components::Rendering_System::Base::Render_Functonal>( "VectorGraphicsComponent" )
				.def( luabind::constructor<>() )
		];
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Rendering_System::Base::Render_Base<WSL::Components::VectorGraphicsComponent>, WSL::Components::Rendering_System::Base::Render_Functonal>( "RenderBase" )
				.def( luabind::constructor<>() )
		];
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Components::Vector_Graphics, WSL::Components::Rendering_System::Base::Render_Base<WSL::Components::VectorGraphicsComponent>>( "VectorGraphics" )
				.def( luabind::constructor<>() )
				.def( "Rotate", &WSL::Components::Vector_Graphics::Rotate )
				.def( "SetDraw", &WSL::Components::Vector_Graphics::SetDraw )
				.def( "GetDraw", &WSL::Components::Vector_Graphics::GetDraw )
				.def( "SetColor", (void(WSL::Components::Vector_Graphics::*)( WSL::Containers::Scripting::Lua::ColorWrap ))&WSL::Components::Vector_Graphics::setColor )
				.def( "SetColor", (void(WSL::Components::Vector_Graphics::*)( sf::Color ))&WSL::Components::Vector_Graphics::setColor )
				.def( "GetColor", &WSL::Components::Vector_Graphics::getColor )
		];
		//-----XYZ Base-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Containers::Base::XYZB>( "XYZB" )
				.def( luabind::constructor<>() )
				.def( "GetX", &WSL::Containers::Base::XYZ::getX )
				.def( "GetY", &WSL::Containers::Base::XYZ::getY )
				.def( "GetZ", &WSL::Containers::Base::XYZ::getZ )
				.def( "SetX", &WSL::Containers::Base::XYZ::setX )
				.def( "SetY", &WSL::Containers::Base::XYZ::setY )
				.def( "SetZ", &WSL::Containers::Base::XYZ::setZ )
		];
		//-----XYZ-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Containers::Base::XYZ, WSL::Containers::Base::XYZB>( "XYZ" )
				.def( luabind::constructor<>() )
				.def( "GetX", &WSL::Containers::Base::XYZ::getX )
				.def( "GetY", &WSL::Containers::Base::XYZ::getY )
				.def( "GetZ", &WSL::Containers::Base::XYZ::getZ )
				.def( "SetX", &WSL::Containers::Base::XYZ::setX )
				.def( "SetY", &WSL::Containers::Base::XYZ::setY )
				.def( "SetZ", &WSL::Containers::Base::XYZ::setZ )
		];
		//-----Vector-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Containers::Math::Vector>( "Vector" )
				.def( luabind::constructor<>() )
				.def( "CalculateVector", &WSL::Containers::Math::Vector::CalculateVector )
				.def( "GetDestination", &WSL::Containers::Math::Vector::GetDestination )
				.def( "GetDestinationX", &WSL::Containers::Math::Vector::GetDestinationX )
				.def( "GetDestinationY", &WSL::Containers::Math::Vector::GetDestinationY )
				.def( "GetDestinationZ", &WSL::Containers::Math::Vector::GetDestinationZ )
				.def( "GetPosition", &WSL::Containers::Math::Vector::GetPosition )
				.def( "GetThreeDimentional", &WSL::Containers::Math::Vector::GetThreeDimentional )
				.def( "GetVector", &WSL::Containers::Math::Vector::GetVector )
				.def( "GetX", &WSL::Containers::Math::Vector::GetX )
				.def( "GetY", &WSL::Containers::Math::Vector::GetY )
				.def( "GetZ", &WSL::Containers::Math::Vector::GetZ )
				.def( "GetSpeed", &WSL::Containers::Math::Vector::GetSpeed )
				.def( "Move", &WSL::Containers::Math::Vector::Move )
				.def( "SetDestination", (void(WSL::Containers::Math::Vector::*)(float))&WSL::Containers::Math::Vector::SetDestination )
				.def( "SetDestination", (void(WSL::Containers::Math::Vector::*)(float,float))&WSL::Containers::Math::Vector::SetDestination )
				.def( "SetDestination", (void(WSL::Containers::Math::Vector::*)(float,float,float))&WSL::Containers::Math::Vector::SetDestination )
				.def( "SetDestination", (void(WSL::Containers::Math::Vector::*)(WSL::Containers::Base::XYZ))&WSL::Containers::Math::Vector::SetDestination )
				.def( "SetPosition", &WSL::Containers::Math::Vector::SetPosition )
				.def( "SetSpeed", &WSL::Containers::Math::Vector::SetSpeed )
				.def( "SetThreeDimentional", &WSL::Containers::Math::Vector::SetThreeDimentional )
				.def( "SetVector", &WSL::Containers::Math::Vector::SetVector )
		];
		//-----Bool XYZ-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Containers::Bool_XYZ>( "BoolXYZ" )
				.def( luabind::constructor<>() )
					.def( "GetBool", &WSL::Containers::Bool_XYZ::getBool )
					.def( "GetCoords", &WSL::Containers::Bool_XYZ::getCoords )
					.def( "SetBool", &WSL::Containers::Bool_XYZ::setBool )
					.def( "SetCoords", &WSL::Containers::Bool_XYZ::setCoords )
		];
		//-----Rectangle-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Collision::Scan_Area_Collision::Rectangle>( "Rectangle__" )
				.def( luabind::constructor<>() )
				.def_readwrite( "x", &WSL::Collision::Scan_Area_Collision::Rectangle::x )
				.def_readwrite( "y", &WSL::Collision::Scan_Area_Collision::Rectangle::y )
				.def_readwrite( "z", &WSL::Collision::Scan_Area_Collision::Rectangle::z )
				.def_readwrite( "w", &WSL::Collision::Scan_Area_Collision::Rectangle::w )
				.def_readwrite( "h", &WSL::Collision::Scan_Area_Collision::Rectangle::h )
				.def_readwrite( "l", &WSL::Collision::Scan_Area_Collision::Rectangle::l )
		];
		//-----IDXYZ-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_< WSL::Containers::IDXYZ >( "IDXYZ" )
				.def( luabind::constructor<>() )
				.def( "GetID", &WSL::Containers::IDXYZ::GetID )
				.def( "GetObjectID", &WSL::Containers::IDXYZ::GetObjectID )
				.def( "GetComponentID", &WSL::Containers::IDXYZ::GetComponentID )
				.def( "GetPoint", &WSL::Containers::IDXYZ::GetPoint )
				.def( "SetID", &WSL::Containers::IDXYZ::SetID )
				.def( "SetObjectID", &WSL::Containers::IDXYZ::SetObjectID )
				.def( "SetComponentID", &WSL::Containers::IDXYZ::SetComponentID )
				.def( "SetPoint", &WSL::Containers::IDXYZ::SetPoint )
		];
		//-----Scan Area-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Collision::Scan_Area_Collision::Scan_Area, WSL::Components::Base::Component>( "ScanArea" )
				.def( luabind::constructor<>() )
				.def( "GetCollide", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetCollide )
				.def( "SetCollide", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetCollide )
				.def( "GetCollision", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetCollision )
				.def( "SetCollision", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetCollision )
				.def( "SetX", &WSL::Collision::Scan_Area_Collision::Scan_Area::setX )
				.def( "SetY", &WSL::Collision::Scan_Area_Collision::Scan_Area::setY )
				.def( "SetZ", &WSL::Collision::Scan_Area_Collision::Scan_Area::setZ )
				.def( "GetX", &WSL::Collision::Scan_Area_Collision::Scan_Area::getX )
				.def( "GetY", &WSL::Collision::Scan_Area_Collision::Scan_Area::getY )
				.def( "GetZ", &WSL::Collision::Scan_Area_Collision::Scan_Area::getZ )
				.def( "GetVector", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetVector )
				.def( "SetVector", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetVector )
				.def( "SetLargeX", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetLargeX )
				.def( "SetSmallX", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetSmallX )
				.def( "SetLargeY", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetLargeY )
				.def( "SetSmallY", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetSmallY )
				.def( "SetLargeZ", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetLargeZ )
				.def( "SetSmallZ", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetSmallZ )
				.def( "GetLargeX", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetLargeX )
				.def( "GetSmallX", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetSmallX )
				.def( "GetLargeY", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetLargeY )
				.def( "GetSmallY", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetSmallY )
				.def( "GetLargeZ", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetLargeZ )
				.def( "GetSmallZ", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetSmallZ )
				.def( "GetBoundingBox", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetBoundingBox )
				.def( "SetBoundingBox", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetBoundingBox )
				.def( "GetR", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetR )
				.def( "SetR", &WSL::Collision::Scan_Area_Collision::Scan_Area::SetR )
				.def( "GetACollisionData", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetACollisionData )
				.def( "GetCollisionDataSize", &WSL::Collision::Scan_Area_Collision::Scan_Area::GetCollisionDataSize )
				.def( "ClearCollisionData", &WSL::Collision::Scan_Area_Collision::Scan_Area::ClearCollisionData )
				.def( "AddCollisionData", &WSL::Collision::Scan_Area_Collision::Scan_Area::AddCollisionData )
		];
		//-----Non class type-----//
			//-----int-----//
			luabind::module( engine->luaContainer->State )[
				luabind::class_<WSL::Containers::Scripting::Lua::LuaBindedType<int>>( "CppInt" )
					.def( luabind::constructor<>() )
					.def( "Get", &WSL::Containers::Scripting::Lua::LuaBindedType<int>::Get )
					.def( "Set", &WSL::Containers::Scripting::Lua::LuaBindedType<int>::Set )
			];
			//-----long long signed int-----//
			luabind::module( engine->luaContainer->State )[
				luabind::class_<WSL::Containers::Scripting::Lua::LuaBindedType<long long signed int>>( "CppLongInt" )
					.def( luabind::constructor<>() )
					.def( "Get", &WSL::Containers::Scripting::Lua::LuaBindedType<long long signed int>::Get )
					.def( "Set", &WSL::Containers::Scripting::Lua::LuaBindedType<long long signed int>::Set )
			];
			//-----double-----//
			luabind::module( engine->luaContainer->State )[
				luabind::class_<WSL::Containers::Scripting::Lua::LuaBindedType<double>>( "CppFloat" )
					.def( luabind::constructor<>() )
					.def( "Get", &WSL::Containers::Scripting::Lua::LuaBindedType<double>::Get )
					.def( "Set", &WSL::Containers::Scripting::Lua::LuaBindedType<double>::Set )
			];
			//-----boolean-----//
			luabind::module( engine->luaContainer->State )[
				luabind::class_<WSL::Containers::Scripting::Lua::LuaBindedType<bool>>( "CppBool" )
					.def( luabind::constructor<>() )
					.def( "Get", &WSL::Containers::Scripting::Lua::LuaBindedType<bool>::Get )
					.def( "Set", &WSL::Containers::Scripting::Lua::LuaBindedType<bool>::Set )
			];
		//-----Lua Manager-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Containers::Scripting::Lua_Container>( "Stack" )
				.def( luabind::constructor<>() )
				.def( "AddInt", &WSL::Containers::Scripting::Lua_Container::AddInt )
				.def( "AddLongInt", &WSL::Containers::Scripting::Lua_Container::AddLongInt )
				.def( "AddFloat", &WSL::Containers::Scripting::Lua_Container::AddFloat )
				.def( "GetInt", &WSL::Containers::Scripting::Lua_Container::GetInt )
				.def( "GetLongInt", &WSL::Containers::Scripting::Lua_Container::GetLongInt )
				.def( "GetFloat", &WSL::Containers::Scripting::Lua_Container::GetFloat )
				.def( "SetInt", (void(WSL::Containers::Scripting::Lua_Container::*)(std::string,int))&WSL::Containers::Scripting::Lua_Container::SetVarible )
				.def( "SetLongInt", (void(WSL::Containers::Scripting::Lua_Container::*)(std::string,long long signed int))&WSL::Containers::Scripting::Lua_Container::SetVarible )
				.def( "SetFloat", (void(WSL::Containers::Scripting::Lua_Container::*)(std::string,double))&WSL::Containers::Scripting::Lua_Container::SetVarible )
				.def( "SetInfo", &WSL::Containers::Scripting::Lua_Container::SetInfo )
		];
		//-----Engine Struct-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Engine>( "Engine" )
				.def( luabind::constructor<>() )
		];
		//-----Input Class-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Global::Input>( "Input" )
				.def( luabind::constructor<>() )
				.def( "IsKeyDown", &WSL::Global::Input::IsKeyDown )
				.def( "GetMouseClick", &WSL::Global::Input::GetMouseClick )
				.def( "GetMouseEvent", &WSL::Global::Input::GetMouseEvent )
				.def( "GetMousePosition", &WSL::Global::Input::GetMousePosition )
		];
		//-----Base Entity-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Framework::Standard::Base::BaseEntity>( "BaseEntity" )
				.def( luabind::constructor<>() )
		];
		//-----Entity-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Framework::Standard::Base::Entity, WSL::Framework::Standard::Base::BaseEntity>( "Entity" )
				.def( luabind::constructor<>() )
				.def( "GetChild", &WSL::Framework::Standard::Base::Entity::GetChild )
				.def( "GetComponentID", &WSL::Framework::Standard::Base::Entity::GetComponentID )
				.def( "GetDestroy", &WSL::Framework::Standard::Base::Entity::GetDestroy )
				.def( "GetDestroyScript", &WSL::Framework::Standard::Base::Entity::GetDestroyScript )
				.def( "GetID", &WSL::Framework::Standard::Base::Entity::GetID )
				.def( "GetInitializeScript", &WSL::Framework::Standard::Base::Entity::GetInitializeScript )
				.def( "GetObjID", &WSL::Framework::Standard::Base::Entity::GetObjID )
				.def( "GetOtherScript", &WSL::Framework::Standard::Base::Entity::GetOtherScript )
				.def( "GetRefreshScript", &WSL::Framework::Standard::Base::Entity::GetRefreshScript )
				.def( "RunScript", &WSL::Framework::Standard::Base::Entity::RunScript )
				.def( "SendToLua", &WSL::Framework::Standard::Base::Entity::SendToLua )
				.def( "SetChild", &WSL::Framework::Standard::Base::Entity::SetChild )
				.def( "SetDestroy", &WSL::Framework::Standard::Base::Entity::SetDestroy )
				.def( "SetDestroyScript", &WSL::Framework::Standard::Base::Entity::SetDestroyScript )
				.def( "SetID", &WSL::Framework::Standard::Base::Entity::SetID )
				.def( "SetInitializeScript", &WSL::Framework::Standard::Base::Entity::SetInitializeScript )
				.def( "SetObjID", &WSL::Framework::Standard::Base::Entity::SetObjID )
				.def( "SetOtherScript", &WSL::Framework::Standard::Base::Entity::SetOtherScript )
				.def( "SetRefreshScript", &WSL::Framework::Standard::Base::Entity::SetResfreshScript )
		];
		//-----Positional-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Framework::Standard::Positional, WSL::Framework::Standard::Base::Entity>( "Positional" )
				.def( luabind::constructor<>() )
				.def( "AddPolygon", &WSL::Framework::Standard::Positional::AddPolygon )
				.def( "AddScanArea", &WSL::Framework::Standard::Positional::AddScanArea )
				.def( "AddSprite", &WSL::Framework::Standard::Positional::AddSprite )
				.def( "AddVectorGraphic", &WSL::Framework::Standard::Positional::AddVectorGraphic )
				.def( "DeleteComponents", &WSL::Framework::Standard::Positional::DeleteComponents )
				.def( "GetPosition", &WSL::Framework::Standard::Positional::GetPosition )
				.def( "GetRotation", &WSL::Framework::Standard::Positional::GetRotation )
				.def( "GetChild", &WSL::Framework::Standard::Positional::GetChild )
				.def( "GetComponentID", &WSL::Framework::Standard::Positional::GetComponentID )
				.def( "GetDestroy", &WSL::Framework::Standard::Positional::GetDestroy )
				.def( "GetDestroyScript", &WSL::Framework::Standard::Positional::GetDestroyScript )
				.def( "GetID", &WSL::Framework::Standard::Positional::GetID )
				.def( "GetInitializeScript", &WSL::Framework::Standard::Positional::GetInitializeScript )
				.def( "GetObjID", &WSL::Framework::Standard::Positional::GetObjID )
				.def( "GetOtherScript", &WSL::Framework::Standard::Positional::GetOtherScript )
				.def( "GetRefreshScript", &WSL::Framework::Standard::Positional::GetRefreshScript )
				.def( "GetPhysicalBehavior", &WSL::Framework::Standard::Positional::GetPhysicalBehavior )
				.def( "RunScript", &WSL::Framework::Standard::Positional::RunScript )
				.def( "SendToLua", &WSL::Framework::Standard::Positional::SendToLua )
				.def( "SetChild", &WSL::Framework::Standard::Positional::SetChild )
				.def( "SetDestroy", &WSL::Framework::Standard::Positional::SetDestroy )
				.def( "SetDestroyScript", &WSL::Framework::Standard::Positional::SetDestroyScript )
				.def( "SetID", &WSL::Framework::Standard::Positional::SetID )
				.def( "SetInitializeScript", &WSL::Framework::Standard::Positional::SetInitializeScript )
				.def( "SetObjID", &WSL::Framework::Standard::Positional::SetObjID )
				.def( "SetOtherScript", &WSL::Framework::Standard::Positional::SetOtherScript )
				.def( "SetRefreshScript", &WSL::Framework::Standard::Positional::SetResfreshScript )
				.def( "SetPosition", (void(WSL::Framework::Standard::Positional::*)(float,float))&WSL::Framework::Standard::Positional::SetPosition )
				.def( "SetPosition", (void(WSL::Framework::Standard::Positional::*)(float,float,float))&WSL::Framework::Standard::Positional::SetPosition )
				.def( "SetPosition", (void(WSL::Framework::Standard::Positional::*)(WSL::Containers::Base::XYZ))&WSL::Framework::Standard::Positional::SetPosition )
				.def( "SetRotation", (void(WSL::Framework::Standard::Positional::*)(float))&WSL::Framework::Standard::Positional::SetRotation )
				.def( "SetPhysicalBehavior", &WSL::Framework::Standard::Positional::SetPhysicalBehavior )
		];
		//-----Mobile-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Framework::Standard::Mobile, WSL::Framework::Standard::Positional>( "Mobile" )
				.def( luabind::constructor<>() )
				.def( "AddPolygon", &WSL::Framework::Standard::Mobile::AddPolygon )
				.def( "AddScanArea", &WSL::Framework::Standard::Mobile::AddScanArea )
				.def( "AddSprite", &WSL::Framework::Standard::Mobile::AddSprite )
				.def( "AddVectorGraphic", &WSL::Framework::Standard::Mobile::AddVectorGraphic )
				.def( "Calculate", &WSL::Framework::Standard::Mobile::Calculate )
				.def( "DeleteComponents", &WSL::Framework::Standard::Mobile::DeleteComponents )
				.def( "GetAutoCalculate", &WSL::Framework::Standard::Mobile::GetAutoCalculate )
				.def( "GetAutoMove", &WSL::Framework::Standard::Mobile::GetAutoMove )
				.def( "GetPosition", &WSL::Framework::Standard::Mobile::GetPosition )
				.def( "GetRotation", &WSL::Framework::Standard::Mobile::GetRotation )
				.def( "GetChild", &WSL::Framework::Standard::Mobile::GetChild )
				.def( "GetComponentID", &WSL::Framework::Standard::Mobile::GetComponentID )
				.def( "GetDestroy", &WSL::Framework::Standard::Mobile::GetDestroy )
				.def( "GetDestroyScript", &WSL::Framework::Standard::Mobile::GetDestroyScript )
				.def( "GetID", &WSL::Framework::Standard::Mobile::GetID )
				.def( "GetInitializeScript", &WSL::Framework::Standard::Mobile::GetInitializeScript )
				.def( "GetObjID", &WSL::Framework::Standard::Mobile::GetObjID )
				.def( "GetOtherScript", &WSL::Framework::Standard::Mobile::GetOtherScript )
				.def( "GetRefreshScript", &WSL::Framework::Standard::Mobile::GetRefreshScript )
				.def( "GetVector", &WSL::Framework::Standard::Mobile::GetVector )
				.def( "GetPhysicalBehavior", &WSL::Framework::Standard::Mobile::GetPhysicalBehavior )
				.def( "Move", &WSL::Framework::Standard::Mobile::Move )
				.def( "RunScript", &WSL::Framework::Standard::Mobile::RunScript )
				.def( "SendToLua", &WSL::Framework::Standard::Mobile::SendToLua )
				.def( "SetAutoCalculate", &WSL::Framework::Standard::Mobile::SetAutoCalculate )
				.def( "SetChild", &WSL::Framework::Standard::Mobile::SetChild )
				.def( "SetDestroy", &WSL::Framework::Standard::Mobile::SetDestroy )
				.def( "SetDestroyScript", &WSL::Framework::Standard::Mobile::SetDestroyScript )
				.def( "SetDestination", (void(WSL::Framework::Standard::Mobile::*)(float))&WSL::Framework::Standard::Mobile::SetDestination )
				.def( "SetDestination", (void(WSL::Framework::Standard::Mobile::*)(float,float))&WSL::Framework::Standard::Mobile::SetDestination )
				.def( "SetDestination", (void(WSL::Framework::Standard::Mobile::*)(float,float,float))&WSL::Framework::Standard::Mobile::SetDestination )
				.def( "SetDestination", (void(WSL::Framework::Standard::Mobile::*)(WSL::Containers::Base::XYZ))&WSL::Framework::Standard::Mobile::SetDestination )
				.def( "SetAutoMove", &WSL::Framework::Standard::Mobile::SetAutoMove )
				.def( "SetID", &WSL::Framework::Standard::Mobile::SetID )
				.def( "SetInitializeScript", &WSL::Framework::Standard::Mobile::SetInitializeScript )
				.def( "SetObjID", &WSL::Framework::Standard::Mobile::SetObjID )
				.def( "SetOtherScript", &WSL::Framework::Standard::Mobile::SetOtherScript )
				.def( "SetRefreshScript", &WSL::Framework::Standard::Mobile::SetResfreshScript )
				.def( "SetPosition", (void(WSL::Framework::Standard::Mobile::*)(float,float))&WSL::Framework::Standard::Mobile::SetPosition )
				.def( "SetPosition", (void(WSL::Framework::Standard::Mobile::*)(float,float,float))&WSL::Framework::Standard::Mobile::SetPosition )
				.def( "SetPosition", (void(WSL::Framework::Standard::Mobile::*)(WSL::Containers::Base::XYZ))&WSL::Framework::Standard::Mobile::SetPosition )
				.def( "SetRotation", (void(WSL::Framework::Standard::Mobile::*)(float))&WSL::Framework::Standard::Mobile::SetRotation )
				.def( "SetVector", &WSL::Framework::Standard::Mobile::SetVector )
				.def( "SetPhysicalBehavior", &WSL::Framework::Standard::Mobile::SetPhysicalBehavior )
		];
		//-----Bubble Sort-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Algorithmic::BubbleSort>( "BubbleSort" )
				.def( luabind::constructor<>() )
				.def( "BubbleSortAlgorithm", &WSL::Algorithmic::BubbleSort::BubbleSortAlgorithm )
		];
		//-----Sub Singleton Foundation-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Algorithmic::Base::SubSingletonFoundation>( "SubSingleFoundation" )
				.def( luabind::constructor<>() )
		];
		//-----Sub Singleton Base-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Algorithmic::Base::SubSingleBase, WSL::Algorithmic::Base::SubSingletonFoundation>( "SubSingleBase" )
				.def( luabind::constructor<>() )
		];
		//-----Level-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Algorithmic::Level, WSL::Algorithmic::Base::SubSingleBase>( "Level" )
				.def( luabind::constructor<>() )
				.def( "AddObject", &WSL::Algorithmic::Level::AddObject )
				.def( "GetObject", (void(WSL::Algorithmic::Level::*)(unsigned int,int,int))&WSL::Algorithmic::Level::GetObject )
				.def( "SearchAlgorithim", &WSL::Algorithmic::Level::SearchAlgorithim )
				.def( "SetObject", &WSL::Algorithmic::Level::SetObject )
				.def( "SetActive", &WSL::Algorithmic::Level::SetActive )
				.def( "SetRefresh", &WSL::Algorithmic::Level::SetRefresh )
				.def( "SetDestroy", &WSL::Algorithmic::Level::SetDestroy )
				.def( "ObjectIsInLevel", &WSL::Algorithmic::Level::ObjectIsInLevel )
				.def_readwrite( "active", &WSL::Algorithmic::Level::active )
				.def_readwrite( "refresh", &WSL::Algorithmic::Level::refresh )
				.def_readwrite( "destroy", &WSL::Algorithmic::Level::destroy )
		];
		//-----Render Layer-----//
		luabind::module( engine->luaContainer->State )
		[
			luabind::class_<WSL::Algorithmic::RenderLayer, WSL::Algorithmic::Base::SubSingletonFoundation, WSL::Algorithmic::BubbleSort>( "RenderLayer" )
				.def( "GetActive", &WSL::Algorithmic::RenderLayer::GetActive )
				.def( "SetActive", &WSL::Algorithmic::RenderLayer::SetActive )
				.def( "GetName", &WSL::Algorithmic::RenderLayer::GetName )
				.def( "SetName", &WSL::Algorithmic::RenderLayer::SetName )
		];
		//-----Sound Manager-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_< WSL::Global::SoundManager >( "SoundManager" )
				.def( luabind::constructor<>() )
				.def( "CleanUp", &WSL::Global::SoundManager::CleanUp )
				.def( "LoadSound", &WSL::Global::SoundManager::LoadSound )
				.def( "PauseSound", &WSL::Global::SoundManager::PauseSound )
				.def( "PlaySound", (unsigned int(WSL::Global::SoundManager::*)(unsigned int, bool))&WSL::Global::SoundManager::PlaySound )
				.def( "PlaySound", (unsigned int(WSL::Global::SoundManager::*)(std::string, bool))&WSL::Global::SoundManager::PlaySound )
				.def( "PlaySoundFromFile", &WSL::Global::SoundManager::PlaySoundFromFile )
				.def( "SoundIsPaused", &WSL::Global::SoundManager::SoundIsPaused )
				.def( "SoundIsPlaying", &WSL::Global::SoundManager::SoundIsPlaying )
				.def( "SoundIsStopped", &WSL::Global::SoundManager::SoundIsStopped )
				.def( "StopSound", &WSL::Global::SoundManager::StopSound )
				.def( "UnPauseSound", &WSL::Global::SoundManager::UnPauseSound )
				.def( "Update", &WSL::Global::SoundManager::Update )
		];
		//-----SFML View-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<sf::View>( "SFMLView" )
			.def( luabind::constructor<>() )
		];
		//-----Camera-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Global::Camera>( "Camera" )
				.def( luabind::constructor< float, float, float, float, float, float, sf::View* >() )
				.def( luabind::constructor<>() )
				.def( "GetX", &WSL::Global::Camera::GetX )
				.def( "GetY", &WSL::Global::Camera::GetY )
				.def( "GetZ", &WSL::Global::Camera::GetZ )
				.def( "GetWidth", &WSL::Global::Camera::GetWidth )
				.def( "GetHeight", &WSL::Global::Camera::GetHeight )
				.def( "GetDepth", &WSL::Global::Camera::GetDepth )
				.def( "GetCamera", &WSL::Global::Camera::GetCamera )
				.def( "Move", &WSL::Global::Camera::Move )
				.def( "Zoom", &WSL::Global::Camera::Zoom )
				.def( "SetZoom", &WSL::Global::Camera::SetZoom )
				.def( "SetX", &WSL::Global::Camera::SetX )
				.def( "SetY", &WSL::Global::Camera::SetY )
				.def( "SetZ", &WSL::Global::Camera::SetZ )
				.def( "SetWidth", &WSL::Global::Camera::SetWidth )
				.def( "SetHeight", &WSL::Global::Camera::SetHeight )
				.def( "SetDepth", &WSL::Global::Camera::SetDepth )
				.def( "SetCamera", &WSL::Global::Camera::SetCamera )
		];
		//-----Singleton Base-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Base::SingletonBase>( "SingletonBase" )
				.def( luabind::constructor<>() )
		];
		//-----Core Info Container-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Containers::CoreInfoContainer>( "CoreInfoContainer" )
				.def( luabind::constructor<>() )
					.def( "GetID", &WSL::Containers::CoreInfoContainer::GetID )
					.def( "GetObjID", &WSL::Containers::CoreInfoContainer::GetObjID )
					.def( "GetComponentID", &WSL::Containers::CoreInfoContainer::GetComponentID )
					.def( "SetID", &WSL::Containers::CoreInfoContainer::SetID )
					.def( "SetObjID", &WSL::Containers::CoreInfoContainer::SetObjID )
					.def( "SetComponentID",  &WSL::Containers::CoreInfoContainer::SetComponentID )
		];
		//-----Singleton-----//
		luabind::module( engine->luaContainer->State )[
			luabind::class_<WSL::Singleton, WSL::Base::SingletonBase>( "Singleton" )
				.def( luabind::constructor<>() )
				.def( "AddPolygon", (void(WSL::Singleton::*)(std::string))&WSL::Singleton::AddPolygon )
				.def( "AddPolygon", (void(WSL::Singleton::*)(void))&WSL::Singleton::AddPolygon )
				.def( "AddScanArea", (void(WSL::Singleton::*)(std::string))&WSL::Singleton::AddScanArea )
				.def( "AddScanArea", (void(WSL::Singleton::*)(void))&WSL::Singleton::AddScanArea )
				.def( "AddSprite", (void(WSL::Singleton::*)(float,float,bool))&WSL::Singleton::AddSprite )
				.def( "AddSprite", (void(WSL::Singleton::*)(float,float,unsigned int,bool))&WSL::Singleton::AddSprite )
				.def( "AddSprite", (void(WSL::Singleton::*)(unsigned int,bool))&WSL::Singleton::AddSprite )
				.def( "AddVectorGraphic", (void(WSL::Singleton::*)(std::string))&WSL::Singleton::AddVectorGraphic )
				.def( "AddVectorGraphic", (void(WSL::Singleton::*)())&WSL::Singleton::AddVectorGraphic )
				.def( "BaseSend", &WSL::Singleton::BaseSend )
				.def( "ThreadObject", &WSL::Singleton::ThreadObject )
				.def( "SendObject", &WSL::Singleton::SendObject )
				.def( "EndObjectThread", &WSL::Singleton::EndObjectThread )
				.def( "GetObject", &WSL::Singleton::GetObject )
				.def( "Instantiate", &WSL::Singleton::Instantiate )
				.def( "InstantiateLevel", &WSL::Singleton::InstantiateLevel )
				.def( "InstantiateRenderLayer", (int(WSL::Singleton::*)(std::string))&WSL::Singleton::InstantiateRenderLayer )
				.def( "GetLevel", (void(WSL::Singleton::*)(unsigned int))&WSL::Singleton::GetLevel )
				.def( "GetLevel", (void(WSL::Singleton::*)(std::string))&WSL::Singleton::GetLevel )
				.def( "GetRenderLayer", &WSL::Singleton::GetRenderLayer )
				.def( "GetRenderLayerByLevel", (void(WSL::Singleton::*)(unsigned int))&WSL::Singleton::GetRenderLayerByLevel )
				.def( "GetRenderLayerByLevel", (void(WSL::Singleton::*)(std::string))&WSL::Singleton::GetRenderLayerByLevel )
				.def( "GetDebug", &WSL::Singleton::GetDebug )
				.def( "GetSoundManager", &WSL::Singleton::GetSoundManager )
				.def( "GetCamera", &WSL::Singleton::GetCamera )
				.def( "GetMousePosition", &WSL::Singleton::GetMousePosition )
				.def( "GetThreeDCollision", &WSL::Singleton::GetThreeDCollision )
				.def( "SetLevel", (void(WSL::Singleton::*)(WSL::Algorithmic::Level*,unsigned int))&WSL::Singleton::SetLevel )
				.def( "SetLevel", (void(WSL::Singleton::*)(WSL::Algorithmic::Level*,std::string))&WSL::Singleton::SetLevel )
				.def( "SetDebug", &WSL::Singleton::SetDebug )
				.def( "SetThreeDCollision", &WSL::Singleton::SetThreeDCollision )
				.def( "LoadImage", &WSL::Singleton::LoadImage )
				.def_readwrite( "debug", &WSL::Singleton::debug )
				.def_readwrite( "run", &WSL::Singleton::run )
				.def_readwrite( "currentInfo", &WSL::Singleton::currentInfo )
		];
	}
	//Go'n old school style here!//
	static void Log( bool compile )
	{
		std::ofstream file;
		file.open( "bin/Documentation/Compiles And Executions.txt" );
		file<<"\n-----Beginning of log: -----\n";
		std::string msg = "Software: White - Storm: Lightning.\n Version/Release: Alpha.\n Author: Christopher Augustus Greeley.\n Executed ";
		if( compile == true )
		{
			msg += "and compiled ";
		}
		msg += "on ";
		msg += __DATE__;
		msg += " at ";
		msg += __TIME__;
		msg += ".\n";
		file<<msg;
		msg = "This version of White - Storm: Lightning this was compiled with";
		if( __cplusplus > 199711L )
			msg += " a industry standard version of C++.\n";
		else
			msg += " a non industry standard version of C++.\n";
		file<<msg;
		file<<"-----End of log.-----\n";
		file.close();
	}
	static void Run( WSL::Singleton *s )
	{
		while( true )
		{
			if( s->run == true )
			{
				s->BaseSend();
				luaL_dofile( s->engine->luaContainer->State, "src/Scripts/Engine/Game Scripts/Begin Refresh.lua" );
				s->Cycle();
				s->BaseSend();
				luaL_dofile( s->engine->luaContainer->State, "src/Scripts/Engine/Game Scripts/End Refresh.lua" );
			}
			else
			{
				s->BaseSend();
				luaL_dofile( s->engine->luaContainer->State, "src/Scripts/Engine/Game Scripts/Destroy.lua" );
				s->CleanUp();
				break;
			}
		}
	}
	static void (*BaseSend)();
	static void (*SendObject)();
	static void (*ExternalRegister)( std::vector<WSL::DataTranslation::Base::BaseTranslator*>* );
	static void (*ExternalLuaRegister)( WSL::Engine *engine );
	static bool externalRegister;
	static std::vector<WSL::DataTranslation::Base::BaseTranslator*> InitializeTranslators( 
		std::vector<WSL::DataTranslation::Base::BaseTranslator*> translators )
	{
		WSL::DataTranslation::EntityTranslator *entityTrans = new WSL::DataTranslation::EntityTranslator;
		entityTrans->BaseSend = BaseSend;
		entityTrans->SendObject = SendObject;
		{
			WSL::DataTranslation::Base::BaseTranslator *temp = &*entityTrans;
			translators.push_back( temp );
		}
		WSL::DataTranslation::PositionalTranslator *posTrans = new WSL::DataTranslation::PositionalTranslator;
		posTrans->BaseSend = BaseSend;
		posTrans->SendObject = SendObject;
		{
			WSL::DataTranslation::Base::BaseTranslator *temp = &*posTrans;
			translators.push_back( temp );
		}
		WSL::DataTranslation::MobileTranslator *mobileTrans = new WSL::DataTranslation::MobileTranslator;
		mobileTrans->BaseSend = BaseSend;
		mobileTrans->SendObject = SendObject;
		{
			WSL::DataTranslation::Base::BaseTranslator *temp = &*mobileTrans;
			translators.push_back( temp );
		}
		if( externalRegister == true )
			ExternalRegister( &translators );
		return translators;
	}
	static WSL::Singleton *singlet;
	static void MiddleBaseSend()
	{
		singlet->BaseSend();
	}
	static void MiddleLuaObjectSend()
	{
		singlet->SendObjectToLua();
	}
	static WSL::Singleton* InitializeEngine()
	{
		Log( true );
		WSL::Singleton *s = new WSL::Singleton( true );
		LuaRegister( s->engine );
		if( externalRegister == true )
			ExternalLuaRegister( s->engine );
		BaseSend = &MiddleBaseSend;
		SendObject = &MiddleLuaObjectSend;
		singlet = s;
		s->SetUpTranslators = &InitializeTranslators;
		s->InitializeTranslators();
		{
			WSL::DataTransfer::Lua::SingletonSender *se = new WSL::DataTransfer::Lua::SingletonSender;
			se->singleton = s;
			s->sender = se;
			s->BaseSend();
			luaL_dofile( s->engine->luaContainer->State, "src/Scripts/Engine/Game Scripts/Initialize.lua" );
		}
		return s;
	}
	static WSL::Singleton* EngineInitialize()
	{
		WSL::Singleton *single = InitializeEngine();
		Recurse = &Run;
		return single;
	}
	static void ExecuteWhiteStormLightning()
	{
		Recurse( EngineInitialize() );
	}
}
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
#include "Component.h"
namespace WSL
{
	//Last minute thought.//
	namespace Containers
	{
		class IDXYZ
		{
			unsigned int id, objectID, componentID;
			WSL::Containers::Base::XYZ point;
			public: 
				IDXYZ()
				{
					point = WSL::Containers::Base::XYZ();
					id = 0;
					objectID = 0;
					componentID = 0;
				}
				IDXYZ( unsigned int id_, unsigned int objectID_, unsigned int componentID_, WSL::Containers::Base::XYZ point_ )
				{
					point = point_;
					id = id_;
					objectID = objectID_;
					componentID = componentID_;
				}
				unsigned int GetID() {
					return id;
				}
				unsigned int GetObjectID() { 
					return objectID;
				}
				unsigned int GetComponentID() {
					return componentID;
				}
				WSL::Containers::Base::XYZ GetPoint() {
					return point;
				}
				void SetID( unsigned int id_ ) {
					id = id_;
				}
				void SetObjectID( unsigned int objectID_ ) { 
					objectID = objectID_;
				}
				void SetComponentID( unsigned int componentID_ ) {
					componentID = componentID_;
				}
				void SetPoint( WSL::Containers::Base::XYZ point_ ) {
					point = point_;
				}

		};
	}
	namespace Collision
	{
		namespace Scan_Area_Collision
		{
			//Temporary code but
			//I needed it for the time beaing thank you Lightdark from the Elysian Shadows chat room!!!!!
			typedef struct
			{
					int x;
					int y;
					int w;
					int h;
			} Rectangle;
			//This class is for the most part deprocated. It will be re-implemented in a future release.//
			class Scan_Area : public WSL::Components::Base::Component
			{
				std::vector< WSL::Containers::IDXYZ  > collisionData;
				float X, Y, Z;
				WSL::Containers::Bool_XYZ collision;
				std::vector<WSL::Containers::Base::XYZ> Points;
				std::vector<WSL::Containers::Base::XYZ> Collision_Coords;
				std::vector<sf::Sprite> Debug_Markers;
				std::vector<WSL::Containers::Base::XYZ> Magnitudes;
				std::vector<WSL::Containers::Base::XYZ> Back_Up;
				WSL::Containers::Base::XYZ Origin;
				bool initialized;
				bool Rotated;
				float rotation;
				bool collide;
				std::vector<bool> Checked;
				float Last_Move, xLarge, yLarge, zLarge, xSmall, ySmall, zSmall;
				bool destroy;
				WSL::Containers::Base::XYZ vector;
				bool boundingBox;
				Rectangle r;
			public:
				Scan_Area( float x, float y, float z )
				{
					boundingBox = false;
					destroy = false;
					xLarge = 0;
					yLarge = 0;
					zLarge = 0;
					xSmall = 0;
					ySmall = 0;
					zSmall = 0;
					X = x;
					Y = y;
					Z = z;
					initialized = false;
					Rotated = false;
					Last_Move = 0;
					rotation = 0;
					collide = true;
				}
				Scan_Area()
				{
					/*if( boundingBox != true )
						boundingBox = false;
					collide = true;
					destroy = false;
					X = 0; Y = 0; Z = 0; initialized = false;
					Rotated = false;
					Last_Move = 0;
					rotation = 0;*/
				}
				WSL::Containers::IDXYZ GetACollisionData( unsigned int index )
				{
					if( index < collisionData.size() )
						return collisionData[ index ];
					return WSL::Containers::IDXYZ();
				}
				inline void AddCollisionData( WSL::Containers::IDXYZ dataToAdd ) {
					collisionData.push_back( dataToAdd );
				}
				inline unsigned int GetCollisionDataSize() {
					return collisionData.size();
				}
				inline void ClearCollisionData() {
					collisionData.clear();
				}
				inline Rectangle GetR()
				{
					return r;
				}
				inline void SetR( Rectangle r_ )
				{
					r = r_;
				}
				inline void SetBoundingBox( bool value )
				{
					boundingBox = value;
				}
				inline bool GetBoundingBox()
				{
					return boundingBox;
				}
				inline float getX()
				{
					return X;
				}
				inline float getY()
				{
					return Y;
				}
				inline float getZ()
				{
					return Z;
				}
				inline void setX( float x_ )
				{
					X = x_;
				}
				inline void setY( float y_ )
				{
					Y = y_;
				}
				inline void setZ( float z_ )
				{
					Z = z_;
				}
				inline WSL::Containers::Base::XYZ GetVector()
				{
					return vector;
				}
				inline void SetVector( WSL::Containers::Base::XYZ vector_ )
				{
					vector = vector_;
				}
				inline void SetCollide( bool collide_ )
				{
					collide = collide_;
				}
				inline bool GetCollide()
				{
					return collide;
				}
				inline void SetDestroy( bool destroy_ )
				{
					destroy = destroy_;
				}
				inline bool GetDestroy()
				{
					return destroy;
				}
				inline void SetCollision( WSL::Containers::Bool_XYZ collision_ )
				{
					collision = collision_;
				}
				inline WSL::Containers::Bool_XYZ GetCollision()
				{
					return collision;
				}
				inline void SetLargeX( float x )
				{
					xLarge = x;
				}
				inline void SetLargeY( float y )
				{
					yLarge = y;
				}
				inline void SetLargeZ( float z )
				{
					zLarge = z;
				}
				inline void SetSmallX( float x )
				{
					xSmall = x;
				}
				inline void SetSmallY( float y )
				{
					ySmall = y;
				}
				inline void SetSmallZ( float z )
				{
					zSmall = z;
				}
				inline float GetLargeX()
				{
					return xLarge;
				}
				inline float GetLargeY()
				{
					return yLarge;
				}
				inline float GetLargeZ()
				{
					return zLarge;
				}
				inline float GetSmallX()
				{
					return xSmall;
				}
				inline float GetSmallY()
				{
					return ySmall;
				}
				inline float GetSmallZ()
				{
					return zSmall;
				}
				inline void setOrigin( WSL::Containers::Base::XYZ Value ) { Origin = Value; }
				inline WSL::Containers::Base::XYZ getOrigin() { return Origin; }
				inline void setInitialized( bool Value ) { initialized = Value; }
				inline std::vector<WSL::Containers::Base::XYZ> getPoints() { return Points; }
				inline float getLast_Move() { return Last_Move; }
				inline void setLast_Move( float z ) { Last_Move = z; }
				inline void setRotated( bool Value ) { Rotated = Value; }
				inline bool getRotated() { return Rotated; }
				inline unsigned int Back_Up_Size() { return Back_Up.size(); }
				inline void Set_Coordinates( float x, float y, float z ) { X = x; Y = y; Z = z; }
				inline void SetRotation( float degree )
				{
					rotation = degree;
					while( rotation > 360 )
						rotation -= 360;
					if( rotation < 0 )
						rotation *= -1;
				}
				inline float GetRotation()
				{
					while( rotation > 360 )
						rotation -= 360;
					if( rotation < 0 )
						rotation *= -1;
					return rotation;
				}
				inline WSL::Containers::Base::XYZ getCoordinates()
				{
					WSL::Containers::Base::XYZ Returner( X, Y, Z );
					return Returner;
				}
				inline void Add_Point( WSL::Containers::Base::XYZ X )
				{
					Points.push_back( X );
				}
				inline void Add_Magnitude( WSL::Containers::Base::XYZ mag )
				{
					Magnitudes.push_back( mag );
				}
				inline std::vector<WSL::Containers::Base::XYZ> getMagnitudes()
				{
					return Magnitudes;
				}
				inline void setMagnitudes( std::vector<WSL::Containers::Base::XYZ> Value )
				{
					Magnitudes = Value;
				}
				inline void Reset_Scan_Area()
				{
					Magnitudes = Back_Up;
					initialized = true;
				}
				void setaMagnitude( WSL::Containers::Base::XYZ Value, unsigned int i )
				{
					if( initialized == false || Magnitudes.size() == 0 )
					{
						std::cout<<"Please add elements to the std::vector"<<std::endl;
						std::cout<<"''magnitudes'' before trying to accses them."<<std::endl;
						std::cout<<"(Have you tried using the Initialize scan area method?"<<std::endl;
						std::cout<<"for method ''setaMagnitude''."<<std::endl;
					}
					else
					{
						if( i >= 0 && i < Magnitudes.size() )
							Magnitudes[i] = Value;
					}
				}
				WSL::Containers::Base::XYZ getaMagnitude( unsigned int i )
				{
					if( initialized == false || Magnitudes.size() == 0 )
					{
						std::cout<<"Please add elements to the std::vector"<<std::endl;
						std::cout<<"''magnitudes'' before trying to accses them."<<std::endl;
						std::cout<<"(Have you tried using the Initialize scan area method?"<<std::endl;
						std::cout<<"for method ''getaMagnitude''."<<std::endl;
						WSL::Containers::Base::XYZ f;
						return f;
					}
					else
					{
						if( i >= 0 && i < Magnitudes.size() )
							return Magnitudes[i];
						else
						{
							std::cout<<"You have attempted to accses a"<<std::endl;
							std::cout<<"non - existant element of the"<<std::endl;
							std::cout<<"std::vector ''Magnitudes''"<<std::endl;
							std::cout<<"a default value has been returned"<<std::endl;
							std::cout<<"please enter a valid unsigned int"<<std::endl;
							std::cout<<"to accses a existant element."<<std::endl;
							std::cout<<"(is your unsigned int less than zero"<<std::endl;
							std::cout<<"or greater than or equil to the size"<<std::endl;
							std::cout<<"of ''Magnitudes'')? For method getaMagnitude"<<std::endl;
							WSL::Containers::Base::XYZ Default( 0, 0, 0 );
							return Default;
						}
					}
				}
				inline std::vector<WSL::Containers::Base::XYZ> getCollision_Coords()
				{
					return Collision_Coords;
				}
				inline std::vector<sf::Sprite> getDebug_Markers()
				{
					return Debug_Markers;
				}
				inline void setPoints( std::vector<WSL::Containers::Base::XYZ> Value )
				{
					Points = Value;
				}
				inline void setCollision_Coords( std::vector<WSL::Containers::Base::XYZ> Value )
				{
					Collision_Coords = Value;
				}
				inline void setDebug_Markers( std::vector<sf::Sprite> Value )
				{
					Debug_Markers = Value;
				}
				sf::Sprite getMarker( unsigned int i )
				{
					if( i < Debug_Markers.size() && i >= 0 )
						return Debug_Markers[i];
					else
					{
						std::cout<<"You have attempeted to accses"<<std::endl;
						std::cout<<"a element of the std::vector"<<std::endl;
						std::cout<<"''Debug_Markers'' please attempt"<<std::endl;
						std::cout<<"to accses a valid element."<<std::endl;
						std::cout<<"A default value has been returned"<<std::endl;
						std::cout<<"for method ''getMarker''."<<std::endl;
						sf::Sprite S;
						return S;
					}
				}
				void setMarker( sf::Sprite Value, unsigned int i )
				{
					if( i < Debug_Markers.size() && i >= 0 )
						Debug_Markers[i] = Value;
					else
					{
						std::cout<<"You have attempeted to accses"<<std::endl;
						std::cout<<"a element of the std::vector"<<std::endl;
						std::cout<<"''Debug_Markers'' please attempt"<<std::endl;
						std::cout<<"to accses a valid element in"<<std::endl;
						std::cout<<"method ''setMarker''."<<std::endl;
					}
				}
				WSL::Containers::Base::XYZ getCollision_Coord( unsigned int i )
				{
					if( i < Collision_Coords.size() && i >= 0 )
						return Collision_Coords[i];
					else
					{
						std::cout<<"You have attempeted to accses"<<std::endl;
						std::cout<<"a element of the std::vector"<<std::endl;
						std::cout<<"''Collision_Coords'' please attempt"<<std::endl;
						std::cout<<"to accses a valid element."<<std::endl;
						std::cout<<"A default value has been returned"<<std::endl;
						std::cout<<"for method ''setCollision_Coord''."<<std::endl;
						WSL::Containers::Base::XYZ X;
						return X;
					}
				}
				void setCollision_Coord( WSL::Containers::Base::XYZ Value, unsigned int i )
				{
					if( i < Collision_Coords.size() && i >= 0 )
						Collision_Coords[i] = Value;
					else
					{
						std::cout<<"You have attempeted to accses"<<std::endl;
						std::cout<<"a element of the std::vector"<<std::endl;
						std::cout<<"''Collision_Coords'' please attempt"<<std::endl;
						std::cout<<"to accses a valid element in"<<std::endl;
						std::cout<<"method ''getCollision_Coord''."<<std::endl;
					}
				}
				WSL::Containers::Base::XYZ getPoint( unsigned int i )
				{
					if( i < Points.size() && i >= 0 )
						return Points[i];
					else
					{
						std::cout<<"You have attempeted to accses"<<std::endl;
						std::cout<<"a element of the std::vector"<<std::endl;
						std::cout<<"''Points'' please attempt"<<std::endl;
						std::cout<<"to accses a valid element."<<std::endl;
						std::cout<<"A default value has been returned"<<std::endl;
						std::cout<<"for method ''getPoint''."<<std::endl;
						WSL::Containers::Base::XYZ X;
						return X;
					}
				}
				void setPoint( WSL::Containers::Base::XYZ Value, unsigned int i )
				{
					if( i < Points.size() && i >= 0 )
						Points[i] = Value;
					else
					{
						std::cout<<"You have attempeted to accses"<<std::endl;
						std::cout<<"a element of the std::vector"<<std::endl;
						std::cout<<"''Points'' please attempt"<<std::endl;
						std::cout<<"to accses a valid element in"<<std::endl;
						std::cout<<"method ''setPoint''."<<std::endl;
					}
				}
				friend class Initializer;
			};
		}
	}
}
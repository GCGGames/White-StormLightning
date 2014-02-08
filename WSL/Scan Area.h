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
		namespace ScanAreaCollision
		{
			//Temporary code but
			//I needed it for the time beaing thank you Lightdark from the Elysian Shadows chat room!!!!!
			typedef struct
			{
					float z;
					float x;
					float y;
					float w;
					float h;
					float l;
			} Rectangle;
			//This class is for the most part deprocated. It will be re-implemented in a future release.//
			class ScanArea : public WSL::Components::Base::Component
			{
				std::vector< WSL::Containers::IDXYZ > collisionData;
				float X, Y, Z;
				WSL::Containers::BoolXYZ collision;
				std::vector< WSL::Containers::Base::XYZ > points;
				std::vector< WSL::Containers::Base::XYZ > collionsCoordinates;
				std::vector< sf::Sprite > debugMarkers;
				std::vector< WSL::Containers::Base::XYZ > magnitudes;
				std::vector< WSL::Containers::Base::XYZ > backUp;
				WSL::Containers::Base::XYZ origin;
				bool initialized;
				bool rotated;
				float rotation;
				bool collide;
				std::vector< bool > checked;
				float lastMove, xLarge, yLarge, zLarge, xSmall, ySmall, zSmall;
				bool destroy;
				WSL::Containers::Base::XYZ vector;
				bool boundingBox;
				Rectangle rectangle;
			public:
				ScanArea( float x, float y, float z )
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
					rotated = false;
					lastMove = 0;
					rotation = 0;
					collide = true;
				}
				ScanArea() {
				}
				ScanArea( const ScanArea& scanAreaToCopy )
				{
					collisionData = scanAreaToCopy.collisionData;
					X = scanAreaToCopy.X;
					Y = scanAreaToCopy.Y;
					Z = scanAreaToCopy.Z;
					collision = scanAreaToCopy.collision;
					points = scanAreaToCopy.points;
					collionsCoordinates = scanAreaToCopy.collionsCoordinates;
					debugMarkers = scanAreaToCopy.debugMarkers;
					magnitudes = scanAreaToCopy.magnitudes;
					backUp = scanAreaToCopy.backUp;
					origin = scanAreaToCopy.origin;
					initialized = scanAreaToCopy.initialized;
					rotated = scanAreaToCopy.rotated;
					rotation = scanAreaToCopy.rotation;
					collide = scanAreaToCopy.collide;
					checked = scanAreaToCopy.checked;
					lastMove = scanAreaToCopy.lastMove;
					xLarge = scanAreaToCopy.xLarge;
					yLarge = scanAreaToCopy.yLarge;
					zLarge = scanAreaToCopy.zLarge;
					xSmall = scanAreaToCopy.xSmall;
					ySmall = scanAreaToCopy.ySmall;
					zSmall = scanAreaToCopy.zSmall;
					destroy = scanAreaToCopy.destroy;
					vector = scanAreaToCopy.vector;
					boundingBox = scanAreaToCopy.boundingBox;
					rectangle = scanAreaToCopy.rectangle;
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
				inline Rectangle GetR() {
					return rectangle;
				}
				inline void SetR( Rectangle rectangle_ ) {
					rectangle = rectangle_;
				}
				inline void SetBoundingBox( bool value ) {
					boundingBox = value;
				}
				inline bool GetBoundingBox() {
					return boundingBox;
				}
				inline float GetX() {
					return X;
				}
				inline float GetY() {
					return Y;
				}
				inline float GetZ() {
					return Z;
				}
				inline void SetX( float x_ ) {
					X = x_;
				}
				inline void SetY( float y_ ) {
					Y = y_;
				}
				inline void SetZ( float z_ ) {
					Z = z_;
				}
				inline WSL::Containers::Base::XYZ GetVector() {
					return vector;
				}
				inline void SetVector( WSL::Containers::Base::XYZ vector_ ) {
					vector = vector_;
				}
				inline void SetCollide( bool collide_ ) {
					collide = collide_;
				}
				inline bool GetCollide() {
					return collide;
				}
				inline void SetDestroy( bool destroy_ ) {
					destroy = destroy_;
				}
				inline bool GetDestroy() {
					return destroy;
				}
				inline void SetCollision( WSL::Containers::BoolXYZ collision_ ) {
					collision = collision_;
				}
				inline WSL::Containers::BoolXYZ GetCollision() {
					return collision;
				}
				inline void SetLargeX( float x ) {
					xLarge = x;
				}
				inline void SetLargeY( float y ) {
					yLarge = y;
				}
				inline void SetLargeZ( float z ) {
					zLarge = z;
				}
				inline void SetSmallX( float x ) {
					xSmall = x;
				}
				inline void SetSmallY( float y ) {
					ySmall = y;
				}
				inline void SetSmallZ( float z ) {
					zSmall = z;
				}
				inline float GetLargeX() {
					return xLarge;
				}
				inline float GetLargeY() {
					return yLarge;
				}
				inline float GetLargeZ() {
					return zLarge;
				}
				inline float GetSmallX() {
					return xSmall;
				}
				inline float GetSmallY() {
					return ySmall;
				}
				inline float GetSmallZ() {
					return zSmall;
				}
				inline void SetOrigin( WSL::Containers::Base::XYZ origin_ ) {
					origin = origin_;
				}
				inline WSL::Containers::Base::XYZ GetOrigin() {
					return origin;
				}
				inline void SetInitialized( bool initialized_ ) {
					initialized = initialized_;
				}
				inline std::vector< WSL::Containers::Base::XYZ > GetPoints() {
					return points;
				}
				inline float GetLastMove() {
					return lastMove;
				}
				inline void SetLastMove( float z ) {
					lastMove = z;
				}
				inline void SetRotated( bool rotated_ ) {
					rotated = rotated_;
				}
				inline bool GetRotated() {
					return rotated;
				}
				inline unsigned int BackUpSize() {
					return backUp.size();
				}
				inline void SetCoordinates( float x, float y, float z )
				{
					X = x;
					Y = y;
					Z = z;
				}
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
				inline WSL::Containers::Base::XYZ getCoordinates() {
					WSL::Containers::Base::XYZ Returner( X, Y, Z );
					return Returner;
				}
				inline void AddPoint( WSL::Containers::Base::XYZ X ) {
					points.push_back( X );
				}
				inline void AddMagnitude( WSL::Containers::Base::XYZ mag ) {
					magnitudes.push_back( mag );
				}
				inline std::vector<WSL::Containers::Base::XYZ> GetMagnitudes() {
					return magnitudes;
				}
				inline void SetMagnitudes( std::vector<WSL::Containers::Base::XYZ> value ) {
					magnitudes = value;
				}
				inline void Reset_ScanArea() {
					magnitudes = backUp;
					initialized = true;
				}
				void SetAMagnitude( WSL::Containers::Base::XYZ value, unsigned int i )
				{
					if( initialized == false || magnitudes.size() == 0 )
					{
						std::cout << "Please add elements to the std::vector" << std::endl;
						std::cout << "''mmagnitudes'' before trying to accses them." << std::endl;
						std::cout << "(Have you tried using the Initialize scan area method?" << std::endl;
						std::cout << "for method ''SetAMagnitude''." << std::endl;
					}
					else {
						if( i >= 0 && i < magnitudes.size() )
							magnitudes[ i ] = value;
					}
				}
				WSL::Containers::Base::XYZ GetAMagnitude( unsigned int i )
				{
					if( initialized == false || magnitudes.size() == 0 )
					{
						std::cout << "Please add elements to the std::vector" << std::endl;
						std::cout << "''mmagnitudes'' before trying to accses them." << std::endl;
						std::cout << "(Have you tried using the Initialize scan area method?" << std::endl;
						std::cout << "for method ''getaMagnitude''." << std::endl;
						WSL::Containers::Base::XYZ failed;
						return failed;
					}
					else
					{
						if( i >= 0 && i < magnitudes.size() )
							return magnitudes[ i ];
						else
						{
							std::cout << "You have attempted to accses a" << std::endl;
							std::cout << "non - existant element of the" << std::endl;
							std::cout << "std::vector ''mmagnitudes''" << std::endl;
							std::cout << "a default value has been returned" << std::endl;
							std::cout << "please enter a valid unsigned int" << std::endl;
							std::cout << "to accses a existant element." << std::endl;
							std::cout << "(is your unsigned int less than zero" << std::endl;
							std::cout << "or greater than or equil to the size" << std::endl;
							std::cout << "of ''mmagnitudes'')? For method getaMagnitude" << std::endl;
							WSL::Containers::Base::XYZ default___( 0, 0, 0 );
							return default___;
						}
					}
				}
				inline std::vector< WSL::Containers::Base::XYZ > GetCollionsCoordinates() {
					return collionsCoordinates;
				}
				inline std::vector< sf::Sprite > GetDebugMarkers() {
					return debugMarkers;
				}
				inline void SetPoints( std::vector<WSL::Containers::Base::XYZ> value ) {
					points = value;
				}
				inline void SetCollionsCoordinates( std::vector<WSL::Containers::Base::XYZ> value ) {
					collionsCoordinates = value;
				}
				inline void SetDebugMarkers( std::vector<sf::Sprite> value ) {
					debugMarkers = value;
				}
				sf::Sprite GetMarker( unsigned int i )
				{
					if( i < debugMarkers.size() && i >= 0 )
						return debugMarkers[ i ];
					else
					{
						std::cout << "You have attempeted to accses" << std::endl;
						std::cout << "a element of the std::vector" << std::endl;
						std::cout << "''debugMarkers'' please attempt" <<  std::endl;
						std::cout << "to accses a valid element." << std::endl;
						std::cout << "A default value has been returned" <<  std::endl;
						std::cout << "for method ''getMarker''." << std::endl;
						sf::Sprite sprite;
						return sprite;
					}
				}
				void SetMarker( sf::Sprite debugMarker, unsigned int i )
				{
					if( i < debugMarkers.size() && i >= 0 )
						debugMarkers[ i ] = debugMarker;
					else
					{
						std::cout << "You have attempeted to accses" << std::endl;
						std::cout << "a element of the std::vector" << std::endl;
						std::cout << "''debugMarkers'' please attempt" << std::endl;
						std::cout << "to accses a valid element in" << std::endl;
						std::cout << "method ''setMarker''." << std::endl;
					}
				}
				WSL::Containers::Base::XYZ GetCollisionCoord( unsigned int i )
				{
					if( i < collionsCoordinates.size() && i >= 0 )
						return collionsCoordinates[ i ];
					else
					{
						std::cout << "You have attempeted to accses" << std::endl;
						std::cout << "a element of the std::vector" << std::endl;
						std::cout << "''collionsCoordinates'' please attempt" << std::endl;
						std::cout << "to accses a valid element." << std::endl;
						std::cout << "A default value has been returned" << std::endl;
						std::cout << "for method ''setCollision_Coord''." << std::endl;
						WSL::Containers::Base::XYZ defualt__;
						return defualt__;
					}
				}
				void SetCollisionCoord( WSL::Containers::Base::XYZ collisionCoordinate, unsigned int i )
				{
					if( i < collionsCoordinates.size() && i >= 0 )
						collionsCoordinates[ i ] = collisionCoordinate;
					else
					{
						std::cout << "You have attempeted to accses" << std::endl;
						std::cout << "a element of the std::vector" << std::endl;
						std::cout << "''collionsCoordinates'' please attempt" << std::endl;
						std::cout << "to accses a valid element in" << std::endl;
						std::cout << "method ''GetCollisionCoord''." << std::endl;
					}
				}
				WSL::Containers::Base::XYZ GetPoint( unsigned int i )
				{
					if( i < points.size() && i >= 0 )
						return points[ i ];
					else
					{
						std::cout << "You have attempeted to accses" << std::endl;
						std::cout << "a element of the std::vector" << std::endl;
						std::cout << "''points'' please attempt" << std::endl;
						std::cout << "to accses a valid element." << std::endl;
						std::cout << "A default value has been returned" << std::endl;
						std::cout << "for method ''GetPoint''." << std::endl;
						WSL::Containers::Base::XYZ default___;
						return default___;
					}
				}
				void SetPoint( WSL::Containers::Base::XYZ point, unsigned int i )
				{
					if( i < points.size() && i >= 0 )
						points[ i ] = point;
					else
					{
						std::cout << "You have attempeted to accses" << std::endl;
						std::cout << "a element of the std::vector" << std::endl;
						std::cout << "''points'' please attempt" << std::endl;
						std::cout << "to accses a valid element in" << std::endl;
						std::cout << "method ''setPoint''." << std::endl;
					}
				}
				friend class Initializer;
				friend class ScanArea;
			};
		}
	}
}

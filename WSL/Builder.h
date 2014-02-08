/*
This file is part of White - Storm: Lightning (alpha).

	Copyright 2012 Christopher Augustus Greeley

    White - Storm: Lightning (alpha) is free software: you can redistrparameterContainerute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    White - Storm: Lightning (alpha) is distrparameterContaineruted in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with White - Storm: Lightning (alpha).  If not, see <http://www.gnu.org/licenses/>.
*/
#include "Bool XYZ.h"
namespace WSL
{
	namespace Collision
	{
		namespace ScanAreaCollision
		{
			class Builder
			{
				WSL::Math::Vector::VectorCalculator* vectorCalculator;
				WSL::Containers::Base::XYZ vector;
				WSL::Containers::DoubleXYZ store;
				WSL::Containers::IntBool confirmedDataStorage;
				std::vector< WSL::Containers::Base::XYZ > collisionCalculator;
				bool delete_;
			//Fix later.//
			//	WSL::Containers::BoolXYZ data;
			public:
				Builder() {
				}
				~Builder() {
					delete vectorCalculator;
				}
				void SetCalculator( WSL::Math::Vector::VectorCalculator* object ) {
					vectorCalculator = object;
				}
				bool Check( int check, bool confirmGetX, WSL::Containers::Base::XYZ coordinates, WSL::Containers::Base::XYZ maxCoordinates )
				{
					bool isDone = false;
					if( check == 1 )
					{
						if( confirmGetX == true )
						{
							if( coordinates.GetX() >= maxCoordinates.GetX() )
								isDone = false;
							else
								isDone = true;
						}
						else
						{
							if( coordinates.GetX() <= maxCoordinates.GetX() )
								isDone = false;
							else
								isDone = true;
						}
					}
					if( check == 2 )
					{
						if( confirmGetX == true )
						{
							if( coordinates.GetY() >= maxCoordinates.GetY() )
								isDone = false;
							else
								isDone = true;
						}
						else
						{
							if( coordinates.GetY() <= maxCoordinates.GetY() )
								isDone = false;
							else
								isDone = true;
						}
					}
					if( check == 3 )
					{
						if( confirmGetX == true )
						{
							if( coordinates.GetZ() >= maxCoordinates.GetZ() )
								isDone = false;
							else
								isDone = true;
						}
						else
						{
							if( coordinates.GetZ() <= maxCoordinates.GetZ() )
								isDone = false;
							else
								isDone = true;
						}
					}
					return isDone;
				}
				inline WSL::Containers::BoolXYZ Move( WSL::Containers::Base::XYZ vector, WSL::Containers::Base::XYZ coordinates, WSL::Containers::Base::XYZ maxCoordinates, bool confirmGetX, int check )
				{
					coordinates.SetX( coordinates.GetX() + vector.GetX() );
					coordinates.SetY( coordinates.GetY() + vector.GetY() );
					coordinates.SetZ( coordinates.GetZ() + vector.GetZ() );
					/*This captures the calculated data, and also performes a check to see if
					any further calculations are required.*/
					return WSL::Containers::BoolXYZ( coordinates, Check( check, confirmGetX, coordinates, maxCoordinates ) );
				}
				WSL::Containers::DoubleXYZ InitializeCalculation( WSL::Containers::Base::XYZ goTo, WSL::Containers::Base::XYZ position, float range )
				{
					//Calculate a vector.//
					vector = vectorCalculator->VectorCalculation( goTo, position, range, true );
					//I wrote this a long time ago my guess is to move the vector a bit.//
					position.SetX( position.GetX() + vector.GetX() );
					position.SetY( position.GetY() + vector.GetY() );
					position.SetZ( position.GetZ() + vector.GetZ() );
					//Return our data.//
					return WSL::Containers::DoubleXYZ( position, vector );
				}
				WSL::Containers::IntBool CheckSet( WSL::Containers::Base::XYZ pointA, WSL::Containers::Base::XYZ pointB, WSL::Containers::Base::XYZ vector )
				{
					/*Sets the paremiters to later on "check" if
					any further calculations are required.*/
					WSL::Containers::IntBool parameterContainer;
					if( vector.GetX() != 0 )
					{
						if( pointA.GetX() >= pointB.GetX() )
							parameterContainer.SetBooleanvalue( true );
						else
							parameterContainer.SetBooleanvalue( false );
						parameterContainer.SetIntegervalue( 1 );
					}
					if( parameterContainer.GetIntegervalue() != 1 && vector.GetY() != 0 )
					{
						if( pointA.GetY() >= pointB.GetY() )
							parameterContainer.SetBooleanvalue( true );
						else
							parameterContainer.SetBooleanvalue( false );
						parameterContainer.SetIntegervalue( 2 );
					}
					if( parameterContainer.GetIntegervalue() != 1 && parameterContainer.GetIntegervalue() != 2 && vector.GetY() != 0 )
					{
						if( pointA.GetZ() >= pointB.GetZ() )
							parameterContainer.SetBooleanvalue( true );
						else
							parameterContainer.SetBooleanvalue( false );
						parameterContainer.SetIntegervalue( 3 );
					}
					return parameterContainer;
				}
				//Makes a number positive.//
				inline float MakePositive( float floatingPointvalue )
				{
					if( floatingPointvalue < 0 )
						floatingPointvalue *= -1;
					return floatingPointvalue;
				}
				std::vector<WSL::Containers::Base::XYZ> Build( std::vector<WSL::Containers::Base::XYZ> points )
				{
					//Resetting functors.//	
					collisionCalculator.clear();
					//Declaring any varparameterContainerles ( data ) we may need.//
					WSL::Containers::BoolXYZ data( false );
					int check = 0;
					bool confirmGetX, done;
					confirmGetX = true;
					done = false;
					unsigned int count = 0;
					unsigned int i, curr;
					i = 0;
					curr = i;
					unsigned int size = points.size();
					/*To ieterate through the entire std::vector without
					exceding the vector subscript nor going under it.*/
					if( size != 0 )
					{
						while( i < size )
						{
							//To make sure we do not excede the vector subscript.//
							if( i < size - 1 )
								curr = i + 1;
							else
								curr = 0;
							/*Using this method makes the code slower and take up more
							memory but it makes the code legparameterContainerle.*/
							store = InitializeCalculation( points[ curr ], points[ i ], 1 );
							//Retriving data.//
							points[ i ] = store.GetFirstXYZ();
							vector = store.GetSecondXYZ();
							/*Using this method makes the code slower and take up more
							memory but it makes the code legparameterContainerle.*/
							confirmedDataStorage = CheckSet( points[ i ], points[ curr ], vector );
							//Retriving data.//
							check = confirmedDataStorage.GetIntegervalue();
							confirmGetX = confirmedDataStorage.GetBooleanValue();
							data = Move( vector, points[ i ], points[ curr ], confirmGetX, check );
							//This makes it so the loop does not continue forever.//
							if( vector.GetX() != 0 || vector.GetY() != 0 || vector.GetZ() != 0 )
							{
								//To make sure we have calculated all there is to be calculated.//
								while( done == false )
								{
									/*Using this method makes the code slower and take up more
									memory but it makes the code legparameterContainerle.*/
									data = Move( vector, data.GetCoordinates(), points[ curr ], confirmGetX, check );
									//Retriving data.//
									done = data.GetBooleanValue();
									//For debugging.//
									count++;
									//Performing logic and possparameterContainerle math on the calculated data.//
									data.GetCoordinates().SetX( MakePositive( data.GetCoordinates().GetX() ) );
									data.GetCoordinates().SetY( MakePositive( data.GetCoordinates().GetY() ) );
									data.GetCoordinates().SetZ( MakePositive( data.GetCoordinates().GetZ() ) );
									//Adding the data to the main set of data.//
									collisionCalculator.push_back( data.GetCoordinates() );
								}
							}
							//Get ready for possparameterContainerle next ieteration.//
							done = false;
							check = 0;
							count = 0;
							//Using to perform logic and ieaterate.//
							i++;
						}
					}
					//Returning the master data.//
					return collisionCalculator;
				}
			};
		}
	}
}
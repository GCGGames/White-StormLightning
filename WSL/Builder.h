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
#include "Bool XYZ.h"
namespace WSL
{
	namespace Collision
	{
		namespace Scan_Area_Collision
		{
			class Builder
			{
				WSL::Math::Vector::VectorCalculator *Vector_C;
				WSL::Containers::Base::XYZ Vector;
				WSL::Containers::Double_XYZ store;
				WSL::Containers::Int_Bool I_B;
				std::vector<WSL::Containers::Base::XYZ> Col_C;
				bool delete_;
			//Fix later.//
			//	WSL::Containers::Bool_XYZ data;
			public:
				Builder()
				{
				}
				~Builder()
				{
					delete Vector_C;
				}
				void setCalculator( WSL::Math::Vector::VectorCalculator *Object )
				{
					Vector_C = Object;
				}
				bool check( int Check, bool gx, WSL::Containers::Base::XYZ Coords, WSL::Containers::Base::XYZ Max_Coords )
				{
					bool Is_Done = false;
					if( Check == 1 )
					{
						if( gx == true )
						{
							if( Coords.getX() >= Max_Coords.getX() )
								Is_Done = false;
							else
								Is_Done = true;
						}
						else
						{
							if( Coords.getX() <= Max_Coords.getX() )
								Is_Done = false;
							else
								Is_Done = true;
						}
					}
					if( Check == 2 )
					{
						if( gx == true )
						{
							if( Coords.getY() >= Max_Coords.getY() )
								Is_Done = false;
							else
								Is_Done = true;
						}
						else
						{
							if( Coords.getY() <= Max_Coords.getY() )
								Is_Done = false;
							else
								Is_Done = true;
						}
					}
					if( Check == 3 )
					{
						if( gx == true )
						{
							if( Coords.getZ() >= Max_Coords.getZ() )
								Is_Done = false;
							else
								Is_Done = true;
						}
						else
						{
							if( Coords.getZ() <= Max_Coords.getZ() )
								Is_Done = false;
							else
								Is_Done = true;
						}
					}
					return Is_Done;
				}
				inline WSL::Containers::Bool_XYZ Move( WSL::Containers::Base::XYZ Vector, WSL::Containers::Base::XYZ Coords, WSL::Containers::Base::XYZ Max_Coords, bool Gx, int Check )
				{
					Coords.setX( Coords.getX() + Vector.getX() );
					Coords.setY( Coords.getY() + Vector.getY() );
					Coords.setZ( Coords.getZ() + Vector.getZ() );
					/*This captures the calculated data, and also performes a check to see if
					any further calculations are required.*/
					return WSL::Containers::Bool_XYZ( Coords, check( Check, Gx, Coords, Max_Coords ) );
				}
				WSL::Containers::Double_XYZ Initialize_Calculation( WSL::Containers::Base::XYZ Goto, WSL::Containers::Base::XYZ Position, float Range )
				{
					//Calculate a vector.//
					Vector = Vector_C->VectorCalculation( Goto, Position, Range, true );
					//I wrote this a long time ago my guess is to move the vector a bit.//
					Position.setX( Position.getX() + Vector.getX() );
					Position.setY( Position.getY() + Vector.getY() );
					Position.setZ( Position.getZ() + Vector.getZ() );
					//Return our data.//
					return WSL::Containers::Double_XYZ( Position, Vector );
				}
				WSL::Containers::Int_Bool Check_Set( WSL::Containers::Base::XYZ point_a, WSL::Containers::Base::XYZ point_b, WSL::Containers::Base::XYZ vector )
				{
					/*Sets the paremiters to later on "check" if
					any further calculations are required.*/
					WSL::Containers::Int_Bool ib;
					if( vector.getX() != 0 )
					{
						if( point_a.getX() >= point_b.getX() )
							ib.setBool( true );
						else
							ib.setBool( false );
						ib.setInt( 1 );
					}
					if( ib.getInt() != 1 && vector.getY() != 0 )
					{
						if( point_a.getY() >= point_b.getY() )
							ib.setBool( true );
						else
							ib.setBool( false );
						ib.setInt( 2 );
					}
					if( ib.getInt() != 1 && ib.getInt() != 2 && vector.getY() != 0 )
					{
						if( point_a.getZ() >= point_b.getZ() )
							ib.setBool( true );
						else
							ib.setBool( false );
						ib.setInt( 3 );
					}
					return ib;
				}
				//Makes a number positive.//
				inline float Make_Positive( float f ) { if( f < 0 ) { f *= -1; } return f; }
				std::vector<WSL::Containers::Base::XYZ> Build( std::vector<WSL::Containers::Base::XYZ> Points )
				{
					//Resetting functors.//	
					Col_C.clear();
					//Declaring any varibles ( data ) we may need.//
					WSL::Containers::Bool_XYZ data( false );
					int Check = 0;
					bool Gx, Done;
					Gx = true;
					Done = false;
					unsigned int count = 0;
					unsigned int i, curr;
					i = 0;
					curr = i;
					unsigned int size = Points.size();
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
							memory but it makes the code legible.*/
							store = Initialize_Calculation( Points[curr], Points[i], 1 );
							//Retriving data.//
							Points[i] = store.getA();
							Vector = store.getB();
							/*Using this method makes the code slower and take up more
							memory but it makes the code legible.*/
							I_B = Check_Set( Points[i], Points[curr], Vector );
							//Retriving data.//
							Check = I_B.getInt();
							Gx = I_B.getBool();
							data = Move( Vector, Points[i], Points[curr], Gx, Check );
							//This makes it so the loop does not continue forever.//
							if( Vector.getX() != 0 || Vector.getY() != 0 || Vector.getZ() != 0 )
							{
								//To make sure we have calculated all there is to be calculated.//
								while( Done == false )
								{
									/*Using this method makes the code slower and take up more
									memory but it makes the code legible.*/
									data = Move( Vector, data.getCoords(), Points[curr], Gx, Check );
									//Retriving data.//
									Done = data.getBool();
									//For debugging.//
									count++;
									//Performing logic and possible math on the calculated data.//
									data.getCoords().setX( Make_Positive( data.getCoords().getX() ) );
									data.getCoords().setY( Make_Positive( data.getCoords().getY() ) );
									data.getCoords().setZ( Make_Positive( data.getCoords().getZ() ) );
									//Adding the data to the main set of data.//
									Col_C.push_back( data.getCoords() );
								}
							}
							//Get ready for possible next ieteration.//
							Done = false;
							Check = 0;
							count = 0;
							//Using to perform logic and ieaterate.//
							i++;
						}
					}
					//Returning the master data.//
					return Col_C;
				}
			};
		}
	}
}
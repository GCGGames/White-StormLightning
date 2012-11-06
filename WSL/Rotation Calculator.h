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
#include "Scan Area.h"
namespace WSL
{
	namespace Collision
	{
		namespace Scan_Area_Collision
		{
			struct Rotation_Calculator
			{
				void Move( Collision::Scan_Area_Collision::Scan_Area s )
				{
					while( P[0].getX() < s.getPoint( 0 ).getX() )
					{
						P[0].setX( P[0].getX() + data.getX() );
						P[0].setY( P[0].getY() + data.getY() );
						while( i < P.size() )
						{
							P[i].setX( P[0].getX() + TempMags[i].getX() );
							P[i].setY( P[0].getY() + TempMags[i].getY() );
							i++;
						}
						i = 1;
					}
				}
				inline float MakePositive( float value )
				{
					if( value < 0 )
						return ( value * -1 );
					return ( value );
				}
				Collision::Scan_Area_Collision::Scan_Area Degree_Rotation( Collision::Scan_Area_Collision::Scan_Area s, float Degree )
				{
					WSL::Containers::Base::XYZ orignalPosition( s.getPoint( 0 ).getX(), s.getPoint( 0 ).getY(), s.getPoint( 0 ).getZ() );
					s.SetRotation( s.GetRotation() + Degree );
					//Just to make things easier ( P and M are declared else-were ).//
					P = s.getPoints();
					//M = s.getMagnitudes();
					M.clear();
					//Makes a lot less code to be typed/processed.//
					if( P.size() != 0 )
					{
						//Out ietirator.//
						i = 0;
						//Rotation formula.//
						Degree /= 100;
						unsigned int size = P.size();
						while( i < size )
						{
							X = P[i].getX() * cos( Degree ) - P[i].getY() * sin( Degree );
							Y = P[i].getX() * sin( Degree ) + P[i].getY() * cos( Degree );
							P[i].setX( X );
							P[i].setY( Y );
							i++;
						}
						//i = 0;
						//TempMags.clear();
						//i = 0;
						/*

							 //////////////////////////////////////////////////////////////////////////
							///Since the rotation formula does not rotate around the point or a axis//
						   ////we want it to, we calculate the center of were the object is now./////
						  //////////////////////////////////////////////////////////////////////////

						*/
						//Resetting iertorator.//
						i = 0;
						//Giving a intital compartive value.//
						L = P[i].getX();
						l = P[i].getY();
						S = P[i].getX();
						sm = P[i].getY();
						/*Finding the largest and
						  smallest points in the object.*/
						while( i < size )
						{
							if( P[i].getX() > L )
								L = P[i].getX();
							if( P[i].getY() > l )
								l = P[i].getY();
							if( P[i].getX() < S )
								S = P[i].getX();
							if( P[i].getY() < sm )
								sm = P[i].getY();
							i++;
						}
						i = 0;
						float tmx, tmy;
						tmx = 0;
						tmy = 0;
						size = M.size();
						while( i < size )
						{
							if( M[i].getX() < tmx )
								tmx = M[i].getX();
							if( M[i].getY() < tmy )
								tmx = M[i].getY();
							i++;
						}
						i = 0;
						//Calculating the center of the object.//
						/*
							---Varible Description List---
						Captilized varibles are for X and lowercase varibles are for Y.

						L or l for larger value.

						sm or S for smaller value.

						Cx for center X.

						Cy for center Y.

						*/
						{
							float lxt = L;
							float lyt = l;
							float sxt = S;
							float syt = sm;
							Cx = L;
							Cy = l;
							L -= S;
							l -= sm;
							L /= 2;
							l /= 2;
							Cx -= L;
							Cy -= l;
							L = Cx;
							l = Cy;
							s.SetLargeX( L - lxt );
							s.SetLargeY( l - lyt );
							s.SetSmallX( L - sxt );
							s.SetSmallY( l - syt );
						}
						/*Substitue std::vector for the one
						  that currently holds all the magnitudes of all the points
						  from the center of the shape.*/
						Mags.clear();
						i = 0;
						yc = false;
						xc = false;
						float smallZ = s.getZ();
						float largeZ = s.getZ();
						size = P.size();
						while( i < size )
						{
							/*Calculate the points new magnitude
							  from thier center.*/
							Mags.push_back( WSL::Containers::Base::XYZ
								( P[i].getX() - L, P[i].getY() - l, P[i].getZ() ) );
							if( P[i].getZ() > largeZ )
								largeZ = P[i].getZ();
							if( P[i].getZ() < smallZ )
								smallZ = P[i].getZ();
							i++;
						}
						s.SetLargeZ( largeZ );
						s.SetSmallZ( smallZ );
						//Resetting the magnitudes.//
						s.setMagnitudes( Mags );
						/*Return our "Scan Area".
						  Another method will properly
						  place our points with their new
						  magnitudes.*/
						s.setPoints( P );
						s.setRotated( true );
					}
					return s;
				}
				private:
				//Data for later use.//
				float X, Y, L, l, sm, S, Cx, Cy, Tx, Ty, Sx, Sy;
				std::vector<WSL::Containers::Base::XYZ> Mags, P, TempMags, M;
				unsigned int i, Iret;
				bool xc, yc;
				WSL::Containers::Base::XYZ data;
			};
		}
	}
}
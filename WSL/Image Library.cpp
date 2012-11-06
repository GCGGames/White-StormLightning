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
#include "Image Library.h"
unsigned int WSL::Global::Image_Library::AddImage( std::string Name, std::string Dir )
{
	unsigned int i = 0;
	bool confirm = false;
	while( i < dirs.size() && confirm == false )
	{
		if( Dir == dirs[i] )
			confirm = true;
		else
			i++;
	}
	if( confirm == true )
	{
		std::cout<<"Image already loaded. Returning image index."<<std::endl;
		return i;
	}
	else
	{
		i = 0;
		while( i < names.size() && confirm == false )
		{
			if( Name == names[i] )
				confirm = true;
			else
				i++;
		}
		if( confirm == true )
		{
			std::cout<<"The name "<<Name<<" has already been used"<<std::endl;
			std::cout<<"to denotate a diffrent image, your image shall now be"<<std::endl;
			std::cout<<"called "<<Name + "1"<<"."<<std::endl;
			Name += "1";
		}
		sf::Image temp;
		masterImages.push_back( temp );
		dirs.push_back( Dir );
		names.push_back( Name );
		if( masterImages[masterImages.size() - 1].LoadFromFile( Dir ) )
		{
		}
		else
		{
			std::cout<<"Failed to load image "<<Name<<" from file "<<Dir<<std::endl;
			std::cout<<"Please make sure the file directory is correct and attempt to load the image again."<<std::endl;
		}	
	}
	return masterImages.size() - 1;
}
/*	

		When dealing with sf::Images they can not go out of scope.
	so to get the correct one you put these methods in as a argument.

	For example:
		Sprite.SetImage( imageLibrary.masterImages[ GetImage( "Rocket Ship" ) ] );


*/
unsigned int WSL::Global::Image_Library::GetImage( std::string Name )
{
	if( masterImages.size() >= 0 )
	{
		unsigned int i = 0;
		unsigned int namesSize = names.size();
		while(  i < namesSize && Name != names[i] )
				i++;
		if( i < names.size() )
			return i;
		else
		{
			std::cerr<<"No image found with the name "<<Name<<". Please enter a name for a valid image."<<std::endl;
			return 0;
		}
	}
	else
	{
		std::cout<<"You have attempted to accses a non-existant image."<<std::endl;
		std::cout<<"This message has occured beacuse you have not allocated any images."<<std::endl;
		std::cout<<"A default value has been returned."<<std::endl;
		return 0;
	}
}
unsigned int WSL::Global::Image_Library::GetImage( unsigned int Elem )
{
	if( Elem >= 0 )
	{
		if( Elem < masterImages.size() )
			return Elem;
		else
		{
			std::cout<<"You have attempted to accses a non-existant image"<<std::endl;
			std::cout<<"A default has been returned."<<std::endl;
			return 0;
		}
		return Elem;
	}
	else
	{
		std::cout<<"Please do not try to go out of the vector subscript range of images"<<std::endl;
		std::cout<<"You entered "<<Elem<<", this number is invalid. A default value has been returned."<<std::endl;
		return 0;
	}
}
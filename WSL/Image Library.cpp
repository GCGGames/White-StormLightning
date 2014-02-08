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
unsigned int WSL::Global::ImageLibrary::AddImage( std::string name, std::string dir )
{
	unsigned int i = 0;
	bool confirm = false;
	while( i < dirs.size() && confirm == false )
	{
		if( dir == dirs[ i ] )
			confirm = true;
		else
			i++;
	}
	if( confirm == true ) {
		std::cout << "Image already loaded. Returning image index." << std::endl;
		return i;
	}
	else
	{
		i = 0;
		while( i < names.size() && confirm == false )
		{
			if( name == names[ i ] )
				confirm = true;
			else
				i++;
		}
		if( confirm == true )
		{
			std::cout << "The name " << name << " has already been used" << std::endl;
			std::cout << "to denotate a diffrent image, your image shall now be" << std::endl;
			std::cout << "called " << name + "1" << "." << std::endl;
			name += "1";
		}
		sf::Image temp;
		masterImages.push_back( temp );
		dirs.push_back( dir );
		names.push_back( name );
		if( !( masterImages[ masterImages.size() - 1 ].LoadFromFile( dir ) ) ) {
			std::cout << "Failed to load image " << name << " from file " << dir << std::endl;
			std::cout << "Please make sure the file directory is correct and attempt to load the image again." << std::endl;
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
unsigned int WSL::Global::ImageLibrary::GetImage( std::string name )
{
	if( masterImages.size() >= 0 )
	{
		unsigned int i = 0;
		unsigned int namesSize = names.size();
		while( i < namesSize && name.compare( names[ i ] ) != 0 )
				i++;
		if( i < names.size() )
			return i;
		else {
			std::cerr << "No image found with the name " << name << ". Please enter a name for a valid image." << std::endl;
			return 0;
		}
	}
	else
	{
		std::cout << "You have attempted to accses a non-existant image." << std::endl;
		std::cout << "This message has occured beacuse you have not allocated any images." << std::endl;
		std::cout << "A default value has been returned." << std::endl;
		return 0;
	}
}
unsigned int WSL::Global::ImageLibrary::GetImage( unsigned int element )
{
	if( element >= 0 )
	{
		if( element < masterImages.size() )
			return element;
		else
		{
			std::cout << "You have attempted to accses a non-existant image" << std::endl;
			std::cout << "A default has been returned." << std::endl;
			return 0;
		}
		return element;
	}
	else
	{
		std::cout << "Please do not try to go out of the vector subscript range of images" << std::endl;
		std::cout << "You entered " << element << ", this number is invalid. A default value has been returned." << std::endl;
		return 0;
	}
}
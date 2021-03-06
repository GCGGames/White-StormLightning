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
#include "Lightning Sprite.h"
void WSL::Components::LightningSprite::AddAnimation( unsigned int animation ) {
	animations.push_back( animation );
}
unsigned int WSL::Components::LightningSprite::AddAnimationToSingleton()
{
	refrence->animations.Add( WSL::Components::Algorithimic::Animation() );
	unsigned int a = refrence->animations.Array.size() - 1;
	animations.push_back( a );
	return (a);
}
//There is no debugging for this method.//
void WSL::Components::LightningSprite::Animate()
{
	if( animate == true )
	{
		unsigned int size = animations.size();
		if( size != 0 )
		{
			if( currentAnimation < size )
			{
				if( refrence->animations.Array[ currentAnimation ].GetType() == Sheet )
					t.SetSubRect( refrence->animations.Array[ currentAnimation ].AnimateSheet( animateFirstToLast ) );
				else
					t.SetImage( refrence->imageLibrary->masterImages[ refrence->animations.Array[ currentAnimation ].AnimateImages( animateFirstToLast ) ] );
			}
		}
	}
}
bool WSL::Components::LightningSprite::GetAnimate() {
	return ( animate );
}
bool WSL::Components::LightningSprite::GetAnimateFirstToLast() {
	return ( animateFirstToLast );
}
unsigned int WSL::Components::LightningSprite::GetCurrentAnimation() {
	return ( currentAnimation );
}
void WSL::Components::LightningSprite::DeleteRefrence() {
	refrence = NULL;
}
void WSL::Components::LightningSprite::SetAnimate( bool animate_ ) {
	animate = animate_;
}
void WSL::Components::LightningSprite::SetAnimateFirstToLast( bool animateFirstToLast_ ) {
	animateFirstToLast = animateFirstToLast_;
}
void WSL::Components::LightningSprite::SetCurrentAnimation( unsigned int currentAnimation_ ) {
	currentAnimation = currentAnimation_;
}
void WSL::Components::LightningSprite::SetRefrence( WSL::Base::EngineBase* refrence_ ) {
	refrence = NULL;
	refrence = refrence_;
}
unsigned int WSL::Components::LightningSprite::GetImage() {
	return image;
}
void WSL::Components::LightningSprite::Resize( float x, float y ) {
	t.Resize( x, y );
}
void WSL::Components::LightningSprite::Resize( float size ) {
	t.Resize( size, size );
}
void WSL::Components::LightningSprite::SetImage( unsigned int image_, WSL::Global::ImageLibrary* imgLib ) {
	image = image_;
	t.SetImage( imgLib->masterImages[ image ] );
}
void WSL::Components::LightningSprite::SetUpSprite( float x, float y, bool reScale )
{
	if( image != image )
	{
		std::cerr << "Please select a image before using the overload ( float x, float y, bool )" << std::endl;
		std::cerr << "for SetUpSprite. If you would like to select a image while doing so" << std::endl;
		std::cerr << "please use the same line but with the following arguments ( float x, float y, bool unsigned int, bool )." << std::endl;
	}
	else
	{
		t.SetCenter( t.GetSize().x / 2.f, t.GetSize().y / 2.f );
		t.SetPosition( x, y );
		position.SetX( x );
		position.SetY( y );
		if( reScale == true )
			t.SetScale( 1.f, 1.f );
	}
}
void WSL::Components::LightningSprite::SetUpSprite( unsigned int image_, bool reScale, WSL::Global::ImageLibrary* imgLib )
{
	SetImage( image_, imgLib );
	t.SetCenter( t.GetSize().x / 2.f, t.GetSize().y / 2.f );
	t.SetPosition( 0.f, 0.f );
	if( reScale == true )
		t.SetScale( 1.f, 1.f );
}
void WSL::Components::LightningSprite::SetUpSprite( float x, float y, unsigned int image_, bool reScale, WSL::Global::ImageLibrary* imgLib )
{
	SetImage( image_, imgLib );
	t.SetCenter( t.GetSize().x / 2.f, t.GetSize().y / 2.f );
	t.SetPosition( x, y );
	position.SetX( x );
	position.SetY( y );
	if( reScale == true )
		t.SetScale( 1.f, 1.f );
}
void WSL::Components::LightningSprite::SendAnimation() {
	luabind::globals( refrence->luaContainer->State )[ "animation" ] = &refrence->animations.Array[ currentAnimation ];
}
void WSL::Components::LightningSprite::UpadateAnimations( WSL::Algorithmic::SenderNode node2 )
{
	//To make sure we still have valid information.//
	unsigned int size, i;
	i = 0;
	size = animations.size();
	std::vector<unsigned int> index;
	while( i < size )
	{
		node.SetElement( animations[ i ] );
		node.UpdateStatus( node2.Notify( animations[ i ] ) );
		animations[ i ] = node.GetElement();
		{
			unsigned int i2 = 0;
			unsigned int Size = node2.Size();
			while( i2 < Size )
			{
				if( animations[ i ] == node2.GetDeletedPosition( i2 ) )
					index.push_back( i );
				i2++;		
			}
		}
		if( i < size )
			i++;
	}
	i = 0;
	size = index.size();
	while( i < size ) {
		animations.erase( animations.begin() + index[ i ] );
		i++;
	}
}
void WSL::Components::LightningSprite::Draw( sf::RenderWindow* window ) {
	Animate();
	window->Draw( t );
}

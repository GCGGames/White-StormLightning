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
#include "Core Info Container.h"
namespace WSL
{
	namespace Framework
	{
		namespace Standard
		{
			namespace Base
			{
				class BaseEntity
				{
					protected:
						bool refresh, destroy, initialize, runDestroyScript, onLuaStack;
						int objID, iD, componentID;
						std::string refreshScript, initializeScript, destroyScript, otherScript;
						WSL::Engine* refrence;
						std::vector< WSL::Containers::CoreInfoContainer > children;
					public:
						BaseEntity() {
						}
						virtual void RunSubClassMethodBegin() {
						}
						virtual void RunSubClassMethodEnd() {
						}
						void (* SendSelf )();
						virtual void InitializeEntity( int objectID ) {
						}
						virtual void Construct( int objectID, bool refresh_, bool destroy_, bool initialize_, bool runDestroy,
							std::string refeshScript_, std::string initializeScript_, std::string destroyScript_,
							std::string otherScript_, WSL::Engine* refrence_ ) {
						}
						virtual void DeleteRefrence() {
						}
						virtual std::string GetRefreshScript() {
							return std::string();
						}
						virtual std::string GetInitializeScript() {
							return std::string();
						}
						virtual std::string GetDestroyScript() {
							return std::string();
						}
						virtual std::string GetOtherScript() {
							return std::string();
						}
						virtual bool GetDestroy(){ return false;
						}
						virtual bool GetIsOnLuaStack() { return false;
						}
						virtual void SetDestroy( bool destroy_ ) {
						}
						virtual WSL::Containers::CoreInfoContainer GetChild( unsigned int id, unsigned int objID_ ) {
							return WSL::Containers::CoreInfoContainer();
						}
						virtual void SetRefrence( WSL::Engine* refrence_ ) {
						}
						virtual void SendToLua() {
						}
						virtual void SetResfreshScript( std::string script ) {
						}
						virtual void SetInitializeScript( std::string script ) {
						}
						virtual void SetDestroyScript( std::string script ) {
						}
						virtual void SetOtherScript( std::string script ) {
						}
						virtual void SetChild( unsigned int id, unsigned int objID_, WSL::Containers::CoreInfoContainer replacement ) {
						}
						virtual void SetOnLuaStack( bool value ) {
							onLuaStack = value;
						}
						virtual int GetComponentID() {
							return ( 0 );
						}
						virtual int GetID() {
							return ( 0 );
						}
						virtual int GetObjID() {
							return ( 0 );
						}
						virtual void SetObjID( int value ) {
						}
						virtual void SetID( int value ) {
						}
						virtual void RunScript( std::string script ) {
						}
						virtual void RunInitScript( std::string script ) {
						}
						virtual void Initialize() {
						}
						virtual void Refresh() {
						}
						virtual void Destroy() {
						}
						virtual void DeleteIdentification() {
						}
						virtual void EntityInitialize() {
						}
						virtual void EntityRefresh() {
						}
						virtual void EntityDestroy() {
						}
				};
			}
		}
	}
}
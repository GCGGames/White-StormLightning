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
#include "Lua Send Base.h"
namespace WSL
{
	namespace Algorithmic
	{
		namespace Base
		{
			struct SubSingletonFoundation
			{
				WSL::DataTransfer::Lua::SenderBase *sender;
				void DeleteRefrence(){ refrence = NULL; sender = NULL; }
				void SetRefrence( WSL::Base::SingletonBase *singleton ){ refrence = singleton; }
				bool active;
				inline bool GetActive()
				{
					return active;
				}
				inline void SetActive( bool active_ )
				{
					active = active_;
				}
			protected:
				WSL::Base::SingletonBase *refrence;
			};
			struct SubSingleBase : public SubSingletonFoundation
			{
				virtual void Initialize(){}
				virtual void Refresh(){}
				virtual void Destroy(){}
				bool initialize, refresh, destroy;
				std::string initializeScript, refreshScript, destroyScript;
			};
		}
	}
}
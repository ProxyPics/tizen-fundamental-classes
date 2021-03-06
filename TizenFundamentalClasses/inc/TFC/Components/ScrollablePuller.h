/*
 * Tizen Fundamental Classes - TFC
 * Copyright (c) 2016-2017 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *    Components/ScrollablePuller.h
 *
 * Experimental component to implement scroll-to-refresh like UI
 *
 * Created on:  Nov 18, 2016
 * Author:      Kevin Winata
 */

#ifndef TFC_COMPONENTS_SCROLLABLEPULLER_H_
#define TFC_COMPONENTS_SCROLLABLEPULLER_H_

#include "TFC/Components/ComponentBase.h"

namespace TFC {
namespace Components {

class LIBAPI ScrollablePuller :
		public ComponentBase,
		public EFL::EFLProxyClass,
		EventEmitterClass<ScrollablePuller>,
		PropertyClass<ScrollablePuller>
{
	using PropertyClass<ScrollablePuller>::Property;
	using EventEmitterClass<ScrollablePuller>::Event;

public :
	ScrollablePuller();
	~ScrollablePuller();

	Event<void*> eventPull;
	Event<Evas_Object**> eventPullerContentFill;

	void ResetPuller();
	void TogglePuller(bool enable);
protected :
	virtual Evas_Object* CreateComponent(Evas_Object* root) final;
private :
	std::string partName;

	EvasObjectEvent eventResize;
	EvasSmartEvent eventScrollTop;
	EvasSmartEvent eventScrollDown;
	EvasSmartEvent eventPulledEnd;
	EvasSmartEvent eventPullerScroll;
	EvasSmartEvent eventPullerStop;

	std::size_t pullerSize;
	Evas_Coord width;
	Evas_Coord height;
	Evas_Coord posX;
	Evas_Coord posY;

	Evas_Object* scrollable;
	Evas_Object* rootLayout;
	Evas_Object* puller;
	Evas_Object* box;
	Evas_Object* bgTop;
	Evas_Object* bgBottom;

	bool pullerShown;

	Evas_Object* GetScrollable() { return scrollable; }
	void SetScrollable(Evas_Object* scroll) { scrollable = scroll; }

	std::string const& GetPartName() const { return partName; }
	void SetPartName(std::string const& name) { partName = name; }

	std::size_t GetPullerSize() const { return pullerSize; }
	void SetPullerSize(std::size_t const& size) { pullerSize = size; }

	void OnResize(EFL::EvasEventSourceInfo objSource, void* event_data);
	void OnScrollTop(Evas_Object* obj, void* eventData);
	void OnScrollDown(Evas_Object* obj, void* eventData);
	void OnPulledEnd(Evas_Object* obj, void* eventData);
	void OnPullerScroll(Evas_Object* obj, void* eventData);
	void OnPullerStop(Evas_Object* obj, void* eventData);
public:
	Property<Evas_Object*>::Get<&ScrollablePuller::GetScrollable>::Set<&ScrollablePuller::SetScrollable> Scrollable;
	Property<std::string const&>::Get<&ScrollablePuller::GetPartName>::Set<&ScrollablePuller::SetPartName> PartName;
	Property<std::size_t>::Get<&ScrollablePuller::GetPullerSize>::Set<&ScrollablePuller::SetPullerSize> PullerSize;
};

}
}



#endif /* TFC_COMPONENTS_SCROLLABLEPULLER_H_ */

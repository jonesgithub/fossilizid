/*
 * channelserver.cpp
 *
 *  Created on: 2015-1-17
 *      Author: qianqians
 */
#include "channelserver.h"

#include <boost/make_shared.hpp>

namespace Fossilizid{
namespace juggle {

namespace jsonplugin{

namespace acceptor{

channelserver::channelserver(boost::shared_ptr<service> service){
	_service = service;
}

channelserver::~channelserver(){
}

void channelserver::init(char * ip, short port){
	que = remoteq::queue();
	acp = remoteq::acceptor(que, remoteq::endpoint(ip, port));

	_service->init();
}

void channelserver::poll(){
	remoteq::EVENT ev = remoteq::queue(que);
	switch (ev.type)
	{
	case remoteq::event_type_none:
		break;
				
	case remoteq::event_type_accept:
		{
			remoteq::CHANNEL ch = remoteq::accept(ev.handle.acp);
			if (ch != 0){
				boost::shared_ptr<channel> c = boost::make_shared<channel>(ch);
				mapchannel.insert(std::make_pair(ch, c));
				c->handle_new_channel();
			}
		}
		break;

	case remoteq::event_type_recv:
		{	
			remoteq::CHANNEL ch = ev.handle.ch;
				
			boost::shared_ptr<juggle::object> v = boost::make_shared<object>();
			while (remoteq::pop(ch, *v, jsonplugin::buf_to_object)){
				if (v->hasfield("suuid")){
					continue;
				}

				mapchannel[ch]->pushcmd(v);
			}
		}
		break;

	case remoteq::event_type_disconnect:
		{
			mapchannel[ev.handle.ch]->handle_disconnect_channel();
			mapchannel.erase(ev.handle.ch);
			remoteq::close(ev.handle.ch);
		}
		break;

	default:
		break;
	}

	_service->poll();
}

} /* namespace acceptor */

namespace connect{

channelserver::channelserver(boost::shared_ptr<service> service){
	_service = service;
}
	
channelserver::~channelserver(){
}

void channelserver::connect(char * ip, short port){
	remoteq::CHANNEL ch = remoteq::connect(remoteq::endpoint(ip, port), que);
	if (ch != 0){
		boost::shared_ptr<channel> c = boost::make_shared<channel>(ch);
		mapchannel.insert(std::make_pair(ch, c));
		c->handle_new_channel();
	}
}

void channelserver::init(){
	que = remoteq::queue();

	_service->init();
}

void channelserver::poll(){
		remoteq::EVENT ev = remoteq::queue(que);
	switch (ev.type)
	{
	case remoteq::event_type_none:
		break;

	case remoteq::event_type_recv:
		{	
			remoteq::CHANNEL ch = ev.handle.ch;
				
			boost::shared_ptr<juggle::object> v = boost::make_shared<object>();
			while (remoteq::pop(ch, *v, jsonplugin::buf_to_object)){
				if (v->hasfield("suuid")){
					continue;
				}

				mapchannel[ch]->pushcmd(v);
			}
		}
		break;

	case remoteq::event_type_disconnect:
		{
			mapchannel[ev.handle.ch]->handle_disconnect_channel();
			mapchannel.erase(ev.handle.ch);
			remoteq::close(ev.handle.ch);
		}
		break;

	default:
		break;
	}

	_service->poll();
}

} /* namespace connect */

} /* namespace jsonplugin */

} /* namespace juggle */
} /* namespace Fossilizid */
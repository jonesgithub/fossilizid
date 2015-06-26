/*
 * channelserver.h
 *
 *  Created on: 2015-1-17
 *      Author: qianqians
 */
#ifndef _json_channelserver_h
#define _json_channelserver_h

#include <boost/unordered_map.hpp>

#include "../../interface/service.h"
#include "../../../remoteq/remote_queue.h"

#include "channel.h"

namespace Fossilizid{
namespace juggle{

namespace jsonplugin{

namespace acceptor{

class channelserver{
public:
	channelserver(boost::shared_ptr<service> service);
	~channelserver();

	void init(char * ip, short port);

	void poll();

private:
	remoteq::QUEUE que;
	remoteq::ACCEPTOR acp;

	boost::shared_ptr<service> _service;

	boost::unordered_map<remoteq::CHANNEL, boost::shared_ptr<channel> > mapchannel;

};

} /* namespace acceptor */

namespace connect{

class channelserver{
public:
	channelserver(boost::shared_ptr<service> service);
	~channelserver();

	void connect(char * ip, short port);

	void init();

	void poll();

private:
	remoteq::QUEUE que;

	boost::shared_ptr<service> _service;

	boost::unordered_map<remoteq::CHANNEL, boost::shared_ptr<channel> > mapchannel;

};

} /* namespace connect */

} /* namespace json */

} /* namespace juggle */
} /* namespace Fossilizid */

#endif //_json_channelserver_h
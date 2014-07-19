/*************************************************************************
 * libjson-rpc-cpp
 *************************************************************************
 * @file    socketclient.h
 * @date    12.07.2014
 * @author  Bertrand Cachet <bertrand.cachet@gmail.com>
 * @license See attached LICENSE.txt
 ************************************************************************/
#ifndef JSONRPC_CONNECTORS_SOCKETCLIENT_H
#define JSONRPC_CONNECTORS_SOCKETCLIENT_H

#include "../clientconnector.h"
#include "../exception.h"
#include "socket.h"

// WinUser.h has a preprocessor macro to replace SendMessage with SendMessageW or SendMessageA
// We need to undef this macro to be sure that our AbstractClientConnector::SendMessage methods are not
// modified by this preprocessor macro
#ifdef _WINUSER_
	#ifdef SendMessage
	#undef SendMessage
	#endif
#endif


namespace jsonrpc
{
  class SocketClient : public AbstractClientConnector
  {
    public:
      SocketClient(const std::string& url = "0.0.0.0", const std::string& port = "8080", const int type = SOCK_STREAM) throw (JsonRpcException);
      virtual ~SocketClient();

	  void SendMessage(const std::string& message, std::string& result) throw(JsonRpcException);
    private:
      int socket_;
      struct addrinfo* server_info_;
  };
} // namespace jsonrpc

#endif /* JSONRPC_CONNECTORS_SOCKETCLIENT_H*/

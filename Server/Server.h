#pragma once
#include <SFML/Network.hpp>

class Server
{
public:
	explicit Server(unsigned short port);
	void     Update();

private:
	unsigned short m_port;
	sf::TcpSocket m_socket;
	sf::TcpListener m_listener;
	sf::IpAddress m_ipAddress;
};
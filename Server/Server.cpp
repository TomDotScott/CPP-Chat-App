#include <iostream>
#include "Server.h"

Server::Server(const unsigned short port) :
	m_port(port),
	m_ipAddress(sf::IpAddress::getLocalAddress())
{
	if (m_socket.connect(m_ipAddress, m_port) == sf::TcpSocket::Status::Error)
	{
		std::cout << "Connection error" << std::endl;
	}

	m_listener.listen(m_port);
	m_listener.accept(m_socket);
}

void Server::Update()
{
	char buffer[1024];
	std::size_t receivedSize;
	m_socket.receive(buffer, sizeof(buffer), receivedSize);
	if (receivedSize > 0)
	{
		std::cout << buffer << std::endl;
	}
}

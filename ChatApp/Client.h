#pragma once
#include <string>
#include <SFML/Network.hpp>

class Client
{
public:
	Client(std::string userName, unsigned short port);
	void Update();

private:
	std::string m_name;
	sf::TcpSocket m_socket;
	sf::IpAddress m_ipAddress;

	void Send(const std::string& message);
	void Receive(char* buffer);
};

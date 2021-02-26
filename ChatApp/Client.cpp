#include "Client.h"

#include <iostream>

Client::Client(std::string userName, const unsigned short port) :
	m_name(std::move(userName)),
	m_ipAddress(sf::IpAddress::getLocalAddress())
{
	if (m_socket.connect(m_ipAddress, port) == sf::TcpSocket::Status::Error)
	{
		std::cout << "Connection error" << std::endl;
	}else
	{
		const std::string confirmationMessage{ m_name + " has connected on port: " + std::to_string(m_socket.getLocalPort())};
		m_socket.send(confirmationMessage.c_str(), confirmationMessage.length() + 1);
	}

}

void Client::Update()
{
	std::string text;
	std::getline(std::cin, text);
	if (!text.empty())
	{
		Send(m_name + ": " + text);
	}
}

void Client::Send(const std::string& message)
{
	if(m_socket.send(message.c_str(), message.length() + 1) == sf::TcpSocket::Status::Error)
	{
		std::cout << "Error occured when sending the message." << std::endl;
	}
}

void Client::Receive(char* buffer)
{
	size_t received{};
	m_socket.receive(buffer, sizeof(buffer), received);
	if(received > 0)
	{
		std::cout << buffer << std::endl;
	}
}

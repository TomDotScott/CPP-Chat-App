#include <iostream>
#include <thread>
#include "Client.h"


int main()
{
    std::cout << "Enter a username: ";
    std::string name;
    std::cin >> name;
	
    Client client(name, 55002);
    while(true)
    {
        client.Update();
    }
    return 0;
}

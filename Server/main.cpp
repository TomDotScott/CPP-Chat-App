#include <iostream>

#include "Server.h"

int main()
{
    Server server(55002);
	while(true)
	{
		server.Update();
	}
}

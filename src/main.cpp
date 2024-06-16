#include <iostream>
#include "LoadBalancer.h"

int main() {
    int numServers, duration;
    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the duration to run the load balancer: ";
    std::cin >> duration;

    LoadBalancer lb(numServers);
    lb.run(duration);

    return 0;
}

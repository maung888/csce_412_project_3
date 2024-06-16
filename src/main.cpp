#include <iostream>
#include "LoadBalancer.h"

/**
 * @brief Entry point of the program.
 * 
 * This function initializes the load balancer with the user-specified number
 * of servers and runs it for the specified duration.
 * 
 * @return int Exit status of the program.
 */
int main() {
    int numServers; 
    int duration; 

    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;
    std::cout << "Enter the duration to run the load balancer: ";
    std::cin >> duration;

    LoadBalancer lb(numServers);
    lb.run(duration);

    return 0;
}

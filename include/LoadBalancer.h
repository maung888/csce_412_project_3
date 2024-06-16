#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <queue>
#include "WebServer.h"
#include "Request.h"

/**
 * @class LoadBalancer
 * @brief The LoadBalancer class handles distributing requests to web servers.
 */
class LoadBalancer {
public:
    /**
     * @brief Constructor for LoadBalancer.
     * @param numServers Initial number of servers.
     */
    LoadBalancer(int numServers);

    /**
     * @brief Runs the load balancer for a specified duration.
     * @param duration The duration to run the load balancer.
     */
    void run(int duration);

private:
    std::vector<WebServer> web_servers; /**< List of web servers. */
    std::queue<Request> request_queue; /**< Queue of requests. */
    int original_requests; /**< Number of original requests. */
    int random_requests; /**< Number of randomly generated requests. */
    int handled_requests; /**< Number of handled requests. */
    int num_servers; /**< Number of servers. */

    /**
     * @brief Initializes the specified number of requests.
     * @param numRequests The number of requests to initialize.
     */
    void initializeRequests(int numRequests);

    /**
     * @brief Adds a request to the load balancer.
     * @param request The request to add.
     */
    void addRequest(Request request);

    /**
     * @brief Balances the load among the servers.
     */
    void balanceLoad();

    /**
     * @brief Generates a random IP address.
     * @return A random IP address as a string.
     */
    std::string generateRandomIP();

    /**
     * @brief Prints the statistics of the load balancer after completion.
     */
    void printStatistics() const;
};

#endif // LOADBALANCER_H

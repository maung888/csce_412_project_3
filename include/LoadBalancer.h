#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <queue>
#include "WebServer.h"
#include "Request.h"

/**
 * @class LoadBalancer
 * @brief Manages load balancing across multiple web servers.
 */
class LoadBalancer {
public:
    /**
     * @brief Constructs a LoadBalancer with a specified number of servers.
     * @param numServers The number of web servers to manage.
     */
    LoadBalancer(int numServers);

    /**
     * @brief Runs the load balancer for a specified duration.
     * @param duration The duration to run the load balancer, in arbitrary time units.
     */
    void run(int duration);

private:
    std::vector<WebServer> web_servers; ///< A list of web servers managed by the load balancer.
    std::queue<Request> request_queue; ///< A queue of requests waiting to be processed.

    int original_requests; ///< Number of original requests initialized.
    int random_requests; ///< Number of randomly generated requests.
    int handled_requests; ///< Total number of requests handled.
    int num_servers; ///< Maximum number of servers allowed.
    int min_processing_time; ///< Minimum processing time of requests.
    int max_processing_time; ///< Maximum processing time of requests.

    /**
     * @brief Initializes the load balancer with a number of requests.
     * @param numRequests The number of initial requests to generate.
     */
    void initializeRequests(int numRequests);

    /**
     * @brief Adds a request to the request queue.
     * @param request The request to add.
     */
    void addRequest(Request request);

    /**
     * @brief Balances the load across web servers by assigning requests to available servers.
     */
    void balanceLoad();

    /**
     * @brief Generates a random IP address.
     * @return A randomly generated IP address in the format "xxx.xxx.xxx.xxx".
     */
    std::string generateRandomIP();

    /**
     * @brief Prints statistics about the load balancer's operation.
     */
    void printStatistics() const;
};

#endif // LOADBALANCER_H

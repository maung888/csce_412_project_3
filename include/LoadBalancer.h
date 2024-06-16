#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <queue>
#include "WebServer.h"
#include "Request.h"

class LoadBalancer {
public:
    LoadBalancer(int numServers);
    void run(int duration);

private:
    std::vector<WebServer> web_servers;
    std::queue<Request> request_queue;
    int original_requests;
    int random_requests;
    int handled_requests;
    int num_servers;

    void initializeRequests(int numRequests);
    void addRequest(Request request);
    void balanceLoad();
    std::string generateRandomIP();
    void printStatistics() const;
};

#endif // LOADBALANCER_H

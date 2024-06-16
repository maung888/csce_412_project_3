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
    int num_servers;

    void initializeRequests(int numRequests);
    void addRequest(Request request);
    void balanceLoad();
};

#endif // LOADBALANCER_H

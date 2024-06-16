#include "LoadBalancer.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int SERVER_IDLE_THRESHOLD = 5;

LoadBalancer::LoadBalancer(int numServers)
    : original_requests(0), random_requests(0), handled_requests(0), num_servers(numServers) {
    for (int i = 0; i < numServers; ++i) {
        web_servers.emplace_back(i);
    }
    initializeRequests(numServers * 100); // Add initial requests
}

void LoadBalancer::initializeRequests(int numRequests) {
    for (int i = 0; i < numRequests; ++i) {
        addRequest(Request(generateRandomIP(), generateRandomIP(), rand() % 100));
        original_requests++;
    }
}

void LoadBalancer::addRequest(Request request) {
    request_queue.push(request);
    std::cout << "Added request with IP in: " << request.getIpIn() << ", IP out: " << request.getIpOut() << ", processing time: " << request.getProcessingTime() << std::endl;
}

void LoadBalancer::balanceLoad() {
    while (!request_queue.empty()) {
        bool assigned = false;

        for (auto& server : web_servers) {
            if (!server.isBusy()) {
                Request req = request_queue.front();
                request_queue.pop();
                server.assignRequest(req);
                std::cout << "Assigned request to server " << server.getId() << " with IP in: " << req.getIpIn() << ", IP out: " << req.getIpOut() << std::endl;
                assigned = true;
                handled_requests++;
                break;
            }
        }

        if (!assigned && web_servers.size() < static_cast<size_t>(num_servers)) {
            int new_server_id = web_servers.size();
            web_servers.emplace_back(new_server_id);
            Request req = request_queue.front();
            request_queue.pop();
            web_servers.back().assignRequest(req);
            std::cout << "Allocated new server " << new_server_id << " and assigned request with IP in: " << req.getIpIn() << ", IP out: " << req.getIpOut() << std::endl;
            handled_requests++;
        }

        if (!assigned && web_servers.size() >= static_cast<size_t>(num_servers)) {
            break;
        }
    }

    auto it = std::remove_if(web_servers.begin(), web_servers.end(), [](WebServer& server) {
        if (!server.isBusy() && server.getIdleTime() > SERVER_IDLE_THRESHOLD) {
            std::cout << "Deallocating server " << server.getId() << " due to inactivity." << std::endl;
            return true;
        }
        return false;
    });

    web_servers.erase(it, web_servers.end());
}

void LoadBalancer::run(int duration) {
    srand(time(0));

    for (int t = 0; t < duration; ++t) {
        balanceLoad();
        for (auto& server : web_servers) {
            if (server.isBusy()) {
                server.processRequest();
            }
        }

        if (rand() % 100 < 10) {
            addRequest(Request(generateRandomIP(), generateRandomIP(), rand() % 100));
            random_requests++;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    printStatistics();
}

std::string LoadBalancer::generateRandomIP() {
    return std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256);
}

void LoadBalancer::printStatistics() const {
    std::cout << "Load Balancer run completed." << std::endl;
    std::cout << "Original requests: " << original_requests << std::endl;
    std::cout << "Randomly generated requests: " << random_requests << std::endl;
    std::cout << "Total requests handled: " << handled_requests << std::endl;
    std::cout << "Total requests in queue: " << request_queue.size() << std::endl;
}

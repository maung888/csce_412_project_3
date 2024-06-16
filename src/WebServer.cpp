#include "WebServer.h"
#include <iostream>

WebServer::WebServer(int id) : id(id), busy(false), idle_time(0) {}

int WebServer::getId() const {
    return id;
}

bool WebServer::isBusy() const {
    return busy;
}

void WebServer::assignRequest(Request request) {
    current_request = request;
    busy = true;
    last_request_time = std::chrono::high_resolution_clock::now();
    std::cout << "Server " << id << " assigned request with IP in: " << request.getIpIn() << ", IP out: " << request.getIpOut() << std::endl;
}

void WebServer::processRequest() {
    if (busy) {
        auto now = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_request_time).count();
        
        if (duration >= current_request.getProcessingTime()) {
            busy = false;
            setIdleTime(0);
            std::cout << "Server " << id << " finished processing request." << std::endl;
        }
    } else {
        idle_time += 10; // Increment idle time by the sleep duration (10 milliseconds)
    }
}

void WebServer::setIdleTime(int time) {
    idle_time = time;
}

int WebServer::getIdleTime() const {
    return idle_time;
}

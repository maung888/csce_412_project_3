#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <chrono>

class WebServer {
public:
    WebServer(int id);
    int getId() const;
    bool isBusy() const;
    void assignRequest(Request request);
    void processRequest();
    void setIdleTime(int time);
    int getIdleTime() const;

private:
    int id;
    bool busy;
    Request current_request;
    int idle_time; // Idle time in milliseconds
    std::chrono::time_point<std::chrono::high_resolution_clock> last_request_time;
};

#endif // WEBSERVER_H

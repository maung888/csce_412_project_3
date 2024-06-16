#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <chrono>

/**
 * @class WebServer
 * @brief The WebServer class represents a server that handles requests.
 */
class WebServer {
public:
    /**
     * @brief Constructor for WebServer.
     * @param id The ID of the server.
     */
    WebServer(int id);

    /**
     * @brief Gets the ID of the server.
     * @return The server ID as an integer.
     */
    int getId() const;

    /**
     * @brief Checks if the server is busy processing a request.
     * @return True if the server is busy, false otherwise.
     */
    bool isBusy() const;

    /**
     * @brief Assigns a request to the server.
     * @param request The request to be assigned.
     */
    void assignRequest(Request request);

    /**
     * @brief Processes the current request.
     */
    void processRequest();

    /**
     * @brief Sets the idle time of the server.
     * @param time The idle time in milliseconds.
     */
    void setIdleTime(int time);

    /**
     * @brief Gets the idle time of the server.
     * @return The idle time in milliseconds.
     */
    int getIdleTime() const;

private:
    int id; ///< The ID of the server
    bool busy; ///< Indicates if the server is busy processing a request
    Request current_request; ///< The current request being processed
    int idle_time; ///< Idle time in milliseconds
    std::chrono::time_point<std::chrono::high_resolution_clock> last_request_time; ///< Time point of the last request processed
};

#endif // WEBSERVER_H

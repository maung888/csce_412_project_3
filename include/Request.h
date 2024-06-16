#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @class Request
 * @brief The Request class represents a network request with IP addresses and processing time.
 */
class Request {
private:
    std::string ip_in; ///< IP address of the incoming request
    std::string ip_out; ///< IP address of the outgoing request
    int processing_time; ///< Time taken to process the request

public:
    /**
     * @brief Default constructor for Request.
     */
    Request();

    /**
     * @brief Parameterized constructor for Request.
     * @param ipIn The incoming IP address.
     * @param ipOut The outgoing IP address.
     * @param time The processing time for the request.
     */
    Request(std::string ipIn, std::string ipOut, int time);

    /**
     * @brief Gets the incoming IP address.
     * @return The incoming IP address as a string.
     */
    std::string getIpIn() const;

    /**
     * @brief Gets the outgoing IP address.
     * @return The outgoing IP address as a string.
     */
    std::string getIpOut() const;

    /**
     * @brief Gets the processing time.
     * @return The processing time as an integer.
     */
    int getProcessingTime() const;
};

#endif // REQUEST_H

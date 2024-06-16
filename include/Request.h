#ifndef REQUEST_H
#define REQUEST_H

#include <string>


class Request {
private:
    std::string ip_in; ///< IP address of the incoming request
    std::string ip_out; ///< IP address of the outgoing request
    int processing_time; ///< Time taken to process the request

public:

    Request();

    Request(std::string ipIn, std::string ipOut, int time);
    std::string getIpIn() const;

    std::string getIpOut() const;

    int getProcessingTime() const;
};

#endif // REQUEST_H

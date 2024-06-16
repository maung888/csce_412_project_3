#include "Request.h"

Request::Request() : ip_in(""), ip_out(""), processing_time(0) {}

Request::Request(std::string ipIn, std::string ipOut, int time) : ip_in(ipIn), ip_out(ipOut), processing_time(time) {}

std::string Request::getIpIn() const {
    return ip_in;
}

std::string Request::getIpOut() const {
    return ip_out;
}

int Request::getProcessingTime() const {
    return processing_time;
}

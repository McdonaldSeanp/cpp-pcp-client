#include <cpp-pcp-client/connector/timings.hpp>

#include <sstream>

namespace PCPClient {

ConnectionTimings::ConnectionTimings()
        : start { boost::chrono::high_resolution_clock::now() } {
}

ConnectionTimings::Duration_us ConnectionTimings::getTCPInterval() const {
    return boost::chrono::duration_cast<ConnectionTimings::Duration_us>(
        tcp_pre_init - start);
}

ConnectionTimings::Duration_us ConnectionTimings::getHandshakeInterval() const {
    return boost::chrono::duration_cast<ConnectionTimings::Duration_us>(
        tcp_post_init - tcp_pre_init);
}

ConnectionTimings::Duration_us ConnectionTimings::getWebSocketInterval() const {
    return boost::chrono::duration_cast<ConnectionTimings::Duration_us>(
        open - start);
}

ConnectionTimings::Duration_us ConnectionTimings::getCloseInterval() const {
    return boost::chrono::duration_cast<ConnectionTimings::Duration_us>(
        close - start);
}

}  // namespace PCPClient

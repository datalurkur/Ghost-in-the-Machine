#ifndef LOG_H
#define LOG_H

#include <Base/Base.h>

#define LOG_DEBUG   0x01
#define LOG_INFO    0x02
#define LOG_WARNING 0x04
#define LOG_ERROR   0x08

typedef char LogChannel;

class Log {
public:
    static void enableAllChannels();
    static void disableAllChannels();
 
    static void enableChannel(LogChannel channel);
    static void disableChannel(LogChannel channel);

    static bool isChannelEnabled(LogChannel channel);

    static Log& getLogStream(LogChannel channel);

public:
    Log();
    virtual ~Log();

    template <typename T> Log& operator<<(const T &rhs);

private:
    static Log *outputStream;
    static LogChannel channelState;

private:
    std::ostream *_outputStream;
};

template <typename T> Log& Log::operator<<(const T &rhs) {
    (*_outputStream) << rhs;
    return *this;
}

#define LogToChannel(channel, msg) \
    do { \
        if(Log::isChannelEnabled(channel)) { \
            Log::getLogStream(channel) << msg << "\n"; \
        } \
    } while(false)


#define Debug(msg) LogToChannel(LOG_DEBUG,   msg)
#define Info(msg)  LogToChannel(LOG_INFO,    msg)
#define Warn(msg)  LogToChannel(LOG_WARNING, msg)
#define Error(msg) LogToChannel(LOG_ERROR,   msg)

#endif

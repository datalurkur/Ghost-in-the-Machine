#include <Base/Log.h>

Log* Log::outputStream = 0;
LogChannel Log::channelState = 0;

Log::Log(): _outputStream(&std::cout) {
}

Log::~Log() {
    _outputStream->flush();
}

void Log::enableAllChannels() {
    channelState = 0xff;
}

void Log::disableAllChannels() {
    channelState = 0x00;
}

void Log::enableChannel(LogChannel channel) {
    channelState |= channel;
}

void Log::disableChannel(LogChannel channel) {
    channelState &= (0xff - channel);
}

bool Log::isChannelEnabled(LogChannel channel) {
    return (channelState & channel);
}

Log& Log::getLogStream(LogChannel channel) {
    if(!outputStream) {
        outputStream = new Log();
    }
    return *outputStream;
}

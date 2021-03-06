/*
 * Copyright (c) 2018 Ambroz Bizjak
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef AIPSTACK_SIGNAL_WATCHER_COMMON_H
#define AIPSTACK_SIGNAL_WATCHER_COMMON_H

#include <aipstack/event_loop/EventLoop.h>
#include <aipstack/event_loop/SignalCommon.h>

namespace AIpStack {

/**
 * @addtogroup event-loop
 * @{
 */

/**
 * Represents information about a received signal as reported by @ref SignalWatcher.
 */
struct SignalInfo {
    /**
     * Type of received signal.
     */
    SignalType type;
};

#ifndef IN_DOXYGEN
class SignalCollectorImplBase {
public:
    inline SignalType baseGetSignals () const;
};
#endif

#ifndef IN_DOXYGEN
class SignalWatcherImplBase {
public:
    inline EventLoop & getEventLoop () const;
    inline SignalCollectorImplBase & getCollector () const;
    inline void callHandler (SignalInfo signal_info);
};
#endif

/** @} */

}

#endif

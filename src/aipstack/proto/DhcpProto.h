/*
 * Copyright (c) 2017 Ambroz Bizjak
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

#ifndef AIPSTACK_DHCP_PROTO_H
#define AIPSTACK_DHCP_PROTO_H

#include <cstdint>

#include <aipstack/infra/Struct.h>
#include <aipstack/ip/IpAddr.h>

namespace AIpStack {

enum class DhcpOp : std::uint8_t {
    BootRequest = 1,
    BootReply = 2,
};

enum class DhcpHwAddrType : std::uint8_t {
    Ethernet = 1,
};

enum class DhcpOptionOverload : std::uint8_t {
    None = 0, // used internally only
    FileOptions = 1,
    SnameOptions = 2,
    FileSnameOptions = 3,
};

enum class DhcpMagicField : std::uint32_t {
    Magic = 0x63825363,
};

inline constexpr std::uint16_t DhcpServerPort = 67;
inline constexpr std::uint16_t DhcpClientPort = 68;

enum class DhcpOptionType : std::uint8_t {
    Pad = 0,
    End = 255,
    SubnetMask = 1,
    Router = 3,
    DomainNameServer = 6,
    HostName = 12,
    RequestedIpAddress = 50,
    IpAddressLeaseTime = 51,
    OptionOverload = 52,
    DhcpMessageType = 53,
    DhcpServerIdentifier = 54,
    ParameterRequestList = 55,
    Message = 56,
    MaximumMessageSize = 57,
    RenewalTimeValue = 58,
    RebindingTimeValue = 59,
    VendorClassIdentifier = 60,
    ClientIdentifier = 61,
};

enum class DhcpMessageType : std::uint8_t {
    Discover = 1,
    Offer = 2,
    Request = 3,
    Decline = 4,
    Ack = 5,
    Nak = 6,
    Release = 7,
};

AIPSTACK_DEFINE_STRUCT(DhcpHeader1,
    (DhcpOp,      AIpStack::DhcpOp)
    (DhcpHtype,   DhcpHwAddrType)
    (DhcpHlen,    std::uint8_t)
    (DhcpHops,    std::uint8_t)
    (DhcpXid,     std::uint32_t)
    (DhcpSecs,    std::uint16_t)
    (DhcpFlags,   std::uint16_t)
    (DhcpCiaddr,  Ip4Addr)
    (DhcpYiaddr,  Ip4Addr)
    (DhcpSiaddr,  Ip4Addr)
    (DhcpGiaddr,  Ip4Addr)
    (DhcpChaddr,  char[16])
)

AIPSTACK_DEFINE_STRUCT(DhcpHeader2,
    (DhcpSname,   char[64])
    (DhcpFile,    char[128])
)

AIPSTACK_DEFINE_STRUCT(DhcpHeader3,
    (DhcpMagic,   DhcpMagicField)
)

inline constexpr std::size_t DhcpHeaderSize =
    DhcpHeader1::Size + DhcpHeader2::Size + DhcpHeader3::Size;

AIPSTACK_DEFINE_STRUCT(DhcpOptionHeader,
    (OptType,     DhcpOptionType)
    (OptLen,      std::uint8_t)
)

AIPSTACK_DEFINE_STRUCT(DhcpOptMsgType,
    (MsgType,     DhcpMessageType)
)

AIPSTACK_DEFINE_STRUCT(DhcpOptMaxMsgSize,
    (MaxMsgSize,  std::uint16_t)
)

AIPSTACK_DEFINE_STRUCT(DhcpOptServerId,
    (ServerId,    std::uint32_t)
)

AIPSTACK_DEFINE_STRUCT(DhcpOptTime,
    (Time,        std::uint32_t)
)

AIPSTACK_DEFINE_STRUCT(DhcpOptAddr,
    (Addr,        Ip4Addr)
)

AIPSTACK_DEFINE_STRUCT(DhcpOptOptionOverload,
    (Overload,    DhcpOptionOverload)
)

}

#endif

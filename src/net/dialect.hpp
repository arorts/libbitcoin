#ifndef LIBBITCOIN_NET_DIALECT_H
#define LIBBITCOIN_NET_DIALECT_H

#include <string>
#include <memory>

#include "bitcoin/net/messages.hpp"

#include "serializer.hpp"

namespace libbitcoin {
namespace net {

class dialect
{
public:
    virtual serializer::stream to_network(
            message::version version) const = 0;

    virtual serializer::stream to_network(
            message::verack verack) const = 0;

    virtual message::header header_from_network(
            const serializer::stream& stream) const = 0;

    virtual message::version version_from_network(
            const serializer::stream& stream) const = 0;

    virtual bool verify_header(net::message::header header_msg) const = 0;
};

class original_dialect : public dialect
{
public:
    // Create stream from message
    serializer::stream to_network(message::version version) const;
    serializer::stream to_network(message::verack verack) const;

    // Create header/messages from stream
    message::header header_from_network(
            const serializer::stream& stream) const;

    message::version version_from_network(
            const serializer::stream& stream) const;

    bool verify_header(net::message::header header_msg) const;
};

} // net
} // libbitcoin

#endif
#include <map>
#include "json-rpc-interface.hpp"

#ifndef KEYBOXD_RPC_SERVER_IMPLEMENTATION
#define KEYBOXD_RPC_SERVER_IMPLEMENTATION

struct rpc_server_state;
class rpc_server : public json_rpc_context_server
{
    
public:
    explicit rpc_server();
    virtual void session_added(generic_json_rpc_session * session);
    virtual void session_removed(generic_json_rpc_session *session);
    virtual void call(generic_json_rpc_session *session, const json &id, const std::string method_name, const json& params  );

private:
    rpc_server_state *d;
    void genericReply(generic_json_rpc_session *session, const json & id, int32_t errCode, const std::string errMessage, const json & data);
};

#endif

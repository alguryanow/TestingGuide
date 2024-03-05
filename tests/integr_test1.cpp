#include "../src/Server.h"
#include "../src/Client.h"

#include <systemc>
using namespace sc_core;


int sc_main(int argc, char* argv[])
{
    //-- Сервер и Клиент
    Server server("SERVER");
    Client client("CLIENT");

    //-- через что они будут обмениваться
    sc_fifo<int> client_to_server;
    sc_fifo<int> server_to_client;

    //-- связываю Клиента с Сервером
    server.data_in(client_to_server);
    server.data_out(server_to_client);

    client.data_in(server_to_client);
    client.data_out(client_to_server);

    //-- собственно моделирование
    sc_start(1, SC_SEC);
    
    if(client.m_value != 17){
        return 1;
    }

    return 0;

};


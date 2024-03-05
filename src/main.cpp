#include "Server.h"
#include "Client.h"

#include <systemc>
using namespace sc_core;


int sc_main(int argc, char* argv[])
{
    //-- Сервер и Клиент
    Server server("SERVER");
    Client client("CLIENT");

    //-- через что они будут обмениваться
    sc_fifo<int> client_to_server;
    sc_fifo<int> server_to_client1;
    sc_fifo<int> server_to_client2;

    //-- связываю Клиента с Сервером
    server.data_in(client_to_server);
    server.data_out1(server_to_client1);
    server.data_out2(server_to_client2);

    client.data_in1(server_to_client1);
    client.data_in2(server_to_client2);
    client.data_out(client_to_server);

    //-- собственно моделирование
    sc_start(1, SC_SEC);
    
    return 0;

};


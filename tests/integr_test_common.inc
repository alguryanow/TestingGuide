#include "../src/Server.h"
#include "../src/Client.h"

#include <systemc>
using namespace sc_core;

#define DOCTEST_CONFIG_IMPLEMENT
#include "../../doctest.h"

int sc_main(int argc, char* argv[]) { return 0;} // заглушка для возможности линковки с systemc

int main(int argc, char* argv[])
{
    doctest::Context context;

    int res = context.run();

    return res;
}


TEST_CASE("test1")
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

#include "../src/Server.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "../../doctest.h"

int sc_main(int argc, char* argv[]) { return 0;} // заглушка для возможности линковки с systemc

int main(int argc, char* argv[])
{
    doctest::Context context;

    int res = context.run();

    return res;
}

TEST_CASE("Server's process() test"){
    Server server("SERVER");

    CHECK( server.process(8) == 16 );
}

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

TEST_CASE("Server's process() test, regular cases"){
    Server server("SERVER");

    CHECK( server.process1(8) == 16 );
    CHECK( server.process1(-8) == -16 ); //-- Проверка для отрицательных чисел
    CHECK( server.process2(8) == 9 );
    CHECK( server.process2(-8) == -7 ); //-- Проверка для отрицательных чисел
}

TEST_CASE("Server's process() test, corner cases"){
    Server server("SERVER");

    //-- Переполнение: 2e9 * 2 = 4e9 сильно больше 2^31
    CHECK( server.process1(2000000000) == -294967296 );  

    CHECK( server.process2(0x7FFFFFFF) == 0x80000000 );  

}

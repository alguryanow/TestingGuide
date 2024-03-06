#include "integr_test_common.inc"

    //-- задаю входные данные для тестирования
    client.m_out_value = -10;

    //-- собственно моделирование
    sc_start(1, SC_SEC);
    
    //-- проверяю выходные данные
    CHECK(client.m_inp_value1 == -20);
    CHECK(client.m_inp_value2 == -9);
}


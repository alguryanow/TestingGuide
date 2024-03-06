#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <systemc>
using namespace sc_core;

SC_MODULE(Client){
    sc_fifo_out<int> data_out;  ///* для отправки Серверу
    sc_fifo_in<int> data_in;    ///* для приёма ответа от Сервера

    SC_CTOR(Client){
        SC_THREAD(thread);
    }

    void thread(){
        //-- отправка запроса
        std::cout << "Client: sending " << m_out_value << " to Server" << std::endl;
        data_out.write(m_out_value);  
        //-- ожидание  ответа
        wait( data_in.data_written_event() );
        //-- приём и распечатка ответа
        m_inp_value = data_in.read(); 
        std::cout << "Client: got value " << m_inp_value << std::endl;
    }

    int m_out_value;    //-- для возможности задания входных данных
    int m_inp_value;    //-- для проверки выходных данных
};


#endif // __CLIENT_H__

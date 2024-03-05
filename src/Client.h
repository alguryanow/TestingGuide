#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <systemc>
using namespace sc_core;

SC_MODULE(Client){
    sc_fifo_out<int> data_out;  ///* для отправки Серверу
    sc_fifo_in<int> data_in1;    ///* для приёма ПЕРВОГО ответа от Сервера
    sc_fifo_in<int> data_in2;    ///* для приёма ВТОРОГО ответа от Сервера

    SC_CTOR(Client){
        SC_THREAD(thread);
    }

    void thread(){
        //-- отправка запроса
        std::cout << "Client: sending " << m_out_value << " to Server" << std::endl;
        data_out.write(m_out_value);  
        //-- ожидание ВТОРОГО ответа
        wait( data_in2.data_written_event() );
        //-- приём и распечатка ответа
        m_inp_value1 = data_in1.read(); 
        m_inp_value2 = data_in2.read(); 
        std::cout << "Client: got values " << m_inp_value1 << " and " << m_inp_value2 << std::endl;
    }

    int m_out_value;
    int m_inp_value1;
    int m_inp_value2;

};


#endif // __CLIENT_H__

#ifndef __SERVER_H__
#define __SERVER_H__

#include <systemc>
using namespace sc_core;

SC_MODULE(Server){
    sc_fifo_in<int> data_in;    ///* для приёма запроса от Клиента
    sc_fifo_out<int> data_out;  ///* для отправки ответа Клиенту

    SC_CTOR(Server){
        SC_THREAD(thread);
    }

    void thread(){
        while(true){
            //-- ожидание запроса от Клиента
            wait( data_in.data_written_event() );   
            //-- чтение и распечатка запроса
            int value = data_in.read();
            std::cout << "Server: got value " << value << std::endl;
            //-- отправка ответа
            data_out.write( process(value) );
        }
    }

    int process(value){
        return value*2;
    }

};

#endif // __SERVER_H__

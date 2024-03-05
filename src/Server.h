#ifndef __SERVER_H__
#define __SERVER_H__

#include <systemc>
using namespace sc_core;

SC_MODULE(Server){
    sc_fifo_in<int> data_in;    ///* для приёма запроса от Клиента
    sc_fifo_out<int> data_out1;  ///* для отправки ПЕРВОГО ответа Клиенту
    sc_fifo_out<int> data_out2;  ///* для отправки ВТОРОГО ответа Клиенту

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
            data_out1.write( process1(value) );
            data_out2.write( process2(value) );
        }
    }

    int process1(int value){
        return value*2;    
    }

    int process2(int value){
        return value+1;    
    }
};

#endif // __SERVER_H__

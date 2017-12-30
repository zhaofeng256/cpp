#include <iostream>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;
class Singleton;

pthread_t thread1;
pthread_t thread2;


class Singleton {
    public:
    static Singleton * getInstance() {
        if(NULL == gInstance) {
            pthread_mutex_lock(&mutex1);
            if(NULL == gInstance)
            gInstance = new Singleton();
            pthread_mutex_unlock(&mutex1);
        }
        return gInstance;
    }
    
    void printInfo() {
        cout << "info" << endl;
    }
    private:
    static Singleton *gInstance;
    static pthread_mutex_t mutex1; 
    Singleton() {
        cout << "constructor" << endl;
    }

};

Singleton* Singleton::gInstance;
pthread_mutex_t Singleton::mutex1 = PTHREAD_MUTEX_INITIALIZER; 

void* thread1_work(void *arg)
{
    pthread_detach(pthread_self());
    cout << "thread 1 running" << endl;
    Singleton *s = Singleton::getInstance();
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    return NULL;
}

void* thread2_work(void *arg)
{
    pthread_detach(pthread_self());
    cout << "thread 2 running" << endl;
    Singleton *s = Singleton::getInstance();
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
}

int main(int argc, char **argv)
{
    Singleton *s = Singleton::getInstance();
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    s->printInfo();

    pthread_create(&thread1, NULL, thread1_work, NULL);
    pthread_create(&thread2, NULL, thread2_work, NULL);
    sleep(3);
    return 0;

}

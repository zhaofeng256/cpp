#include <iostream>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

using namespace std;
class Singleton;
Singleton *gInstance;

pthread_t thread1;
pthread_t thread2;


class Singleton {
    public:
    static Singleton * getInstance() {
        if(NULL == gInstance)
            gInstance = new Singleton();
        return gInstance;
    }
    Singleton() {
        cout << "constructor" << endl;
    }

    void printInfo() {
        cout << "info" << endl;
    }
};

void* thread1_work(void *arg)
{
    cout << "thread 1 running" << endl;
    Singleton *s = Singleton::getInstance();
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    return NULL;
}

void* thread2_work(void *arg)
{
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

#include "event_epoll.h"
using namespace std;

typedef void fileProcessFunc(int fd, void* data);
typedef void timeProcessFunc(int fd, void* data);

typedef struct FileEvent_ {
    int state_;
    fileProcessFunc* read_func_;
    fileProcessFunc* write_func_;
}FileEvent;

typedef struct TimeEvent_ {
    int state_;
    timeProcessFunc* proc_;
}TimeEvent;

typedef struct ProcessEvent_ {
    int fd;
}ProcessEvent;

class EventLoop {
public:
    static EventLoop* GetInstance() {
        if (!instance_) {
            instance_ = new EventLoop();
        }
        return instance_;
    }

    static void Uninstall() {

    }

    int CreateFileEvent(int fd, fileProcessFunc* rproc, fileProcessFunc* wproc, int mask);
    int DeleteFileEvent(int fd, int mask);



private:
    void release();
    void seteventsize(int size) {
        fileEvents_ = (FileEvent*)malloc(sizeof(FileEvent) * size);
        processEvent_ = (ProcessEvent*)malloc(sizeof(ProcessEvent) * size);
    }


    EventLoop();
    EventLoop(int size);
    ~EventLoop();

private:
    static EventLoop*   instance_;
    FileEvent* fileEvents_;
    TimeEvent* timeEvents_;
    ProcessEvent* processEvent_;
    int         event_size_;
    int         max_fd_;
    EventEpoll  *epoll_;
}
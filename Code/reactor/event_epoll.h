#include<sys/epoll.h>
using namespace std;

#define EENONE   0
#define EEREAD   1
#define EEWRITE  2

typedef struct timeval_ {
    long sec_;
    long usec_;
}timeval;

class EventEpoll {
public:
    EventEpoll();
    EventEpoll(int size);
    ~EventEpoll();
    ResizeEvent(int size);
    int AddEvent(int fd, int mask, int state);
    int DelEvent(int fd, int mask, int state);
    int PollEvent();

private:
    int     epfd_;
    int     size_
    struct epoll_event     *events_;
}
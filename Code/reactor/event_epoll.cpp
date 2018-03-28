#include "event_epoll.h"

using namespace std;

EventEpoll::EventEpoll() {
    epfd_ = epoll_create(1024);
    event_ = malloc(sizeof(epoll_event) * 100);
    memset(event, 0, sizeof(epoll_event) * 100);
    size_ = 100;
}

EventEpoll::EventEpoll(int size) {
    epfd_  = epoll_create(1024);
    event_ = malloc(sizeof(epoll_event) * size);
    memset(event, 0, sizeof(epoll_event) * size);
    size_ = size;
}

EventEpoll::~EventEpoll() {
    free(event_);
    close(epfd_);
}

EventEpoll::ResizeEvent(int size) {

}

int EventEpoll::AddEvent(int fd, int mask, int state) {
    struct epoll_event ee = {0};
    int op = state == EENONE ? EPOLL_CTL_ADD : EPOLL_CTL_MOD;
    if (mask & EEREAD) ee.events |= EPOLLIN;
    if (mask & EEWRITE) ee.events |= EPOLLOUT;
    ee.data.fd = fd;
    if (epoll_ctl(epfd_, op, fd, &ee) == -1) return -1;
    return 0;
}

int EventEpoll::DelEvent(int fd, int mask, int state) {
    struct epoll_event ee = {0};
    state = ~mask & state;
    int op = state == EENONE ? EPOLL_CTL_DEL : EPOLL_CTL_MOD;
    if (state & EEREAD) ee.events |= EPOLLIN;
    if (state & EEWRITE) ee.events |= EPOLLOUT;
    if (epoll_ctl(epfd, op, fd, &ee) == -1) return -1;
    return 0;
}

int EventEpoll::PollEvent(timeval *tvp) {
    int num_event = epoll_wait(epfd_, events_, size_, tvp ? tvp->sec * 1000 + tvp->usec / 1000 : -1);
    if (num_event > 0) {

    }
    return num_event;
}
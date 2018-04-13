#ifndef __SKIPLIST_H__
#define __SKIPLIST_H__

#include <string>
using namespace std;

#define MAX_LEVEL 10
typedef string type;
typedef struct skiplistlevel {
    struct _skip_list_node *forward_;
    unsigned int span_;
} SkipListLevel,

typedef struct _skip_list_node {
    string value_;
    double score_;
    struct _skip_list_node *backward_;
    SkipListLevel level_[];
}SkipListNode;


class SkipList {
public:
    SkipList();
    ~SkipList();
    int InsertNode(string value, double score);
    int DeleteNode(string value, double score);
    vector<string> Find(double score);
private:
    SkipListNode* createnode(int level, type value, double score);
    int randomlevel();
    
private:
    SkipListNode *header_, *tail_;
    unsigned long length_;
    int level_;
}

#endif
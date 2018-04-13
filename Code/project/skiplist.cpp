#include "skiplist.h"
#include <time.h>
#include <vector>

using namespace std;

int getrandom() {
  srand((int)time(0));
  return rand();
}

SkipList::SkipList() {
    level_ = 1;
    length_ = 0;
    header_ = createnode(MAX_LEVEL, "", 0);
    for (int i = 0; i < MAX_LEVEL; i ++) {
        header_->level_[i].forward_ = NULL;
        header_->level_[i].span_ = 0;
    }
    header_->backward_ = NULL;
    tail_ = NULL;
}

SkipList::SkipList() {

}

int SkipList::InsertNode(string value, double score) {
  SkipListNode* pnode = header_;
  SkipListNode* updata[MAX_LEVEL];
  int span[MAX_LEVEL];
  memset(updata, 0, sizeof(SkipList*) * MAX_LEVEL);
  while (pnode != NULL) {
    for (int i = level_ - 1; i >= 0; i--) {
      span[i] = i == level_ - 1 ? 0 : span[i + 1];
      while (pnode->level_[i].forward_ != NULL && pnode->level_[i].forward_->score_ <= score) {
        pnode = pnode->level_[i].forward_;
        span[i] ++;
      }
      updata[i] = pnode;
    }
  }
  int level = randomlevel();
  SkipListNode *insert_node = createnode(level, value, score);
  if (level > level_) {
    for (int i = level_; i < level - 1; i++) {
      updata[i] = header_;
      span[i] = 0;
      header_->level_[i].span_ = length_;
    }
    level_ = level;
  }
  for (int i = 0; i < level; i++) {
    insert_node->level_[i].forward_ = updata[i]->level_[i].forward_;
    insert_node->level_[i].span_ = updata[i]->level_[i].span_ - span[0];
    updata[i]->level_[i].forward_ = insert_node;
    updata[i]->level_[i].span_ = i == 0 ? 1 : updata[i - 1]->level_[i - 1].span_ + span[i - 1];
  }

  for (int i = level; i < level_; i++) {
    updata[i]->level_[i].span_++;
  }

  insert_node->backward_ = updata[0] == header_ ? NULL : updata[0];
  length_++;
  if (insert_node->level_[0].forward_ != NULL) {
    insert_node->level_[0].forward_->backward_ = insert_node;
  }
  else {
    tail_ = insert_node;
  }
  return 0;
}

int SkipList::DeleteNode(string value, double score) {
  SkipListNode *updata[MAX_LEVEL], *pnode;
  pnode = header_;
  for (int i = level_ - 1; i >= 0; i--) {
    while (pnode->level_[i].forward_ != NULL && (pnode->level_[i].forward_->score_ < score || 
      (pnode->level_[i].forward_->score_ == score && pnode->level_[i].forward_->value_ < value))) {
      pnode = pnode->level_[i].forward_;
    }
    updata[i] = pnode;
  }
  pnode = pnode->level_[0].forward_;
  for (int i = 0; i < level_; i++) {
    if (updata[i]->level_[i].forward_ != pnode) {
      updata[i]->level_[i].span_--;
    }
    else {
      updata[i]->level_[i].forward_ = pnode->level_[i].forward_;
      updata[i]->level_[i].span_ += pnode->level_[i].span_ - 1;
    }
  }
  while (level_ > 1 && header_->level_[level_ - 1].forward_ == NULL) {
    level_--;
  }
  free(pnode);
  length_--;
}

vector<string> SkipList::Find(double score) {
  SkipListNode *pnode;
  pnode = header_;
  for (int i = level_ - 1; i >= 0; i--) {
    while (pnode->level_[i].forward_ != NULL && (pnode->level_[i].forward_->score_ < score)) {
      pnode = pnode->level_[i].forward_;
    }
  }
  pnode = pnode->level_[0].forward_;
  vector<string> res_vec;
  while (pnode->score_ == score) {
    res_vec.push_back(pnode->value_);
  }
  return res_vec;
}

SkipListNode* SkipList::createnode(int level, type value, double score) {
    SkipListNode *node = (SkipListNode*)malloc(sizeof(SkipListNode) + level * sizeof(skiplistlevel));
    memset(node, 0, sizeof(SkipListNode) + sizeof(skiplistlevel) * level);
    node->score_ = score;
    node->value_ = value;
}

int SkipList::randomlevel() {
  int lev = 1;
  while (getrandom() & 0xFFFF < 0.25 * 0xFFFF) {
    lev++;
  }
  return lev > MAX_LEVEL ? MAX_LEVEL : lev;
}







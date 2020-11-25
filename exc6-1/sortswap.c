#include "lists.h"
void swap(ListEntry* left, ListEntry* right) {
    if (left != right) {
        ListEntry* RightBefore;
        ListEntry* RightAfter;
        ListEntry* LeftBefore;
        ListEntry* LeftAfter;
        if (left->After != right) {
            RightBefore = right->Before;
            LeftAfter = left->After;
            LeftBefore = left->Before;
            RightAfter = right->After;
            left->Before = RightBefore;
            left->After = RightAfter;
            RightAfter->Before = left;
            RightBefore->After = left;
            right->Before = LeftBefore;
            right->After = LeftAfter;
            LeftAfter->Before = right;
            LeftBefore->After = right;
        }
        else
        {
            LeftBefore = left->Before;
            RightAfter = right->After;
            LeftBefore->After = right;
            right->Before = LeftBefore;
            right->After = left;
            left->Before = right;
            RightAfter->Before = left;
            left->After = RightAfter;
        }
    }
}
void MyQsort(ListEntry* head, ListEntry* tail, int first, int last)
{
    if (first < last) {
        int right = last;
        ListEntry* right1 = head;
        int counter = 0;
        while (counter != right) {
            right1 = right1->After;
            ++counter;
        }
        StringList* right2 = GET_CONTENT_RECORD(StringList, pointers, right1);
        int left = first;
        ListEntry* left1 = head;
        counter = 0;
        while (counter != left) {
            left1 = left1->After;
            ++counter;
        }
        StringList* left2 = GET_CONTENT_RECORD(StringList, pointers, left1);
        StringList* middle_ = GET_CONTENT_RECORD(StringList, pointers, right1);
        while (left <= right) {
            while (left2->size < middle_->size) {
                left++;
                left1 = left1->After;
                left2 = GET_CONTENT_RECORD(StringList, pointers, left1);
            }
            while (right2->size > middle_->size) {
                right--;
                right1 = right1->Before;
                right2 = GET_CONTENT_RECORD(StringList, pointers, right1);
            }
            if (left <= right) {
                ListEntry* left1pos = left1->After;
                ListEntry* right1pos = right1->Before;
                swap(left1, right1);
                left1 = left1pos;
                right1 = right1pos;
                left++;
                right--;
                right2 = GET_CONTENT_RECORD(StringList, pointers, right1);
                left2 = GET_CONTENT_RECORD(StringList, pointers, left1);
            }
        }
        MyQsort(head, tail, first, right);
        MyQsort(head, tail, left, last);
    }
}
void Sort(ListEntry* head, ListEntry* tail, int first, int last) {
    if (first < last && head != tail) {
        ListEntry* Left = head;
        ListEntry* Right = tail;
        ListEntry* Middle = tail;
        StringList* left2 = GET_CONTENT_RECORD(StringList, pointers, Left);
        StringList* middle_ = GET_CONTENT_RECORD(StringList, pointers, Middle);
        StringList* right2 = GET_CONTENT_RECORD(StringList, pointers, Right);
        int LEFT = first;
        int RIGHT = last;
        while (LEFT <= RIGHT)
        {
            while (left2->size < middle_->size) {
                Left = Left->After;
                LEFT++;
                left2 = GET_CONTENT_RECORD(StringList, pointers, Left);
            }
            while (right2->size > middle_->size) {
                Right = Right->Before;
                RIGHT--;
                right2 = GET_CONTENT_RECORD(StringList, pointers, Right);
            }
           
            if (LEFT <= RIGHT)
            {
                ListEntry* left1pos = Left->After;
                ListEntry* right1pos = Right->Before;
                if (Left == head) {
                    head = Right;
                }
                if (Right == tail) {
                    tail = Left;
                }
                swap(Left, Right);
                if (LEFT + 1 != RIGHT) {
                    Left = left1pos;
                    Right = right1pos;
                }
                LEFT++;
                RIGHT--;
                left2 = GET_CONTENT_RECORD(StringList, pointers, Left);
                right2 = GET_CONTENT_RECORD(StringList, pointers, Right);
            }
        }
       
        if (head != Right) {
            Sort(head, Right, first, RIGHT);
        }
        if (Left != tail) {
            Sort(Left, tail, LEFT, last);
        }
    }
}
void QSort(ListEntry* head, ListEntry* tail) {
    Sort(head->After, tail->Before, 0, SIZE-1);
}
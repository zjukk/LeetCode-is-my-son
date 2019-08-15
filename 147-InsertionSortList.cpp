#include <iostream>
#include <limits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        //此处不能有dummy->next = head，dummy->next = NULL,这是一个排序好的链表，每加进来一个元素其末尾元素的next都指向NULL
        //dummy指向的是当前的最小元素
        ListNode* dummy = new ListNode(-1);
        // ListNode* lc=head;
        // head=head->next;
        // lc->next=NULL;
        while (head) {
            ListNode* next = head->next;//将下一次要排序的结点提前保存下来
            //需要指出的是cur和dummy是两个不同的指针，但是两者的值相同，也就是指向的对象时同一个对象
            ListNode* cur = dummy;
            //用cur来遍历已经排好序的部分，head来保存未排序部分的头结点
            //找到的元素（cur->next），刚好大于等于head,如果直接用cur进行比较，则需要访问cur的前一个结点，
            // 需要单独记录，所以采用cur->next进行比较。区别于数组的插入排序，
            // 由于单向链表的特性链表这里是从前往后找插入位置
            while (cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            //跳出循环时，cur指向的是插入点前的那个对象，已和dummy无任何关系
            head->next = cur->next;
            cur->next = head;
            head = next;//更新下一次进入排序的结点
        }
        return dummy->next;
        //Taking memory leak into consideration
        //ListNode* res = dummy->next;
        //delete dummy;
        //return res;
    }
};
//this one runs faster
//比较已经排好序的链表尾部结点pre和下一个结点cur值的大小，如果pre->val > cur->val就从头dummy开始寻找cur应该插入的位置
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = head;//由于在循环中需要比较
        ListNode* cur = pre->next;
        while (cur) {
            if (cur && pre->val > cur->val) {
                ListNode* tmp = dummy;
                //<=->stable, <->unstable
                while (tmp->next->val <= cur->val) {
                    tmp = tmp->next;//这个操作是相当于给tmp重新赋值，并不影响dummy的值
                }
                //此时要讲cur插入到tmp和tmp->next中间
                pre->next = cur->next;
                cur->next = tmp->next;
                tmp->next = cur;
                cur = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
int main() {
    return 0;
}
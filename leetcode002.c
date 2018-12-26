#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertList(char *string) {
	struct ListNode* newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->next = 0;
	newNode->val = 0;
	struct ListNode* headNode = newNode;
	int flag = 0;
	for(int i=0;i<strlen(string);++i) {
		if (flag == 0) {
			newNode->val = string[i]-'0';
			flag = 1;
		}
		else {
			struct ListNode* nextNode = (struct ListNode *)malloc(sizeof(struct ListNode));
			nextNode->val = string[i]-'0';
			nextNode->next = 0;
			newNode->next = nextNode;
			newNode = nextNode;
		}
	}
	return headNode;
}

void printNode(struct ListNode *listNode) {
	while(listNode) {
		printf("%d", listNode->val);
		listNode = listNode->next;
	}
	printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->next = 0;
	newNode->val = 0;
	struct ListNode* headNode = newNode;
	int flag = 0;
	while(l1 || l2 || flag) {
		int a = 0;
		int b = 0;
		int sum = 0;
		int mark = 0;
		a = l1 ? l1->val : 0;
		b = l2 ? l2->val : 0;
		sum = a+b+flag;
		flag = sum/10;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
		struct ListNode* nextNode = (struct ListNode *)malloc(sizeof(struct ListNode));
		nextNode->val = sum%10;
		nextNode->next = 0;
		newNode->next = nextNode;
		newNode = nextNode;
	}
	return headNode->next;
}

int main(int argc, char const *argv[])
{
	char *ch = "12345\0";
	char *ch1 = "912345\0";
	struct ListNode *listA = insertList(ch);
	struct ListNode *listB = insertList(ch1);
	struct ListNode *listC = addTwoNumbers(listA,listB);
	printNode(listA);
	printNode(listB);
	printNode(listC);
	return 0;
}
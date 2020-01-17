#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

SinglyLinkedListNode* pre(SinglyLinkedListNode* init, int n) {
	SinglyLinkedListNode* walker = init, *link;
  	
  	while(walker->next != NULL)
    {
        if(walker->data == n)
            link = walker;
      
        walker = walker->next;
    }
  
  	walker->next = link;
  	return init;
}

// ||START EDITING|| 

/*
 * Complete the 'grantWish' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* grantWish(SinglyLinkedListNode* head) {
    
    vector<int> values;
    
    while (head != nullptr){
        
        values.push_back(head->data);
        head = head->next;
    }
    
    int size = values.size();
    int repeat_index;
    int repeating = values[size-1];
    
    for (int i=0;i+1<size;i++)
    {
        if (values[i] == repeating)
            repeat_index = i;
    }
    
    int num_repeating = size - repeat_index - 1;
    
    num_repeating/=2;
    
    int new_repeat = values[size - num_repeating - 1];
    
    values[size-1] = new_repeat;
    
    SinglyLinkedList *res = new SinglyLinkedList();
    
    for (int i=0;i<size;i++)
    {
        res->insert_node(values[i]);
    }
    
    return res->head;
}

// ||END EDITING||


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* init = new SinglyLinkedList();

    string init_count_temp;
    getline(cin, init_count_temp);

    int init_count = stoi(ltrim(rtrim(init_count_temp)));

    for (int i = 0; i < init_count; i++) {
        string init_item_temp;
        getline(cin, init_item_temp);

        int init_item = stoi(ltrim(rtrim(init_item_temp)));

        init->insert_node(init_item);
    }

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    SinglyLinkedListNode* head2 = pre(init->head, n);

    SinglyLinkedListNode* answer = grantWish(head2);

    while(answer->data > 0)
    {
      	fout << answer->data << " ";
      	answer->data *= -1;
      	answer = answer->next;
    }
  	fout << -1*answer->data << " ";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

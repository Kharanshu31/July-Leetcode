/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *p=head;
        stack<Node *>s;
        while(p!=NULL || !s.empty())
        {
            if(p->child!=NULL)
            {
                if(p->next!=NULL)
                    s.push(p->next);
                
                p->next=p->child;
                p->next->prev=p;
                p->child=NULL;
            }
            
            else
            {
                if(p->next==NULL && !s.empty())
                {
                    p->next=s.top();
                    s.pop();
                    p->next->prev=p;
                }
            }
            p=p->next;
            
        }
        
//         while(p!=NULL || !s.empty())
//         {
//             if(p->child!=NULL)
//             {
//                 if(p)
//                     s.push(p);
                
//                 p->next=p->child;
//                 p->next->prev=p;
//                 p->child=NULL;
//             }
            
//             else
//             {
//                 if(p->next==NULL && !s.empty())
//                 {
//                     p=s.top();
//                     s.pop();
//                 }
//             }
//             p=p->next;
            
//         }
        
        
        return head;
    }
};

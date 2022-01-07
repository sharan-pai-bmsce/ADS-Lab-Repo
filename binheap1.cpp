#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data,degree;
    Node *child,*sibling,*parent;

    Node(int key){
        data=key;
        degree=0;
        child=parent=sibling=NULL;
    }
};

list<Node*> unionHeap(list<Node*> heap,list<Node*> temp){
    auto it1=heap.begin();
    auto it2=temp.begin();
    list<Node*> li;
    while(it1!=heap.end()&&it2!=temp.end()){
        if((*it1)->degree<=(*it2)->degree){
            li.push_back(*it1);
            it1++;
        }else{
            li.push_back(*it2);
            it2++;
        }
    }

    while(it1!=heap.end()){
        li.push_back(*it1);
        it1++;
    }
    while(it2!=temp.end()){
        li.push_back(*it2);
        it2++;
    }

    return li;
}

Node *merge(Node* h1,Node* h2){
    h2->parent=h1;
    h2->sibling=h1->child;
    // This must always come after the sibling statement since if we assign the child already we will end up losing the child pointer.
    /*
                        12
                       / |
                      /  |
      (Child of 12)  17  14 (Now: sibling of 17,earlier: child of 12)
                     |
                    21 
    */
    h1->child=h2;
    h1->degree++;
    if(h1->data<h2->data){
        int temp=h1->data;
        h1->data=h2->data;
        h2->data=temp;
    }
    return h1;
}

list<Node*> adjust(list<Node*> temp){
    if(temp.size()<=1){
        return temp;
    }
    list<Node*> ls;
    auto it1=temp.begin();
    auto it2=temp.begin();
    auto it3=temp.begin();
    if(temp.size()==2){
        it2++;
        it3=temp.end();
    }else{
        it2++;
        it3=it2;
        it3++;
    }

    while(it1!=temp.end()){
        if(it2==temp.end()){
            it1++;
        }else if((*it1)->degree<(*it2)->degree){
            it1++;
            it2++;
            if(it3!=temp.end()){
                it3++;
            }
        }else if(it3!=temp.end()&&(*it1)->degree==(*it2)->degree&&(*it1)->degree==(*it3)->degree){
            it1++;
            it2++;
            it3++;
        }else if((*it1)->degree==(*it2)->degree){
            *it1=merge(*it1,*it2);
            it2=temp.erase(it2);
            if(it3!=temp.end()){
                it3++;
            }
        }
    }
    return temp;
}

list<Node*> insert(list<Node*> heap,int key){
    // Node* node=new Node(key);
    list<Node*> temp;
    // temp.push_back(node);
    temp.push_back(new Node(key));
    temp=unionHeap(heap,temp);
    return adjust(temp);
}

void printTree(Node* root){
    while(root){
        cout<<root->data<<" ";
        printTree(root->child);
        root=root->sibling;
    }
}
void printHeap(list<Node*> heap){
    int i=0;
    for(auto it=heap.begin();it!=heap.end();it++){
        cout<<"Tree-"<<i<<":";
        printTree(*it);
        i++;
        cout<<endl;
    }
}

Node* getMin(list<Node*> heap){
    Node *minN;
    int min=INT16_MAX;
    for(auto it=heap.begin();it!=heap.end();it++){
        if((*it)->data<min){
            min=(*it)->data;
            minN=*it;
        }
    }
    return minN;
}

list<Node*> removeNode(Node* root){
    list<Node*> nHeap,lo;
    Node* temp=root->child;
    Node* k;
    while(temp!=NULL){
        k=temp;
        temp=temp->sibling;
        k->sibling=NULL;
        nHeap.push_front(k);
    }
    return nHeap;
}

list<Node*> extractMin(list<Node*> heap){
    list<Node*> nHeap,lo;
    Node* temp=getMin(heap);
    for(auto it=heap.begin();it!=heap.end();it++){
        if((*it)!=temp){
            nHeap.push_back(*it);
        }
    }
    lo=removeNode(temp);
    nHeap=unionHeap(nHeap,lo);
    return adjust(nHeap);
}

int main(){
    list<Node*> heap;
    heap=insert(heap,12);
    cout<<"First:"<<endl;printHeap(heap);
    heap=insert(heap,14);
    cout<<"Second:"<<endl;printHeap(heap);
    heap=insert(heap,10);
    cout<<"Third:"<<endl;printHeap(heap);
    heap=insert(heap,9);
    cout<<"Forth:"<<endl;printHeap(heap);
    heap=extractMin(heap);
    cout<<"Fifth:"<<endl;printHeap(heap);
    return 0;
}
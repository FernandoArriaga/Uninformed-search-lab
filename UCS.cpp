#include<stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include<list>

class statenode {
public:
int pathcost;
int Nstart;
int Nfinish;
statenode* parent;
std::vector<std::stack<char> > stacks;
//std::list<statenode*> children;
void cpc(void)
{
    this->pathcost=(parent->pathcost)+1+abs(Nstart-Nfinish);
}

friend class UCS;
};

unsigned int hn(statenode*)
{
    return 0;
}

class UCS {
    public:
int height;
unsigned int lowestpathcost;
statenode* Instate;
statenode* Goalstate;
std::vector<statenode*> Pqueue;

statenode* fn(void)
{
    int j;
    statenode* temp;
 for (unsigned int i=0;i<Pqueue.size();i++)
 {
     if(((Pqueue[i]->pathcost)+hn(Pqueue[i]))<lowestpathcost)
     {
         lowestpathcost=((Pqueue[i]->pathcost)+hn(Pqueue[i]));
         temp=Pqueue[i];
         j=i;
     }
 }
 Pqueue.erase(Pqueue.begin()+j);
 return temp;
}

void expand (statenode* p)
{

}

friend class statenode;
};


statenode* initialize(std::string buffer){
statenode* temp=new statenode;
std::stack<char> sbuffer;
int j=0;
for(unsigned int i=0;i<buffer.length();i++)
{
    if(buffer[i]>='A' && buffer[i]<='z')
    {
    sbuffer.push(buffer[i]);
    }

    if(buffer[i]==';')
    {
    temp->stacks.push_back(sbuffer);
    j++;
        while(!sbuffer.empty())
        {
        sbuffer.pop();
        }
    }
}
temp->stacks.push_back(sbuffer);
temp->parent=0;
temp->Nstart=0;
temp->Nfinish=0;
temp->pathcost=0;
return temp;
}


statenode* shift(statenode* node, int start, int finish)
{
statenode* next=new statenode;
for(unsigned int i=0; i<node->stacks.size();i++)
{
next->stacks.push_back(node->stacks[i]);
}
next->stacks[finish].push(next->stacks[start].top());
next->stacks[start].pop();
next->parent=node;
next->Nstart=start;
next->Nfinish=finish;
next->cpc();
std::cout<<next->stacks[start].top();
return next;
}

bool comp (statenode* current, statenode* goal)
{
    for (unsigned int i=0; i<current->stacks.size();i++)
    {
        while (!current->stacks[i].empty()&&!goal->stacks[i].empty())
        {
            if (current->stacks[i].top()!=goal->stacks[i].top())
                return false;
            current->stacks[i].pop();
            goal->stacks[i].pop();
        }
        if(current->stacks[i].empty()!=goal->stacks[i].empty())
            return false;
    }
    return true;
}

void solution(statenode* temp)
{
    if (temp->parent->parent==0)
    {
        std::cout<<"("<<temp->Nstart<<","<<temp->Nfinish<<")";
        return;
    }
    solution(temp->parent);
    std::cout<<";"<<"("<<temp->Nstart<<","<<temp->Nfinish<<")";
    return;
}

int main(int argc, char* argv[]) {
std::stack<char> out;
UCS SS;
SS.lowestpathcost=4294967295;

std::string line;
std::vector<std::string> lines;
std::cin>>SS.height;
std::getline(std::cin,line);
scanf("%d",&SS.height);

std::getline(std::cin, line);
SS.Instate=initialize(line);

std::getline(std::cin, line);

SS.Goalstate=initialize(line);
SS.Goalstate->parent=SS.Instate;

SS.Pqueue.push_back(SS.Instate);


if (comp(SS.Instate,SS.Goalstate))
    std::cout<<"success"<<std::endl;
else
    std::cout<<"not the same"<<std::endl;

std::cout<<SS.Goalstate->pathcost<<std::endl;
solution(SS.Goalstate);

std::cout<<SS.height<<std::endl;
printf("\n");*/

for(unsigned int i=0; i<SS.Instate->stacks.size();i++)
{
while (!SS.Instate->stacks[i].empty())
{
std::cout<<SS.Instate->stacks[i].top()<<std::endl;
SS.Instate->stacks[i].pop();
}
printf("\n");
}

for(unsigned int i=0; i<SS.Goalstate->stacks.size();i++)
{
while (!SS.Goalstate->stacks[i].empty())
{
std::cout<<SS.Goalstate->stacks[i].top()<<std::endl;
SS.Goalstate->stacks[i].pop();
}
printf("\n");
}

  return 0;
}

#include<bits/stdc++.h>
#include<vector>
#include<map>

typedef long long ll;

using namespace std;
ll itemincache=0;

ll capacity;



// doubly linked list
template <typename p,typename t>
class LRU
{
    
public:

struct node
{
    t key;
    p value;
    struct node *prev=NULL;
    struct node *next=NULL;
};
struct node *front=NULL;     //new element entered
struct node *rear=NULL;      //least recently used element

map<p,struct node *> mp;    //to store key and corresponding address



void set_value(p a,t b)
{          
        

                //if item is present in cache
              
               if(mp.find(a)!=mp.end())
              { 
                mp[a]->value = b;
               struct node *find_b = mp[a];

          

               if(find_b==front) {
                 return;
                    }
              if(find_b == rear) {
          rear = rear->prev;
          rear->next = NULL;
       }
      else {
          find_b->prev->next = find_b->next;
          find_b->next->prev = find_b->prev;
      }

      find_b->next = front;
      find_b->prev = NULL;
      front->prev = find_b;
      front = find_b;
      return ;
       }


            

                        //if item not present in the cache
           
             if(itemincache == capacity)
                {
                   p remove_key=rear->key;
                    mp.erase(remove_key);
                   
                   if(rear==NULL)
                   {
                    return;
                   }
                   if(front == rear) {
                   delete rear;
                  front =rear= NULL;
                   }
                  else 
                      {
                         struct node *temp = rear;
                         rear = rear->prev;
                         rear->next = NULL;
                         delete temp;
                       }


            itemincache--;


                }
            struct node *new_node;
     
            new_node=(struct node *)malloc(sizeof(struct node));
            new_node->key=a;
            new_node->value=b;
            
           if (!front && !rear)
           {
           rear = front = new_node;
          
           }
           else
           {
            new_node->next=front;
            front->prev=new_node;
            front=new_node;
           }
           itemincache++;

            mp.insert(make_pair(new_node->key,new_node));    // insert in map
            
            // insert value in doubly linked list


}


t get_value(p a)
{
   

     if(mp.find(a)==mp.end())

     {    
        // cout<<"key not found"<<endl;
          return "-1";
     }

    t val=mp[a]->value;
    
     
    if(mp[a]==front) {
          return val;
      }
      if(mp[a] == rear) {
          rear = rear->prev;
          rear->next = NULL;
      }
      else {
          mp[a]->prev->next = mp[a]->next;
          mp[a]->next->prev = mp[a]->prev;
      }

      mp[a]->next = front;
      mp[a]->prev = NULL;
      front->prev = mp[a];
      front = mp[a];

 //cout<<"key found"<<endl;
 return val;

}
};
   
int main()
{   
    //struct node *temp;
    LRU<string,string> lru;
    //ll cell;            //frame in cache
    cin>>capacity;

    ll n;            //number of test cases
    cin>>n;

    char type;
    //vector<string> vc;

    string key,value;
    
    for(int i=0;i<n;i++)
    { 
        cin>>type;
         if(type=='S')
        {
            cin>>key>>value;
            lru.set_value(key,value);
            
        }
        if(type=='G')
        {
            cin>>key;
            
         cout<<lru.get_value(key)<<endl;
        }
       
    }
 
    return 0;
   
}




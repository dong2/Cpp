#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>

typedef struct item{
    char id[64];
    char ip[64];
    int port;
    int status;
    bool operator==(struct item b) const  
    {  
        return (strcmp(this->id, b.id)==0);  
    }  
    bool operator!=(struct item b) const  
    {  
        return (strcmp(this->id, b.id)!=0);
    }  
} item_t;

template < typename T>
class db_t { 
  public:
    std::list<T> l;
  public:
    int insert(T t)
    {
        auto it = std::find(l.begin(), l.end(), t);
        if (it == l.end()) {
            l.insert(it, t);
            return 0;
        }else{
            return -1;
        }
    }

    int remove(const char* id){
        int i;
        if(l.size() == 0) return -1;
        
        for (T &n : l) {
            if(strcmp(n.id, id) == 0){
                l.remove(n);
                break;
            }else i++;
        }
        if(i == l.size()) return -1;
        else return 0;
    }

    int update(T t, const char* id){
        int i;
        if(l.size() == 0) return -1;

        for (T &n : l) {
            if(strcmp(n.id, id) == 0){
                n = t;
                break;
            }else i++;
        }
        if(i == l.size()) return -1;
        else return 0;        
    }

    T select(const char* id){
        T t;
		memset(&t, 0, sizeof(T));
        for (T &n : l) {
            if(strcmp(n.id, id) == 0){
                t = n;
                break;
            }
        }
        return t;
    }

    int size()
    {
        return l.size();
    }

    void dump(){
        for (T &n : l) {
            std::cout << n.id << '\n';
			std::cout << n.ip << '\n';
			std::cout << n.port << '\n';
			std::cout << n.status << '\n';
        }    
    }

  private:

};

int main()
{
    db_t<item_t> db;
    
    item_t item1;
	memset(&item1, 0, sizeof(item_t));
    strcpy(item1.id,"34020000001320000001"); 

    item_t item2;
	memset(&item2, 0, sizeof(item_t));
    strcpy(item2.id,"34020000001320000002");

    item_t item3;
	memset(&item3, 0, sizeof(item_t));
    strcpy(item3.id,"34020000001320000003"); 
    strcpy(item3.ip,"127.0.0.1");
 
    std::cout << "-------------insert----------------" << '\n';

    //insert
    db.insert(item1);
    db.insert(item2);
    db.insert(item3);

    std::cout << db.size() << '\n';
    db.dump();
    
    std::cout << "-------------delete----------------" << '\n';

    //delete
    db.remove("34020000001320000001");
    db.remove("34020000001320000002");
    //db.remove("34020000001320000003");

    std::cout << db.size() << '\n';
    db.dump();
    
    std::cout << "-------------select----------------" << '\n';

    //select
    item_t item = db.select("34020000001320000003");
    std::cout << item.ip << '\n';

    std::cout << db.size() << '\n';
    db.dump();

    std::cout << "-------------update----------------" << '\n';

    //update
    item_t item_tmp = db.select("34020000001320000003");
    strcpy(item_tmp.ip,"0.0.0.0");
    item_tmp.port = 6000;
    item_tmp.status = 0;
    db.update(item_tmp, "34020000001320000003");

    std::cout << db.size() << '\n';
    db.dump();

    return 0; 
}

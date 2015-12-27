#include<iostream>
#include<string.h>
class Cstring 
{
public:
//    Cstring();
    Cstring(const char * str=NULL);
    Cstring(const Cstring & obj_str);
    const Cstring & operator=(const Cstring & obj_str);
    friend const Cstring operator+(const Cstring & obj_stra, const Cstring & obj_strb);
    void print();
    ~Cstring();
private:
    char *data;
};/*
Cstring::Cstring()
{
    data=NULL;
}*/
Cstring::Cstring(const char * str)
{
    if(str!=NULL){
        int len = strlen(str)+1;
        data = new char[len];
        memcpy(data, str, len);
    }else{
        data=NULL;
    }
}
Cstring::Cstring(const Cstring & obj_str)
{
    int len;
//    delete []data;
    if(obj_str.data!=NULL){
        len = strlen(obj_str.data)+1;
        this->data = new char[len];
        memcpy(this->data, obj_str.data, len);
    }else
        data = NULL;
}
const Cstring & Cstring::operator=(const Cstring & obj_str)
{
    int len;
    if(data!=NULL)
        delete []data;
    if(obj_str.data!=NULL){
        len = strlen(obj_str.data)+1;
        this->data = new char[len];
        memcpy(this->data, obj_str.data, len);
    }else
        data = NULL;
}
const Cstring operator+(const Cstring & obj_stra,const Cstring & obj_strb)
{
    int len;
    Cstring result;
    if(obj_stra.data!=NULL||obj_strb.data!=NULL){
        len = strlen(obj_stra.data)+strlen(obj_strb.data)+1;
        result.data = new char[len];
        memcpy(result.data, obj_stra.data, strlen(obj_stra.data));
        memcpy(result.data+strlen(obj_stra.data), obj_strb.data, strlen(obj_strb.data)+1);
    }else
        result.data = NULL;
    return result;
}
void Cstring::print()
{
    if(data!=NULL)
        std::cout<<data<<std::endl;
}
Cstring::~Cstring()
{
    if(data!=NULL)
        delete []data;
}
int main(void)
{
    Cstring obja("abc");
    Cstring objb("def");
    Cstring objc;
//    Cstring objc=obja+objb;
    objc=obja+objb;
    Cstring objd(obja);
    obja.print();
    objb.print();
    objc.print();
    objd.print();
}

#ifndef CHAIN_H
#define CHAIN_H


template <typename T>class chain
{
public:
    chain()
    {
        s=0;
        start=nullptr;
    };
    ~chain()
    {
        while(s>0)
        {
            del(0);
        }
    };
    void add(T t)
    {
        s++;
        object* d=start;
        start=new object(t, d);
        return;
    };
    void invert(){
        for(int i=0; i<s/2; i++){
            T dummy = get_data(i);
            set_data(i, get_data(s-i-1));
            set_data(s-i-1, dummy);
        }
        return;
    }
    void append(T t)
    {
        if(s==0) add(t);
        else
        {
            s++;
            object* d=start;
            for(int i=0; i<s-2; i++) d=d->get_next();
            d->set_next(new object(t));
        }
        return;
    };
    void ins(T t, int i)
    {
        if(i==0) add(t);
        else if(s>0 and i<=s)
        {
            s++;
            object* d=start;
            for(int c=0; c<i-1; c++) d=d->get_next();
            object* d2=d->get_next();
            d->set_next(new object(t, d2));
        }
        return;
    }
    void del(int i)
    {
        if(i==0 && s>0)
        {
            s--;
            object* d=start->get_next();
            delete start;
            start=d;
        }
        else if(i<=s && s>0)
        {
            s--;
            object* d=start;
            for(int c=0; c<i-1; c++) d=d->get_next();
            object* d2=d->get_next();
            object* d3=d2->get_next();
            delete d2;
            d->set_next(d3);
        }
        return;
    };
    T get_data(int i)
    {
        if(0<=i && i<s)
        {
            object* d=start;
            for(int c=0; c<i; c++) d=d->get_next();
            return d->get_data();
        }
        else return nullptr;
    }
    void set_data(int i, T data)
    {
        if(0<=i && i<s)
        {
            object* d=start;
            for(int c=0; c<i; c++) d=d->get_next();
            d->set_data(data);
        }
        return;
    }
    int get_size(void)
    {
        return s;
    }
private:
    class object
    {
    public:
        object()
        {
            next=nullptr;
            return;
        }
        object(T d)
        {
            data=d;
            return;
        }
        object(T d, object* n)
        {
            data=d;
            next=n;
            return;
        }
        ~object()
        {
            return;
        }
        object* get_next(void)
        {
            return next;
        }
        void set_next(object* n)
        {
            next=n;
            return;
        }
        T get_data(void)
        {
            return data;
        }
        void set_data(T d)
        {
            data=d;
            return;
        }
    private:
        T data;
        object* next;
    };
    int s;
    object* start;
};

#endif // CHAIN_H
